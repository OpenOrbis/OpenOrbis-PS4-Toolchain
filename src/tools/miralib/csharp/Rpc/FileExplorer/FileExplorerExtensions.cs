using Google.Protobuf;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace MiraConnection.Rpc.FileExplorer
{
    public static class FileExplorerExtensions
    {
        public enum OpenOnlyFlags : int
        {
            O_RDONLY = 0x0000,
            O_WRONLY = 0x0001,
            O_RDWR = 0x0002,
            O_ACCMODE = 0x0003,
            O_NONBLOCK = 0x0004,
            O_APPEND = 0x0008,
            O_SHLOCK = 0x0010,
            O_EXLOCK = 0x0020,
            O_ASYNC = 0x0040,
            O_FSYNC = 0x0080,
            O_SYNC = 0x0080,
            O_NOFOLLOW = 0x0100,
            O_CREAT = 0x0200,
            O_TRUNC = 0x0400,
            O_EXCL = 0x0800,
            O_NOCTTY = 0x8000,
            O_DIRECT = 0x00010000,
            O_DIRECTORY = 0x00020000,
            O_EXEC = 0x00040000
        }

        public enum FileTypes : byte
        {
            DT_UNKNOWN = 0,
            DT_FIFO = 1,
            DT_CHR = 2,
            DT_DIR = 4,
            DT_BLK = 6,
            DT_REG = 8,
            DT_LNK = 10,
            DT_SOCK = 12,
            DT_WHT = 14
        }

        public const int c_MaxBufferLength = 0x1000;
        public const int c_MaxPathLength = 0x400;
        public const int c_MaxNameLength = 255;

        public static int Open(this MiraLib.MiraConnection p_Connection, string p_Path, int p_Flags, int p_Mode)
        {
            if (p_Connection == null)
                return -1;

            if (string.IsNullOrWhiteSpace(p_Path))
                return -1;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader()
                {
                    Category = RpcCategory.File,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)FileExplorerCommands.FileExplorer_Open
                },
                Data = ByteString.CopyFrom
                (
                    new FmOpenRequest
                    {
                        Path = p_Path,
                        Flags = p_Flags,
                        Mode = p_Mode
                    }.ToByteArray()
                )
            };

            var s_Response = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_Response == null)
                return -1;

            return (int)s_Response.Header.Error;
        }

        public static void Close(this MiraLib.MiraConnection p_Connection, int p_Handle)
        {
            if (p_Connection == null)
                return;

            if (p_Handle < 0)
                return;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader()
                {
                    Category = RpcCategory.File,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)FileExplorerCommands.FileExplorer_Close
                },
                Data = ByteString.CopyFrom
                (
                    new FmCloseRequest
                    {
                        Handle = p_Handle
                    }.ToByteArray()
                )
            };

            // We don't care about the response
            p_Connection.SendMessageWithResponse(s_Transport);
        }

        public static byte[] Read(this MiraLib.MiraConnection p_Connection, int p_Handle, ulong p_Offset, int p_Count)
        {
            if (p_Connection == null)
                return null;

            if (p_Handle < 0)
                return null;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader()
                {
                    Category = RpcCategory.File,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)FileExplorerCommands.FileExplorer_Read
                },
                Data = ByteString.CopyFrom
                (
                    // TODO: Add offset
                    new FmReadRequest
                    {
                        Handle = p_Handle,
                        Size = (uint)p_Count
                    }.ToByteArray()
                )
            };

            var s_ResponseData = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseData == null)
                return null;

            var s_Response = FmReadResponse.Parser.ParseFrom(s_ResponseData.Data);
            if (s_Response == null)
                return null;

            return s_Response.Data.ToArray();
        }

        public static bool Write(this MiraLib.MiraConnection p_Connection, int p_Handle, byte[] p_Data)
        {
            if (p_Connection == null)
                return false;

            if (p_Handle < 0)
                return false;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader()
                {
                    Category = RpcCategory.File,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)FileExplorerCommands.FileExplorer_Write
                },
                Data = ByteString.CopyFrom
                (
                    // TODO: Add offset
                    new FmWriteRequest
                    {
                        Handle = p_Handle,
                        Data = ByteString.CopyFrom(p_Data)
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return false;

            return s_ResponseTransport.Header.Error >= 0;
        }

        public static List<FmDent> GetDents(this MiraLib.MiraConnection p_Connection, string p_Path)
        {
            if (p_Connection == null)
                return new List<FmDent>();

            if (string.IsNullOrWhiteSpace(p_Path))
                return new List<FmDent>();

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader()
                {
                    Category = RpcCategory.File,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)FileExplorerCommands.FileExplorer_GetDents
                },
                Data = ByteString.CopyFrom
                (
                    new FmGetDentsRequest
                    {
                        Path = p_Path
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return new List<FmDent>();

            var s_Response = FmGetDentsResponse.Parser.ParseFrom(s_ResponseTransport.Data);
            if (s_Response == null)
                return new List<FmDent>();

            return s_Response.Dents.ToList();
        }

        public static FmStatResponse Stat(this MiraLib.MiraConnection p_Connection, string p_Path)
        {
            if (p_Connection == null)
                return null;

            if (string.IsNullOrWhiteSpace(p_Path))
                return null;

            var s_Handle = p_Connection.Open(p_Path, (int)OpenOnlyFlags.O_RDONLY, 0777);
            if (s_Handle < 0)
                return null;

            var s_Stat = p_Connection.Stat(s_Handle);

            p_Connection.Close(s_Handle);

            return s_Stat;
        }

        public static FmStatResponse Stat(this MiraLib.MiraConnection p_Connection, int p_Handle)
        {
            if (p_Connection == null)
                return null;

            if (p_Handle < 0)
                return null;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader()
                {
                    Category = RpcCategory.File,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)FileExplorerCommands.FileExplorer_Stat
                },
                Data = ByteString.CopyFrom
                (
                    new FmStatRequest
                    {
                        Handle = p_Handle,
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return null;

            return FmStatResponse.Parser.ParseFrom(s_ResponseTransport.Data);
        }

        public static bool Echo(this MiraLib.MiraConnection p_Connection, string p_Message)
        {
            if (p_Connection == null)
                return false;

            if (string.IsNullOrWhiteSpace(p_Message))
                return false;

            if (p_Message.Length > ushort.MaxValue)
                return false;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader()
                {
                    Category = RpcCategory.File,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)FileExplorerCommands.FileExplorer_Echo
                },
                Data = ByteString.CopyFrom
                (
                    new FmEchoRequest
                    {
                        Message = p_Message
                    }.ToByteArray()
                )
            };

            return p_Connection.SendMessage(s_Transport);
        }

        public static FileStream DownloadFile(this MiraLib.MiraConnection p_Connection, string p_Path, string p_OutputPath, Action<int, bool> p_StatusCallback = null)
        {
            var s_Stream = File.OpenWrite(p_OutputPath);

            var s_FileHandle = Open(p_Connection, p_Path, (int)OpenOnlyFlags.O_RDONLY, 0);
            if (s_FileHandle < 0)
            {
                p_StatusCallback?.Invoke(0, true);
                return null;
            }

            var s_Stat = Stat(p_Connection, s_FileHandle);
            if (s_Stat == null)
            {
                p_StatusCallback?.Invoke(0, true);
                return null;
            }

            var s_ChunkSize = 0x4000;
            var s_Chunks = s_Stat.StSize / s_ChunkSize;
            var s_Leftover = (int)s_Stat.StSize % s_ChunkSize;

            ulong s_Offset = 0;

            using (var s_Writer = new BinaryWriter(s_Stream, Encoding.ASCII, true))
            {
                for (var i = 0; i < s_Chunks; ++i)
                {
                    var l_Data = Read(p_Connection, s_FileHandle, s_Offset, s_ChunkSize);
                    if (l_Data == null)
                    {
                        p_StatusCallback?.Invoke(0, true);
                        return null;
                    }

                    // Write a chunk
                    s_Writer.Write(l_Data);

                    // Increment our offset
                    s_Offset += (ulong)l_Data.LongCount();

                    // Calculate and update status
                    p_StatusCallback?.Invoke((int)(((float)s_Offset / (float)s_Stat.StSize) * 100), false);
                }

                // Write the leftover data
                var s_Data = Read(p_Connection, s_FileHandle, s_Offset, s_Leftover);
                if (s_Data == null)
                {
                    p_StatusCallback?.Invoke(0, true);
                    return null;
                }

                // Write the leftover
                s_Writer.Write(s_Data);

                // Increment our offset
                s_Offset += (ulong)s_Data.LongCount();

                // Calculate and update status
                p_StatusCallback?.Invoke((int)(((float)s_Offset / (float)s_Stat.StSize) * 100), false);
            }

            return s_Stream;
        }

        public static List<byte> DownloadFileToByteArray(this MiraLib.MiraConnection p_Connection, string p_Path)
        {
            List<byte> s_Bytes = new List<byte>();
            var s_FileHandle = Open(p_Connection, p_Path, (int)OpenOnlyFlags.O_RDONLY, 0);
            if (s_FileHandle < 0)
            {
                return null;
            }

            var s_Stat = Stat(p_Connection, s_FileHandle);
            if (s_Stat == null)
            {
                return null;
            }

            var s_ChunkSize = 0x4000;
            var s_Chunks = s_Stat.StSize / s_ChunkSize;
            var s_Leftover = (int)s_Stat.StSize % s_ChunkSize;

            ulong s_Offset = 0;
            for (var i = 0; i < s_Chunks; ++i)
            {
                var l_Data = Read(p_Connection, s_FileHandle, s_Offset, s_ChunkSize);
                if (l_Data == null)
                {
                    return null;
                }
                s_Bytes.AddRange(l_Data);
                // Increment our offset
                s_Offset += (ulong)l_Data.LongCount();
            }

            // Write the leftover data
            var s_Data = Read(p_Connection, s_FileHandle, s_Offset, s_Leftover);
            if (s_Data == null)
            {
                return null;
            }
            // Write the leftover
            s_Bytes.AddRange(s_Data);
            return s_Bytes;
        }

        public static byte[] DecryptSelf(this MiraLib.MiraConnection p_Connection, string p_Path)
        {
            if (p_Connection == null)
                return null;

            if (p_Path.Length > FileExplorerExtensions.c_MaxPathLength)
                return null;

            throw new NotImplementedException();
            //var s_Request = new Message(
            //    MessageCategory.File,
            //    (uint)FileExplorerCommands.FileExplorer_DecryptSelf,
            //    true,
            //    new FileExplorerDecryptSelfRequest(p_Path).Serialize());

            //p_Connection.SendMessage(s_Request);

            //var s_ResponseList = new List<FileExplorerDecryptSelfResponse>();
            //do
            //{
            //    var (s_Response, s_Payload) = p_Connection.RecvMessage<FileExplorerDecryptSelfResponse>(s_Request);
            //    if (s_Response == null || s_Response?.Error < 0 || s_Payload == null)
            //        return null;

            //    var s_ChunkIndex = s_Payload.Index;
            //    if (s_ChunkIndex == ulong.MaxValue)
            //        break;

            //    s_ResponseList.Add(s_Payload);
            //}
            //while (true);

            //using (var s_Writer = new BinaryWriter(new MemoryStream()))
            //{
            //    for (var i = 0; i < s_ResponseList.Count; ++i)
            //    {
            //        s_Writer.Seek((int)s_ResponseList[i].Offset, SeekOrigin.Begin);
            //        s_Writer.Write(s_ResponseList[i].Data);
            //    }

            //    return ((MemoryStream)s_Writer.BaseStream).ToArray();
            //}
        }

        public static byte[] DownloadFile(this MiraLib.MiraConnection p_Connection, string p_Path, Action<int, bool> p_StatusCallback = null)
        {
            var s_FileHandle = Open(p_Connection, p_Path, (int)OpenOnlyFlags.O_RDONLY, 0);
            if (s_FileHandle < 0)
            {
                p_StatusCallback?.Invoke(0, true);
                return null;
            }

            var s_Stat = Stat(p_Connection, s_FileHandle);
            if (s_Stat == null)
            {
                p_StatusCallback?.Invoke(0, true);
                return null;
            }

            var s_ChunkSize = 0x1000;
            var s_Chunks = s_Stat.StSize / s_ChunkSize;
            var s_Leftover = (int)s_Stat.StSize % s_ChunkSize;

            ulong s_Offset = 0;

            byte[] s_ReturnData = null;
            using (var s_Writer = new BinaryWriter(new MemoryStream()))
            {
                for (var i = 0; i < s_Chunks; ++i)
                {
                    var l_Data = Read(p_Connection, s_FileHandle, s_Offset, s_ChunkSize);
                    if (l_Data == null)
                    {
                        p_StatusCallback?.Invoke(0, true);
                        return null;
                    }

                    // Write a chunk
                    s_Writer.Write(l_Data);

                    // Increment our offset
                    s_Offset += (ulong)l_Data.LongCount();

                    // Calculate and update status
                    p_StatusCallback?.Invoke((int)(((float)s_Offset / (float)s_Stat.StSize) * 100), false);
                }

                // Write the leftover data
                var s_Data = Read(p_Connection, s_FileHandle, s_Offset, s_Leftover);
                if (s_Data == null)
                {
                    p_StatusCallback?.Invoke(0, true);
                    return null;
                }

                // Write the leftover
                s_Writer.Write(s_Data);

                // Increment our offset
                s_Offset += (ulong)s_Data.LongCount();

                // Calculate and update status
                p_StatusCallback?.Invoke((int)(((float)s_Offset / (float)s_Stat.StSize) * 100), false);

                s_ReturnData = ((MemoryStream)s_Writer.BaseStream).ToArray();
            }

            return s_ReturnData;
        }

        public static bool Unlink(this MiraLib.MiraConnection p_Connection, string p_Path)
        {
            if (p_Connection == null)
                return false;

            if (string.IsNullOrWhiteSpace(p_Path))
                return false;

            if (p_Path.Length > c_MaxPathLength)
                return false;

            throw new NotImplementedException();
            //var s_Message = new Message(
            //    MessageCategory.File,
            //    (uint)FileExplorerCommands.FileExplorer_Unlink,
            //    true,
            //    new FileExplorerUnlinkRequest(p_Path).Serialize());

            //return p_Connection.SendMessage(s_Message);
        }
    }
}
