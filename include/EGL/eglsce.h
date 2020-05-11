#ifndef __eglsce_h_
#define __eglsce_h_ 1

#ifdef __cplusplus
extern "C" {
#endif

struct EGLPIGLETMEMORYINFOSCE;
typedef struct EGLPIGLETMEMORYINFOSCE EGLPIGLETMEMORYINFOSCE_t;

#define EGLMEMORYINFO_t EGLPIGLETMEMORYINFOSCE_t

#define eglMemoryInfo eglPigletMemoryInfoSCE

void eglPigletMemoryInfoSCE(EGLPIGLETMEMORYINFOSCE_t* pInfo);

#ifdef __cplusplus
}
#endif

#endif
