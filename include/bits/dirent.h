#define _DIRENT_HAVE_D_RECLEN
#define _DIRENT_HAVE_D_OFF
#define _DIRENT_HAVE_D_TYPE

struct dirent {
	unsigned int    d_fileno;
	unsigned short  d_reclen;
	unsigned char   d_type;
	unsigned char   d_namlen;
	char d_name[256];
};
