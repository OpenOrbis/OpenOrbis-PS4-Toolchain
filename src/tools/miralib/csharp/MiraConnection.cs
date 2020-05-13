using Google.Protobuf;
using System;
using System.Diagnostics;
using System.IO;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Text;

/// <summary>
/// Namespace <c>MiraLib</c> contains all the necessary classes and functions for managing consoles on the PC side for applications to use.
/// </summary>
namespace MiraLib
{
    /// <summary>
    /// Class <c>MiraConnection</c> contains variables and functions necessary for connecting and sending messages to the PS4, as well as receiving responses from it.
    /// </summary>
    public class MiraConnection
    {
        private TcpClient m_Client;

        #region Constants
        // Default RPC port
        public const int c_DefaultPort = 9999;

        // Default logging port
        public const int c_DefaultLog = 9998;

        // Default max buffer size (64 MiB)
        public const int c_MaxBufferSize = 0x4000000;

        public const int c_HeaderMagic = 0b10;
        #endregion

        /// <summary>
        /// Is the client currently connected
        /// </summary>
        public bool IsConnected => m_Client?.Connected ?? false;

        /// <summary>
        /// IP Address or hostname of the console
        /// </summary>
        public string ConnectionAddress { get; protected set; }

        /// <summary>
        /// Connection port
        /// </summary>
        public ushort ConnectionPort { get; protected set; }

        /// <summary>
        /// Consoles name (or address if not populated)
        /// </summary>
        public string ConsoleName { get; protected set; }

        /// <summary>
        /// Maximum buffer size
        /// </summary>
        public int MaxBufferSize { get; protected set; } = c_MaxBufferSize;

        /// <summary>
        /// Timeout in seconds (used for send and recv)
        /// </summary>
        public int TimeoutInSeconds { get; protected set; } = 5;

        private int TimeoutInMilliseconds => 1000 * TimeoutInSeconds;

        /// <summary>
        /// MiraConnection class constructor.
        /// </summary>
        /// <param name="p_Address">IP address of the PS4.</param>
        /// <param name="p_Port">Port that Mira is running on on the PS4. Defaults to 9999.</param>
        public MiraConnection(string p_Address, ushort p_Port = c_DefaultPort)
        {
            ConnectionAddress = p_Address;
            ConnectionPort = p_Port;
        }

        /// <summary>
        /// public method <c>Connect</c> attempts to connect to the PS4 Mira server with the credentials given by the class constructor.
        /// </summary>
        /// <returns>True if a connection was established, false otherwise.</returns>
        public bool Connect()
        {
            try
            {
                // Create a TCP pipe with a 5 second timeout and 64MiB buffer
                m_Client = new TcpClient(AddressFamily.InterNetwork)
                {
                    ReceiveTimeout = 1000 * TimeoutInSeconds,
                    SendTimeout = 1000 * TimeoutInSeconds,
                    ReceiveBufferSize = MaxBufferSize,
                    SendBufferSize = MaxBufferSize
                };

                m_Client.ConnectAsync(ConnectionAddress, ConnectionPort).Wait(TimeoutInMilliseconds);
            }
            catch (Exception p_Exception)
            {
#if DEBUG
                Debug.WriteLine($"could not connect: {p_Exception}");
#endif
                m_Client = null;
                return false;
            }

            return IsConnected;
        }

        /// <summary>
        /// public method <c>Disconnect</c> disposes of the TCP socket and nullifies it.
        /// </summary>
        public void Disconnect()
        {
            m_Client?.Dispose();
            m_Client = null;
        }

        /// <summary>
        /// public method <c>SendMessage(category, type, error, data)</c> takes the given information and constructs an RpcTransport capsule and sends it to the PS4.
        /// </summary>
        /// <param name="p_Category">Category to send the message to.</param>
        /// <param name="p_Type">Type of message for that category.</param>
        /// <param name="p_Error">Error code.</param>
        /// <param name="p_Data">Endpoint specific data.</param>
        /// <returns>True if the message was sent, false otherwise.</returns>
        public bool SendMessage(RpcCategory p_Category, uint p_Type, long p_Error, byte[] p_Data)
        {
            // Create a capsule for the entire message
            var s_Transport = new RpcTransport
            {
                // Create the request header
                Header = new RpcHeader
                {
                    Category = p_Category,
                    Type = p_Type,
                    Error = p_Error,
                    IsRequest = true,
                    Magic = c_HeaderMagic
                },
                Data = ByteString.CopyFrom(p_Data)
            };

            // Send it off
            return SendMessage(s_Transport);
        }

        /// <summary>
        /// public method <c>SendMessage(message)</c> sends the given message/capsule to the PS4.
        /// </summary>
        /// <param name="p_OutgoingMessage">Message to send.</param>
        /// <returns>True if the message was sent, false otherwise.</returns>
        public bool SendMessage(RpcTransport p_OutgoingMessage)
        {
            // Validate that we are connected
            if (!IsConnected)
                return false;

            var s_MessageData = p_OutgoingMessage.ToByteArray();
            var s_Buffer = new byte[Marshal.SizeOf<ulong>() + s_MessageData.Length];

            Buffer.BlockCopy(BitConverter.GetBytes((ulong)s_MessageData.Length), 0, s_Buffer, 0, 8);
            Buffer.BlockCopy(s_MessageData, 0, s_Buffer, 8, s_MessageData.Length);

            // Write this, should call serialize which will have header + payload data
            using (var s_Writer = new BinaryWriter(m_Client.GetStream(), Encoding.ASCII, true))
                s_Writer.Write(s_Buffer);

            return true;
        }

        /// <summary>
        /// public method <c>SendMessageWithResponse</c> sends the given message/capsule to the PS4 and waits for a response, then returns it.
        /// </summary>
        /// <param name="p_Message">Message to send.</param>
        /// <returns>RpcTransport response message, or null if the response was invalid.</returns>
        public RpcTransport SendMessageWithResponse(RpcTransport p_Message)
        {
            if (!SendMessage(p_Message))
                return null;

            return RecvMessage();
        }

        /// <summary>
        /// public method <c>RecvMessage</c> waits for the next message sent by the server and returns it.
        /// </summary>
        /// <returns>RpcTransport Message, or null if the message was invalid.</returns>
        public RpcTransport RecvMessage()
        {
            byte[] s_Data = null;

            // Read the message size from the client stream
            using (var s_Reader = new BinaryReader(m_Client.GetStream(), Encoding.ASCII, true))
            {
                // Parse the message size
                var s_MessageSize = s_Reader.ReadUInt64();

                // Reject messages that would exceed the size of the buffer
                if (s_MessageSize > (ulong)MaxBufferSize)
                    return null;

                // Read the actual message
                s_Data = s_Reader.ReadBytes((int)s_MessageSize);
            }

            if (s_Data == null)
                return null;

            // Create a capsule via the RpcTransport parser
            return RpcTransport.Parser.ParseFrom(s_Data);
        }
    }
}
