/* copied from kernel definition, but with padding replaced
 * by the corresponding correctly-sized userspace types. */

#include <stdint.h>

struct stat {
	dev_t st_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	off_t st_size;
	blkcnt_t st_blocks;
	blksize_t st_blksize;
	uint32_t st_flags;
	uint32_t st_gen;
	int32_t st_lspare;
	struct timespec st_birthtim;
	unsigned int :(8 / 2) * (16 - (int)sizeof(struct timespec));
	unsigned int :(8 / 2) * (16 - (int)sizeof(struct timespec));
};