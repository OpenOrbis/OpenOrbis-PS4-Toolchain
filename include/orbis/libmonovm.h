#ifndef _SCE_MONO_VM_H_
#define _SCE_MONO_VM_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void _wapi_fileshare_layout();
// Empty Comment
void mini_get_debug_options();
// Empty Comment
void mono_add_internal_call();
// Empty Comment
void mono_aot_register_module();
// Empty Comment
void mono_array_addr_with_size();
// Empty Comment
void mono_array_element_size();
// Empty Comment
void mono_array_length();
// Empty Comment
void mono_assembly_get_image();
// Empty Comment
void mono_assembly_open_full();
// Empty Comment
void mono_class_from_name();
// Empty Comment
void mono_class_get_element_class();
// Empty Comment
void mono_class_get_fields();
// Empty Comment
void mono_class_get_method_from_name();
// Empty Comment
void mono_class_get_nesting_type();
// Empty Comment
void mono_class_get_type();
// Empty Comment
void mono_config_parse();
// Empty Comment
void mono_debug_init();
// Empty Comment
void mono_debugger_agent_parse_options();
// Empty Comment
void mono_delegate_free_ftnptr();
// Empty Comment
void mono_delegate_to_ftnptr();
// Empty Comment
void mono_dl_fallback_register();
// Empty Comment
void mono_domain_assembly_open();
// Empty Comment
void mono_domain_get();
// Empty Comment
void mono_environment_exitcode_get();
// Empty Comment
void mono_error_cleanup();
// Empty Comment
void mono_error_init();
// Empty Comment
void mono_error_ok();
// Empty Comment
void mono_field_get_flags();
// Empty Comment
void mono_field_get_type();
// Empty Comment
void mono_free();
// Empty Comment
void mono_gc_collect();
// Empty Comment
void mono_gc_collection_count();
// Empty Comment
void mono_gc_deregister_root();
// Empty Comment
void mono_gc_make_root_descr_user();
// Empty Comment
void mono_gc_max_generation();
// Empty Comment
void mono_gc_out_of_memory();
// Empty Comment
void mono_gc_register_root_wbarrier();
// Empty Comment
void mono_gc_walk_heap();
// Empty Comment
void mono_gc_wbarrier_generic_store();
// Empty Comment
void mono_get_exception_out_of_memory();
// Empty Comment
void mono_get_method();
// Empty Comment
void mono_get_trampoline_func();
// Empty Comment
void mono_image_get_entry_point();
// Empty Comment
void mono_jit_cleanup();
// Empty Comment
void mono_jit_exec();
// Empty Comment
void mono_jit_info_get_code_size();
// Empty Comment
void mono_jit_info_get_code_start();
// Empty Comment
void mono_jit_init();
// Empty Comment
void mono_jit_init_version();
// Empty Comment
void mono_jit_parse_options();
// Empty Comment
void mono_jit_set_aot_only();
// Empty Comment
void mono_loader_lock();
// Empty Comment
void mono_loader_unlock();
// Empty Comment
void mono_locks_dump();
// Empty Comment
void mono_main();
// Empty Comment
void mono_object_get_class();
// Empty Comment
void mono_object_get_size();
// Empty Comment
void mono_privileges_finish_init();
// Empty Comment
void mono_profiler_install();
// Empty Comment
void mono_profiler_install_allocation();
// Empty Comment
void mono_profiler_install_class();
// Empty Comment
void mono_profiler_install_enter_leave();
// Empty Comment
void mono_profiler_install_exception();
// Empty Comment
void mono_profiler_install_gc();
// Empty Comment
void mono_profiler_install_gc_moves();
// Empty Comment
void mono_profiler_install_gc_roots();
// Empty Comment
void mono_profiler_install_jit_compile();
// Empty Comment
void mono_profiler_install_jit_end();
// Empty Comment
void mono_profiler_install_module();
// Empty Comment
void mono_profiler_install_monitor();
// Empty Comment
void mono_profiler_install_runtime_initialized();
// Empty Comment
void mono_profiler_install_statistical();
// Empty Comment
void mono_profiler_install_thread();
// Empty Comment
void mono_profiler_install_thread_name();
// Empty Comment
void mono_profiler_load();
// Empty Comment
void mono_profiler_set_events();
// Empty Comment
void mono_raise_exception();
// Empty Comment
void mono_register_bundled_assemblies();
// Empty Comment
void mono_runtime_invoke();
// Empty Comment
void mono_runtime_quit();
// Empty Comment
void mono_runtime_resource_limit();
// Empty Comment
void mono_runtime_resource_set_callback();
// Empty Comment
void mono_runtime_run_main();
// Empty Comment
void mono_runtime_set_shutting_down();
// Empty Comment
void mono_security_enable_core_clr();
// Empty Comment
void mono_security_set_core_clr_platform_callback();
// Empty Comment
void mono_set_assemblies_path();
// Empty Comment
void mono_set_dirs();
// Empty Comment
void mono_stack_walk_no_il();
// Empty Comment
void mono_string_chars();
// Empty Comment
void mono_string_from_utf16();
// Empty Comment
void mono_string_length();
// Empty Comment
void mono_string_new();
// Empty Comment
void mono_string_new_wrapper();
// Empty Comment
void mono_string_to_utf8();
// Empty Comment
void mono_string_to_utf8_checked();
// Empty Comment
void mono_thread_attach();
// Empty Comment
void mono_thread_current();
// Empty Comment
void mono_thread_detach();
// Empty Comment
void mono_thread_suspend_all_other_threads();
// Empty Comment
void mono_threads_set_default_stacksize();
// Empty Comment
void mono_threads_set_shutting_down();
// Empty Comment
void mono_type_get_class();
// Empty Comment
void mono_type_get_type();
// Empty Comment
void mono_unhandled_exception();


#endif

#ifdef __cplusplus
}
#endif