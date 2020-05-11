#pragma once

#define ORBIS_NET_AF_INET				2
#define ORBIS_NET_SOCK_STREAM			1
#define ORBIS_NET_SOCK_DGRAM			2
#define ORBIS_NET_SOCK_RAW				3
#define ORBIS_NET_SOCK_DGRAM_P2P		6
#define ORBIS_NET_SOCK_STREAM_P2P		10
 
#define SCE_NET_DBG_MAX_NAME_LENGTH	31

typedef int OrbisNetId;
typedef uint32_t OrbisNetSocklen_t;
typedef uint32_t OrbisNetInAddr_t;
typedef uint16_t OrbisNetInPort_t;
typedef uint8_t OrbisNetSaFamily_t;


typedef struct OrbisNetLinger {
	int status;
	int unk01;
} OrbisNetLinger;

typedef struct OrbisNetSockaddr {
	uint8_t len;
	OrbisNetSaFamily_t sa_family;
	char sa_data[14];
} OrbisNetSockaddr;

typedef struct OrbisNetIovec {
	void *iov_base;
	size_t iov_len;
} OrbisNetIovec;

typedef struct OrbisNetMsghdr {
	void *msg_name;
	OrbisNetSocklen_t msg_namelen;
	OrbisNetIovec *msg_iov;
	int msg_iovlen;
	void *msg_control;
	OrbisNetSocklen_t msg_controllen;
	int msg_flags;
} OrbisNetMsghdr;

typedef struct OrbisNetUdpSndOnSuspend {
	int onoff;
	OrbisNetSockaddr *addr;
	OrbisNetSocklen_t addrlen;
	void *data;
	OrbisNetSocklen_t datalen;
} OrbisNetUdpSndOnSuspend;