
#include <sys/types.h>



#ifndef MIRA_H
#define MIRA_H

typedef enum SceAuthenticationId_t : uint64_t
{
    sceSblACMgrIsAllowedToUsePupUpdate0 = 0x3800100000000001ULL,
    SceVdecProxy = 0x3800000000000003ULL, //same as SceSpkService 
    SceVencProxy = 0x3800000000000004ULL,
    Orbis_audiod = 0x3800000000000005ULL,
    Coredump = 0x3800000000000006ULL,// same as orbis-jsc-compiler.self
    SceSysCore = 0x3800000000000007ULL,
    Orbis_setip = 0x3800000000000008ULL,
    GnmCompositor = 0x3800000000000009ULL,
    SceShellUI = 0x380000000000000fULL, // NPXS20001
    SceShellCore = 0x3800000000000010ULL,
    NPXS20103 = 0x3800000000000011ULL,
    SceGameLiveStreaming = 0x3800000000000012ULL, //NPXS21000 samething and SceNKNetworkProcess 
    SCE_SYS_SERVICES = 0x3800000000010003ULL,
    ScePartyDaemon = 0x3800000000000014ULL,
    MaxAccess = 0x3801000000000013ULL,
    SceAvCapture = 0x3800000000000015ULL,
    SceVideoCoreServer = 0x3800000000000016ULL,
    SceRemotePlay = 0x3800000000000019ULL,
    mini_syscore = 0x3800000000000022ULL,
    UNK_ICC = 0x3800800000000024ULL,
    SceCloudClientDaemon = 0x3800000000000028ULL,
    fs_cleaner = 0x380000000000001dULL,
    SceNKWebProcess = 0x3800000000010003ULL,
    SecureWebProcess = 0x3800000010000003ULL,
    SecureUIProcess = 0x3800000000000033ULL,
    SceSysAvControl = 0x380000000000001fULL,
    SceSocialScreenMgr = 0x3800000000000037ULL,
    SceSpZeroConf = 0x380000001000000EULL,
    SceMusicCoreServer = 0x380000000000001aULL,
    SceNKUIProcess = 0x380000000000003cULL,
    sceSblACMgrHasUseHp3dPipeCapability = 0x3800000010000009ULL,
    UNK_PFS = 0x380100000000000AULL,
    sceSblACMgrHasUseHp3dPipeCapability2 = 0x380100000000002CULL,
    OS_UPDATE = 0x3801000000000024ULL,
    VTRM_ADMIN = 0x3800800000000002ULL,
    Decid = 0x3800000000010003,
} SceAuthenticationId;

typedef enum SceCapabilities_t : uint64_t
{
    Max = 0xFFFFFFFFFFFFFFFFULL,
} SceCapabilites;

typedef enum class _MiraThreadCredentialsPrison : uint32_t
{
    // Non-root prison
    Default,

    // Switch prison to root vnode
    Root,

    // Total options count
    COUNT
} MiraThreadCredentialsPrison;

typedef enum class _State : uint32_t
{
    Get,
    Set,
    COUNT
} GSState;

typedef struct _MiraThreadCredentials {


    // Is this a get or set operation
    GSState State;

    // Process ID to modify
    int32_t ProcessId;

    // Threaad ID to modify, or -1 for (all threads in process, USE WITH CAUTION)
    int32_t ThreadId;

    // Everything below is Get/Set
    int32_t EffectiveUserId;
    int32_t RealUserId;
    int32_t SavedUserId;
    int32_t NumGroups;
    int32_t RealGroupId;
    int32_t SavedGroupId;
    MiraThreadCredentialsPrison Prison;
    SceAuthenticationId SceAuthId;
    SceCapabilites Capabilities[4];
    uint64_t Attributes[4];
} MiraThreadCredentials;


#endif