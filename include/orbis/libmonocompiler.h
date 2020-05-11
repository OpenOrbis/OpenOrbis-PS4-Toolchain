#ifndef _SCE_MONO_COMPILER_H_
#define _SCE_MONO_COMPILER_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void mini_create_jit_domain_info();
// Empty Comment
void mini_free_jit_domain_info();
// Empty Comment
void mono_arch_build_imt_thunk();
// Empty Comment
void mono_arch_clear_breakpoint();
// Empty Comment
void mono_arch_create_rgctx_lazy_fetch_trampoline();
// Empty Comment
void mono_arch_get_call_filter();
// Empty Comment
void mono_arch_get_restore_context();
// Empty Comment
void mono_arch_get_rethrow_exception();
// Empty Comment
void mono_arch_get_static_rgctx_trampoline();
// Empty Comment
void mono_arch_get_throw_exception();
// Empty Comment
void mono_arch_get_unbox_trampoline();
// Empty Comment
void mono_arch_init();
// Empty Comment
void mono_arch_set_breakpoint();
// Empty Comment
void mono_code_manager_new();
// Empty Comment
void mono_create_delegate_trampoline();
// Empty Comment
void mono_create_helper_signatures();
// Empty Comment
void mono_create_jit_trampoline();
// Empty Comment
void mono_create_jump_trampoline();
// Empty Comment
void mono_create_specific_trampoline();
// Empty Comment
void mono_defaults();
// Empty Comment
void mono_get_cached_unwind_info();
// Empty Comment
void mono_jit_compile_method();
// Empty Comment
void mono_jit_set_trace_options();
// Empty Comment
void mono_loader_init();
// Empty Comment
void mono_parse_default_optimizations();
// Empty Comment
void mono_perfcounters_init();
// Empty Comment
void mono_profiler_events();
// Empty Comment
void mono_profiler_set_events();
// Empty Comment
void mono_reflection_lookup_dynamic_token();
// Empty Comment
void mono_runtime_set_has_tls_get();
// Empty Comment
void mono_security_set_mode();
// Empty Comment
void mono_set_defaults();
// Empty Comment
void mono_threads_init();
// Empty Comment
void mono_trampolines_init();
// Empty Comment
void mono_verifier_set_mode();


#endif

#ifdef __cplusplus
}
#endif