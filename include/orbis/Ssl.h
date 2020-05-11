#ifndef _SCE_SSL_H_
#define _SCE_SSL_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void CA_MGMT_allocCertDistinguishedName();
// Empty Comment
void CA_MGMT_certDistinguishedNameCompare();
// Empty Comment
void CA_MGMT_convertKeyBlobToPKCS8Key();
// Empty Comment
void CA_MGMT_convertKeyDER();
// Empty Comment
void CA_MGMT_convertKeyPEM();
// Empty Comment
void CA_MGMT_convertPKCS8KeyToKeyBlob();
// Empty Comment
void CA_MGMT_convertProtectedPKCS8KeyToKeyBlob();
// Empty Comment
void CA_MGMT_decodeCertificate();
// Empty Comment
void CA_MGMT_enumAltName();
// Empty Comment
void CA_MGMT_enumCrl();
// Empty Comment
void CA_MGMT_extractAllCertDistinguishedName();
// Empty Comment
void CA_MGMT_extractBasicConstraint();
// Empty Comment
void CA_MGMT_extractCertASN1Name();
// Empty Comment
void CA_MGMT_extractCertTimes();
// Empty Comment
void CA_MGMT_extractKeyBlobEx();
// Empty Comment
void CA_MGMT_extractKeyBlobTypeEx();
// Empty Comment
void CA_MGMT_extractPublicKeyInfo();
// Empty Comment
void CA_MGMT_extractSerialNum();
// Empty Comment
void CA_MGMT_extractSignature();
// Empty Comment
void CA_MGMT_free();
// Empty Comment
void CA_MGMT_freeCertDistinguishedName();
// Empty Comment
void CA_MGMT_freeCertDistinguishedNameOnStack();
// Empty Comment
void CA_MGMT_freeCertificate();
// Empty Comment
void CA_MGMT_freeKeyBlob();
// Empty Comment
void CA_MGMT_freeSearchDetails();
// Empty Comment
void CA_MGMT_getCertSignAlgoType();
// Empty Comment
void CA_MGMT_keyBlobToDER();
// Empty Comment
void CA_MGMT_keyBlobToPEM();
// Empty Comment
void CA_MGMT_makeKeyBlobEx();
// Empty Comment
void CA_MGMT_rawVerifyOID();
// Empty Comment
void CA_MGMT_reorderChain();
// Empty Comment
void CA_MGMT_returnCertificatePrints();
// Empty Comment
void CA_MGMT_verifyCertWithKeyBlob();
// Empty Comment
void CA_MGMT_verifySignature();
// Empty Comment
void CERT_checkCertificateIssuer();
// Empty Comment
void CERT_checkCertificateIssuer2();
// Empty Comment
void CERT_checkCertificateIssuerSerialNumber();
// Empty Comment
void CERT_CompSubjectAltNames();
// Empty Comment
void CERT_CompSubjectAltNames2();
// Empty Comment
void CERT_CompSubjectAltNamesExact();
// Empty Comment
void CERT_CompSubjectCommonName();
// Empty Comment
void CERT_CompSubjectCommonName2();
// Empty Comment
void CERT_ComputeBufferHash();
// Empty Comment
void CERT_decryptRSASignature();
// Empty Comment
void CERT_decryptRSASignatureBuffer();
// Empty Comment
void CERT_enumerateAltName();
// Empty Comment
void CERT_enumerateAltName2();
// Empty Comment
void CERT_enumerateCRL();
// Empty Comment
void CERT_enumerateCRL2();
// Empty Comment
void CERT_enumerateCRLAux();
// Empty Comment
void CERT_extractAllDistinguishedNames();
// Empty Comment
void CERT_extractDistinguishedNames();
// Empty Comment
void CERT_extractDistinguishedNames2();
// Empty Comment
void CERT_extractDistinguishedNamesFromName();
// Empty Comment
void CERT_extractRSAKey();
// Empty Comment
void CERT_extractSerialNum();
// Empty Comment
void CERT_extractSerialNum2();
// Empty Comment
void CERT_extractValidityTime();
// Empty Comment
void CERT_extractValidityTime2();
// Empty Comment
void CERT_getCertExtension();
// Empty Comment
void CERT_getCertificateExtensions();
// Empty Comment
void CERT_getCertificateExtensions2();
// Empty Comment
void CERT_getCertificateIssuerSerialNumber();
// Empty Comment
void CERT_getCertificateIssuerSerialNumber2();
// Empty Comment
void CERT_getCertificateKeyUsage();
// Empty Comment
void CERT_getCertificateKeyUsage2();
// Empty Comment
void CERT_getCertificateSubject();
// Empty Comment
void CERT_getCertificateSubject2();
// Empty Comment
void CERT_getCertSignAlgoType();
// Empty Comment
void CERT_GetCertTime();
// Empty Comment
void CERT_getNumberOfChild();
// Empty Comment
void CERT_getRSASignatureAlgo();
// Empty Comment
void CERT_getSignatureItem();
// Empty Comment
void CERT_getSubjectCommonName();
// Empty Comment
void CERT_getSubjectCommonName2();
// Empty Comment
void CERT_isRootCertificate();
// Empty Comment
void CERT_isRootCertificate2();
// Empty Comment
void CERT_rawVerifyOID();
// Empty Comment
void CERT_rawVerifyOID2();
// Empty Comment
void CERT_setKeyFromSubjectPublicKeyInfo();
// Empty Comment
void CERT_setKeyFromSubjectPublicKeyInfoCert();
// Empty Comment
void CERT_STORE_addCertAuthority();
// Empty Comment
void CERT_STORE_addIdentity();
// Empty Comment
void CERT_STORE_addIdentityNakedKey();
// Empty Comment
void CERT_STORE_addIdentityPSK();
// Empty Comment
void CERT_STORE_addIdentityWithCertificateChain();
// Empty Comment
void CERT_STORE_addTrustPoint();
// Empty Comment
void CERT_STORE_createStore();
// Empty Comment
void CERT_STORE_findCertBySubject();
// Empty Comment
void CERT_STORE_findIdentityByTypeFirst();
// Empty Comment
void CERT_STORE_findIdentityByTypeNext();
// Empty Comment
void CERT_STORE_findIdentityCertChainFirst();
// Empty Comment
void CERT_STORE_findIdentityCertChainNext();
// Empty Comment
void CERT_STORE_findPskByIdentity();
// Empty Comment
void CERT_STORE_releaseStore();
// Empty Comment
void CERT_STORE_traversePskListHead();
// Empty Comment
void CERT_STORE_traversePskListNext();
// Empty Comment
void CERT_validateCertificate();
// Empty Comment
void CERT_validateCertificateWithConf();
// Empty Comment
void CERT_VerifyCertificatePolicies();
// Empty Comment
void CERT_VerifyCertificatePolicies2();
// Empty Comment
void CERT_verifySignature();
// Empty Comment
void CERT_VerifyValidityTime();
// Empty Comment
void CERT_VerifyValidityTime2();
// Empty Comment
void CERT_VerifyValidityTimeWithConf();
// Empty Comment
void CRYPTO_initAsymmetricKey();
// Empty Comment
void CRYPTO_uninitAsymmetricKey();
// Empty Comment
void GC_createInstanceIDs();
// Empty Comment
void getCertSigAlgo();
// Empty Comment
void MOCANA_freeMocana();
// Empty Comment
void MOCANA_initMocana();
// Empty Comment
void RSA_verifySignature();
// Empty Comment
void sceSslClose();
// Empty Comment
void sceSslConnect();
// Empty Comment
void sceSslCreateSslConnection();
// Empty Comment
void sceSslDeleteSslConnection();
// Empty Comment
void sceSslDisableOption();
// Empty Comment
void sceSslDisableOptionInternal();
// Empty Comment
void sceSslDisableOptionInternalInsecure();
// Empty Comment
void sceSslEnableOption();
// Empty Comment
void sceSslEnableOptionInternal();
// Empty Comment
void sceSslFreeCaCerts();
// Empty Comment
void sceSslFreeCaList();
// Empty Comment
void sceSslFreeSslCertName();
// Empty Comment
void sceSslGetCaCerts();
// Empty Comment
void sceSslGetCaList();
// Empty Comment
void sceSslGetIssuerName();
// Empty Comment
void sceSslGetMemoryPoolStats();
// Empty Comment
void sceSslGetNameEntryCount();
// Empty Comment
void sceSslGetNameEntryInfo();
// Empty Comment
void sceSslGetNanoSSLModuleId();
// Empty Comment
void sceSslGetNotAfter();
// Empty Comment
void sceSslGetNotBefore();
// Empty Comment
void sceSslGetSerialNumber();
// Empty Comment
void sceSslGetSslError();
// Empty Comment
void sceSslGetSubjectName();
// Empty Comment
void sceSslInit();
// Empty Comment
void sceSslLoadCert();
// Empty Comment
void sceSslLoadRootCACert();
// Empty Comment
void sceSslRecv();
// Empty Comment
void sceSslSend();
// Empty Comment
void sceSslSetSslVersion();
// Empty Comment
void sceSslSetVerifyCallback();
// Empty Comment
void sceSslShowMemoryStat();
// Empty Comment
void sceSslTerm();
// Empty Comment
void sceSslUnloadCert();
// Empty Comment
void SSL_acceptConnection();
// Empty Comment
void SSL_acceptConnectionCommon();
// Empty Comment
void SSL_assignCertificateStore();
// Empty Comment
void SSL_ASYNC_acceptConnection();
// Empty Comment
void SSL_ASYNC_closeConnection();
// Empty Comment
void SSL_ASYNC_connect();
// Empty Comment
void SSL_ASYNC_connectCommon();
// Empty Comment
void SSL_ASYNC_getRecvBuffer();
// Empty Comment
void SSL_ASYNC_getSendBuffer();
// Empty Comment
void SSL_ASYNC_init();
// Empty Comment
void SSL_ASYNC_initServer();
// Empty Comment
void SSL_ASYNC_recvMessage();
// Empty Comment
void SSL_ASYNC_recvMessage2();
// Empty Comment
void SSL_ASYNC_sendMessage();
// Empty Comment
void SSL_ASYNC_sendMessagePending();
// Empty Comment
void SSL_ASYNC_start();
// Empty Comment
void SSL_closeConnection();
// Empty Comment
void SSL_connect();
// Empty Comment
void SSL_connectWithCfgParam();
// Empty Comment
void SSL_enableCiphers();
// Empty Comment
void SSL_findConnectionInstance();
// Empty Comment
void SSL_getCipherInfo();
// Empty Comment
void SSL_getClientRandom();
// Empty Comment
void SSL_getClientSessionInfo();
// Empty Comment
void SSL_getCookie();
// Empty Comment
void SSL_getInstanceFromSocket();
// Empty Comment
void SSL_getNextSessionId();
// Empty Comment
void SSL_getServerRandom();
// Empty Comment
void SSL_getSessionCache();
// Empty Comment
void SSL_getSessionFlags();
// Empty Comment
void SSL_getSessionInfo();
// Empty Comment
void SSL_getSessionStatus();
// Empty Comment
void SSL_getSocketId();
// Empty Comment
void SSL_getSSLTLSVersion();
// Empty Comment
void SSL_init();
// Empty Comment
void SSL_initiateRehandshake();
// Empty Comment
void SSL_initServerCert();
// Empty Comment
void SSL_ioctl();
// Empty Comment
void SSL_isSessionSSL();
// Empty Comment
void SSL_lockSessionCacheMutex();
// Empty Comment
void SSL_lookupAlert();
// Empty Comment
void SSL_negotiateConnection();
// Empty Comment
void SSL_recv();
// Empty Comment
void SSL_recvPending();
// Empty Comment
void SSL_releaseTables();
// Empty Comment
void SSL_retrieveServerNameList();
// Empty Comment
void SSL_rngFun();
// Empty Comment
void SSL_send();
// Empty Comment
void SSL_sendAlert();
// Empty Comment
void SSL_sendPending();
// Empty Comment
void SSL_setCookie();
// Empty Comment
void SSL_setServerCert();
// Empty Comment
void SSL_setServerNameList();
// Empty Comment
void SSL_setSessionFlags();
// Empty Comment
void SSL_shutdown();
// Empty Comment
void SSL_sslSettings();
// Empty Comment
void SSL_validateCertParam();
// Empty Comment
void VLONG_freeVlongQueue();

#endif

#ifdef __cplusplus
}
#endif