#pragma once 

#define SSL_POOLSIZE 	(128 * 1024U)
#define LIBHTTP_POOLSIZE 	(128 * 1024)

typedef enum{
	ORBIS_METHOD_GET,
	ORBIS_METHOD_POST,
	ORBIS_METHOD_HEAD,
	ORBIS_METHOD_OPTIONS,
	ORBIS_METHOD_PUT,
	ORBIS_METHOD_DELETE,
	ORBIS_METHOD_TRACE,
	ORBIS_CONNECT
} OrbisMethods;

typedef enum {
	ORBIS_HTTP_VERSION_1_0=1,
	ORBIS_HTTP_VERSION_1_1
} OrbisHttpHttpVersion;

typedef enum {
	ORBIS_HTTP_CONTENTLEN_EXIST,
	ORBIS_HTTP_CONTENTLEN_NOT_FOUND,
	ORBIS_HTTP_CONTENTLEN_CHUNK_ENC
} OrbisHttpContentLengthType;

typedef int32_t (*OrbisHttpsCallback)(int32_t libsslCtxId,uint32_t verifyErr,void * const sslCert[],int32_t certNum,void *userArg);
