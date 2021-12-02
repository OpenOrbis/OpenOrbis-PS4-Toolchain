#ifndef	_SYS_SOCKET_H
#define	_SYS_SOCKET_H
#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_socklen_t
#define __NEED_sa_family_t
#define __NEED_size_t
#define __NEED_ssize_t
#define __NEED_uid_t
#define __NEED_pid_t
#define __NEED_gid_t
#define __NEED_struct_iovec

#include <bits/alltypes.h>

#include <bits/socket.h>

struct msghdr {
	void *msg_name;
	socklen_t msg_namelen;
	struct iovec *msg_iov;
#if __LONG_MAX > 0x7fffffff && __BYTE_ORDER == __BIG_ENDIAN
	int __pad1;
#endif
	int msg_iovlen;
#if __LONG_MAX > 0x7fffffff && __BYTE_ORDER == __LITTLE_ENDIAN
	int __pad1;
#endif
	void *msg_control;
#if __LONG_MAX > 0x7fffffff && __BYTE_ORDER == __BIG_ENDIAN
	int __pad2;
#endif
	socklen_t msg_controllen;
#if __LONG_MAX > 0x7fffffff && __BYTE_ORDER == __LITTLE_ENDIAN
	int __pad2;
#endif
	int msg_flags;
};

struct cmsghdr {
#if __LONG_MAX > 0x7fffffff && __BYTE_ORDER == __BIG_ENDIAN
	int __pad1;
#endif
	socklen_t cmsg_len;
#if __LONG_MAX > 0x7fffffff && __BYTE_ORDER == __LITTLE_ENDIAN
	int __pad1;
#endif
	int cmsg_level;
	int cmsg_type;
};

#ifdef _GNU_SOURCE
struct ucred {
	pid_t pid;
	uid_t uid;
	gid_t gid;
};

struct mmsghdr {
	struct msghdr msg_hdr;
	unsigned int  msg_len;
};

struct timespec;

int sendmmsg (int, struct mmsghdr *, unsigned int, unsigned int);
int recvmmsg (int, struct mmsghdr *, unsigned int, unsigned int, struct timespec *);
#endif

struct linger {
	int l_onoff;
	int l_linger;
};

#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2

#ifndef SOCK_STREAM
#define SOCK_STREAM    1
#define SOCK_DGRAM     2
#endif

#define SOCK_RAW       3
#define SOCK_RDM       4
#define SOCK_SEQPACKET 5
#define SOCK_DCCP      6
#define SOCK_PACKET    10

#ifndef SOCK_CLOEXEC
#define SOCK_CLOEXEC   02000000
#define SOCK_NONBLOCK  04000
#endif

#define PF_UNSPEC       0
#define PF_LOCAL        1
#define PF_UNIX         PF_LOCAL
#define PF_FILE         PF_LOCAL
#define PF_INET         2
#define PF_IMPLINK      3
#define PF_PUP          4
#define PF_CHAOS        5
#define PF_NETBIOS      6
#define PF_ISO          7
#define PF_OSI          PF_ISO
#define PF_ECMA         8
#define PF_DATAKIT      9
#define PF_CCITT        10
#define PF_SNA          11
#define PF_DECnet       12
#define PF_DLI          13
#define PF_LAT          14
#define PF_HYLINK       15
#define PF_APPLETALK    16
#define PF_ROUTE        17
#define PF_LINK         18
#define PF_XTP          19
#define PF_COIP         20
#define PF_CNT          21
#define PF_RTIP         22
#define PF_IPX          23
#define PF_SIP          24
#define PF_PIP          25
#define PF_ISDN         26
#define PF_E164         PF_ISDN
#define PF_KEY          27
#define PF_INET6        28
#define PF_NATM         29
#define PF_ATM          30
#define AF_HDRCMPLT     31
#define PF_NETGRAPH     32
#define PF_SLOW         33
#define PF_SCLUSTER     34
#define PF_ARP          35
#define PF_BLUETOOTH    36
#define PF_IEEE80211    37
#define PF_INET_SDP     40
#define PF_INET6_SDP    42
#define PF_MAX          42

