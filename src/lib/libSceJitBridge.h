#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void _ZN19JITSharedDataMemory15shared_mallinfoEv();
void _ZN19JITSharedDataMemory9sbrk_infoE();
void _ZN19JITSharedTextMemory15shared_mallinfoEv();
void _ZN19JITSharedTextMemory9sbrk_infoE();
void _ZN9JITBridge12ringDoorbellEiNS_8DoorbellE();
void _ZN9JITBridge12waitDoorbellEi();
void _ZN9JITBridge14shutdownFromVMEPS_b();
void _ZN9JITBridge16initializeFromVMEPKcPPcPKNS_11RestartDataE();
void _ZN9JITBridge20shutdownFromCompilerEPS_b();
void _ZN9JITBridge22initializeFromCompilerEPKcPPcPKNS_11RestartDataE();
