#ifndef _SCE_WEBKIT_2_H_
#define _SCE_WEBKIT_2_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void cairo_create();
// Empty Comment
void cairo_destroy();
// Empty Comment
void cairo_fill();
// Empty Comment
void cairo_format_stride_for_width();
// Empty Comment
void cairo_image_surface_create_for_data();
// Empty Comment
void cairo_rectangle();
// Empty Comment
void cairo_set_source_rgba();
// Empty Comment
void cairo_surface_destroy();
// Empty Comment
void JSCheckScriptSyntax();
// Empty Comment
void JSClassCreate();
// Empty Comment
void JSClassRelease();
// Empty Comment
void JSClassRetain();
// Empty Comment
void JSContextCreateBacktrace();
// Empty Comment
void JSContextGetGlobalContext();
// Empty Comment
void JSContextGetGlobalObject();
// Empty Comment
void JSContextGetGroup();
// Empty Comment
void JSContextGroupCreate();
// Empty Comment
void JSContextGroupRelease();
// Empty Comment
void JSContextGroupRetain();
// Empty Comment
void JSEndProfiling();
// Empty Comment
void JSEvaluateScript();
// Empty Comment
void JSGarbageCollect();
// Empty Comment
void JSGlobalContextCreate();
// Empty Comment
void JSGlobalContextCreateInGroup();
// Empty Comment
void JSGlobalContextRelease();
// Empty Comment
void JSGlobalContextRetain();
// Empty Comment
void JSMemoryStatsQuerySCE();
// Empty Comment
void JSObjectCallAsConstructor();
// Empty Comment
void JSObjectCallAsFunction();
// Empty Comment
void JSObjectCopyPropertyNames();
// Empty Comment
void JSObjectDeletePrivateProperty();
// Empty Comment
void JSObjectDeleteProperty();
// Empty Comment
void JSObjectGetPrivate();
// Empty Comment
void JSObjectGetPrivateProperty();
// Empty Comment
void JSObjectGetProperty();
// Empty Comment
void JSObjectGetPropertyAtIndex();
// Empty Comment
void JSObjectGetPrototype();
// Empty Comment
void JSObjectHasProperty();
// Empty Comment
void JSObjectIsConstructor();
// Empty Comment
void JSObjectIsFunction();
// Empty Comment
void JSObjectMake();
// Empty Comment
void JSObjectMakeArray();
// Empty Comment
void JSObjectMakeConstructor();
// Empty Comment
void JSObjectMakeDate();
// Empty Comment
void JSObjectMakeError();
// Empty Comment
void JSObjectMakeFunction();
// Empty Comment
void JSObjectMakeFunctionWithCallback();
// Empty Comment
void JSObjectMakeRegExp();
// Empty Comment
void JSObjectSetPrivate();
// Empty Comment
void JSObjectSetPrivateProperty();
// Empty Comment
void JSObjectSetProperty();
// Empty Comment
void JSObjectSetPropertyAtIndex();
// Empty Comment
void JSObjectSetPrototype();
// Empty Comment
void JSPropertyNameAccumulatorAddName();
// Empty Comment
void JSPropertyNameArrayGetCount();
// Empty Comment
void JSPropertyNameArrayGetNameAtIndex();
// Empty Comment
void JSPropertyNameArrayRelease();
// Empty Comment
void JSPropertyNameArrayRetain();
// Empty Comment
void JSReportExtraMemoryCost();
// Empty Comment
void JSStartProfiling();
// Empty Comment
void JSStringCreateWithCharacters();
// Empty Comment
void JSStringCreateWithUTF8CString();
// Empty Comment
void JSStringGetCharactersPtr();
// Empty Comment
void JSStringGetLength();
// Empty Comment
void JSStringGetMaximumUTF8CStringSize();
// Empty Comment
void JSStringGetUTF8CString();
// Empty Comment
void JSStringIsEqual();
// Empty Comment
void JSStringIsEqualToUTF8CString();
// Empty Comment
void JSStringRelease();
// Empty Comment
void JSStringRetain();
// Empty Comment
void JSValueCreateJSONString();
// Empty Comment
void JSValueGetType();
// Empty Comment
void JSValueIsBoolean();
// Empty Comment
void JSValueIsEqual();
// Empty Comment
void JSValueIsInstanceOfConstructor();
// Empty Comment
void JSValueIsNull();
// Empty Comment
void JSValueIsNumber();
// Empty Comment
void JSValueIsObject();
// Empty Comment
void JSValueIsObjectOfClass();
// Empty Comment
void JSValueIsStrictEqual();
// Empty Comment
void JSValueIsString();
// Empty Comment
void JSValueIsUndefined();
// Empty Comment
void JSValueMakeBoolean();
// Empty Comment
void JSValueMakeFromJSONString();
// Empty Comment
void JSValueMakeNull();
// Empty Comment
void JSValueMakeNumber();
// Empty Comment
void JSValueMakeString();
// Empty Comment
void JSValueMakeUndefined();
// Empty Comment
void JSValueProtect();
// Empty Comment
void JSValueToBoolean();
// Empty Comment
void JSValueToNumber();
// Empty Comment
void JSValueToObject();
// Empty Comment
void JSValueToStringCopy();
// Empty Comment
void JSValueUnprotect();
// Empty Comment
void JSWeakObjectMapClear();
// Empty Comment
void JSWeakObjectMapCreate();
// Empty Comment
void JSWeakObjectMapGet();
// Empty Comment
void JSWeakObjectMapRemove();
// Empty Comment
void JSWeakObjectMapSet();
// Empty Comment
void WebProcessMainManx();
// Empty Comment
void WKAccessibilityFocusedObject();
// Empty Comment
void WKAccessibilityRootObject();
// Empty Comment
void WKApplicationCacheManagerDeleteAllEntries();
// Empty Comment
void WKApplicationCacheManagerDeleteEntriesForOrigin();
// Empty Comment
void WKApplicationCacheManagerGetApplicationCacheOrigins();
// Empty Comment
void WKApplicationCacheManagerGetTypeID();
// Empty Comment
void WKArrayAppendItem();
// Empty Comment
void WKArrayCreate();
// Empty Comment
void WKArrayGetItemAtIndex();
// Empty Comment
void WKArrayGetSize();
// Empty Comment
void WKArrayGetTypeID();
// Empty Comment
void WKArrayIsMutable();
// Empty Comment
void WKArrayRemoveItemAtIndex();
// Empty Comment
void WKAuthenticationChallengeGetDecisionListener();
// Empty Comment
void WKAuthenticationChallengeGetPreviousFailureCount();
// Empty Comment
void WKAuthenticationChallengeGetProposedCredential();
// Empty Comment
void WKAuthenticationChallengeGetProtectionSpace();
// Empty Comment
void WKAuthenticationChallengeGetTypeID();
// Empty Comment
void WKAuthenticationDecisionListenerCancel();
// Empty Comment
void WKAuthenticationDecisionListenerGetTypeID();
// Empty Comment
void WKAuthenticationDecisionListenerUseCredential();
// Empty Comment
void WKAXObjectButtonState();
// Empty Comment
void WKAXObjectDescription();
// Empty Comment
void WKAXObjectFrame();
// Empty Comment
void WKAXObjectGetTypeID();
// Empty Comment
void WKAXObjectHelpText();
// Empty Comment
void WKAXObjectPage();
// Empty Comment
void WKAXObjectRole();
// Empty Comment
void WKAXObjectTitle();
// Empty Comment
void WKAXObjectURL();
// Empty Comment
void WKBackForwardListCopyBackListWithLimit();
// Empty Comment
void WKBackForwardListCopyForwardListWithLimit();
// Empty Comment
void WKBackForwardListGetBackItem();
// Empty Comment
void WKBackForwardListGetBackListCount();
// Empty Comment
void WKBackForwardListGetCurrentItem();
// Empty Comment
void WKBackForwardListGetForwardItem();
// Empty Comment
void WKBackForwardListGetForwardListCount();
// Empty Comment
void WKBackForwardListGetItemAtIndex();
// Empty Comment
void WKBackForwardListGetTypeID();
// Empty Comment
void WKBackForwardListItemCopyOriginalURL();
// Empty Comment
void WKBackForwardListItemCopyTitle();
// Empty Comment
void WKBackForwardListItemCopyURL();
// Empty Comment
void WKBackForwardListItemGetTypeID();
// Empty Comment
void WKBooleanCreate();
// Empty Comment
void WKBooleanGetTypeID();
// Empty Comment
void WKBooleanGetValue();
// Empty Comment
void WKBundleActivateMacFontAscentHack();
// Empty Comment
void WKBundleAddOriginAccessWhitelistEntry();
// Empty Comment
void WKBundleAddUserScript();
// Empty Comment
void WKBundleAddUserStyleSheet();
// Empty Comment
void WKBundleBackForwardListClear();
// Empty Comment
void WKBundleBackForwardListCopyItemAtIndex();
// Empty Comment
void WKBundleBackForwardListGetBackListCount();
// Empty Comment
void WKBundleBackForwardListGetForwardListCount();
// Empty Comment
void WKBundleBackForwardListGetTypeID();
// Empty Comment
void WKBundleBackForwardListItemCopyChildren();
// Empty Comment
void WKBundleBackForwardListItemCopyOriginalURL();
// Empty Comment
void WKBundleBackForwardListItemCopyTarget();
// Empty Comment
void WKBundleBackForwardListItemCopyTitle();
// Empty Comment
void WKBundleBackForwardListItemCopyURL();
// Empty Comment
void WKBundleBackForwardListItemGetTypeID();
// Empty Comment
void WKBundleBackForwardListItemIsInPageCache();
// Empty Comment
void WKBundleBackForwardListItemIsSame();
// Empty Comment
void WKBundleBackForwardListItemIsTargetItem();
// Empty Comment
void WKBundleClearAllDatabases();
// Empty Comment
void WKBundleClearAllDiskcaches();
// Empty Comment
void WKBundleClearApplicationCache();
// Empty Comment
void WKBundleDOMWindowExtensionCreate();
// Empty Comment
void WKBundleDOMWindowExtensionGetFrame();
// Empty Comment
void WKBundleDOMWindowExtensionGetScriptWorld();
// Empty Comment
void WKBundleDOMWindowExtensionGetTypeID();
// Empty Comment
void WKBundleFrameAllowsFollowingLink();
// Empty Comment
void WKBundleFrameClearOpener();
// Empty Comment
void WKBundleFrameContainsAnyFormElements();
// Empty Comment
void WKBundleFrameConvertMonotonicTimeToDocumentTime();
// Empty Comment
void WKBundleFrameCopyCertificateInfo();
// Empty Comment
void WKBundleFrameCopyChildFrames();
// Empty Comment
void WKBundleFrameCopyCounterValue();
// Empty Comment
void WKBundleFrameCopyInnerText();
// Empty Comment
void WKBundleFrameCopyLayerTreeAsText();
// Empty Comment
void WKBundleFrameCopyMIMETypeForResourceWithURL();
// Empty Comment
void WKBundleFrameCopyName();
// Empty Comment
void WKBundleFrameCopyProvisionalURL();
// Empty Comment
void WKBundleFrameCopySuggestedFilenameForResourceWithURL();
// Empty Comment
void WKBundleFrameCopyURL();
// Empty Comment
void WKBundleFrameCopyWebArchive();
// Empty Comment
void WKBundleFrameCopyWebArchiveFilteringSubframes();
// Empty Comment
void WKBundleFrameEnableHTMLTile();
// Empty Comment
void WKBundleFrameForJavaScriptContext();
// Empty Comment
void WKBundleFrameGetACMemoryInfo();
// Empty Comment
void WKBundleFrameGetContentBounds();
// Empty Comment
void WKBundleFrameGetDocumentBackgroundColor();
// Empty Comment
void WKBundleFrameGetFrameLoadState();
// Empty Comment
void WKBundleFrameGetJavaScriptContext();
// Empty Comment
void WKBundleFrameGetJavaScriptContextForWorld();
// Empty Comment
void WKBundleFrameGetJavaScriptWrapperForNodeForWorld();
// Empty Comment
void WKBundleFrameGetJavaScriptWrapperForRangeForWorld();
// Empty Comment
void WKBundleFrameGetPage();
// Empty Comment
void WKBundleFrameGetParentFrame();
// Empty Comment
void WKBundleFrameGetPendingUnloadCount();
// Empty Comment
void WKBundleFrameGetScrollOffset();
// Empty Comment
void WKBundleFrameGetTypeID();
// Empty Comment
void WKBundleFrameGetVisibleContentBounds();
// Empty Comment
void WKBundleFrameGetVisibleContentBoundsExcludingScrollbars();
// Empty Comment
void WKBundleFrameHasHorizontalScrollbar();
// Empty Comment
void WKBundleFrameHasVerticalScrollbar();
// Empty Comment
void WKBundleFrameIsMainFrame();
// Empty Comment
void WKBundleFrameRegisterAsyncImageDecoder();
// Empty Comment
void WKBundleFrameSetTextDirection();
// Empty Comment
void WKBundleGarbageCollectJavaScriptObjects();
// Empty Comment
void WKBundleGarbageCollectJavaScriptObjectsOnAlternateThreadForDebugging();
// Empty Comment
void WKBundleGetApplicationConnection();
// Empty Comment
void WKBundleGetFastMallocStatistics();
// Empty Comment
void WKBundleGetJavaScriptHeapStatistics();
// Empty Comment
void WKBundleGetJavaScriptObjectsCount();
// Empty Comment
void WKBundleGetTypeID();
// Empty Comment
void WKBundleHitTestResultCopyAbsoluteImageURL();
// Empty Comment
void WKBundleHitTestResultCopyAbsoluteLinkURL();
// Empty Comment
void WKBundleHitTestResultCopyAbsoluteMediaURL();
// Empty Comment
void WKBundleHitTestResultCopyAbsolutePDFURL();
// Empty Comment
void WKBundleHitTestResultCopyLinkLabel();
// Empty Comment
void WKBundleHitTestResultCopyLinkTitle();
// Empty Comment
void WKBundleHitTestResultCopyNodeHandle();
// Empty Comment
void WKBundleHitTestResultGetFrame();
// Empty Comment
void WKBundleHitTestResultGetImageRect();
// Empty Comment
void WKBundleHitTestResultGetIsSelected();
// Empty Comment
void WKBundleHitTestResultGetTargetFrame();
// Empty Comment
void WKBundleHitTestResultGetTypeID();
// Empty Comment
void WKBundleInspectorClose();
// Empty Comment
void WKBundleInspectorEvaluateScriptForTest();
// Empty Comment
void WKBundleInspectorGetTypeID();
// Empty Comment
void WKBundleInspectorSetPageProfilingEnabled();
// Empty Comment
void WKBundleInspectorShow();
// Empty Comment
void WKBundleIsPageBoxVisible();
// Empty Comment
void WKBundleIsProcessingUserGesture();
// Empty Comment
void WKBundleNavigationActionCopyFormElement();
// Empty Comment
void WKBundleNavigationActionCopyHitTestResult();
// Empty Comment
void WKBundleNavigationActionGetEventModifiers();
// Empty Comment
void WKBundleNavigationActionGetEventMouseButton();
// Empty Comment
void WKBundleNavigationActionGetNavigationType();
// Empty Comment
void WKBundleNavigationActionGetTypeID();
// Empty Comment
void WKBundleNodeHandleCopyDocument();
// Empty Comment
void WKBundleNodeHandleCopyDocumentFrame();
// Empty Comment
void WKBundleNodeHandleCopyHTMLFrameElementContentFrame();
// Empty Comment
void WKBundleNodeHandleCopyHTMLIFrameElementContentFrame();
// Empty Comment
void WKBundleNodeHandleCopyHTMLTableCellElementCellAbove();
// Empty Comment
void WKBundleNodeHandleCreate();
// Empty Comment
void WKBundleNodeHandleGetElementBounds();
// Empty Comment
void WKBundleNodeHandleGetHTMLInputElementAutofilled();
// Empty Comment
void WKBundleNodeHandleGetHTMLInputElementLastChangeWasUserEdit();
// Empty Comment
void WKBundleNodeHandleGetHTMLTextAreaElementLastChangeWasUserEdit();
// Empty Comment
void WKBundleNodeHandleGetRenderRect();
// Empty Comment
void WKBundleNodeHandleGetTypeID();
// Empty Comment
void WKBundleNodeHandleSetHTMLInputElementAutofilled();
// Empty Comment
void WKBundleNodeHandleSetHTMLInputElementValueForUser();
// Empty Comment
void WKBundleNumberOfPages();
// Empty Comment
void WKBundleOverrideBoolPreferenceForTestRunner();
// Empty Comment
void WKBundlePageCanHandleRequest();
// Empty Comment
void WKBundlePageClearMainFrameName();
// Empty Comment
void WKBundlePageClose();
// Empty Comment
void WKBundlePageConfirmComposition();
// Empty Comment
void WKBundlePageConfirmCompositionWithText();
// Empty Comment
void WKBundlePageCopyRenderLayerTree();
// Empty Comment
void WKBundlePageCopyRenderTree();
// Empty Comment
void WKBundlePageCopyRenderTreeExternalRepresentation();
// Empty Comment
void WKBundlePageCopyTrackedRepaintRects();
// Empty Comment
void WKBundlePageCreateScaledSnapshotInDocumentCoordinates();
// Empty Comment
void WKBundlePageCreateSnapshotInDocumentCoordinates();
// Empty Comment
void WKBundlePageCreateSnapshotInViewCoordinates();
// Empty Comment
void WKBundlePageDidEnterFullScreen();
// Empty Comment
void WKBundlePageDidExitFullScreen();
// Empty Comment
void WKBundlePageExecuteEditingCommand();
// Empty Comment
void WKBundlePageFindString();
// Empty Comment
void WKBundlePageForceRepaint();
// Empty Comment
void WKBundlePageGetBackForwardList();
// Empty Comment
void WKBundlePageGetBackingScaleFactor();
// Empty Comment
void WKBundlePageGetInspector();
// Empty Comment
void WKBundlePageGetMainFrame();
// Empty Comment
void WKBundlePageGetPageGroup();
// Empty Comment
void WKBundlePageGetPageZoomFactor();
// Empty Comment
void WKBundlePageGetRenderTreeSize();
// Empty Comment
void WKBundlePageGetTextZoomFactor();
// Empty Comment
void WKBundlePageGetTypeID();
// Empty Comment
void WKBundlePageGroupCopyIdentifier();
// Empty Comment
void WKBundlePageGroupGetTypeID();
// Empty Comment
void WKBundlePageHasComposition();
// Empty Comment
void WKBundlePageHasLocalDataForURL();
// Empty Comment
void WKBundlePageInstallPageOverlay();
// Empty Comment
void WKBundlePageIsEditingCommandEnabled();
// Empty Comment
void WKBundlePageIsTrackingRepaints();
// Empty Comment
void WKBundlePageNumberForElementById();
// Empty Comment
void WKBundlePageOverlayCreate();
// Empty Comment
void WKBundlePageOverlayFractionFadedIn();
// Empty Comment
void WKBundlePageOverlayGetTypeID();
// Empty Comment
void WKBundlePageOverlaySetNeedsDisplay();
// Empty Comment
void WKBundlePageResetTrackedRepaints();
// Empty Comment
void WKBundlePageSetComposition();
// Empty Comment
void WKBundlePageSetContextMenuClient();
// Empty Comment
void WKBundlePageSetDefersLoading();
// Empty Comment
void WKBundlePageSetEditorClient();
// Empty Comment
void WKBundlePageSetFormClient();
// Empty Comment
void WKBundlePageSetFullScreenClient();
// Empty Comment
void WKBundlePageSetPageLoaderClient();
// Empty Comment
void WKBundlePageSetPageZoomFactor();
// Empty Comment
void WKBundlePageSetPaintedObjectsCounterThreshold();
// Empty Comment
void WKBundlePageSetPolicyClient();
// Empty Comment
void WKBundlePageSetResourceLoadClient();
// Empty Comment
void WKBundlePageSetScaleAtOrigin();
// Empty Comment
void WKBundlePageSetTextZoomFactor();
// Empty Comment
void WKBundlePageSetTracksRepaints();
// Empty Comment
void WKBundlePageSetUIClient();
// Empty Comment
void WKBundlePageSetUnderlayPage();
// Empty Comment
void WKBundlePageSimulateMouseDown();
// Empty Comment
void WKBundlePageSimulateMouseMotion();
// Empty Comment
void WKBundlePageSimulateMouseUp();
// Empty Comment
void WKBundlePageSizeAndMarginsInPixels();
// Empty Comment
void WKBundlePageStopLoading();
// Empty Comment
void WKBundlePageUninstallPageOverlay();
// Empty Comment
void WKBundlePageWillEnterFullScreen();
// Empty Comment
void WKBundlePageWillExitFullScreen();
// Empty Comment
void WKBundlePostMessage();
// Empty Comment
void WKBundlePostSynchronousMessage();
// Empty Comment
void WKBundleRangeHandleGetTypeID();
// Empty Comment
void WKBundleRemoveAllUserContent();
// Empty Comment
void WKBundleRemoveAllVisitedLinks();
// Empty Comment
void WKBundleRemoveOriginAccessWhitelistEntry();
// Empty Comment
void WKBundleRemoveUserScript();
// Empty Comment
void WKBundleRemoveUserScripts();
// Empty Comment
void WKBundleRemoveUserStyleSheet();
// Empty Comment
void WKBundleRemoveUserStyleSheets();
// Empty Comment
void WKBundleReportException();
// Empty Comment
void WKBundleResetOriginAccessWhitelists();
// Empty Comment
void WKBundleScriptWorldClearWrappers();
// Empty Comment
void WKBundleScriptWorldCreateWorld();
// Empty Comment
void WKBundleScriptWorldGetTypeID();
// Empty Comment
void WKBundleScriptWorldNormalWorld();
// Empty Comment
void WKBundleSetAllowFileAccessFromFileURLs();
// Empty Comment
void WKBundleSetAllowUniversalAccessFromFileURLs();
// Empty Comment
void WKBundleSetAppCacheMaximumSize();
// Empty Comment
void WKBundleSetAuthorAndUserStylesEnabled();
// Empty Comment
void WKBundleSetClient();
// Empty Comment
void WKBundleSetDatabaseQuota();
// Empty Comment
void WKBundleSetFrameFlatteningEnabled();
// Empty Comment
void WKBundleSetGarbageCollectClient();
// Empty Comment
void WKBundleSetJavaScriptCanAccessClipboard();
// Empty Comment
void WKBundleSetPopupBlockingEnabled();
// Empty Comment
void WKBundleSetPrivateBrowsingEnabled();
// Empty Comment
void WKBundleSetShouldTrackVisitedLinks();
// Empty Comment
void WKBundleShutdownProcess();
// Empty Comment
void WKBundleSwitchNetworkLoaderToNewTestingSession();
// Empty Comment
void WKCertificateInfoGetTypeID();
// Empty Comment
void WKConnectionGetTypeID();
// Empty Comment
void WKConnectionPostMessage();
// Empty Comment
void WKConnectionSetConnectionClient();
// Empty Comment
void WKContextAccessibilityEnabled();
// Empty Comment
void WKContextAddVisitedLink();
// Empty Comment
void WKContextCreate();
// Empty Comment
void WKContextCreateWithInjectedBundlePath();
// Empty Comment
void WKContextDisableProcessTermination();
// Empty Comment
void WKContextDownloadURLRequest();
// Empty Comment
void WKContextEnableAccessibility();
// Empty Comment
void WKContextEnableProcessTermination();
// Empty Comment
void WKContextGarbageCollectJavaScriptObjects();
// Empty Comment
void WKContextGetApplicationCacheManager();
// Empty Comment
void WKContextGetCacheModel();
// Empty Comment
void WKContextGetCookieManager();
// Empty Comment
void WKContextGetDatabaseManager();
// Empty Comment
void WKContextGetGeolocationManager();
// Empty Comment
void WKContextGetGlobalStatistics();
// Empty Comment
void WKContextGetIconDatabase();
// Empty Comment
void WKContextGetKeyValueStorageManager();
// Empty Comment
void WKContextGetMediaCacheManager();
// Empty Comment
void WKContextGetNotificationManager();
// Empty Comment
void WKContextGetPluginSiteDataManager();
// Empty Comment
void WKContextGetResourceCacheManager();
// Empty Comment
void WKContextGetStatistics();
// Empty Comment
void WKContextGetTypeID();
// Empty Comment
void WKContextMenuCopySubmenuItems();
// Empty Comment
void WKContextMenuItemCopyTitle();
// Empty Comment
void WKContextMenuItemCreateAsAction();
// Empty Comment
void WKContextMenuItemCreateAsCheckableAction();
// Empty Comment
void WKContextMenuItemCreateAsSubmenu();
// Empty Comment
void WKContextMenuItemGetChecked();
// Empty Comment
void WKContextMenuItemGetEnabled();
// Empty Comment
void WKContextMenuItemGetTag();
// Empty Comment
void WKContextMenuItemGetType();
// Empty Comment
void WKContextMenuItemGetTypeID();
// Empty Comment
void WKContextMenuItemGetUserData();
// Empty Comment
void WKContextMenuItemSeparatorItem();
// Empty Comment
void WKContextMenuItemSetUserData();
// Empty Comment
void WKContextPauseHTMLTiles();
// Empty Comment
void WKContextPostMessageToInjectedBundle();
// Empty Comment
void WKContextRegisterURLSchemeAsEmptyDocument();
// Empty Comment
void WKContextRegisterURLSchemeAsSecure();
// Empty Comment
void WKContextResumeHTMLTiles();
// Empty Comment
void WKContextSetAdditionalPluginsDirectory();
// Empty Comment
void WKContextSetAlwaysUsesComplexTextCodePath();
// Empty Comment
void WKContextSetCacheModel();
// Empty Comment
void WKContextSetConnectionClient();
// Empty Comment
void WKContextSetCookieMode();
// Empty Comment
void WKContextSetCookieStorageDirectory();
// Empty Comment
void WKContextSetDatabaseDirectory();
// Empty Comment
void WKContextSetDomainRelaxationForbiddenForURLScheme();
// Empty Comment
void WKContextSetDownloadClient();
// Empty Comment
void WKContextSetHistoryClient();
// Empty Comment
void WKContextSetHTTPPipeliningEnabled();
// Empty Comment
void WKContextSetHTTPProxy();
// Empty Comment
void WKContextSetIconDatabasePath();
// Empty Comment
void WKContextSetIFilterHTTPProxy();
// Empty Comment
void WKContextSetInitializationUserDataForInjectedBundle();
// Empty Comment
void WKContextSetInjectedBundleClient();
// Empty Comment
void WKContextSetLocalStorageDirectory();
// Empty Comment
void WKContextSetPrivilegedNetworkBandwidth();
// Empty Comment
void WKContextSetShouldUseFontSmoothing();
// Empty Comment
void WKContextSetSystemStorageDirectory();
// Empty Comment
void WKContextSetUserID();
// Empty Comment
void WKContextSetUserStorageDirectory();
// Empty Comment
void WKContextSetWebProcessPath();
// Empty Comment
void WKContextSetWebSecurityFilter();
// Empty Comment
void WKContextStartMemorySampler();
// Empty Comment
void WKContextStopMemorySampler();
// Empty Comment
void WKContextWarmInitialProcess();
// Empty Comment
void WKCookieManagerDeleteAllCookies();
// Empty Comment
void WKCookieManagerDeleteCookiesForHostname();
// Empty Comment
void WKCookieManagerGetHostnamesWithCookies();
// Empty Comment
void WKCookieManagerGetHTTPCookieAcceptPolicy();
// Empty Comment
void WKCookieManagerGetTypeID();
// Empty Comment
void WKCookieManagerSetClient();
// Empty Comment
void WKCookieManagerSetCookieForHostname();
// Empty Comment
void WKCookieManagerSetHTTPCookieAcceptPolicy();
// Empty Comment
void WKCookieManagerStartObservingCookieChanges();
// Empty Comment
void WKCookieManagerStopObservingCookieChanges();
// Empty Comment
void WKCredentialCopyUser();
// Empty Comment
void WKCredentialCreate();
// Empty Comment
void WKCredentialCreateWithCertificateInfo();
// Empty Comment
void WKCredentialGetTypeID();
// Empty Comment
void WKDatabaseManagerDeleteAllDatabases();
// Empty Comment
void WKDatabaseManagerDeleteDatabasesForOrigin();
// Empty Comment
void WKDatabaseManagerDeleteDatabasesWithNameForOrigin();
// Empty Comment
void WKDatabaseManagerGetDatabaseDetailsCurrentUsageKey();
// Empty Comment
void WKDatabaseManagerGetDatabaseDetailsDisplayNameKey();
// Empty Comment
void WKDatabaseManagerGetDatabaseDetailsExpectedUsageKey();
// Empty Comment
void WKDatabaseManagerGetDatabaseDetailsKey();
// Empty Comment
void WKDatabaseManagerGetDatabaseDetailsNameKey();
// Empty Comment
void WKDatabaseManagerGetDatabaseOrigins();
// Empty Comment
void WKDatabaseManagerGetDatabasesByOrigin();
// Empty Comment
void WKDatabaseManagerGetOriginKey();
// Empty Comment
void WKDatabaseManagerGetOriginQuotaKey();
// Empty Comment
void WKDatabaseManagerGetOriginUsageKey();
// Empty Comment
void WKDatabaseManagerGetTypeID();
// Empty Comment
void WKDatabaseManagerSetClient();
// Empty Comment
void WKDatabaseManagerSetQuotaForOrigin();
// Empty Comment
void WKDataCreate();
// Empty Comment
void WKDataGetBytes();
// Empty Comment
void WKDataGetSize();
// Empty Comment
void WKDataGetTypeID();
// Empty Comment
void WKDictionaryAddItem();
// Empty Comment
void WKDictionaryCopyKeys();
// Empty Comment
void WKDictionaryGetItemForKey();
// Empty Comment
void WKDictionaryGetSize();
// Empty Comment
void WKDictionaryGetTypeID();
// Empty Comment
void WKDictionaryIsMutable();
// Empty Comment
void WKDictionaryRemoveItem();
// Empty Comment
void WKDictionarySetItem();
// Empty Comment
void WKDoubleCreate();
// Empty Comment
void WKDoubleGetTypeID();
// Empty Comment
void WKDoubleGetValue();
// Empty Comment
void WKDownloadCancel();
// Empty Comment
void WKDownloadCopyRequest();
// Empty Comment
void WKDownloadGetResumeData();
// Empty Comment
void WKDownloadGetTypeID();
// Empty Comment
void WKErrorCopyDomain();
// Empty Comment
void WKErrorCopyFailingURL();
// Empty Comment
void WKErrorCopyLocalizedDescription();
// Empty Comment
void WKErrorCopySslVerificationResultString();
// Empty Comment
void WKErrorCopyWKErrorDomain();
// Empty Comment
void WKErrorGetErrorCode();
// Empty Comment
void WKErrorGetSslVerificationResult();
// Empty Comment
void WKErrorGetTypeID();
// Empty Comment
void WKFormSubmissionListenerContinue();
// Empty Comment
void WKFormSubmissionListenerGetTypeID();
// Empty Comment
void WKFrameCanProvideSource();
// Empty Comment
void WKFrameCanShowMIMEType();
// Empty Comment
void WKFrameCopyChildFrames();
// Empty Comment
void WKFrameCopyMIMEType();
// Empty Comment
void WKFrameCopyProvisionalURL();
// Empty Comment
void WKFrameCopyTitle();
// Empty Comment
void WKFrameCopyUnreachableURL();
// Empty Comment
void WKFrameCopyURL();
// Empty Comment
void WKFrameGetCertificateInfo();
// Empty Comment
void WKFrameGetFrameLoadState();
// Empty Comment
void WKFrameGetMainResourceData();
// Empty Comment
void WKFrameGetPage();
// Empty Comment
void WKFrameGetParentFrame();
// Empty Comment
void WKFrameGetResourceData();
// Empty Comment
void WKFrameGetTypeID();
// Empty Comment
void WKFrameGetWebArchive();
// Empty Comment
void WKFrameIsDisplayingMarkupDocument();
// Empty Comment
void WKFrameIsDisplayingStandaloneImageDocument();
// Empty Comment
void WKFrameIsFrameSet();
// Empty Comment
void WKFrameIsMainFrame();
// Empty Comment
void WKFramePolicyListenerDownload();
// Empty Comment
void WKFramePolicyListenerGetTypeID();
// Empty Comment
void WKFramePolicyListenerIgnore();
// Empty Comment
void WKFramePolicyListenerUse();
// Empty Comment
void WKFrameStopLoading();
// Empty Comment
void WKGeolocationManagerGetTypeID();
// Empty Comment
void WKGeolocationManagerProviderDidChangePosition();
// Empty Comment
void WKGeolocationManagerProviderDidFailToDeterminePosition();
// Empty Comment
void WKGeolocationManagerSetProvider();
// Empty Comment
void WKGeolocationPermissionRequestAllow();
// Empty Comment
void WKGeolocationPermissionRequestDeny();
// Empty Comment
void WKGeolocationPermissionRequestGetTypeID();
// Empty Comment
void WKGeolocationPositionCreate();
// Empty Comment
void WKGeolocationPositionGetTypeID();
// Empty Comment
void WKGetTypeID();
// Empty Comment
void WKGrammarDetailCopyGuesses();
// Empty Comment
void WKGrammarDetailCopyUserDescription();
// Empty Comment
void WKGrammarDetailCreate();
// Empty Comment
void WKGrammarDetailGetLength();
// Empty Comment
void WKGrammarDetailGetLocation();
// Empty Comment
void WKGrammarDetailGetTypeID();
// Empty Comment
void WKGraphicsContextGetTypeID();
// Empty Comment
void WKHitTestResultCopyAbsoluteImageURL();
// Empty Comment
void WKHitTestResultCopyAbsoluteLinkURL();
// Empty Comment
void WKHitTestResultCopyAbsoluteMediaURL();
// Empty Comment
void WKHitTestResultCopyAbsolutePDFURL();
// Empty Comment
void WKHitTestResultCopyLinkLabel();
// Empty Comment
void WKHitTestResultCopyLinkTitle();
// Empty Comment
void WKHitTestResultGetTypeID();
// Empty Comment
void WKIconDatabaseCheckIntegrityBeforeOpening();
// Empty Comment
void WKIconDatabaseClose();
// Empty Comment
void WKIconDatabaseEnableDatabaseCleanup();
// Empty Comment
void WKIconDatabaseGetTypeID();
// Empty Comment
void WKIconDatabaseReleaseIconForURL();
// Empty Comment
void WKIconDatabaseRemoveAllIcons();
// Empty Comment
void WKIconDatabaseRetainIconForURL();
// Empty Comment
void WKIconDatabaseSetIconDatabaseClient();
// Empty Comment
void WKImageCreate();
// Empty Comment
void WKImageCreateCairoSurface();
// Empty Comment
void WKImageGetSize();
// Empty Comment
void WKImageGetTypeID();
// Empty Comment
void WKInspectorAttach();
// Empty Comment
void WKInspectorClose();
// Empty Comment
void WKInspectorDetach();
// Empty Comment
void WKInspectorGetPage();
// Empty Comment
void WKInspectorGetTypeID();
// Empty Comment
void WKInspectorIsAttached();
// Empty Comment
void WKInspectorIsDebuggingJavaScript();
// Empty Comment
void WKInspectorIsFront();
// Empty Comment
void WKInspectorIsProfilingJavaScript();
// Empty Comment
void WKInspectorIsProfilingPage();
// Empty Comment
void WKInspectorIsVisible();
// Empty Comment
void WKInspectorShow();
// Empty Comment
void WKInspectorShowConsole();
// Empty Comment
void WKInspectorShowMainResourceForFrame();
// Empty Comment
void WKInspectorShowResources();
// Empty Comment
void WKInspectorToggleJavaScriptDebugging();
// Empty Comment
void WKInspectorToggleJavaScriptProfiling();
// Empty Comment
void WKInspectorTogglePageProfiling();
// Empty Comment
void WKKeyValueStorageManagerDeleteAllEntries();
// Empty Comment
void WKKeyValueStorageManagerDeleteEntriesForOrigin();
// Empty Comment
void WKKeyValueStorageManagerGetKeyValueStorageOrigins();
// Empty Comment
void WKKeyValueStorageManagerGetTypeID();
// Empty Comment
void WKMediaCacheManagerClearCacheForAllHostnames();
// Empty Comment
void WKMediaCacheManagerClearCacheForHostname();
// Empty Comment
void WKMediaCacheManagerGetHostnamesWithMediaCache();
// Empty Comment
void WKMediaCacheManagerGetTypeID();
// Empty Comment
void WKMutableArrayCreate();
// Empty Comment
void WKMutableDictionaryCreate();
// Empty Comment
void WKNavigationDataCopyOriginalRequest();
// Empty Comment
void WKNavigationDataCopyTitle();
// Empty Comment
void WKNavigationDataCopyURL();
// Empty Comment
void WKNavigationDataGetTypeID();
// Empty Comment
void WKNotificationCopyBody();
// Empty Comment
void WKNotificationCopyIconURL();
// Empty Comment
void WKNotificationCopyTag();
// Empty Comment
void WKNotificationCopyTitle();
// Empty Comment
void WKNotificationGetID();
// Empty Comment
void WKNotificationGetSecurityOrigin();
// Empty Comment
void WKNotificationGetTypeID();
// Empty Comment
void WKNotificationManagerGetTypeID();
// Empty Comment
void WKNotificationManagerProviderDidClickNotification();
// Empty Comment
void WKNotificationManagerProviderDidCloseNotifications();
// Empty Comment
void WKNotificationManagerProviderDidRemoveNotificationPolicies();
// Empty Comment
void WKNotificationManagerProviderDidShowNotification();
// Empty Comment
void WKNotificationManagerProviderDidUpdateNotificationPolicy();
// Empty Comment
void WKNotificationManagerSetProvider();
// Empty Comment
void WKNotificationPermissionRequestAllow();
// Empty Comment
void WKNotificationPermissionRequestDeny();
// Empty Comment
void WKNotificationPermissionRequestGetTypeID();
// Empty Comment
void WKOpenPanelParametersCopyAcceptedMIMETypes();
// Empty Comment
void WKOpenPanelParametersGetAllowsMultipleFiles();
// Empty Comment
void WKOpenPanelParametersGetTypeID();
// Empty Comment
void WKOpenPanelResultListenerCancel();
// Empty Comment
void WKOpenPanelResultListenerChooseFiles();
// Empty Comment
void WKOpenPanelResultListenerGetTypeID();
// Empty Comment
void WKPageBlurFocusedNode();
// Empty Comment
void WKPageCanDelete();
// Empty Comment
void WKPageCanGoBack();
// Empty Comment
void WKPageCanGoForward();
// Empty Comment
void WKPageCenterSelectionInVisibleArea();
// Empty Comment
void WKPageClose();
// Empty Comment
void WKPageCopyActiveURL();
// Empty Comment
void WKPageCopyApplicationNameForUserAgent();
// Empty Comment
void WKPageCopyCommittedURL();
// Empty Comment
void WKPageCopyCustomTextEncodingName();
// Empty Comment
void WKPageCopyCustomUserAgent();
// Empty Comment
void WKPageCopyPendingAPIRequestURL();
// Empty Comment
void WKPageCopyProvisionalURL();
// Empty Comment
void WKPageCopySessionState();
// Empty Comment
void WKPageCopyStandardUserAgentWithApplicationName();
// Empty Comment
void WKPageCopyTitle();
// Empty Comment
void WKPageCopyUserAgent();
// Empty Comment
void WKPageCountStringMatches();
// Empty Comment
void WKPageCreateSnapshotOfVisibleContent();
// Empty Comment
void WKPageExecuteCommand();
// Empty Comment
void WKPageFindString();
// Empty Comment
void WKPageFixedLayoutSize();
// Empty Comment
void WKPageForceRepaint();
// Empty Comment
void WKPageGetAcceleratedCompositingBackgroundColor();
// Empty Comment
void WKPageGetBackForwardList();
// Empty Comment
void WKPageGetBackingScaleFactor();
// Empty Comment
void WKPageGetContentsAsString();
// Empty Comment
void WKPageGetContext();
// Empty Comment
void WKPageGetDebugPaintFlags();
// Empty Comment
void WKPageGetEstimatedProgress();
// Empty Comment
void WKPageGetFocusedFrame();
// Empty Comment
void WKPageGetFrameSetLargestFrame();
// Empty Comment
void WKPageGetGapBetweenPages();
// Empty Comment
void WKPageGetInspector();
// Empty Comment
void WKPageGetMainFrame();
// Empty Comment
void WKPageGetPageCount();
// Empty Comment
void WKPageGetPageGroup();
// Empty Comment
void WKPageGetPageLength();
// Empty Comment
void WKPageGetPageZoomFactor();
// Empty Comment
void WKPageGetPaginationBehavesLikeColumns();
// Empty Comment
void WKPageGetPaginationMode();
// Empty Comment
void WKPageGetProcessIdentifier();
// Empty Comment
void WKPageGetRenderTreeSize();
// Empty Comment
void WKPageGetScaleFactor();
// Empty Comment
void WKPageGetSessionHistoryURLValueType();
// Empty Comment
void WKPageGetSourceForFrame();
// Empty Comment
void WKPageGetTextZoomFactor();
// Empty Comment
void WKPageGetTypeID();
// Empty Comment
void WKPageGoBack();
// Empty Comment
void WKPageGoForward();
// Empty Comment
void WKPageGoToBackForwardListItem();
// Empty Comment
void WKPageGroupCopyIdentifier();
// Empty Comment
void WKPageGroupCreateWithIdentifier();
// Empty Comment
void WKPageGroupGetPreferences();
// Empty Comment
void WKPageGroupGetTypeID();
// Empty Comment
void WKPageGroupSetPreferences();
// Empty Comment
void WKPageHasHorizontalScrollbar();
// Empty Comment
void WKPageHasSelectedRange();
// Empty Comment
void WKPageHasVerticalScrollbar();
// Empty Comment
void WKPageHideFindUI();
// Empty Comment
void WKPageIsClosed();
// Empty Comment
void WKPageIsContentEditable();
// Empty Comment
void WKPageIsPinnedToLeftSide();
// Empty Comment
void WKPageIsPinnedToRightSide();
// Empty Comment
void WKPageLoadAlternateHTMLString();
// Empty Comment
void WKPageLoadData();
// Empty Comment
void WKPageLoadHTMLString();
// Empty Comment
void WKPageLoadPlainTextString();
// Empty Comment
void WKPageLoadURL();
// Empty Comment
void WKPageLoadURLRequest();
// Empty Comment
void WKPageLoadWebArchiveData();
// Empty Comment
void WKPageReload();
// Empty Comment
void WKPageReloadFromOrigin();
// Empty Comment
void WKPageRenderTreeExternalRepresentation();
// Empty Comment
void WKPageRestoreFromSessionState();
// Empty Comment
void WKPageResumeActiveDOMObjectsAndAnimations();
// Empty Comment
void WKPageRunJavaScriptInMainFrame();
// Empty Comment
void WKPageRunJavaScriptInMainFrameAndReturnString();
// Empty Comment
void WKPageSetApplicationNameForUserAgent();
// Empty Comment
void WKPageSetCaretVisible();
// Empty Comment
void WKPageSetCustomBackingScaleFactor();
// Empty Comment
void WKPageSetCustomTextEncodingName();
// Empty Comment
void WKPageSetCustomUserAgent();
// Empty Comment
void WKPageSetDebugPaintFlags();
// Empty Comment
void WKPageSetFixedLayoutSize();
// Empty Comment
void WKPageSetGapBetweenPages();
// Empty Comment
void WKPageSetMaintainsInactiveSelection();
// Empty Comment
void WKPageSetMediaVolume();
// Empty Comment
void WKPageSetMemoryCacheClientCallsEnabled();
// Empty Comment
void WKPageSetPageAndTextZoomFactors();
// Empty Comment
void WKPageSetPageContextMenuClient();
// Empty Comment
void WKPageSetPageFindClient();
// Empty Comment
void WKPageSetPageFormClient();
// Empty Comment
void WKPageSetPageLength();
// Empty Comment
void WKPageSetPageLoaderClient();
// Empty Comment
void WKPageSetPagePolicyClient();
// Empty Comment
void WKPageSetPageUIClient();
// Empty Comment
void WKPageSetPageZoomFactor();
// Empty Comment
void WKPageSetPaginationBehavesLikeColumns();
// Empty Comment
void WKPageSetPaginationMode();
// Empty Comment
void WKPageSetScaleFactor();
// Empty Comment
void WKPageSetScaleFactorKeepingScrollOffset();
// Empty Comment
void WKPageSetShouldSendEventsSynchronously();
// Empty Comment
void WKPageSetTextZoomFactor();
// Empty Comment
void WKPageSetUseFixedLayout();
// Empty Comment
void WKPageStopLoading();
// Empty Comment
void WKPageSupportsTextEncoding();
// Empty Comment
void WKPageSupportsTextZoom();
// Empty Comment
void WKPageSuspendActiveDOMObjectsAndAnimations();
// Empty Comment
void WKPageTerminate();
// Empty Comment
void WKPageTryClose();
// Empty Comment
void WKPageTryRestoreScrollPosition();
// Empty Comment
void WKPageUseFixedLayout();
// Empty Comment
void WKPageValidateCommand();
// Empty Comment
void WKPageWillHandleHorizontalScrollEvents();
// Empty Comment
void WKPluginSiteDataManagerClearAllSiteData();
// Empty Comment
void WKPluginSiteDataManagerClearSiteData();
// Empty Comment
void WKPluginSiteDataManagerGetSitesWithData();
// Empty Comment
void WKPluginSiteDataManagerGetTypeID();
// Empty Comment
void WKPointCreate();
// Empty Comment
void WKPointGetTypeID();
// Empty Comment
void WKPointGetValue();
// Empty Comment
void WKPopupMenuItemCopyText();
// Empty Comment
void WKPopupMenuItemGetTypeID();
// Empty Comment
void WKPopupMenuItemIsEnabled();
// Empty Comment
void WKPopupMenuItemIsItem();
// Empty Comment
void WKPopupMenuItemIsSeparator();
// Empty Comment
void WKPreferencesCopyCursiveFontFamily();
// Empty Comment
void WKPreferencesCopyDefaultTextEncodingName();
// Empty Comment
void WKPreferencesCopyFantasyFontFamily();
// Empty Comment
void WKPreferencesCopyFixedFontFamily();
// Empty Comment
void WKPreferencesCopyFTPDirectoryTemplatePath();
// Empty Comment
void WKPreferencesCopyPictographFontFamily();
// Empty Comment
void WKPreferencesCopySansSerifFontFamily();
// Empty Comment
void WKPreferencesCopySerifFontFamily();
// Empty Comment
void WKPreferencesCopyStandardFontFamily();
// Empty Comment
void WKPreferencesCreate();
// Empty Comment
void WKPreferencesCreateCopy();
// Empty Comment
void WKPreferencesCreateWithIdentifier();
// Empty Comment
void WKPreferencesGetAcceleratedCompositingEnabled();
// Empty Comment
void WKPreferencesGetAcceleratedDrawingEnabled();
// Empty Comment
void WKPreferencesGetApplicationChromeModeEnabled();
// Empty Comment
void WKPreferencesGetAuthorAndUserStylesEnabled();
// Empty Comment
void WKPreferencesGetAVFoundationEnabled();
// Empty Comment
void WKPreferencesGetBackspaceKeyNavigationEnabled();
// Empty Comment
void WKPreferencesGetCanvasUsesAcceleratedDrawing();
// Empty Comment
void WKPreferencesGetCaretBrowsingEnabled();
// Empty Comment
void WKPreferencesGetCompositingBordersVisible();
// Empty Comment
void WKPreferencesGetCompositingRepaintCountersVisible();
// Empty Comment
void WKPreferencesGetCookieEnabled();
// Empty Comment
void WKPreferencesGetCoverAreaMultiplier();
// Empty Comment
void WKPreferencesGetCSSCustomFilterEnabled();
// Empty Comment
void WKPreferencesGetCSSRegionsEnabled();
// Empty Comment
void WKPreferencesGetDatabasesEnabled();
// Empty Comment
void WKPreferencesGetDefaultFixedFontSize();
// Empty Comment
void WKPreferencesGetDefaultFontSize();
// Empty Comment
void WKPreferencesGetDeveloperExtrasEnabled();
// Empty Comment
void WKPreferencesGetDNSPrefetchingEnabled();
// Empty Comment
void WKPreferencesGetDOMPasteAllowed();
// Empty Comment
void WKPreferencesGetDoNotTrack();
// Empty Comment
void WKPreferencesGetEditableLinkBehavior();
// Empty Comment
void WKPreferencesGetEncodingDetectorEnabled();
// Empty Comment
void WKPreferencesGetFileAccessFromFileURLsAllowed();
// Empty Comment
void WKPreferencesGetFontSmoothingLevel();
// Empty Comment
void WKPreferencesGetForceEnableVideo();
// Empty Comment
void WKPreferencesGetForceFTPDirectoryListings();
// Empty Comment
void WKPreferencesGetFrameFlatteningEnabled();
// Empty Comment
void WKPreferencesGetFullScreenEnabled();
// Empty Comment
void WKPreferencesGetHixie76WebSocketProtocolEnabled();
// Empty Comment
void WKPreferencesGetHyperlinkAuditingEnabled();
// Empty Comment
void WKPreferencesGetInspectorUsesWebKitUserInterface();
// Empty Comment
void WKPreferencesGetJavaEnabled();
// Empty Comment
void WKPreferencesGetJavaEnabledForLocalFiles();
// Empty Comment
void WKPreferencesGetJavaScriptCanAccessClipboard();
// Empty Comment
void WKPreferencesGetJavaScriptCanOpenWindowsAutomatically();
// Empty Comment
void WKPreferencesGetJavaScriptEnabled();
// Empty Comment
void WKPreferencesGetLoadsImagesAutomatically();
// Empty Comment
void WKPreferencesGetLoadsSiteIconsIgnoringImageLoadingPreference();
// Empty Comment
void WKPreferencesGetLocalFileContentSniffingEnabled();
// Empty Comment
void WKPreferencesGetLocalStorageEnabled();
// Empty Comment
void WKPreferencesGetMediaPlaybackAllowsInline();
// Empty Comment
void WKPreferencesGetMediaPlaybackRequiresUserGesture();
// Empty Comment
void WKPreferencesGetMinimumFontSize();
// Empty Comment
void WKPreferencesGetMockScrollbarsEnabled();
// Empty Comment
void WKPreferencesGetNeedsSiteSpecificQuirks();
// Empty Comment
void WKPreferencesGetNotificationsEnabled();
// Empty Comment
void WKPreferencesGetOfflineWebApplicationCacheEnabled();
// Empty Comment
void WKPreferencesGetPageCacheEnabled();
// Empty Comment
void WKPreferencesGetPageCacheSupportsPlugins();
// Empty Comment
void WKPreferencesGetPaginateDuringLayoutEnabled();
// Empty Comment
void WKPreferencesGetPluginsEnabled();
// Empty Comment
void WKPreferencesGetPrivateBrowsingEnabled();
// Empty Comment
void WKPreferencesGetRegionBasedColumnsEnabled();
// Empty Comment
void WKPreferencesGetShouldDisplayCaptions();
// Empty Comment
void WKPreferencesGetShouldDisplaySubtitles();
// Empty Comment
void WKPreferencesGetShouldDisplayTextDescriptions();
// Empty Comment
void WKPreferencesGetShouldPrintBackgrounds();
// Empty Comment
void WKPreferencesGetShouldRespectImageOrientation();
// Empty Comment
void WKPreferencesGetShowsToolTipOverTruncatedText();
// Empty Comment
void WKPreferencesGetSuppressesIncrementalRendering();
// Empty Comment
void WKPreferencesGetTabsToLinks();
// Empty Comment
void WKPreferencesGetTextAreasAreResizable();
// Empty Comment
void WKPreferencesGetTypeID();
// Empty Comment
void WKPreferencesGetUniversalAccessFromFileURLsAllowed();
// Empty Comment
void WKPreferencesGetWebArchiveDebugModeEnabled();
// Empty Comment
void WKPreferencesGetWebAudioEnabled();
// Empty Comment
void WKPreferencesGetWebGLEnabled();
// Empty Comment
void WKPreferencesGetWebSecurityEnabled();
// Empty Comment
void WKPreferencesGetXSSAuditorEnabled();
// Empty Comment
void WKPreferencesResetTestRunnerOverrides();
// Empty Comment
void WKPreferencesSetAcceleratedCompositingEnabled();
// Empty Comment
void WKPreferencesSetAcceleratedDrawingEnabled();
// Empty Comment
void WKPreferencesSetApplicationChromeModeEnabled();
// Empty Comment
void WKPreferencesSetAuthorAndUserStylesEnabled();
// Empty Comment
void WKPreferencesSetAVFoundationEnabled();
// Empty Comment
void WKPreferencesSetBackspaceKeyNavigationEnabled();
// Empty Comment
void WKPreferencesSetCanvasUsesAcceleratedDrawing();
// Empty Comment
void WKPreferencesSetCaretBrowsingEnabled();
// Empty Comment
void WKPreferencesSetCompositingBordersVisible();
// Empty Comment
void WKPreferencesSetCompositingRepaintCountersVisible();
// Empty Comment
void WKPreferencesSetCookieEnabled();
// Empty Comment
void WKPreferencesSetCoverAreaMultiplier();
// Empty Comment
void WKPreferencesSetCSSCustomFilterEnabled();
// Empty Comment
void WKPreferencesSetCSSRegionsEnabled();
// Empty Comment
void WKPreferencesSetCursiveFontFamily();
// Empty Comment
void WKPreferencesSetDatabasesEnabled();
// Empty Comment
void WKPreferencesSetDefaultFixedFontSize();
// Empty Comment
void WKPreferencesSetDefaultFontSize();
// Empty Comment
void WKPreferencesSetDefaultTextEncodingName();
// Empty Comment
void WKPreferencesSetDeveloperExtrasEnabled();
// Empty Comment
void WKPreferencesSetDNSPrefetchingEnabled();
// Empty Comment
void WKPreferencesSetDOMPasteAllowed();
// Empty Comment
void WKPreferencesSetDoNotTrack();
// Empty Comment
void WKPreferencesSetEditableLinkBehavior();
// Empty Comment
void WKPreferencesSetEncodingDetectorEnabled();
// Empty Comment
void WKPreferencesSetFantasyFontFamily();
// Empty Comment
void WKPreferencesSetFileAccessFromFileURLsAllowed();
// Empty Comment
void WKPreferencesSetFixedFontFamily();
// Empty Comment
void WKPreferencesSetFontSmoothingLevel();
// Empty Comment
void WKPreferencesSetForceEnableVideo();
// Empty Comment
void WKPreferencesSetForceFTPDirectoryListings();
// Empty Comment
void WKPreferencesSetFrameFlatteningEnabled();
// Empty Comment
void WKPreferencesSetFTPDirectoryTemplatePath();
// Empty Comment
void WKPreferencesSetFullScreenEnabled();
// Empty Comment
void WKPreferencesSetHixie76WebSocketProtocolEnabled();
// Empty Comment
void WKPreferencesSetHyperlinkAuditingEnabled();
// Empty Comment
void WKPreferencesSetInspectorUsesWebKitUserInterface();
// Empty Comment
void WKPreferencesSetJavaEnabled();
// Empty Comment
void WKPreferencesSetJavaEnabledForLocalFiles();
// Empty Comment
void WKPreferencesSetJavaScriptCanAccessClipboard();
// Empty Comment
void WKPreferencesSetJavaScriptCanOpenWindowsAutomatically();
// Empty Comment
void WKPreferencesSetJavaScriptEnabled();
// Empty Comment
void WKPreferencesSetLoadsImagesAutomatically();
// Empty Comment
void WKPreferencesSetLoadsSiteIconsIgnoringImageLoadingPreference();
// Empty Comment
void WKPreferencesSetLocalFileContentSniffingEnabled();
// Empty Comment
void WKPreferencesSetLocalStorageEnabled();
// Empty Comment
void WKPreferencesSetMediaPlaybackAllowsInline();
// Empty Comment
void WKPreferencesSetMediaPlaybackRequiresUserGesture();
// Empty Comment
void WKPreferencesSetMinimumFontSize();
// Empty Comment
void WKPreferencesSetMockScrollbarsEnabled();
// Empty Comment
void WKPreferencesSetNeedsSiteSpecificQuirks();
// Empty Comment
void WKPreferencesSetNotificationsEnabled();
// Empty Comment
void WKPreferencesSetOfflineWebApplicationCacheEnabled();
// Empty Comment
void WKPreferencesSetPageCacheEnabled();
// Empty Comment
void WKPreferencesSetPageCacheSupportsPlugins();
// Empty Comment
void WKPreferencesSetPaginateDuringLayoutEnabled();
// Empty Comment
void WKPreferencesSetPictographFontFamily();
// Empty Comment
void WKPreferencesSetPluginsEnabled();
// Empty Comment
void WKPreferencesSetPrivateBrowsingEnabled();
// Empty Comment
void WKPreferencesSetRegionBasedColumnsEnabled();
// Empty Comment
void WKPreferencesSetSansSerifFontFamily();
// Empty Comment
void WKPreferencesSetSerifFontFamily();
// Empty Comment
void WKPreferencesSetShouldDisplayCaptions();
// Empty Comment
void WKPreferencesSetShouldDisplaySubtitles();
// Empty Comment
void WKPreferencesSetShouldDisplayTextDescriptions();
// Empty Comment
void WKPreferencesSetShouldPrintBackgrounds();
// Empty Comment
void WKPreferencesSetShouldRespectImageOrientation();
// Empty Comment
void WKPreferencesSetShowsToolTipOverTruncatedText();
// Empty Comment
void WKPreferencesSetStandardFontFamily();
// Empty Comment
void WKPreferencesSetSuppressesIncrementalRendering();
// Empty Comment
void WKPreferencesSetTabsToLinks();
// Empty Comment
void WKPreferencesSetTextAreasAreResizable();
// Empty Comment
void WKPreferencesSetUniversalAccessFromFileURLsAllowed();
// Empty Comment
void WKPreferencesSetWebArchiveDebugModeEnabled();
// Empty Comment
void WKPreferencesSetWebAudioEnabled();
// Empty Comment
void WKPreferencesSetWebGLEnabled();
// Empty Comment
void WKPreferencesSetWebSecurityEnabled();
// Empty Comment
void WKPreferencesSetXSSAuditorEnabled();
// Empty Comment
void WKProtectionSpaceCopyHost();
// Empty Comment
void WKProtectionSpaceCopyRealm();
// Empty Comment
void WKProtectionSpaceGetAuthenticationScheme();
// Empty Comment
void WKProtectionSpaceGetIsProxy();
// Empty Comment
void WKProtectionSpaceGetPort();
// Empty Comment
void WKProtectionSpaceGetReceivesCredentialSecurely();
// Empty Comment
void WKProtectionSpaceGetServerType();
// Empty Comment
void WKProtectionSpaceGetTypeID();
// Empty Comment
void WKRectCreate();
// Empty Comment
void WKRectGetTypeID();
// Empty Comment
void WKRectGetValue();
// Empty Comment
void WKRelease();
// Empty Comment
void WKRenderLayerCopyElementID();
// Empty Comment
void WKRenderLayerCopyElementTagName();
// Empty Comment
void WKRenderLayerCopyRendererName();
// Empty Comment
void WKRenderLayerGetAbsoluteBounds();
// Empty Comment
void WKRenderLayerGetCompositingLayerType();
// Empty Comment
void WKRenderLayerGetElementClassNames();
// Empty Comment
void WKRenderLayerGetNegativeZOrderList();
// Empty Comment
void WKRenderLayerGetNormalFlowList();
// Empty Comment
void WKRenderLayerGetPositiveZOrderList();
// Empty Comment
void WKRenderLayerGetTypeID();
// Empty Comment
void WKRenderLayerIsClipped();
// Empty Comment
void WKRenderLayerIsClipping();
// Empty Comment
void WKRenderLayerIsReflection();
// Empty Comment
void WKRenderObjectCopyName();
// Empty Comment
void WKRenderObjectGetAbsolutePosition();
// Empty Comment
void WKRenderObjectGetChildren();
// Empty Comment
void WKRenderObjectGetFrameRect();
// Empty Comment
void WKRenderObjectGetTypeID();
// Empty Comment
void WKResourceCacheManagerClearCacheForAllOrigins();
// Empty Comment
void WKResourceCacheManagerClearCacheForOrigin();
// Empty Comment
void WKResourceCacheManagerGetCacheOrigins();
// Empty Comment
void WKResourceCacheManagerGetTypeID();
// Empty Comment
void WKRetain();
// Empty Comment
void WKSecurityOriginCopyDatabaseIdentifier();
// Empty Comment
void WKSecurityOriginCopyHost();
// Empty Comment
void WKSecurityOriginCopyProtocol();
// Empty Comment
void WKSecurityOriginCopyToString();
// Empty Comment
void WKSecurityOriginCreate();
// Empty Comment
void WKSecurityOriginCreateFromDatabaseIdentifier();
// Empty Comment
void WKSecurityOriginCreateFromString();
// Empty Comment
void WKSecurityOriginGetHost();
// Empty Comment
void WKSecurityOriginGetPort();
// Empty Comment
void WKSecurityOriginGetProtocol();
// Empty Comment
void WKSecurityOriginGetTypeID();
// Empty Comment
void WKSerializedScriptValueCreate();
// Empty Comment
void WKSerializedScriptValueCreateWithInternalRepresentation();
// Empty Comment
void WKSerializedScriptValueDeserialize();
// Empty Comment
void WKSerializedScriptValueGetInternalRepresentation();
// Empty Comment
void WKSerializedScriptValueGetTypeID();
// Empty Comment
void WKSizeCreate();
// Empty Comment
void WKSizeGetTypeID();
// Empty Comment
void WKSizeGetValue();
// Empty Comment
void WKStringCopyJSString();
// Empty Comment
void WKStringCreateWithJSString();
// Empty Comment
void WKStringCreateWithUTF8CString();
// Empty Comment
void WKStringGetCharacters();
// Empty Comment
void WKStringGetLength();
// Empty Comment
void WKStringGetMaximumUTF8CStringSize();
// Empty Comment
void WKStringGetTypeID();
// Empty Comment
void WKStringGetUTF8CString();
// Empty Comment
void WKStringIsEmpty();
// Empty Comment
void WKStringIsEqual();
// Empty Comment
void WKStringIsEqualToUTF8CString();
// Empty Comment
void WKStringIsEqualToUTF8CStringIgnoringCase();
// Empty Comment
void WKTextCheckerChangeSpellingToWord();
// Empty Comment
void WKTextCheckerCheckSpelling();
// Empty Comment
void WKTextCheckerContinuousSpellCheckingEnabledStateChanged();
// Empty Comment
void WKTextCheckerGrammarCheckingEnabledStateChanged();
// Empty Comment
void WKTextCheckerSetClient();
// Empty Comment
void WKUInt64Create();
// Empty Comment
void WKUInt64GetTypeID();
// Empty Comment
void WKUInt64GetValue();
// Empty Comment
void WKURLCopyHostName();
// Empty Comment
void WKURLCopyScheme();
// Empty Comment
void WKURLCopyString();
// Empty Comment
void WKURLCreateWithUTF8CString();
// Empty Comment
void WKURLGetTypeID();
// Empty Comment
void WKURLIsEqual();
// Empty Comment
void WKURLRequestCopyURL();
// Empty Comment
void WKURLRequestCreateWithWKURL();
// Empty Comment
void WKURLRequestGetTypeID();
// Empty Comment
void WKURLRequestSetDefaultTimeoutInterval();
// Empty Comment
void WKURLResponseCopyMimeType();
// Empty Comment
void WKURLResponseCopyURL();
// Empty Comment
void WKURLResponseGetHttpStatusCode();
// Empty Comment
void WKURLResponseGetTypeID();
// Empty Comment
void WKUserContentURLPatternCopyHost();
// Empty Comment
void WKUserContentURLPatternCopyScheme();
// Empty Comment
void WKUserContentURLPatternCreate();
// Empty Comment
void WKUserContentURLPatternGetTypeID();
// Empty Comment
void WKUserContentURLPatternIsValid();
// Empty Comment
void WKUserContentURLPatternMatchesSubdomains();
// Empty Comment
void WKUserContentURLPatternMatchesURL();
// Empty Comment
void WKViewAccessibilityFocusedObject();
// Empty Comment
void WKViewAccessibilityHitTest();
// Empty Comment
void WKViewAccessibilityRootObject();
// Empty Comment
void WKViewClearBackingStores();
// Empty Comment
void WKViewClearSelection();
// Empty Comment
void WKViewContextMenuItemSelected();
// Empty Comment
void WKViewCreate();
// Empty Comment
void WKViewDidEnterFullScreen();
// Empty Comment
void WKViewDidExitFullScreen();
// Empty Comment
void WKViewGetCanvasHole();
// Empty Comment
void WKViewGetPage();
// Empty Comment
void WKViewHandleImeEvent();
// Empty Comment
void WKViewHandleKeyboardEvent();
// Empty Comment
void WKViewHandleMouseEvent();
// Empty Comment
void WKViewHandleWheelEvent();
// Empty Comment
void WKViewIsFullScreen();
// Empty Comment
void WKViewPaint();
// Empty Comment
void WKViewPaintToCurrentGLContext();
// Empty Comment
void WKViewReplyAuthenticationChallenge();
// Empty Comment
void WKViewReplyCertificateVerification();
// Empty Comment
void WKViewReplyCreateNewPage();
// Empty Comment
void WKViewReplyJavaScriptAlert();
// Empty Comment
void WKViewReplyJavaScriptConfirm();
// Empty Comment
void WKViewReplyJavaScriptPrompt();
// Empty Comment
void WKViewRequestExitFullScreen();
// Empty Comment
void WKViewRestoreBackingStores();
// Empty Comment
void WKViewScrollBy();
// Empty Comment
void WKViewSetActive();
// Empty Comment
void WKViewSetDrawsBackground();
// Empty Comment
void WKViewSetDrawsTransparentBackground();
// Empty Comment
void WKViewSetFocused();
// Empty Comment
void WKViewSetIsVisible();
// Empty Comment
void WKViewSetPageScaleFactor();
// Empty Comment
void WKViewSetSize();
// Empty Comment
void WKViewSetViewAccessibilityClient();
// Empty Comment
void WKViewSetViewContextMenuClient();
// Empty Comment
void WKViewSetViewPopupMenuClient();
// Empty Comment
void WKViewSyncCoordinatedGraphicsState();
// Empty Comment
void WKViewValueChangedForPopupMenu();
// Empty Comment
void WKViewWillEnterFullScreen();
// Empty Comment
void WKViewWillExitFullScreen();

#endif

#ifdef __cplusplus
}
#endif