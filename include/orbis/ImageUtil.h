#ifndef _SCE_IMAGE_UTIL_H_
#define _SCE_IMAGE_UTIL_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void __dso_handle();
// Empty Comment
void jcopy_block_row();
// Empty Comment
void jcopy_sample_rows();
// Empty Comment
void jdiv_round_up();
// Empty Comment
void jinit_1pass_quantizer();
// Empty Comment
void jinit_2pass_quantizer();
// Empty Comment
void jinit_arith_decoder();
// Empty Comment
void jinit_arith_encoder();
// Empty Comment
void jinit_c_coef_controller();
// Empty Comment
void jinit_c_main_controller();
// Empty Comment
void jinit_c_master_control();
// Empty Comment
void jinit_c_prep_controller();
// Empty Comment
void jinit_color_converter();
// Empty Comment
void jinit_color_deconverter();
// Empty Comment
void jinit_compress_master();
// Empty Comment
void jinit_d_coef_controller();
// Empty Comment
void jinit_d_main_controller();
// Empty Comment
void jinit_d_post_controller();
// Empty Comment
void jinit_downsampler();
// Empty Comment
void jinit_forward_dct();
// Empty Comment
void jinit_huff_decoder();
// Empty Comment
void jinit_huff_encoder();
// Empty Comment
void jinit_input_controller();
// Empty Comment
void jinit_inverse_dct();
// Empty Comment
void jinit_marker_reader();
// Empty Comment
void jinit_marker_writer();
// Empty Comment
void jinit_master_decompress();
// Empty Comment
void jinit_memory_mgr();
// Empty Comment
void jinit_merged_upsampler();
// Empty Comment
void jinit_upsampler();
// Empty Comment
void jpeg_abort();
// Empty Comment
void jpeg_abort_compress();
// Empty Comment
void jpeg_abort_decompress();
// Empty Comment
void jpeg_add_quant_table();
// Empty Comment
void jpeg_alloc_huff_table();
// Empty Comment
void jpeg_alloc_quant_table();
// Empty Comment
void jpeg_aritab();
// Empty Comment
void jpeg_calc_jpeg_dimensions();
// Empty Comment
void jpeg_calc_output_dimensions();
// Empty Comment
void jpeg_consume_input();
// Empty Comment
void jpeg_copy_critical_parameters();
// Empty Comment
void jpeg_core_output_dimensions();
// Empty Comment
void jpeg_CreateCompress();
// Empty Comment
void jpeg_CreateDecompress();
// Empty Comment
void jpeg_default_colorspace();
// Empty Comment
void jpeg_default_qtables();
// Empty Comment
void jpeg_destroy();
// Empty Comment
void jpeg_destroy_compress();
// Empty Comment
void jpeg_destroy_decompress();
// Empty Comment
void jpeg_fdct_float();
// Empty Comment
void jpeg_fdct_ifast();
// Empty Comment
void jpeg_fdct_islow();
// Empty Comment
void jpeg_finish_compress();
// Empty Comment
void jpeg_finish_decompress();
// Empty Comment
void jpeg_finish_output();
// Empty Comment
void jpeg_free_large();
// Empty Comment
void jpeg_free_small();
// Empty Comment
void jpeg_get_large();
// Empty Comment
void jpeg_get_small();
// Empty Comment
void jpeg_has_multiple_scans();
// Empty Comment
void jpeg_idct_10x10();
// Empty Comment
void jpeg_idct_11x11();
// Empty Comment
void jpeg_idct_12x12();
// Empty Comment
void jpeg_idct_13x13();
// Empty Comment
void jpeg_idct_14x14();
// Empty Comment
void jpeg_idct_15x15();
// Empty Comment
void jpeg_idct_16x16();
// Empty Comment
void jpeg_idct_1x1();
// Empty Comment
void jpeg_idct_2x2();
// Empty Comment
void jpeg_idct_3x3();
// Empty Comment
void jpeg_idct_4x4();
// Empty Comment
void jpeg_idct_5x5();
// Empty Comment
void jpeg_idct_6x6();
// Empty Comment
void jpeg_idct_7x7();
// Empty Comment
void jpeg_idct_9x9();
// Empty Comment
void jpeg_idct_float();
// Empty Comment
void jpeg_idct_ifast();
// Empty Comment
void jpeg_idct_islow();
// Empty Comment
void jpeg_input_complete();
// Empty Comment
void jpeg_mem_available();
// Empty Comment
void jpeg_mem_dest();
// Empty Comment
void jpeg_mem_init();
// Empty Comment
void jpeg_mem_src();
// Empty Comment
void jpeg_mem_term();
// Empty Comment
void jpeg_natural_order();
// Empty Comment
void jpeg_natural_order2();
// Empty Comment
void jpeg_natural_order3();
// Empty Comment
void jpeg_natural_order4();
// Empty Comment
void jpeg_natural_order5();
// Empty Comment
void jpeg_natural_order6();
// Empty Comment
void jpeg_natural_order7();
// Empty Comment
void jpeg_new_colormap();
// Empty Comment
void jpeg_open_backing_store();
// Empty Comment
void jpeg_quality_scaling();
// Empty Comment
void jpeg_read_coefficients();
// Empty Comment
void jpeg_read_header();
// Empty Comment
void jpeg_read_raw_data();
// Empty Comment
void jpeg_read_scanlines();
// Empty Comment
void jpeg_resync_to_restart();
// Empty Comment
void jpeg_save_markers();
// Empty Comment
void jpeg_set_colorspace();
// Empty Comment
void jpeg_set_defaults();
// Empty Comment
void jpeg_set_linear_quality();
// Empty Comment
void jpeg_set_marker_processor();
// Empty Comment
void jpeg_set_quality();
// Empty Comment
void jpeg_simple_progression();
// Empty Comment
void jpeg_start_compress();
// Empty Comment
void jpeg_start_decompress();
// Empty Comment
void jpeg_start_output();
// Empty Comment
void jpeg_std_error();
// Empty Comment
void jpeg_std_message_table();
// Empty Comment
void jpeg_stdio_dest();
// Empty Comment
void jpeg_stdio_src();
// Empty Comment
void jpeg_suppress_tables();
// Empty Comment
void jpeg_write_coefficients();
// Empty Comment
void jpeg_write_m_byte();
// Empty Comment
void jpeg_write_m_header();
// Empty Comment
void jpeg_write_marker();
// Empty Comment
void jpeg_write_raw_data();
// Empty Comment
void jpeg_write_scanlines();
// Empty Comment
void jpeg_write_tables();
// Empty Comment
void jround_up();
// Empty Comment
void jzero_far();


#endif

#ifdef __cplusplus
}
#endif