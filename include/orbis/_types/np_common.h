#pragma once

#include <stdint.h>

#define ORBIS_NP_TITLE_ID_LEN (12)
#define ORBIS_NP_TITLE_SECRET_SIZE (128)
#define ORBIS_NP_CLIENT_SECRET_MAX_LEN (256)
#define ORBIS_NP_DEFAULT_SERVICE_LABEL (0x00000000)
#define ORBIS_NP_INVALID_SERVICE_LABEL (0xFFFFFFFF)
#define ORBIS_NP_CLIENT_ID_MAX_LEN (128)
#define ORBIS_NP_AUTHORIZATION_CODE_MAX_LEN (128)
#define ORBIS_NP_ID_TOKEN_MAX_LEN (4096)
#define ORBIS_NP_INVALID_ACCOUNT_ID (0)
#define ORBIS_NP_UNIFIED_ENTITLEMENT_LABEL_SIZE (17)
#define ORBIS_NP_LANGUAGE_CODE_MAX_LEN (5)
#define Orbis_NP_PLUS_FEATURE_REALTIME_MULTIPLAY (0x1)
#define ORBIS_NP_PLUS_EVENT_RECHECK_NEEDED (0x1)

#define ORBIS_NP_COMMUNICATION_PASSPHRASE_SIZE (128)

#define ORBIS_NP_PLATFORM_TYPE_NONE (0)
#define ORBIS_NP_PLATFORM_TYPE_PS3 (1)
#define ORBIS_NP_PLATFORM_TYPE_VITA (2)
#define ORBIS_NP_PLATFORM_TYPE_PS4 (3)
#define ORBIS_NP_PLATFORM_TYPE_ORBIS (3) /* for compatibility */

#define ORBIS_NP_PORT (3658)

#define ORBIS_NP_MAX_REQUEST_NUM (32)
#define ORBIS_NP_TIMEOUT_NO_EFFECT (0)

#define ORBIS_NP_POLL_ASYNC_RET_FINISHED (0)
#define ORBIS_NP_POLL_ASYNC_RET_RUNNING (1)
#define ORBIS_NP_SESSION_ID_MAX_SIZE (45)    /* session id */
#define ORBIS_NP_INVITATION_ID_MAX_SIZE (60) /* invitation id */

#define ORBIS_NP_ONLINEID_MIN_LENGTH 3
#define ORBIS_NP_ONLINEID_MAX_LENGTH 16

#define ORBIS_NP_SESSION_INVITATION_EVENT_FLAG_INVITATION (0x01)

#define Orbis_NP_NO_AGE_RESTRICTION (0)
#define ORBIS_NP_COUNTRY_CODE_LENGTH (2)

typedef int32_t OrbisNpPlatformType;

typedef struct OrbisNpTitleId
{
    char id[ORBIS_NP_TITLE_ID_LEN + 1];
    uint8_t padding[3];
} OrbisNpTitleId;

typedef struct OrbisNpTitleSecret
{
    uint8_t data[ORBIS_NP_TITLE_SECRET_SIZE];
} OrbisNpTitleSecret;

typedef struct OrbisNpClientId
{
    char id[ORBIS_NP_CLIENT_ID_MAX_LEN + 1];
    uint8_t padding[7];
} OrbisNpClientId;

typedef struct OrbisNpClientSecret
{
    char secret[ORBIS_NP_CLIENT_SECRET_MAX_LEN + 1];
    uint8_t padding[7];
} OrbisNpClientSecret;

typedef uint32_t OrbisNpServiceLabel;

typedef struct OrbisNpAuthorizationCode
{
    char code[ORBIS_NP_AUTHORIZATION_CODE_MAX_LEN + 1];
    uint8_t padding[7];
} OrbisNpAuthorizationCode;

typedef struct OrbisNpIdToken
{
    char token[ORBIS_NP_ID_TOKEN_MAX_LEN + 1];
    uint8_t padding[7];
} OrbisNpIdToken;

typedef struct OrbisNpCommunicationId
{
    char data[9];
    char term;
    uint8_t num;
    char dummy;
} OrbisNpCommunicationId;

typedef struct OrbisNpCommunicationPassphrase
{
    uint8_t data[ORBIS_NP_COMMUNICATION_PASSPHRASE_SIZE];
} OrbisNpCommunicationPassphrase;

typedef enum OrbisNpState
{
    Orbis_NP_STATE_UNKNOWN = 0,
    Orbis_NP_STATE_SIGNED_OUT,
    Orbis_NP_STATE_SIGNED_IN
} OrbisNpState;

