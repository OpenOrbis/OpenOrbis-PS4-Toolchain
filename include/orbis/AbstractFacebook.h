#ifndef _SCE_ABSTRACT_FACEBOOK_H_
#define _SCE_ABSTRACT_FACEBOOK_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


void _ZN15AbstractStorage14FacebookFolder10NewContentERKSbIcSt11char_traitsIcENS_8StlAllocIcEEEPSt10shared_ptrINS_7ContentEE();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder11SetMetadataEPN23sceMetadataReaderWriter8MetadataE();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder12create_albumEv();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder12readExternalESt10shared_ptrINS_7ContentEE();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder12RemoveFolderERKSbIcSt11char_traitsIcENS_8StlAllocIcEEEb();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder13ParseMetadataEPN23sceMetadataReaderWriter8MetadataES3_();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder13RemoveContentERKSbIcSt11char_traitsIcENS_8StlAllocIcEEE();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder13writeExternalESt10shared_ptrINS_7ContentEE();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder4OpenENS_8ItemTypeE();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder5CloseEv();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder6RemoveEb();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder8NextItemEPSt10shared_ptrINS_4ItemEE();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolder9NewFolderERKSbIcSt11char_traitsIcENS_8StlAllocIcEEEPSt10shared_ptrINS_6FolderEE();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolderC1ERKSbIcSt11char_traitsIcENS_8StlAllocIcEEEb();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolderC2ERKSbIcSt11char_traitsIcENS_8StlAllocIcEEEb();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolderD0Ev();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolderD1Ev();
// Empty Comment
void _ZN15AbstractStorage14FacebookFolderD2Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent11SetMetadataEPN23sceMetadataReaderWriter8MetadataE();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent12readExternalESt10shared_ptrINS_7ContentEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent13ParseMetadataEPN23sceMetadataReaderWriter8MetadataES3_();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent13writeExternalESt10shared_ptrINS_7ContentEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent4OpenEit();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent5CloseEv();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent5FlushEv();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent6RemoveEv();
// Empty Comment
void _ZN15AbstractStorage15FacebookContent6RenameERKSbIcSt11char_traitsIcENS_8StlAllocIcEEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookContentD0Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookContentD1Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookContentD2Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookService13SearchStorageEv();
// Empty Comment
void _ZN15AbstractStorage15FacebookService23create_storage_instanceERKSbIcSt11char_traitsIcENS_8StlAllocIcEEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookService4StopEv();
// Empty Comment
void _ZN15AbstractStorage15FacebookService5StartEv();
// Empty Comment
void _ZN15AbstractStorage15FacebookServiceC1Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookServiceC2Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookServiceD0Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookServiceD1Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookServiceD2Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorage11DeserializeESt10shared_ptrINS_7ContentEEPS1_INS_4ItemEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorage11SetMetadataEPN23sceMetadataReaderWriter8MetadataE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorage13GetRootFolderEPSt10shared_ptrINS_6FolderEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorage15CreateRecursiveERKSbIcSt11char_traitsIcENS_8StlAllocIcEEENS_8ItemTypeEPSt10shared_ptrINS_4ItemEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorage15RemoveRecursiveERKSbIcSt11char_traitsIcENS_8StlAllocIcEEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorage7GetItemERKSbIcSt11char_traitsIcENS_8StlAllocIcEEEPSt10shared_ptrINS_4ItemEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorage7IsExistERKSbIcSt11char_traitsIcENS_8StlAllocIcEEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorage9SerializeESt10shared_ptrINS_7ContentEES1_INS_4ItemEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorageC1ERKSbIcSt11char_traitsIcENS_8StlAllocIcEEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorageC2ERKSbIcSt11char_traitsIcENS_8StlAllocIcEEE();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorageD0Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorageD1Ev();
// Empty Comment
void _ZN15AbstractStorage15FacebookStorageD2Ev();
// Empty Comment
void _ZNK15AbstractStorage14FacebookFolder10GetServiceEv();
// Empty Comment
void _ZNK15AbstractStorage14FacebookFolder13GetCapabilityEv();
// Empty Comment
void _ZNK15AbstractStorage14FacebookFolder7GetStatEPNS_4StatE();
// Empty Comment
void _ZNK15AbstractStorage15FacebookContent10GetServiceEv();
// Empty Comment
void _ZNK15AbstractStorage15FacebookContent13GetCapabilityEv();
// Empty Comment
void _ZNK15AbstractStorage15FacebookContent7GetStatEPNS_4StatE();
// Empty Comment
void _ZNK15AbstractStorage15FacebookService14GetServiceTypeEv();
// Empty Comment
void _ZNK15AbstractStorage15FacebookStorage10GetServiceEv();
// Empty Comment
void _ZNK15AbstractStorage15FacebookStorage13GetCapabilityEv();
// Empty Comment
void _ZNK15AbstractStorage15FacebookStorage7GetStatEPNS_4StatE();
// Empty Comment
void _ZNKSt15_Ref_count_base12_Get_deleterERKSt9type_info();
// Empty Comment
void _ZNSt10_Ref_countIN15AbstractStorage14FacebookFolderEE12_Delete_thisEv();
// Empty Comment
void _ZNSt10_Ref_countIN15AbstractStorage14FacebookFolderEE8_DestroyEv();
// Empty Comment
void _ZNSt10_Ref_countIN15AbstractStorage14FacebookFolderEED0Ev();
// Empty Comment
void _ZNSt10_Ref_countIN15AbstractStorage14FacebookFolderEED1Ev();
// Empty Comment
void _ZNSt10_Ref_countIN15AbstractStorage15FacebookContentEE12_Delete_thisEv();
// Empty Comment
void _ZNSt10_Ref_countIN15AbstractStorage15FacebookContentEE8_DestroyEv();
// Empty Comment
void _ZNSt10_Ref_countIN15AbstractStorage15FacebookContentEED0Ev();
// Empty Comment
void _ZNSt10_Ref_countIN15AbstractStorage15FacebookContentEED1Ev();
// Empty Comment
void _ZNSt6vectorIN15AbstractStorage19FacebookFolderEntryESaIS1_EE9push_backEOS1_();
// Empty Comment
void _ZTVN15AbstractStorage14FacebookFolderE();
// Empty Comment
void _ZTVN15AbstractStorage15FacebookContentE();
// Empty Comment
void _ZTVN15AbstractStorage15FacebookServiceE();
// Empty Comment
void _ZTVN15AbstractStorage15FacebookStorageE();

#endif

#ifdef __cplusplus
}
#endif