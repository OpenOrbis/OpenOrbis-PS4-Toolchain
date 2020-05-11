#ifndef _SCE_ORBIS_COMPAT_H_
#define _SCE_ORBIS_COMPAT_H_

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
void _ZN3NTF10initializeERKNS_18CreationParametersE();
// Empty Comment
void _ZN3NTF13URLRequestJob6createEPNS_17URLRequestMessageEPNS_18URLRequestListenerE();
// Empty Comment
void _ZN3NTF14NetworkControl12getIPAddressEv();
// Empty Comment
void _ZN3NTF17URLRequestMessage14setSchedulerIdEi();
// Empty Comment
void _ZN3NTF17URLRequestMessage17setIsMainResourceEb();
// Empty Comment
void _ZN3NTF17URLRequestMessage8destructEPS0_();
// Empty Comment
void _ZN3NTF18CreationParametersC1Ev();
// Empty Comment
void _ZN3NTF18URLResponseMessage14getMessageTypeEv();
// Empty Comment
void _ZN3NTF21ResourceRequestLogger11isLoggerUrlEPKc();
// Empty Comment
void _ZN3NTF21ResourceRequestLogger9AdminPage4htmlEv();
// Empty Comment
void _ZN3NTF21ResourceRequestLogger9AdminPage4sizeEv();
// Empty Comment
void _ZN3NTF21ResourceRequestLogger9AdminPageC1EPKc();
// Empty Comment
void _ZN3NTF21ResourceRequestLogger9AdminPageD1Ev();
// Empty Comment
void _ZN3NTF21URLRequestDataMessage6createEv();
// Empty Comment
void _ZN3NTF21URLRequestFileMessage6createEv();
// Empty Comment
void _ZN3NTF21URLRequestHttpMessage6createEv();
// Empty Comment
void _ZN3NTF26URLRequestUndefinedMessage6createEv();
// Empty Comment
void _ZN3NTF5Cache16DiskCacheUtility9deleteAllEv();
// Empty Comment
void _ZN3NTF6Cookie11CookieJarDB11getInstanceEv();
// Empty Comment
void _ZN3NTF6Cookie11CookieJarDB9setEnableEb();
// Empty Comment
void _ZN3NTF7Privacy13setDoNotTrackEb();
// Empty Comment
void _ZN3NTF8finalizeEv();
// Empty Comment
void _ZN3sce10CanvasUtil11bindTextureEhPNS_13CanvasTextureE();
// Empty Comment
void _ZN3sce13CanvasTexture12createRGB565Eii();
// Empty Comment
void _ZN3sce13CanvasTexture14createRGBA8888Eii();
// Empty Comment
void _ZN3sce6Canvas6handleEh();
// Empty Comment
void _ZN3sce6Canvas9acquireIdEv();
// Empty Comment
void _ZN3sce6Canvas9releaseIdEh();
// Empty Comment
void _ZN4Manx10FontStream4openEPKcPv();
// Empty Comment
void _ZN4Manx10FontStream4readEPvjS1_();
// Empty Comment
void _ZN4Manx10FontStream4seekEjPv();
// Empty Comment
void _ZN4Manx10FontStream4sizeEPv();
// Empty Comment
void _ZN4Manx10FontStream5closeEPv();
// Empty Comment
void _ZN4Manx10FontStream6createEv();
// Empty Comment
void _ZN4Manx10FontStream7destroyEPv();
// Empty Comment
void _ZN4Manx11getFontDataEPKcPPvPj();
// Empty Comment
void _ZN4Manx11getFontNameEPKwjPKcRNS_17FontSynthesisHintE();
// Empty Comment
void _ZN4Manx11getFontPathEPKwj();
// Empty Comment
void _ZN4Manx11MediaPlayer12supportsTypeEPKcS2_();
// Empty Comment
void _ZN4Manx12getFontScaleEPKwj();
// Empty Comment
void _ZN4Manx15ProcessLauncher6launchEPKcPiS3_();
// Empty Comment
void _ZN4Manx17getBaselineOffsetEPKwj();
// Empty Comment
void _ZN4Manx18getDefaultFontPathEv();
// Empty Comment
void _ZN4Manx19getFontWeightOffsetEPKwj();
// Empty Comment
void _ZN4Manx21DisplayRefreshMonitor10waitVblankEv();
// Empty Comment
void _ZN4Manx21DisplayRefreshMonitor4stopEv();
// Empty Comment
void _ZN4Manx21DisplayRefreshMonitorC1Ev();
// Empty Comment
void _ZN4Manx21DisplayRefreshMonitorD1Ev();
// Empty Comment
void _ZN4Manx21getPlatformFamilyListEPKwj();
// Empty Comment
void _ZN4Manx27monotonicallyIncreasingTimeEv();
// Empty Comment
void _ZN4Manx6Bundle6createEv();
// Empty Comment
void _ZN4Manx6Screen14availableWidthEv();
// Empty Comment
void _ZN4Manx6Screen15availableHeightEv();
// Empty Comment
void _ZN4Manx6Screen5widthEv();
// Empty Comment
void _ZN4Manx6Screen6heightEv();
// Empty Comment
void _ZN4Manx6System19setVirtualRangeNameEPvmPKc();
// Empty Comment
void _ZN4Manx6System21defaultThreadPriorityEv();
// Empty Comment
void _ZN4Manx6System6osNameEv();
// Empty Comment
void _ZN4Manx7RunLoop3runEv();
// Empty Comment
void _ZN4Manx7RunLoop4initEv();
// Empty Comment
void _ZN4Manx7RunLoop4pollEv();
// Empty Comment
void _ZN4Manx7RunLoop7currentEv();
// Empty Comment
void _ZN4Manx8Gamepads6createEv();
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
void crc32();
// Empty Comment
void curl_easy_cleanup();
// Empty Comment
void curl_easy_getinfo();
// Empty Comment
void curl_easy_init();
// Empty Comment
void curl_easy_pause();
// Empty Comment
void curl_easy_perform();
// Empty Comment
void curl_easy_recv();
// Empty Comment
void curl_easy_reset();
// Empty Comment
void curl_easy_send();
// Empty Comment
void curl_easy_setopt();
// Empty Comment
void curl_easy_strerror();
// Empty Comment
void curl_global_cleanup();
// Empty Comment
void curl_global_init();
// Empty Comment
void curl_multi_add_handle();
// Empty Comment
void curl_multi_cleanup();
// Empty Comment
void curl_multi_fdset();
// Empty Comment
void curl_multi_info_read();
// Empty Comment
void curl_multi_init();
// Empty Comment
void curl_multi_perform();
// Empty Comment
void curl_multi_remove_handle();
// Empty Comment
void curl_multi_setopt();
// Empty Comment
void curl_multi_timeout();
// Empty Comment
void curl_share_cleanup();
// Empty Comment
void curl_share_init();
// Empty Comment
void curl_share_setopt();
// Empty Comment
void curl_slist_append();
// Empty Comment
void curl_slist_free_all();
// Empty Comment
void curl_version_info();
// Empty Comment
void deflate();
// Empty Comment
void deflateBound();
// Empty Comment
void deflateEnd();
// Empty Comment
void deflateInit2_();
// Empty Comment
void deflateReset();
// Empty Comment
void gethostbyname_r();
// Empty Comment
void inflate();
// Empty Comment
void inflateEnd();
// Empty Comment
void inflateInit_();
// Empty Comment
void inflateInit2_();
// Empty Comment
void inflateReset();
// Empty Comment
void pa_pop_marker();
// Empty Comment
void pa_push_marker();
// Empty Comment
void pa_sync();
// Empty Comment
void ShCompile();
// Empty Comment
void ShConstructCompiler();
// Empty Comment
void ShDestruct();
// Empty Comment
void ShGetActiveAttrib();
// Empty Comment
void ShGetActiveUniform();
// Empty Comment
void ShGetInfo();
// Empty Comment
void ShGetInfoLog();
// Empty Comment
void ShGetObjectCode();
// Empty Comment
void ShInitBuiltInResources();
// Empty Comment
void ShInitialize();
// Empty Comment
void uncompress();

#endif

#ifdef __cplusplus
}
#endif