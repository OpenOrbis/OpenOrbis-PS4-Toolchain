#pragma once

/* protocol */
#define ORBIS_NET_IPPROTO_IP            0
#define ORBIS_NET_IPPROTO_ICMP          1
#define ORBIS_NET_IPPROTO_IGMP          2
#define ORBIS_NET_IPPROTO_TCP           6
#define ORBIS_NET_IPPROTO_UDP           17
#define ORBIS_NET_SOL_SOCKET            0xffff

/* socket option (IP) */
#define ORBIS_NET_IP_HDRINCL            2
#define ORBIS_NET_IP_TOS                3
#define ORBIS_NET_IP_TTL                4
#define ORBIS_NET_IP_MULTICAST_IF       9
#define ORBIS_NET_IP_MULTICAST_TTL      10
#define ORBIS_NET_IP_MULTICAST_LOOP     11
#define ORBIS_NET_IP_ADD_MEMBERSHIP     12
#define ORBIS_NET_IP_DROP_MEMBERSHIP    13
#define ORBIS_NET_IP_TTLCHK             30
#define ORBIS_NET_IP_MAXTTL             31
#define ORBIS_NET_IP_DONTFRAG           67

/* socket option (TCP) */
#define ORBIS_NET_TCP_NODELAY           1
#define ORBIS_NET_TCP_MAXSEG            2
#define ORBIS_NET_TCP_MSS_TO_ADVERTISE  3
#define ORBIS_NET_TCP_KEEPLISTEN        128

/* socket option (UDP) */
#define ORBIS_NET_UDP_SND_ON_SUSPEND    128

/* socket option (SOCKET) */
#define ORBIS_NET_SO_REUSEADDR          0x00000004
#define ORBIS_NET_SO_KEEPALIVE          0x00000008
#define ORBIS_NET_SO_BROADCAST          0x00000020
#define ORBIS_NET_SO_LINGER             0x00000080
#define ORBIS_NET_SO_REUSEPORT          0x00000200
#define ORBIS_NET_SO_ONESBCAST          0x00010000
#define ORBIS_NET_SO_USECRYPTO          0x00020000
#define ORBIS_NET_SO_USESIGNATURE       0x00040000
#define	ORBIS_NET_SO_NOSIGPIPE			0x00000800

#define ORBIS_NET_SO_SNDBUF             0x1001
#define ORBIS_NET_SO_RCVBUF             0x1002
#define ORBIS_NET_SO_ERROR              0x1007
#define ORBIS_NET_SO_TYPE               0x1008

#define ORBIS_NET_SO_SNDTIMEO           0x1105
#define ORBIS_NET_SO_RCVTIMEO           0x1106
#define ORBIS_NET_SO_ERROR_EX           0x1107
#define ORBIS_NET_SO_ACCEPTTIMEO        0x1108
#define ORBIS_NET_SO_CONNECTTIMEO       0x1109

#define ORBIS_NET_SO_NBIO               0x1200
#define ORBIS_NET_SO_POLICY             0x1201
#define ORBIS_NET_SO_NAME               0x1202
#define ORBIS_NET_SO_PRIORITY           0x1203

/* socket types */
#define ORBIS_NET_AF_INET				2
#define ORBIS_NET_SOCK_STREAM			1
#define ORBIS_NET_SOCK_DGRAM			2
#define ORBIS_NET_SOCK_RAW				3
#define ORBIS_NET_SOCK_DGRAM_P2P		6
#define ORBIS_NET_SOCK_STREAM_P2P		10

/* address families */
#define ORBIS_NET_AF_LOCAL				1
#define ORBIS_NET_AF_INET               2

/* ORBIS_NET_SO_POLICY */
#define ORBIS_NET_SOCK_POLICY_NUM_MIN   0
#define ORBIS_NET_SOCK_POLICY_NUM_MAX   15
#define ORBIS_NET_SOCK_POLICY_NA        -1

/* ORBIS_NET_SO_PRIORITY */
#define ORBIS_NET_SOCK_PRIORITY_NUM_MIN        1
#define ORBIS_NET_SOCK_PRIORITY_NUM_USER_MIN   8
#define ORBIS_NET_SOCK_PRIORITY_NUM_USER_MAX   23
#define ORBIS_NET_SOCK_PRIORITY_NUM_MAX        31

/* address & mask */
#define ORBIS_NET_INADDR_ANY           ((unsigned int)0x00000000)
#define ORBIS_NET_INADDR_LOOPBACK      ((unsigned int)0x7f000001)
#define ORBIS_NET_INADDR_BROADCAST     ((unsigned int)0xffffffff)
#define ORBIS_NET_INADDR_UNSPEC_GROUP  ((unsigned int)0xe0000000)
#define ORBIS_NET_INADDR_AUTOIP        ((unsigned int)0xa9fe0000)

#define ORBIS_NET_IN_CLASSD_NET        ((unsigned int)0xf0000000)
#define ORBIS_NET_IN_AUTOIP_NET        ((unsigned int)0xffff0000)

#define ORBIS_NET_INET_ADDRSTRLEN     16

/* multicast */
#define ORBIS_NET_IP_DEFAULT_MULTICAST_TTL   1
#define ORBIS_NET_IP_DEFAULT_MULTICAST_LOOP  1

/* flags */
#define ORBIS_NET_MSG_PEEK            0x00000002
#define ORBIS_NET_MSG_WAITALL         0x00000040
#define ORBIS_NET_MSG_DONTWAIT        0x00000080
#define ORBIS_NET_MSG_USECRYPTO       0x00100000
#define ORBIS_NET_MSG_USESIGNATURE    0x00200000
#define ORBIS_NET_MSG_PEEKLEN		  (0x00400000 | ORBIS_NET_MSG_PEEK)
 
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
	int IPAddress;					// 0x28
	char padding1[0x24];			// 0x2C
	unsigned char MacAddress[6];	// 0x50
	char padding2[0x192];			// 0x56
}; //0x1E8
