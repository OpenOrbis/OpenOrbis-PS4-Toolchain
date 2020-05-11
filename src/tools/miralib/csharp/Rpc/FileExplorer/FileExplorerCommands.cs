namespace MiraConnection.Rpc.FileExplorer
{
    public enum FileExplorerCommands : uint
    {
        FileExplorer_Open = 0x58AFA0D4,
        FileExplorer_Close = 0x43F82FDB,
        FileExplorer_Read = 0x64886217,
        FileExplorer_Write = 0x2D92D440,
        FileExplorer_GetDents = 0x7433E67A,
        FileExplorer_Stat = 0xDC67DC51,
        FileExplorer_MkDir = 0x66F97F1E,
        FileExplorer_RmDir = 0xA1222091,
        FileExplorer_Unlink = 0x569F464B,
        FileExplorer_Echo = 0xEBDB1342,
        FileExplorer_DecryptSelf = 0xEA9BF6A9,
    };
}