#define AF_UNSPEC       PF_UNSPEC
#define AF_LOCAL        PF_LOCAL
#define AF_UNIX         PF_UNIX
#define AF_FILE         PF_FILE
#define AF_INET         PF_INET
#define AF_IMPLINK      PF_IMPLINK
#define AF_PUP          PF_PUP
#define AF_CHAOS        PF_CHAOS
#define AF_NETBIOS      PF_NETBIOS
#define AF_ISO          PF_ISO
#define AF_OSI          PF_OSI
#define AF_ECMA         PF_ECMA
#define AF_DATAKIT      PF_DATAKIT
#define AF_CCITT        PF_CCITT
#define AF_SNA          PF_SNA
#define AF_DECnet       PF_DECnet
#define AF_DLI          PF_DLI
#define AF_LAT          PF_LAT
#define AF_HYLINK       PF_HYLINK
#define AF_APPLETALK    PF_APPLETALK
#define AF_ROUTE        PF_ROUTE
#define AF_LINK         PF_LINK
#define AF_XTP          PF_XTP
#define AF_COIP         PF_COIP
#define AF_CNT          PF_CNT
#define AF_RTIP         PF_RTIP
#define AF_IPX          PF_IPX
#define AF_SIP          PF_SIP
#define AF_PIP          PF_PIP
#define AF_ISDN         PF_ISDN
#define AF_E164         PF_E164
#define AF_KEY          PF_KEY
#define AF_INET6        PF_INET6
#define AF_NATM         PF_NATM
#define AF_ATM          PF_ATM
#define AF_HDRCMPLT     PF_HDRCMPLT
#define AF_NETGRAPH     PF_NETGRAPH
#define AF_SLOW         PF_SLOW
#define AF_SCLUSTER     PF_SCLUSTER
#define AF_ARP          PF_ARP
#define AF_BLUETOOTH    PF_BLUETOOTH
#define AF_IEEE80211    PF_IEEE80211
#define AF_INET_SDP     PF_INET_SDP
#define AF_INET6_SDP    PF_INET6_SDP
#define AF_MAX          PF_MAX

#ifndef SO_DEBUG
#define SO_DEBUG        1
#define SO_REUSEADDR    2
#define SO_TYPE         3
#define SO_ERROR        4
#define SO_DONTROUTE    5
#define SO_BROADCAST    6
#define SO_SNDBUF       7
#define SO_RCVBUF       8
#define SO_KEEPALIVE    9
#define SO_OOBINLINE    10
#define SO_NO_CHECK     11
#define SO_PRIORITY     12
#define SO_LINGER       13
#define SO_BSDCOMPAT    14
#define SO_REUSEPORT    15
#define SO_PASSCRED     16
#define SO_PEERCRED     17
#define SO_RCVLOWAT     18
#define SO_SNDLOWAT     19
#define SO_ACCEPTCONN   30
#define SO_PEERSEC      31
#define SO_SNDBUFFORCE  32
#define SO_RCVBUFFORCE  33
#define SO_PROTOCOL     38
#define SO_DOMAIN       39
#endif

#ifndef SO_RCVTIMEO
#if __LONG_MAX == 0x7fffffff
#define SO_RCVTIMEO     66
#define SO_SNDTIMEO     67
#else
#define SO_RCVTIMEO     20
#define SO_SNDTIMEO     21
#endif
#endif

#ifndef SO_TIMESTAMP
#if __LONG_MAX == 0x7fffffff
#define SO_TIMESTAMP    63
#define SO_TIMESTAMPNS  64
#define SO_TIMESTAMPING 65
#else
#define SO_TIMESTAMP    29
#define SO_TIMESTAMPNS  35
#define SO_TIMESTAMPING 37
#endif
#endif

#define SO_SECURITY_AUTHENTICATION              22
#define SO_SECURITY_ENCRYPTION_TRANSPORT        23
#define SO_SECURITY_ENCRYPTION_NETWORK          24

#define SO_BINDTODEVICE 25

#define SO_ATTACH_FILTER        26
#define SO_DETACH_FILTER        27
#define SO_GET_FILTER           SO_ATTACH_FILTER

#define SO_PEERNAME             28
#define SCM_TIMESTAMP           SO_TIMESTAMP
#define SO_PASSSEC              34
#define SCM_TIMESTAMPNS         SO_TIMESTAMPNS
#define SO_MARK                 36
#define SCM_TIMESTAMPING        SO_TIMESTAMPING
#define SO_RXQ_OVFL             40
#define SO_WIFI_STATUS          41
#define SCM_WIFI_STATUS         SO_WIFI_STATUS
#define SO_PEEK_OFF             42
#define SO_NOFCS                43
#define SO_LOCK_FILTER          44
#define SO_SELECT_ERR_QUEUE     45
#define SO_BUSY_POLL            46
#define SO_MAX_PACING_RATE      47
#define SO_BPF_EXTENSIONS       48
#define SO_INCOMING_CPU         49
#define SO_ATTACH_BPF           50
#define SO_DETACH_BPF           SO_DETACH_FILTER
#define SO_ATTACH_REUSEPORT_CBPF 51
#define SO_ATTACH_REUSEPORT_EBPF 52
#define SO_CNX_ADVICE           53
#define SCM_TIMESTAMPING_OPT_STATS 54
#define SO_MEMINFO              55
#define SO_INCOMING_NAPI_ID     56
#define SO_COOKIE               57
#define SCM_TIMESTAMPING_PKTINFO 58
#define SO_PEERGROUPS           59
#define SO_ZEROCOPY             60
#define SO_TXTIME               61
#define SCM_TXTIME              SO_TXTIME
#define SO_BINDTOIFINDEX        62
#define SO_DETACH_REUSEPORT_BPF 68

