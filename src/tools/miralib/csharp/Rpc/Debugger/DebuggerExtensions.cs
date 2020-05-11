using Google.Protobuf;
using System.Collections.Generic;
using System.Linq;

namespace MiraConnection.Rpc.Debugger
{
    public static class DebuggerExtensions
    {
        public enum Signals : int
        {
            SIGHUP = 1,
            SIGINT = 2,
            SIGQUIT = 3,
            SIGILL = 4,
            SIGTRAP = 5,
            SIGABRT = 6,
            SIGIOT = SIGABRT,
            SIGEMT = 7,
            SIGFPE = 8,
            SIGKILL = 9,
            SIGBUS = 10,
            SIGSEGV = 11,
            SIGSYS = 12,
            SIGPIPE = 13,
            SIGALRM = 14,
            SIGTERM = 15,
            SIGURG = 16,
            SIGSTOP = 17,
            SIGSTP = 18,
            SIGCONT = 19,
            SIGCHLD = 20,
            SIGTTIN = 21,
            SIGTTOU = 22,
            SIGIO = 23,
        }

        public enum Protections : int
        {
            PROT_READ = 0x01,
            PROT_WRITE = 0x02,
            PROT_EXEC = 0x04
        }

        public static byte[] ReadMemory(this MiraLib.MiraConnection p_Connection, ulong p_Address, uint p_Size)
        {
            if (p_Connection == null)
                return null;

            if (p_Address == 0 || p_Size == 0)
                return null;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_ReadMem
                },
                Data = ByteString.CopyFrom
                (
                    new DbgReadProcessMemoryRequest
                    {
                        Address = p_Address,
                        Size = p_Size
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return null;

            if (s_ResponseTransport.Header.Error < 0)
                return null;

            var s_Response = DbgReadProcessMemoryResponse.Parser.ParseFrom(s_ResponseTransport.Data.ToByteArray());

            return s_Response?.Data.ToByteArray();
        }

        public static bool WriteMemory(this MiraLib.MiraConnection p_Connection, ulong p_Address, byte[] p_Data)
        {
            if (p_Connection == null)
                return false;

            if (p_Address == 0 || p_Data == null || p_Data?.Length == 0)
                return false;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_WriteMem
                },
                Data = ByteString.CopyFrom
                (
                    new DbgWriteProcessMemoryRequest
                    {
                        Address = p_Address,
                        Data = ByteString.CopyFrom(p_Data)
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return false;

            return s_ResponseTransport.Header.Error >= 0;
        }

        public static bool Protect(this MiraLib.MiraConnection p_Connection, ulong p_Address, uint p_Size, int p_Protection)
        {
            if (p_Connection == null)
                return false;

            if (p_Address == 0 || p_Size == 0)
                return false;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_ProtectMem
                },
                Data = ByteString.CopyFrom
                (
                    new DbgProtectProcessMemoryRequest
                    {
                        Address = p_Address,
                        Length = p_Size,
                        Protection = p_Protection
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return false;

            return s_ResponseTransport.Header.Error >= 0;
        }

        public static DbgProcessFull GetProcessInfo(this MiraLib.MiraConnection p_Connection, int p_ProcessId)
        {
            if (p_Connection == null)
                return null;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_GetProcInfo
                },
                Data = ByteString.CopyFrom
                (
                    new DbgGetProcessInfoRequest
                    {
                        ProcessId = p_ProcessId
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return null;

            if (s_ResponseTransport.Header.Error < 0)
                return null;

            return DbgProcessFull.Parser.ParseFrom(s_ResponseTransport.Data.ToByteArray());
        }

        public static DbgGetRegistersResponse GetThreadRegisters(this MiraLib.MiraConnection p_Connection, int p_ThreadId)
        {
            if (p_Connection == null)
                return null;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_GetRegs
                },
                Data = ByteString.CopyFrom
                (
                    new DbgGetRegistersRequest
                    {
                        ThreadId = p_ThreadId
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return null;

            if (s_ResponseTransport.Header.Error < 0)
                return null;

            return DbgGetRegistersResponse.Parser.ParseFrom(s_ResponseTransport.Data.ToByteArray());
        }

        public static DbgThreadFull GetThreadInfo(this MiraLib.MiraConnection p_Connection, int p_ThreadId)
        {
            if (p_Connection == null)
                return null;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_GetThreadInfo
                },
                Data = ByteString.CopyFrom
                (
                    new DbgGetThreadInfoRequest
                    {
                        ThreadId = p_ThreadId
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return null;

            if (s_ResponseTransport.Header.Error < 0)
                return null;

            return DbgThreadFull.Parser.ParseFrom(s_ResponseTransport.Data.ToByteArray());
        }

        public static DbgGetProcessThreadsResponse GetProcessThreads(this MiraLib.MiraConnection p_Connection, int p_ProcessId)
        {
            if (p_Connection == null)
                return null;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_GetProcThreads
                },
                Data = ByteString.CopyFrom
                (
                    new DbgGetProcessInfoRequest
                    {
                        ProcessId = p_ProcessId
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return null;

            if (s_ResponseTransport.Header.Error < 0)
                return null;

            return DbgGetProcessThreadsResponse.Parser.ParseFrom(s_ResponseTransport.Data.ToByteArray());
        }

        public static ulong Allocate(this MiraLib.MiraConnection p_Connection, uint p_Size)
        {
            if (p_Size == 0)
                return 0;

            if (p_Connection == null)
                return 0;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_AllocateProcMem
                },
                Data = ByteString.CopyFrom
                (
                    new DbgAllocateProcessMemoryRequest
                    {
                        Size = p_Size
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return 0;

            if (s_ResponseTransport.Header.Error < 0)
                return 0;

            var s_Response = DbgAllocateProcessMemoryResponse.Parser.ParseFrom(s_ResponseTransport.Data.ToByteArray());
            if (s_Response == null)
                return 0;

            return s_Response.Address;
        }

        public static bool Free(this MiraLib.MiraConnection p_Connection, ulong p_Address, uint p_Size = 0)
        {
            if (p_Connection == null)
                return false;

            if (p_Address == 0)
                return false;

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_FreeProcMem
                },
                Data = ByteString.CopyFrom
                (
                    new DbgFreeProcessMemoryRequest
                    {
                        Address = p_Address,
                        Size = p_Size
                    }.ToByteArray()
                )
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return false;

            return s_ResponseTransport.Header.Error >= 0;
        }

        public static bool Attach(this MiraLib.MiraConnection p_Connection, int p_ProcessId)
        {
            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_Attach
                },
                Data = ByteString.CopyFrom
                (
                    new DbgAttachRequest
                    {
                        ProcessId = p_ProcessId
                    }.ToByteArray()
                )
            };

            var s_TransportResponse = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_TransportResponse == null)
                return false;

            return s_TransportResponse.Header.Error >= 0;
        }

        public static bool Detach(this MiraLib.MiraConnection p_Connection, bool p_Force = false)
        {
            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_Detach
                },
                Data = ByteString.CopyFrom
                (
                    new DbgDetachRequest
                    {
                        Force = true
                    }.ToByteArray()
                )
            };

            var s_TransportResponse = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_TransportResponse == null)
                return false;

            return s_TransportResponse.Header.Error == 0;
        }

        public static bool SignalProcess(this MiraLib.MiraConnection p_Connection, int p_Signal)
        {
            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_SignalProc
                },
                Data = ByteString.CopyFrom
                (
                    new DbgSignalProcessRequest
                    {
                        Signal = p_Signal
                    }.ToByteArray()
                )
            };

            var s_TransportResponse = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_TransportResponse == null)
                return false;

            return s_TransportResponse.Header.Error == 0;
        }

        public static List<DbgProcessLimited> GetProcList(this MiraLib.MiraConnection p_Connection)
        {
            var s_ProcessList = new List<DbgProcessLimited>();

            if (p_Connection == null)
                return new List<DbgProcessLimited>();

            var s_Transport = new RpcTransport
            {
                Header = new RpcHeader
                {
                    Category = RpcCategory.Debug,
                    Error = 0,
                    IsRequest = true,
                    Magic = MiraLib.MiraConnection.c_HeaderMagic,
                    Type = (uint)DebuggerCommands.DbgCmd_GetProcList
                },
                Data = ByteString.Empty
            };

            var s_ResponseTransport = p_Connection.SendMessageWithResponse(s_Transport);
            if (s_ResponseTransport == null)
                return new List<DbgProcessLimited>();

            if (s_ResponseTransport.Header.Error < 0)
                return new List<DbgProcessLimited>();

            var s_Response = DbgGetProcessListResponse.Parser.ParseFrom(s_ResponseTransport.Data);

            return s_Response.Processes.ToList();
        }
    }
}
