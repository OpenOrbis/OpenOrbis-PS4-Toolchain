#ifndef _SCE_JIT_BRIDGE_H_
#define _SCE_JIT_BRIDGE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void _ZN19JITSharedDataMemory15shared_mallinfoEv();
// Empty Comment
void _ZN19JITSharedDataMemory9sbrk_infoE();
// Empty Comment
void _ZN19JITSharedTextMemory15shared_mallinfoEv();
// Empty Comment
void _ZN19JITSharedTextMemory9sbrk_infoE();
// Empty Comment
void _ZN9JITBridge12ringDoorbellEiNS_8DoorbellE();
// Empty Comment
void _ZN9JITBridge12waitDoorbellEi();
// Empty Comment
void _ZN9JITBridge14shutdownFromVMEPS_b();
// Empty Comment
void _ZN9JITBridge16initializeFromVMEPKcPPcPKNS_11RestartDataE();
// Empty Comment
void _ZN9JITBridge20shutdownFromCompilerEPS_b();
// Empty Comment
void _ZN9JITBridge22initializeFromCompilerEPKcPPcPKNS_11RestartDataE();

#endif

#ifdef __cplusplus
}
#endif