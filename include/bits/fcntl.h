#define O_CREAT         01000
#define O_EXCL          04000
#define O_NOCTTY        0100000
#define O_TRUNC         02000
#define O_APPEND        010
#define O_NONBLOCK      04
#define O_DSYNC         0           // missing in freebsd headers
#define O_SYNC          0200
#define O_RSYNC         0           // missing in freebsd headers
#define O_DIRECTORY     0400000
#define O_NOFOLLOW      0400
#define O_CLOEXEC       04000000

#define O_ASYNC         0100
#define O_DIRECT        0200000
#define O_LARGEFILE     0
#define O_NOATIME       0           // missing in freebsd headers
#define O_PATH          0           // missing in freebsd headers
#define O_TMPFILE       0           // missing in freebsd headers
#define O_NDELAY        O_NONBLOCK

#define F_DUPFD         0
#define F_GETFD         1
#define F_SETFD         2
#define F_GETFL         3
#define F_SETFL         4

#define F_SETOWN        6
#define F_GETOWN        5
//F_SETSIG is linux-specific
//F_GETSIG is linux-specific

#define F_GETLK         11
#define F_SETLK         12
#define F_SETLKW        13

//F_SETOWN_EX is linux-specific
//F_GETOWN_EX is linux-specific

//F_GETOWNER_UIDS missing in freebsd headers
