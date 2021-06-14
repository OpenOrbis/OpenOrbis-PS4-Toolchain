#pragma once

#include <stdint.h>
#include <np_common.h>

#define ORBIS_NP_WEBAPI_CONTENT_TYPE_APPLICATION_JSON_UTF8 "application/json; charset=utf-8"
#define ORBIS_NP_WEBAPI_DEFAULT_CONNECTION_NUM 1
#define ORBIS_NP_WEBAPI_MAX_CONNECTION_NUM 16

#define ORBIS_NP_WEBAPI_PUSH_EVENT_DATA_TYPE_LEN_MAX 64
#define ORBIS_NP_WEBAPI_EXTD_PUSH_EVENT_EXTD_DATA_KEY_LEN_MAX 32
#define ORBIS_NP_WEBAPI_NP_SERVICE_NAME_NONE NULL

typedef enum OrbisNpWebApiHttpMethod
{
    ORBIS_NP_WEBAPI_HTTP_METHOD_GET,
    ORBIS_NP_WEBAPI_HTTP_METHOD_POST,
    ORBIS_NP_WEBAPI_HTTP_METHOD_PUT,
    ORBIS_NP_WEBAPI_HTTP_METHOD_DELETE
} OrbisNpWebApiHttpMethod;

typedef struct OrbisNpWebApiContentParameter
{
    size_t contentLength;
    const char *pContentType;
    uint8_t reserved[16];
} OrbisNpWebApiContentParameter;

typedef struct OrbisNpWebApiHttpHeader
{
    char *pName;
    char *pValue;
} OrbisNpWebApiHttpHeader;

typedef struct OrbisNpWebApiMultipartPartParameter
{
    OrbisNpWebApiHttpHeader *pHeaders;
    size_t headerNum;
    size_t contentLength;
} OrbisNpWebApiMultipartPartParameter;

typedef struct OrbisNpWebApiPushEventDataType
{
    char val[ORBIS_NP_WEBAPI_PUSH_EVENT_DATA_TYPE_LEN_MAX + 1];
} OrbisNpWebApiPushEventDataType;

typedef struct OrbisNpWebApiExtdPushEventExtdDataKey
{
    char val[ORBIS_NP_WEBAPI_EXTD_PUSH_EVENT_EXTD_DATA_KEY_LEN_MAX + 1];
} OrbisNpWebApiExtdPushEventExtdDataKey;

typedef struct OrbisNpWebApiExtdPushEventFilterParameter
{
    OrbisNpWebApiPushEventDataType dataType;
    OrbisNpWebApiExtdPushEventExtdDataKey *pExtdDataKey;
    size_t extdDataKeyNum;
} OrbisNpWebApiExtdPushEventFilterParameter;

typedef struct OrbisNpWebApiExtdPushEventExtdData
{
    OrbisNpWebApiExtdPushEventExtdDataKey extdDataKey;
    char *pData;
    size_t dataLen;
} OrbisNpWebApiExtdPushEventExtdData;

typedef struct OrbisNpWebApiMemoryPoolStats
{
    size_t poolSize;
    size_t maxInuseSize;
    size_t currentInuseSize;
    int32_t reserved;
} OrbisNpWebApiMemoryPoolStats;

typedef struct OrbisNpWebApiResponseInformationOption
{
    int32_t httpStatus;
    char *pErrorObject;
    size_t errorObjectSize;
    size_t responseDataSize;
} OrbisNpWebApiResponseInformationOption;

typedef void (*OrbisNpWebApiExtdPushEventCallbackA)(
    int32_t userCtxId,
    int32_t callbackId,
    const char *pNpServiceName,
    OrbisNpServiceLabel npServiceLabel,
    const OrbisNpPeerAddressA *pTo,
    const void *pToOnlineId,
    const OrbisNpPeerAddressA *pFrom,
    const void *pFromOnlineId,
    const OrbisNpWebApiPushEventDataType *pDataType,
    const char *pData,
    size_t dataLen,
    const OrbisNpWebApiExtdPushEventExtdData *pExtdData,
    size_t extdDataNum,
    void *pUserArg);