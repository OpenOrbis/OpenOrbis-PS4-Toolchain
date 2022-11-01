#define weaksym __attribute__((weak))
#define weaksymal(_AliasName) __attribute__((weak, alias(#_AliasName)))
#define hidesym __attribute__((visibility("hidden")))

typedef void(*fp_t)(void);
typedef int(*module_func_t)(unsigned long long argl, void *argp);

extern void(*__preinit_array_start[])(void) weaksym;
extern void(*__preinit_array_end[])(void) weaksym;
extern void(*__init_array_start[])(void) weaksym;
extern void(*__init_array_end[])(void) weaksym;
extern void(*__fini_array_start[])(void) weaksym;
extern void(*__fini_array_end[])(void) weaksym;
extern void __cxa_finalize(void *dsoh) weaksymal(__cxa_finalize_dummy);
extern int module_start(unsigned long long argl, void *argp) weaksymal(module_start_dummy);
extern int module_stop(unsigned long long argl, void *argp) weaksymal(module_stop_dummy);
extern int _init(unsigned long long argl, void *argp, module_func_t overrider) hidesym;
extern int _fini(unsigned long long argl, void *argp, module_func_t overrider) hidesym;
extern void *__dso_handle hidesym;

#define call_fp_array(_Name) for (fp_t *f = (_Name##_start); f && (f != (_Name##_end)); ++f) if (*f) (*f)()

// sce_module_param
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.sce_module_param\" \n"
"_sceProcessParam: \n"
	// size
"	.quad 	0x18 \n"
	// magic
"	.quad   0x13C13F4BF \n"
	// SDK version
"	.quad 	0x4508101 \n"
".att_syntax prefix \n"
);

// data globals
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".data \n"
"_sceLibc: \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

int _init(unsigned long long argl, void *argp, module_func_t overrider /* ???? */) {
	call_fp_array(__preinit_array);
	call_fp_array(__init_array);
	
	if (overrider) return overrider(argl, argp);
	else if (&module_start) return module_start(argl, argp);
	
	return 0;
}

int _fini(unsigned long long argl, void *argp, module_func_t overrider /* ???? */) {
	static char completed = 0;
	int rc = 0;
	
	if (completed) {
		return rc;
	}
	completed = 1;
	
	
	if (overrider) rc = overrider(argl, argp);
	else if (&module_stop) rc = module_stop(argl, argp);
	
	if (&__cxa_finalize) __cxa_finalize(__dso_handle);
	call_fp_array(__fini_array);
	
	return rc;
}


hidesym int module_start_dummy(unsigned long long argl, void *argp) { return 0; }
hidesym int module_stop_dummy(unsigned long long argl, void *argp)  { return 0; }
hidesym void __cxa_finalize_dummy(void *dsoh) { }

void *__dso_handle = &__dso_handle;
