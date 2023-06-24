#pragma once

typedef enum OrbisNetType
{
	ORBIS_NET_AF_INET = 2,
	ORBIS_NET_SOCK_STREAM = 1,
	ORBIS_NET_SOCK_DGRAM = 2,
	ORBIS_NET_SOCK_RAW = 3,
	ORBIS_NET_SOCK_DGRAM_P2P = 6,
	ORBIS_NET_SOCK_STREAM_P2P = 0,
} OrbisNetType;

#define SCE_NET_DBG_MAX_NAME_LENGTH	31

typedef int32_t OrbisNetId;
typedef uint32_t OrbisNetSocklen_t;
typedef uint32_t OrbisNetInAddr_t;
typedef uint16_t OrbisNetInPort_t;
typedef uint8_t OrbisNetSaFamily_t;


typedef struct OrbisNetLinger {
	int32_t status;
	int32_t unk01;
} OrbisNetLinger;

typedef struct OrbisNetSockaddr {
	uint8_t len;
	OrbisNetSaFamily_t sa_family;
	char sa_data[14];
} OrbisNetSockaddr;

typedef struct OrbisNetSockaddrUn
{
	uint8_t sun_len;
	OrbisNetSaFamily_t sun_family;
	char sun_path[104];
} OrbisNetSockaddrUn;

typedef struct OrbisNetIovec {
	void *iov_base;
	size_t iov_len;
} OrbisNetIovec;

typedef struct OrbisNetMsghdr {
	void *msg_name;
	OrbisNetSocklen_t msg_namelen;
	OrbisNetIovec *msg_iov;
	int32_t msg_iovlen;
	void *msg_control;
	OrbisNetSocklen_t msg_controllen;
	int32_t msg_flags;
} OrbisNetMsghdr;

typedef struct OrbisNetUdpSndOnSuspend {
	int32_t onoff;
	OrbisNetSockaddr *addr;
	OrbisNetSocklen_t addrlen;
	void *data;
	OrbisNetSocklen_t datalen;
} OrbisNetUdpSndOnSuspend;

typedef struct OrbisNetDnsInfo {
	OrbisNetInAddr_t primary_dns;
	OrbisNetInAddr_t secondary_dns;
} OrbisNetDnsInfo;

typedef struct OrbisNetInAddr {
	OrbisNetInAddr_t s_addr;
} OrbisNetInAddr;

typedef struct OrbisNetEtherAddr {
	unsigned char data[6];
} OrbisNetEtherAddr;

enum OrbisNetIfName
{
	SCE_NET_IF_NAME_UNKNOWN = -2,
	SCE_NET_IF_NAME_NONE,
	SCE_NET_IF_NAME_LO0,
	SCE_NET_IF_NAME_PHYSICAL,
	SCE_NET_IF_NAME_ETH0 = 1,
	SCE_NET_IF_NAME_ETH1,
	SCE_NET_IF_NAME_DBG0,
	SCE_NET_IF_NAME_WLAN0,
	SCE_NET_IF_NAME_WLAN1,
	SCE_NET_IF_NAME_GBE0,
	SCE_NET_IF_NAME_BT0,
	SCE_NET_IF_NAME_PHONE0,
	SCE_NET_IF_NAME_VIRTUAL,
	SCE_NET_IF_NAME_PPPOE0 = 9,
	SCE_NET_IF_NAME_MAX
};

struct OrbisNetIfEntry
{
	char Name[0x10];				// 0x00
	char padding0[0x18];			// 0x10
	int32_t IPAddress;					// 0x28
	char padding1[0x24];			// 0x2C
	unsigned char MacAddress[6];	// 0x50
	char padding2[0x192];			// 0x56
}; //0x1E8
