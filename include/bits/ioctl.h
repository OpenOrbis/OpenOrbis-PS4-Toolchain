#define IOCPARM_SHIFT       13      /* number of bits for ioctl size */
#define IOCPARM_MASK        ((1 << IOCPARM_SHIFT) - 1) /* parameter length mask */
#define IOCPARM_LEN(x)      (((x) >> 16) & IOCPARM_MASK)
#define IOCBASECMD(x)       ((x) & ~(IOCPARM_MASK << 16))
#define IOCGROUP(x)         (((x) >> 8) & 0xff)

#define IOCPARM_MAX         (1 << IOCPARM_SHIFT) /* max size of ioctl */
#define IOC_VOID            0x20000000  /* no parameters */
#define IOC_OUT             0x40000000  /* copy out parameters */
#define IOC_IN              0x80000000  /* copy in parameters */
#define IOC_INOUT           (IOC_IN|IOC_OUT)
#define IOC_DIRMASK         (IOC_VOID|IOC_OUT|IOC_IN)

#define _IOC(inout,group,num,len)   ((unsigned long) \
    ((inout) | (((len) & IOCPARM_MASK) << 16) | ((group) << 8) | (num)))
#define _IO(g,n)            _IOC(IOC_VOID,  (g), (n), 0)
#define _IOWINT(g,n)        _IOC(IOC_VOID,  (g), (n), sizeof(int))
#define _IOR(g,n,t)         _IOC(IOC_OUT,   (g), (n), sizeof(t))
#define _IOW(g,n,t)         _IOC(IOC_IN,    (g), (n), sizeof(t))
/* this should be _IORW, but stdio got there first */
#define _IOWR(g,n,t)        _IOC(IOC_INOUT, (g), (n), sizeof(t))

#define LINUX_TCGETS        0x5401
#define LINUX_TCSETS        0x5402
#define LINUX_TCSETSW       0x5403
#define LINUX_TCSETSF       0x5404
#define LINUX_TCGETA        0x5405
#define LINUX_TCSETA        0x5406
#define LINUX_TCSETAW       0x5407
#define LINUX_TCSETAF       0x5408
#define LINUX_TCSBRK        0x5409
#define LINUX_TCXONC        0x540A
#define LINUX_TCFLSH        0x540B
#define LINUX_TIOCEXCL      0x540C
#define LINUX_TIOCNXCL      0x540D
#define LINUX_TIOCSCTTY     0x540E
#define LINUX_TIOCGPGRP     0x540F
#define LINUX_TIOCSPGRP     0x5410
#define LINUX_TIOCOUTQ      0x5411
#define LINUX_TIOCSTI       0x5412
#define LINUX_TIOCGWINSZ    0x5413
#define LINUX_TIOCSWINSZ    0x5414
#define LINUX_TIOCMGET      0x5415
#define LINUX_TIOCMBIS      0x5416
#define LINUX_TIOCMBIC      0x5417
#define LINUX_TIOCMSET      0x5418
#define LINUX_TIOCGSOFTCAR  0x5419
#define LINUX_TIOCSSOFTCAR  0x541A
#define LINUX_FIONREAD      0x541B
#define LINUX_TIOCINQ       FIONREAD
#define LINUX_TIOCLINUX     0x541C
#define LINUX_TIOCCONS      0x541D
#define LINUX_TIOCGSERIAL   0x541E
#define LINUX_TIOCSSERIAL   0x541F
#define LINUX_TIOCPKT       0x5420
#define LINUX_FIONBIO       0x5421
#define LINUX_TIOCNOTTY     0x5422
#define LINUX_TIOCSETD      0x5423
#define LINUX_TIOCGETD      0x5424
#define LINUX_TCSBRKP       0x5425
#define LINUX_TIOCSBRK      0x5427
#define LINUX_TIOCCBRK      0x5428
#define LINUX_TIOCGSID      0x5429
#define LINUX_TIOCGRS485    0x542E
#define LINUX_TIOCSRS485    0x542F
#define LINUX_TIOCGPTN      0x80045430
#define LINUX_TIOCSPTLCK    0x40045431
#define LINUX_TIOCGDEV      0x80045432
#define LINUX_TCGETX        0x5432
#define LINUX_TCSETX        0x5433
#define LINUX_TCSETXF       0x5434
#define LINUX_TCSETXW       0x5435
#define LINUX_TIOCSIG       0x40045436
#define LINUX_TIOCVHANGUP   0x5437
#define LINUX_TIOCGPKT      0x80045438
#define LINUX_TIOCGPTLCK    0x80045439
#define LINUX_TIOCGEXCL     0x80045440
#define LINUX_TIOCGPTPEER   0x5441
#define LINUX_TIOCGISO7816  0x80285442
#define LINUX_TIOCSISO7816  0xc0285443

#define LINUX_FIONCLEX      0x5450
#define LINUX_FIOCLEX       0x5451
#define LINUX_FIOASYNC      0x5452
#define LINUX_TIOCSERCONFIG 0x5453
#define LINUX_TIOCSERGWILD  0x5454
#define LINUX_TIOCSERSWILD  0x5455
#define LINUX_TIOCGLCKTRMIOS    0x5456
#define LINUX_TIOCSLCKTRMIOS    0x5457
#define LINUX_TIOCSERGSTRUCT    0x5458
#define LINUX_TIOCSERGETLSR     0x5459
#define LINUX_TIOCSERGETMULTI   0x545A
#define LINUX_TIOCSERSETMULTI   0x545B

#define LINUX_TIOCMIWAIT        0x545C
#define LINUX_TIOCGICOUNT       0x545D
#define LINUX_FIOQSIZE          0x5460

#define LINUX_TIOCM_LE          0x001
#define LINUX_TIOCM_DTR         0x002
#define LINUX_TIOCM_RTS         0x004
#define LINUX_TIOCM_ST          0x008
#define LINUX_TIOCM_SR          0x010
#define LINUX_TIOCM_CTS         0x020
#define LINUX_TIOCM_CAR         0x040
#define LINUX_TIOCM_RNG         0x080
#define LINUX_TIOCM_DSR         0x100
#define LINUX_TIOCM_CD          LINUX_TIOCM_CAR
#define LINUX_TIOCM_RI          LINUX_TIOCM_RNG
#define LINUX_TIOCM_OUT1        0x2000
#define LINUX_TIOCM_OUT2        0x4000
#define LINUX_TIOCM_LOOP        0x8000

#define LINUX_FIOSETOWN         0x8901
#define LINUX_SIOCSPGRP         0x8902
#define LINUX_FIOGETOWN         0x8903
#define LINUX_SIOCGPGRP         0x8904
#define LINUX_SIOCATMARK        0x8905
#if __LONG_MAX == 0x7fffffff
#define LINUX_SIOCGSTAMP        _IOR(0x89, 6, char[16])
#define LINUX_SIOCGSTAMPNS      _IOR(0x89, 7, char[16])
#else
#define LINUX_SIOCGSTAMP        0x8906
#define LINUX_SIOCGSTAMPNS      0x8907
#endif

#include <bits/ioctl_fix.h>