typedef enum OrbisNpGamePresenceStatus
{
    Orbis_NP_GAME_PRESENCE_STATUS_OFFLINE,
    Orbis_NP_GAME_PRESENCE_STATUS_ONLINE
} OrbisNpGamePresenceStatus;

typedef struct OrbisNpUnifiedEntitlementLabel
{
    char data[ORBIS_NP_UNIFIED_ENTITLEMENT_LABEL_SIZE];
    char padding[3];
} OrbisNpUnifiedEntitlementLabel;

typedef uint64_t OrbisNpAccountId;

typedef struct OrbisNpPeerAddressA
{
    OrbisNpAccountId accountId;
    OrbisNpPlatformType platform;
    char padding[4];
} OrbisNpPeerAddressA;

typedef struct OrbisNpLanguageCode
{
    char code[ORBIS_NP_LANGUAGE_CODE_MAX_LEN + 1];
    char padding[10];
} OrbisNpLanguageCode;

typedef struct OrbisNpCountryCode
{
    char data[ORBIS_NP_COUNTRY_CODE_LENGTH];
    char term;
    char padding[1];
} OrbisNpCountryCode;

typedef struct OrbisNpDate
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} OrbisNpDate;

typedef struct OrbisNpAgeRestriction
{
    OrbisNpCountryCode countryCode;
    int8_t age;
    uint8_t padding[3];
} OrbisNpAgeRestriction;

typedef struct OrbisNpContentRestriction
{
    size_t size;
    int8_t defaultAgeRestriction;

    char padding[3];
    int32_t ageRestrictionCount;

    const OrbisNpAgeRestriction *ageRestriction;

} OrbisNpContentRestriction;

typedef struct OrbisNpParentalControlInfo
{
    bool contentRestriction;
    bool chatRestriction;
    bool ugcRestriction;
} OrbisNpParentalControlInfo;

typedef enum OrbisNpReachabilityState
{
    Orbis_NP_REACHABILITY_STATE_UNAVAILABLE = 0,
    Orbis_NP_REACHABILITY_STATE_AVAILABLE,
    Orbis_NP_REACHABILITY_STATE_REACHABLE
} OrbisNpReachabilityState;

typedef struct OrbisNpCheckPlusParameter
{
    size_t size;
    int userId;
    char padding[4];
    uint64_t features;
    uint8_t reserved[32];
} OrbisNpCheckPlusParameter;

typedef struct OrbisNpCheckPlusResult
{
    bool authorized;
    uint8_t reserved[32];
} OrbisNpCheckPlusResult;

typedef int32_t OrbisNpPlusEventType;

typedef struct OrbisNpNotifyPlusFeatureParameter
{
    size_t size;
    int userId;
    char padding[4];
    uint64_t features;
    uint8_t reserved[32];
} OrbisNpNotifyPlusFeatureParameter;

typedef struct OrbisNpCreateAsyncRequestParameter
{
    size_t size;
    int cpuAffinityMask;
    int threadPriority;

    uint8_t padding[4];
} OrbisNpCreateAsyncRequestParameter;

typedef struct OrbisNpSessionId
{
    char data[ORBIS_NP_SESSION_ID_MAX_SIZE];
    char term;
    char padding[2];
} OrbisNpSessionId;

typedef struct OrbisNpInvitationId
{
    char data[ORBIS_NP_INVITATION_ID_MAX_SIZE];
    char term;
    char padding[3];
} OrbisNpInvitationId;

typedef int32_t OrbisNpSessionInvitationEventFlag;

typedef struct OrbisNpSessionInvitationEventParam
{
    OrbisNpSessionId sessionId;
    OrbisNpInvitationId invitationId;
    OrbisNpSessionInvitationEventFlag flag;
    char padding[4];
    int onlineId;
    int userId;
    int referralOnlineId;
    OrbisNpAccountId referralAccountId;
} OrbisNpSessionInvitationEventParam;

typedef uint64_t OrbisNpGameCustomDataId;

typedef struct OrbisNpGameCustomDataEventParam
{
    OrbisNpGameCustomDataId itemId;
    int onlineId;
    int userId;
} OrbisNpGameCustomDataEventParam;

typedef struct OrbisNpOnlineId
{
    char data[ORBIS_NP_ONLINEID_MAX_LENGTH];
    char term;
    char dummy[3];
} OrbisNpOnlineId;

typedef struct OrbisNpId
{
    OrbisNpOnlineId handle;
    uint8_t opt[8];
    uint8_t reserved[8];
} OrbisNpId;