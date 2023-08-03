#ifndef _SCE_SYS_MODULE_H_
#define _SCE_SYS_MODULE_H_

#include "_types/sysmodule.h"

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif
 
/**
  * Sysmodule function to test if a module is loaded or not.
  * @param id is the internal module id. see list of module ids.
  * @return 0 = Success/Valid or Negatives values are error codes.
  */
int32_t sceSysmoduleIsLoaded(enum OrbisSysModule moduleId);

/**
  * Sysmodule function to load a module.
  * @param id is the internal module id. see list of module ids.
  * @return 0 = Success/Valid or Negatives values are error codes.
  */
int32_t sceSysmoduleLoadModule(enum OrbisSysModule moduleId);

/**
  * Sysmodule function to unload a module.
  * @param id is the internal module id. see list of module ids.
  * @return 0 = Success/Valid or Negatives values are error codes.
  */
int32_t sceSysmoduleUnloadModule(enum OrbisSysModule moduleId);
 
// Undocumented Function... Need to reverse
void sceSysmoduleGetModuleHandleInternal();
// Undocumented Function... Need to reverse
void sceSysmoduleIsLoadedInternal();
// Undocumented Function... Need to reverse
void sceSysmoduleLoadModuleByNameInternal();
// Undocumented Function... Need to reverse
uint32_t sceSysmoduleLoadModuleInternal(enum OrbisSysModuleInternal moduleId);
// Undocumented Function... Need to reverse
void sceSysmoduleLoadModuleInternalWithArg();
// Undocumented Function... Need to reverse
void sceSysmodulePreloadModuleForLibkernel();
// Undocumented Function... Need to reverse
void sceSysmoduleUnloadModuleByNameInternal();
// Undocumented Function... Need to reverse
int32_t sceSysmoduleUnloadModuleInternal(enum OrbisSysModuleInternal moduleId);
// Undocumented Function... Need to reverse
void sceSysmoduleUnloadModuleInternalWithArg();

#ifdef __cplusplus
}
#endif
#endif

