using System;
using System.Linq;

/// <summary>
/// Namespace <c>MiraLib</c> contains all the necessary classes and functions for managing consoles on the PC side for applications to use.
/// </summary>
namespace MiraLib
{
    /// <summary>
    /// Class <c>Console</c> contains variables and functions for setting and getting basic information about a console for connections. This includes
    /// the name and IP. It also contains wrapper methods for sending and receiving messages to the PS4.
    /// </summary>
    public class Console
    {
        public MiraConnection Mira;

        private string Name = string.Empty;
        private string IP = string.Empty;

        /// <summary>
        /// public method <c>SetName</c> sets the name to the given <c>newName</c>.
        /// </summary>
        /// <param name="newName">New name to set.</param>
        /// <returns>void.</returns>
        public void SetName(string newName)
        {
            Name = newName;
        }

        /// <summary>
        /// public method <c>SetIPAddress</c> sets the IP address to the given <c>ipString</c>.
        /// </summary>
        /// <param name="ipString">New IP to set.</param>
        /// <returns>void.</returns>
        public bool SetIPAddress(string ipString)
        {
            bool ipValid = validateIPAddress(ipString);

            if (ipValid)
            {
                IP = ipString;
            }

            return ipValid;
        }

        /// <summary>
        /// public method <c>GetName</c> returns the name of this console.
        /// </summary>
        /// <returns>Name of the console as a string.</returns>
        public string GetName()
        {
            return Name;
        }

        /// <summary>
        /// public method <c>GetIPAddress</c> returns the IP address of this console.
        /// </summary>
        /// <returns>IP address of the console as a string.</returns>
        public string GetIPAddress()
        {
            return IP;
        }

        /// <summary>
        /// public method <c>Connect</c> attempts to connect a new MiraConnection instance attached to the console to the PS4.
        /// </summary>
        /// <returns>True if the connection was established, false otherwise.</returns>
        public bool Connect()
        {
            Mira = new MiraConnection(IP);
            return Mira.Connect();
        }

        /// <summary>
        /// public method <c>Disconnect</c> attempts to disconnect the established MiraConnection instance and nullifies it.
        /// </summary>
        /// <returns>void.</returns>
        public void Disconnect()
        {
            if (Mira != null)
            {
                Mira.Disconnect();
                Mira = null;
            }
        }

        /// <summary>
        /// public method <c>SendMessage</c> attempts to send an <c>RpcTransport</c> message/capsule to the PS4 through the established MiraConnection instance.
        /// </summary>
        /// <param name="p_OutgoingMessage">Message to send.</param>
        /// <returns>True if the message was sent, false otherwise.</returns>
        public bool SendMessage(RpcTransport p_OutgoingMessage)
        {
            if (Mira == null)
                return false;

            return Mira.SendMessage(p_OutgoingMessage);
        }

        /// <summary>
        /// public method <c>SendMessage</c> attempts to construct and send a message to the PS4 through the established MiraConnection instance.
        /// </summary>
        /// <param name="p_Category">Category for the message.</param>
        /// <param name="p_Type">Type for the message.</param>
        /// <param name="p_Error">Error code.</param>
        /// <param name="p_Data">Endpoint specific data.</param>
        /// <returns>True if the message was sent, false otherwise.</returns>
        public bool SendMessage(RpcCategory p_Category, uint p_Type, long p_Error, byte[] p_Data)
        {
            if (Mira == null)
                return false;

            return Mira.SendMessage(p_Category, p_Type, p_Error, p_Data);
        }

        /// <summary>
        /// public method <c>SendMessageWithResponse</c> attempts to send a message to the PS4 and receive a response from the established MiraConnection instance.
        /// </summary>
        /// <param name="p_Message">Message to send.</param>
        /// <returns>Response message. If there is no response message or no connection is established, null is returned.</returns>
        public RpcTransport SendMessageWithResponse(RpcTransport p_Message)
        {
            if (Mira == null)
                return null;

            return Mira.SendMessageWithResponse(p_Message);
        }

        /// <summary>
        /// public method <c>RecvMessage</c> attempts to receive a message from the PS4 through the established MiraConnection instance.
        /// </summary>
        /// <returns>Message. If there is no message or no connection is established, null is returned.</returns>
        public RpcTransport RecvMessage()
        {
            if (Mira == null)
                return null;

            return Mira.RecvMessage();
        }

        /// <summary>
        /// private method <c>validateIPAddress</c> returns whether or not a given <c>ip</c> is valid.
        /// </summary>
        /// <param name="ip">IP address to check.</param>
        /// <returns>True if the IP is valid, false otherwise.</returns>
        private bool validateIPAddress(string ip)
        {
            // Disallow blank IP's
            if (String.IsNullOrWhiteSpace(ip))
                return false;

            // IPv4 addresses should always have 4 sections
            string[] ipSections = ip.Split('.');

            if (ipSections.Length != 4)
                return false;

            // Ensure each section is non-empty / valid
            byte validSectionTest;

            if (!ipSections.All(r => byte.TryParse(r, out validSectionTest)))
                return false;

            // All checks pass
            return true;
        }
    }
}
