/*
 * Protections are chosen from these bits, or-ed together
 */
#undef PROT_NONE
#undef PROT_READ
#undef PROT_WRITE
#undef PROT_EXEC

#define	PROT_NONE	0x00	/* no permissions */
#define	PROT_READ	0x01	/* pages can be read */
#define	PROT_WRITE	0x02	/* pages can be written */
#define	PROT_EXEC	0x04	/* pages can be executed */

/*
 * Flags contain sharing type and options.
 * Sharing types; choose one.
 */
#undef MAP_SHARED
#undef MAP_PRIVATE

#define	MAP_SHARED	0x0001		/* share changes */
#define	MAP_PRIVATE	0x0002		/* changes are private */

/*
 * Other flags
 */
#undef MAP_FIXED
#undef MAP_STACK

#define	MAP_FIXED	 0x0010	/* map addr must be exactly as requested */

#define	MAP_RESERVED0020 0x0020	/* previously unimplemented MAP_RENAME */
#define	MAP_RESERVED0040 0x0040	/* previously unimplemented MAP_NORESERVE */
#define	MAP_RESERVED0080 0x0080	/* previously misimplemented MAP_INHERIT */
#define	MAP_RESERVED0100 0x0100	/* previously unimplemented MAP_NOEXTEND */
#define	MAP_HASSEMAPHORE 0x0200	/* region may contain semaphores */
#define	MAP_STACK	 0x0400	/* region grows down, like a stack */
#define	MAP_NOSYNC	 0x0800 /* page to but do not sync underlying file */

/*
 * Mapping type
 */
#undef MAP_FILE
#undef MAP_ANON

#define	MAP_FILE	 0x0000	/* map from file (default) */
#define	MAP_ANON	 0x1000	/* allocated from memory, swap space */

/*
 * Extended flags
 */
#define	MAP_GUARD	 0x00002000 /* reserve but don't map address range */
#define	MAP_EXCL	 0x00004000 /* for MAP_FIXED, fail if address is used */
#define	MAP_NOCORE	 0x00020000 /* dont include these pages in a coredump */
#define	MAP_PREFAULT_READ 0x00040000 /* prefault mapping for reading */
#ifdef __LP64__
#define	MAP_32BIT	 0x00080000 /* map in the low 2GB of address space */
#endif

/*
 * Request specific alignment (n == log2 of the desired alignment).
 *
 * MAP_ALIGNED_SUPER requests optimal superpage alignment, but does
 * not enforce a specific alignment.
 */
#define	MAP_ALIGNED(n)	 ((n) << MAP_ALIGNMENT_SHIFT)
#define	MAP_ALIGNMENT_SHIFT	24
#define	MAP_ALIGNMENT_MASK	MAP_ALIGNED(0xff)
#define	MAP_ALIGNED_SUPER	MAP_ALIGNED(1) /* align on a superpage */

/*
 * Error return from mmap()
 */
#undef MAP_FAILED

#define MAP_FAILED	((void *)-1)

/*
 * msync() flags
 */
#undef MS_SYNC
#undef MS_ASYNC
#undef MS_INVALIDATE

#define	MS_SYNC		0x0000	/* msync synchronously */
#define MS_ASYNC	0x0001	/* return immediately */
#define MS_INVALIDATE	0x0002	/* invalidate all cached data */

/*
 * Advice to madvise
 */
#undef MADV_NORMAL
#undef MADV_RANDOM
#undef MADV_SEQUENTIAL
#undef MADV_WILLNEED
#undef MADV_DONTNEED
#undef MADV_FREE

#define	_MADV_NORMAL	0	/* no further special treatment */
#define	_MADV_RANDOM	1	/* expect random page references */
#define	_MADV_SEQUENTIAL 2	/* expect sequential page references */
#define	_MADV_WILLNEED	3	/* will need these pages */
#define	_MADV_DONTNEED	4	/* dont need these pages */

#define	MADV_NORMAL	_MADV_NORMAL
#define	MADV_RANDOM	_MADV_RANDOM
#define	MADV_SEQUENTIAL _MADV_SEQUENTIAL
#define	MADV_WILLNEED	_MADV_WILLNEED
#define	MADV_DONTNEED	_MADV_DONTNEED
#define	MADV_FREE	5	/* dont need these pages, and junk contents */
#define	MADV_NOSYNC	6	/* try to avoid flushes to physical media */
#define	MADV_AUTOSYNC	7	/* revert to default flushing strategy */
#define	MADV_NOCORE	8	/* do not include these pages in a core file */
#define	MADV_CORE	9	/* revert to including pages in a core file */
#define	MADV_PROTECT	10	/* protect process from pageout kill */

/*
 * Return bits from mincore
 */
#define	MINCORE_INCORE	 	 0x1 /* Page is incore */
#define	MINCORE_REFERENCED	 0x2 /* Page has been referenced by us */
#define	MINCORE_MODIFIED	 0x4 /* Page has been modified by us */
#define	MINCORE_REFERENCED_OTHER 0x8 /* Page has been referenced */
#define	MINCORE_MODIFIED_OTHER	0x10 /* Page has been modified */
#define	MINCORE_SUPER		0x20 /* Page is a "super" page */

/*
 * Anonymous object constant for shm_open().
 */
#define	SHM_ANON		((char *)1)

/*
 * shmflags for shm_open2()
 */
#define	SHM_ALLOW_SEALING		0x00000001
