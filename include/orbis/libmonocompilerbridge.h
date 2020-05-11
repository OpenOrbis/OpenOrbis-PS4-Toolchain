#ifndef _SCE_MONO_COMPILER_BRIDGE_H_
#define _SCE_MONO_COMPILER_BRIDGE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void comm_init();
// Empty Comment
void g_array_append_vals();
// Empty Comment
void g_array_free();
// Empty Comment
void g_array_insert_vals();
// Empty Comment
void g_array_new();
// Empty Comment
void g_ascii_strcasecmp();
// Empty Comment
void g_ascii_strdown();
// Empty Comment
void g_ascii_strncasecmp();
// Empty Comment
void g_ascii_tolower();
// Empty Comment
void g_ascii_xdigit_value();
// Empty Comment
void g_assertion_message();
// Empty Comment
void g_build_path();
// Empty Comment
void g_clear_error();
// Empty Comment
void g_convert();
// Empty Comment
void g_dir_close();
// Empty Comment
void g_dir_open();
// Empty Comment
void g_dir_read_name();
// Empty Comment
void g_dir_rewind();
// Empty Comment
void g_direct_equal();
// Empty Comment
void g_direct_hash();
// Empty Comment
void g_error_free();
// Empty Comment
void g_file_get_contents();
// Empty Comment
void g_file_open_tmp();
// Empty Comment
void g_file_test();
// Empty Comment
void g_filename_from_uri();
// Empty Comment
void g_filename_from_utf8();
// Empty Comment
void g_filename_to_uri();
// Empty Comment
void g_find_program_in_path();
// Empty Comment
void g_free();
// Empty Comment
void g_get_charset();
// Empty Comment
void g_get_current_dir();
// Empty Comment
void g_get_home_dir();
// Empty Comment
void g_get_prgname();
// Empty Comment
void g_get_tmp_dir();
// Empty Comment
void g_get_user_name();
// Empty Comment
void g_getenv();
// Empty Comment
void g_hash_table_destroy();
// Empty Comment
void g_hash_table_foreach();
// Empty Comment
void g_hash_table_foreach_remove();
// Empty Comment
void g_hash_table_insert_replace();
// Empty Comment
void g_hash_table_iter_init();
// Empty Comment
void g_hash_table_iter_next();
// Empty Comment
void g_hash_table_lookup();
// Empty Comment
void g_hash_table_lookup_extended();
// Empty Comment
void g_hash_table_new();
// Empty Comment
void g_hash_table_new_full();
// Empty Comment
void g_hash_table_remove();
// Empty Comment
void g_hash_table_size();
// Empty Comment
void g_list_append();
// Empty Comment
void g_list_copy();
// Empty Comment
void g_list_delete_link();
// Empty Comment
void g_list_find();
// Empty Comment
void g_list_foreach();
// Empty Comment
void g_list_free();
// Empty Comment
void g_list_insert_before();
// Empty Comment
void g_list_insert_sorted();
// Empty Comment
void g_list_length();
// Empty Comment
void g_list_nth();
// Empty Comment
void g_list_nth_data();
// Empty Comment
void g_list_prepend();
// Empty Comment
void g_list_remove();
// Empty Comment
void g_list_remove_link();
// Empty Comment
void g_list_reverse();
// Empty Comment
void g_list_sort();
// Empty Comment
void g_locale_from_utf8();
// Empty Comment
void g_locale_to_utf8();
// Empty Comment
void g_log();
// Empty Comment
void g_log_set_always_fatal();
// Empty Comment
void g_log_set_fatal_mask();
// Empty Comment
void g_logv();
// Empty Comment
void g_malloc();
// Empty Comment
void g_malloc0();
// Empty Comment
void g_markup_parse_context_end_parse();
// Empty Comment
void g_markup_parse_context_free();
// Empty Comment
void g_markup_parse_context_new();
// Empty Comment
void g_markup_parse_context_parse();
// Empty Comment
void g_memdup();
// Empty Comment
void g_path_get_basename();
// Empty Comment
void g_path_get_dirname();
// Empty Comment
void g_path_is_absolute();
// Empty Comment
void g_print();
// Empty Comment
void g_printerr();
// Empty Comment
void g_ptr_array_add();
// Empty Comment
void g_ptr_array_free();
// Empty Comment
void g_ptr_array_new();
// Empty Comment
void g_ptr_array_remove();
// Empty Comment
void g_ptr_array_remove_fast();
// Empty Comment
void g_ptr_array_remove_index_fast();
// Empty Comment
void g_ptr_array_set_size();
// Empty Comment
void g_ptr_array_sized_new();
// Empty Comment
void g_ptr_array_sort();
// Empty Comment
void g_queue_free();
// Empty Comment
void g_queue_is_empty();
// Empty Comment
void g_queue_new();
// Empty Comment
void g_queue_pop_head();
// Empty Comment
void g_queue_push_head();
// Empty Comment
void g_realloc();
// Empty Comment
void g_set_prgname();
// Empty Comment
void g_setenv();
// Empty Comment
void g_shell_parse_argv();
// Empty Comment
void g_shell_quote();
// Empty Comment
void g_shell_unquote();
// Empty Comment
void g_slist_append();
// Empty Comment
void g_slist_concat();
// Empty Comment
void g_slist_copy();
// Empty Comment
void g_slist_delete_link();
// Empty Comment
void g_slist_find();
// Empty Comment
void g_slist_find_custom();
// Empty Comment
void g_slist_foreach();
// Empty Comment
void g_slist_free();
// Empty Comment
void g_slist_free_1();
// Empty Comment
void g_slist_insert_sorted();
// Empty Comment
void g_slist_length();
// Empty Comment
void g_slist_nth();
// Empty Comment
void g_slist_nth_data();
// Empty Comment
void g_slist_prepend();
// Empty Comment
void g_slist_remove();
// Empty Comment
void g_slist_reverse();
// Empty Comment
void g_snprintf();
// Empty Comment
void g_spaced_primes_closest();
// Empty Comment
void g_str_equal();
// Empty Comment
void g_str_has_prefix();
// Empty Comment
void g_str_has_suffix();
// Empty Comment
void g_str_hash();
// Empty Comment
void g_strchomp();
// Empty Comment
void g_strchug();
// Empty Comment
void g_strconcat();
// Empty Comment
void g_strdelimit();
// Empty Comment
void g_strdup();
// Empty Comment
void g_strdup_printf();
// Empty Comment
void g_strdup_vprintf();
// Empty Comment
void g_strerror();
// Empty Comment
void g_strfreev();
// Empty Comment
void g_string_append();
// Empty Comment
void g_string_append_c();
// Empty Comment
void g_string_append_len();
// Empty Comment
void g_string_append_printf();
// Empty Comment
void g_string_append_vprintf();
// Empty Comment
void g_string_free();
// Empty Comment
void g_string_new();
// Empty Comment
void g_string_new_len();
// Empty Comment
void g_string_printf();
// Empty Comment
void g_strjoin();
// Empty Comment
void g_strjoinv();
// Empty Comment
void g_strlcpy();
// Empty Comment
void g_strndup();
// Empty Comment
void g_strreverse();
// Empty Comment
void g_strsplit();
// Empty Comment
void g_timer_destroy();
// Empty Comment
void g_timer_elapsed();
// Empty Comment
void g_timer_new();
// Empty Comment
void g_timer_stop();
// Empty Comment
void g_try_malloc();
// Empty Comment
void g_try_realloc();
// Empty Comment
void g_unichar_tolower();
// Empty Comment
void g_unichar_type();
// Empty Comment
void g_unsetenv();
// Empty Comment
void g_usleep();
// Empty Comment
void g_utf16_to_utf8();
// Empty Comment
void g_utf8_strdown();
// Empty Comment
void g_utf8_to_utf16();
// Empty Comment
void g_utf8_validate();
// Empty Comment
void get_random();
// Empty Comment
void pss_code_mem_alloc();

#endif

#ifdef __cplusplus
}
#endif