#ifndef SOL_SOCKET
#define SOL_SOCKET      0xffff
#endif

#define SOMAXCONN       128

#define MSG_OOB       0x0001
#define MSG_PEEK      0x0002
#define MSG_DONTROUTE 0x0004
#define MSG_CTRUNC    0x0008
#define MSG_PROXY     0x0010
#define MSG_TRUNC     0x0020
#define MSG_DONTWAIT  0x0040
#define MSG_EOR       0x0080
#define MSG_WAITALL   0x0100
#define MSG_FIN       0x0200
#define MSG_SYN       0x0400
#define MSG_CONFIRM   0x0800
#define MSG_RST       0x1000
#define MSG_ERRQUEUE  0x2000
#define MSG_NOSIGNAL  0x4000
#define MSG_MORE      0x8000
#define MSG_WAITFORONE 0x10000
#define MSG_BATCH     0x40000
#define MSG_ZEROCOPY  0x4000000
#define MSG_FASTOPEN  0x20000000
#define MSG_CMSG_CLOEXEC 0x40000000

#define __CMSG_LEN(cmsg) (((cmsg)->cmsg_len + sizeof(long) - 1) & ~(long)(sizeof(long) - 1))
#define __CMSG_NEXT(cmsg) ((unsigned char *)(cmsg) + __CMSG_LEN(cmsg))
#define __MHDR_END(mhdr) ((unsigned char *)(mhdr)->msg_control + (mhdr)->msg_controllen)

#define CMSG_DATA(cmsg) ((unsigned char *) (((struct cmsghdr *)(cmsg)) + 1))
#define CMSG_NXTHDR(mhdr, cmsg) ((cmsg)->cmsg_len < sizeof (struct cmsghdr) || \
	__CMSG_LEN(cmsg) + sizeof(struct cmsghdr) >= __MHDR_END(mhdr) - (unsigned char *)(cmsg) \
	? 0 : (struct cmsghdr *)__CMSG_NEXT(cmsg))
#define CMSG_FIRSTHDR(mhdr) ((size_t) (mhdr)->msg_controllen >= sizeof (struct cmsghdr) ? (struct cmsghdr *) (mhdr)->msg_control : (struct cmsghdr *) 0)

#define CMSG_ALIGN(len) (((len) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1))
#define CMSG_SPACE(len) (CMSG_ALIGN (len) + CMSG_ALIGN (sizeof (struct cmsghdr)))
#define CMSG_LEN(len)   (CMSG_ALIGN (sizeof (struct cmsghdr)) + (len))

#define SCM_RIGHTS      0x01
#define SCM_CREDENTIALS 0x02

struct sockaddr {
	uint8_t sa_len;
	uint8_t sa_family;
	char sa_data[14];
};

struct sockaddr_storage {
	sa_family_t ss_family;
	char __ss_padding[128-sizeof(long)-sizeof(sa_family_t)];
	unsigned long __ss_align;
};

int socket (int, int, int);
int socketpair (int, int, int, int [2]);

int shutdown (int, int);

int bind (int, const struct sockaddr *, socklen_t);
int connect (int, const struct sockaddr *, socklen_t);
int listen (int, int);
int accept (int, struct sockaddr *__restrict, socklen_t *__restrict);
int accept4(int, struct sockaddr *__restrict, socklen_t *__restrict, int);

int getsockname (int, struct sockaddr *__restrict, socklen_t *__restrict);
int getpeername (int, struct sockaddr *__restrict, socklen_t *__restrict);

ssize_t send (int, const void *, size_t, int);
ssize_t recv (int, void *, size_t, int);
ssize_t sendto (int, const void *, size_t, int, const struct sockaddr *, socklen_t);
ssize_t recvfrom (int, void *__restrict, size_t, int, struct sockaddr *__restrict, socklen_t *__restrict);
ssize_t sendmsg (int, const struct msghdr *, int);
ssize_t recvmsg (int, struct msghdr *, int);

int getsockopt (int, int, int, void *__restrict, socklen_t *__restrict);
int setsockopt (int, int, int, const void *, socklen_t);

int sockatmark (int);

#if _REDIR_TIME64
#ifdef _GNU_SOURCE
__REDIR(recvmmsg, __recvmmsg_time64);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif

