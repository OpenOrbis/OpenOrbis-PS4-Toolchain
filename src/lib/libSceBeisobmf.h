#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void isobmf_box_getchildbox();
void isobmf_box_getdiskoffset();
void isobmf_box_getflags32b();
void isobmf_box_getmember_length();
void isobmf_box_getmember_ptr();
void isobmf_box_getmember_type();
void isobmf_box_getnextbox();
void isobmf_box_getstate();
void isobmf_box_gettype();
void isobmf_decoder_clear();
void isobmf_decoder_create();
void isobmf_decoder_decode();
void isobmf_decoder_destroy();
void isobmf_decoder_get_decoder_tree();
void isobmf_decoder_getquerydata();
void isobmf_decoder_next_disk_offset();
void isobmf_decoder_query();
void isobmf_memmanager_set();
