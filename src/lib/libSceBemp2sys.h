#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void bemp2sys_logprintf_getlevel();
void bemp2sys_logprintf_setfunc();
void bemp2sys_logprintf_setlevel();
void bemp2sys_memmanager_set();
void bemp2sys_psdecoder_create();
void bemp2sys_psdecoder_destroy();
void bemp2sys_psdecoder_init();
void bemp2sys_psdecoder_readpacket();
void bemp2sys_psdecoder_release();
void bemp2sys_psdecoder_sendmessage();
void bemp2sys_tsdecoder_create();
void bemp2sys_tsdecoder_destroy();
void bemp2sys_tsdecoder_init();
void bemp2sys_tsdecoder_readpacket();
void bemp2sys_tsdecoder_release();
void bemp2sys_tsdecoder_sendmessage();
