#include <stdint.h>

#define    MFSNAMELEN     16
#define    MNAMELEN       1024

struct statfs {
	uint32_t f_version;         /* structure version number */
	uint32_t f_type;            /* type of filesystem */
	uint64_t f_flags;           /* copy of mount exported flags */
	uint64_t f_bsize;           /* filesystem fragment size */
	uint64_t f_iosize;          /* optimal transfer block size */
	uint64_t f_blocks;          /* total data blocks in filesystem */
	uint64_t f_bfree;           /* free blocks in filesystem */
	int64_t  f_bavail;          /* free blocks avail to non-superuser */
	uint64_t f_files;           /* total file nodes in filesystem */
	int64_t  f_ffree;           /* free nodes avail to non-superuser */
	uint64_t f_syncwrites;      /* count of sync writes since mount */
	uint64_t f_asyncwrites;     /* count of async writes since mount */
	uint64_t f_syncreads;       /* count of sync reads since mount */
	uint64_t f_asyncreads;      /* count of async reads since mount */
	uint64_t f_spare[10];       /* unused spare */
	uint32_t f_namemax;         /* maximum filename length */
	uint32_t f_owner;           /* user that mounted the filesystem */
	uint32_t f_fsid;            /* filesystem id */
	char     f_charspare[80];          /* spare string space */
	char     f_fstypename[MFSNAMELEN]; /* filesystem type name */
	char     f_mntfromname[MNAMELEN];  /* mounted filesystem */
	char     f_mntonname[MNAMELEN];    /* directory on which mounted */
};
