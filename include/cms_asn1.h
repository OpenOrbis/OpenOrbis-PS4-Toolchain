/* Generated from /usr/src/kerberos5/lib/libasn1/../../../crypto/heimdal/lib/asn1/CMS.asn1 */
/* Do not edit */

#ifndef __cms_asn1_h__
#define __cms_asn1_h__

#include <stddef.h>
#include <time.h>

#ifndef __asn1_common_definitions__
#define __asn1_common_definitions__

typedef struct heim_integer {
  size_t length;
  void *data;
  int negative;
} heim_integer;

typedef struct heim_octet_string {
  size_t length;
  void *data;
} heim_octet_string;

typedef char *heim_general_string;

typedef char *heim_utf8_string;

typedef char *heim_printable_string;

typedef char *heim_ia5_string;

typedef struct heim_bmp_string {
  size_t length;
  uint16_t *data;
} heim_bmp_string;

typedef struct heim_universal_string {
  size_t length;
  uint32_t *data;
} heim_universal_string;

typedef char *heim_visible_string;

typedef struct heim_oid {
  size_t length;
  unsigned *components;
} heim_oid;

typedef struct heim_bit_string {
  size_t length;
  void *data;
} heim_bit_string;

typedef struct heim_octet_string heim_any;
typedef struct heim_octet_string heim_any_set;

#define ASN1_MALLOC_ENCODE(T, B, BL, S, L, R)                  \
  do {                                                         \
    (BL) = length_##T((S));                                    \
    (B) = malloc((BL));                                        \
    if((B) == NULL) {                                          \
      (R) = ENOMEM;                                            \
    } else {                                                   \
      (R) = encode_##T(((unsigned char*)(B)) + (BL) - 1, (BL), \
                       (S), (L));                              \
      if((R) != 0) {                                           \
        free((B));                                             \
        (B) = NULL;                                            \
      }                                                        \
    }                                                          \
  } while (0)

struct units;

#endif

#include <rfc2459_asn1.h>
#include <heim_asn1.h>
/* OBJECT IDENTIFIER id-pkcs7 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs7(7) } */
const heim_oid *oid_id_pkcs7(void);

/* OBJECT IDENTIFIER id-pkcs7-data ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs7(7) label-less(1) } */
const heim_oid *oid_id_pkcs7_data(void);

/* OBJECT IDENTIFIER id-pkcs7-signedData ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs7(7) label-less(2) } */
const heim_oid *oid_id_pkcs7_signedData(void);

/* OBJECT IDENTIFIER id-pkcs7-envelopedData ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs7(7) label-less(3) } */
const heim_oid *oid_id_pkcs7_envelopedData(void);

/* OBJECT IDENTIFIER id-pkcs7-signedAndEnvelopedData ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs7(7) label-less(4) } */
const heim_oid *oid_id_pkcs7_signedAndEnvelopedData(void);

/* OBJECT IDENTIFIER id-pkcs7-digestedData ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs7(7) label-less(5) } */
const heim_oid *oid_id_pkcs7_digestedData(void);

/* OBJECT IDENTIFIER id-pkcs7-encryptedData ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs7(7) label-less(6) } */
const heim_oid *oid_id_pkcs7_encryptedData(void);

/*
CMSVersion ::= INTEGER {
  CMSVersion_v0(0),
  CMSVersion_v1(1),
  CMSVersion_v2(2),
  CMSVersion_v3(3),
  CMSVersion_v4(4)
}
*/

typedef enum CMSVersion {
  CMSVersion_v0 = 0,
  CMSVersion_v1 = 1,
  CMSVersion_v2 = 2,
  CMSVersion_v3 = 3,
  CMSVersion_v4 = 4
} CMSVersion;

int    encode_CMSVersion(unsigned char *, size_t, const CMSVersion *, size_t *);
int    decode_CMSVersion(const unsigned char *, size_t, CMSVersion *, size_t *);
void   free_CMSVersion  (CMSVersion *);
size_t length_CMSVersion(const CMSVersion *);
int    copy_CMSVersion  (const CMSVersion *, CMSVersion *);


/*
DigestAlgorithmIdentifier ::= AlgorithmIdentifier
*/

typedef AlgorithmIdentifier DigestAlgorithmIdentifier;

int    encode_DigestAlgorithmIdentifier(unsigned char *, size_t, const DigestAlgorithmIdentifier *, size_t *);
int    decode_DigestAlgorithmIdentifier(const unsigned char *, size_t, DigestAlgorithmIdentifier *, size_t *);
void   free_DigestAlgorithmIdentifier  (DigestAlgorithmIdentifier *);
size_t length_DigestAlgorithmIdentifier(const DigestAlgorithmIdentifier *);
int    copy_DigestAlgorithmIdentifier  (const DigestAlgorithmIdentifier *, DigestAlgorithmIdentifier *);


/*
DigestAlgorithmIdentifiers ::= SET OF DigestAlgorithmIdentifier
*/

typedef struct DigestAlgorithmIdentifiers {
  unsigned int len;
  DigestAlgorithmIdentifier *val;
} DigestAlgorithmIdentifiers;

int    encode_DigestAlgorithmIdentifiers(unsigned char *, size_t, const DigestAlgorithmIdentifiers *, size_t *);
int    decode_DigestAlgorithmIdentifiers(const unsigned char *, size_t, DigestAlgorithmIdentifiers *, size_t *);
void   free_DigestAlgorithmIdentifiers  (DigestAlgorithmIdentifiers *);
size_t length_DigestAlgorithmIdentifiers(const DigestAlgorithmIdentifiers *);
int    copy_DigestAlgorithmIdentifiers  (const DigestAlgorithmIdentifiers *, DigestAlgorithmIdentifiers *);


/*
SignatureAlgorithmIdentifier ::= AlgorithmIdentifier
*/

typedef AlgorithmIdentifier SignatureAlgorithmIdentifier;

int    encode_SignatureAlgorithmIdentifier(unsigned char *, size_t, const SignatureAlgorithmIdentifier *, size_t *);
int    decode_SignatureAlgorithmIdentifier(const unsigned char *, size_t, SignatureAlgorithmIdentifier *, size_t *);
void   free_SignatureAlgorithmIdentifier  (SignatureAlgorithmIdentifier *);
size_t length_SignatureAlgorithmIdentifier(const SignatureAlgorithmIdentifier *);
int    copy_SignatureAlgorithmIdentifier  (const SignatureAlgorithmIdentifier *, SignatureAlgorithmIdentifier *);


/*
ContentType ::= OBJECT IDENTIFIER
*/

typedef heim_oid ContentType;

int    encode_ContentType(unsigned char *, size_t, const ContentType *, size_t *);
int    decode_ContentType(const unsigned char *, size_t, ContentType *, size_t *);
void   free_ContentType  (ContentType *);
size_t length_ContentType(const ContentType *);
int    copy_ContentType  (const ContentType *, ContentType *);


/*
MessageDigest ::= OCTET STRING
*/

typedef heim_octet_string MessageDigest;

int    encode_MessageDigest(unsigned char *, size_t, const MessageDigest *, size_t *);
int    decode_MessageDigest(const unsigned char *, size_t, MessageDigest *, size_t *);
void   free_MessageDigest  (MessageDigest *);
size_t length_MessageDigest(const MessageDigest *);
int    copy_MessageDigest  (const MessageDigest *, MessageDigest *);


/*
ContentInfo ::= SEQUENCE {
  contentType     ContentType,
  content         [0] heim_any OPTIONAL,
}
*/

typedef struct ContentInfo {
  ContentType contentType;
  heim_any *content;
} ContentInfo;

int    encode_ContentInfo(unsigned char *, size_t, const ContentInfo *, size_t *);
int    decode_ContentInfo(const unsigned char *, size_t, ContentInfo *, size_t *);
void   free_ContentInfo  (ContentInfo *);
size_t length_ContentInfo(const ContentInfo *);
int    copy_ContentInfo  (const ContentInfo *, ContentInfo *);


/*
EncapsulatedContentInfo ::= SEQUENCE {
  eContentType    ContentType,
  eContent        [0] OCTET STRING OPTIONAL,
}
*/

typedef struct EncapsulatedContentInfo {
  ContentType eContentType;
  heim_octet_string *eContent;
} EncapsulatedContentInfo;

int    encode_EncapsulatedContentInfo(unsigned char *, size_t, const EncapsulatedContentInfo *, size_t *);
int    decode_EncapsulatedContentInfo(const unsigned char *, size_t, EncapsulatedContentInfo *, size_t *);
void   free_EncapsulatedContentInfo  (EncapsulatedContentInfo *);
size_t length_EncapsulatedContentInfo(const EncapsulatedContentInfo *);
int    copy_EncapsulatedContentInfo  (const EncapsulatedContentInfo *, EncapsulatedContentInfo *);


/*
CertificateSet ::= SET OF heim_any
*/

typedef struct CertificateSet {
  unsigned int len;
  heim_any *val;
} CertificateSet;

int    encode_CertificateSet(unsigned char *, size_t, const CertificateSet *, size_t *);
int    decode_CertificateSet(const unsigned char *, size_t, CertificateSet *, size_t *);
void   free_CertificateSet  (CertificateSet *);
size_t length_CertificateSet(const CertificateSet *);
int    copy_CertificateSet  (const CertificateSet *, CertificateSet *);


/*
CertificateList ::= Certificate
*/

typedef Certificate CertificateList;

int    encode_CertificateList(unsigned char *, size_t, const CertificateList *, size_t *);
int    decode_CertificateList(const unsigned char *, size_t, CertificateList *, size_t *);
void   free_CertificateList  (CertificateList *);
size_t length_CertificateList(const CertificateList *);
int    copy_CertificateList  (const CertificateList *, CertificateList *);


/*
CertificateRevocationLists ::= SET OF CertificateList
*/

typedef struct CertificateRevocationLists {
  unsigned int len;
  CertificateList *val;
} CertificateRevocationLists;

int    encode_CertificateRevocationLists(unsigned char *, size_t, const CertificateRevocationLists *, size_t *);
int    decode_CertificateRevocationLists(const unsigned char *, size_t, CertificateRevocationLists *, size_t *);
void   free_CertificateRevocationLists  (CertificateRevocationLists *);
size_t length_CertificateRevocationLists(const CertificateRevocationLists *);
int    copy_CertificateRevocationLists  (const CertificateRevocationLists *, CertificateRevocationLists *);


/*
IssuerAndSerialNumber ::= SEQUENCE {
  issuer          Name,
  serialNumber    CertificateSerialNumber,
}
*/

typedef struct IssuerAndSerialNumber {
  Name issuer;
  CertificateSerialNumber serialNumber;
} IssuerAndSerialNumber;

int    encode_IssuerAndSerialNumber(unsigned char *, size_t, const IssuerAndSerialNumber *, size_t *);
int    decode_IssuerAndSerialNumber(const unsigned char *, size_t, IssuerAndSerialNumber *, size_t *);
void   free_IssuerAndSerialNumber  (IssuerAndSerialNumber *);
size_t length_IssuerAndSerialNumber(const IssuerAndSerialNumber *);
int    copy_IssuerAndSerialNumber  (const IssuerAndSerialNumber *, IssuerAndSerialNumber *);


/*
CMSIdentifier ::= CHOICE {
  issuerAndSerialNumber   IssuerAndSerialNumber,
  subjectKeyIdentifier    [0] SubjectKeyIdentifier,
}
*/

typedef struct CMSIdentifier {
  enum {
    choice_CMSIdentifier_issuerAndSerialNumber = 1,
    choice_CMSIdentifier_subjectKeyIdentifier
  } element;
  union {
    IssuerAndSerialNumber issuerAndSerialNumber;
    SubjectKeyIdentifier subjectKeyIdentifier;
  } u;
} CMSIdentifier;

int    encode_CMSIdentifier(unsigned char *, size_t, const CMSIdentifier *, size_t *);
int    decode_CMSIdentifier(const unsigned char *, size_t, CMSIdentifier *, size_t *);
void   free_CMSIdentifier  (CMSIdentifier *);
size_t length_CMSIdentifier(const CMSIdentifier *);
int    copy_CMSIdentifier  (const CMSIdentifier *, CMSIdentifier *);


/*
SignerIdentifier ::= CMSIdentifier
*/

typedef CMSIdentifier SignerIdentifier;

int    encode_SignerIdentifier(unsigned char *, size_t, const SignerIdentifier *, size_t *);
int    decode_SignerIdentifier(const unsigned char *, size_t, SignerIdentifier *, size_t *);
void   free_SignerIdentifier  (SignerIdentifier *);
size_t length_SignerIdentifier(const SignerIdentifier *);
int    copy_SignerIdentifier  (const SignerIdentifier *, SignerIdentifier *);


/*
RecipientIdentifier ::= CMSIdentifier
*/

typedef CMSIdentifier RecipientIdentifier;

int    encode_RecipientIdentifier(unsigned char *, size_t, const RecipientIdentifier *, size_t *);
int    decode_RecipientIdentifier(const unsigned char *, size_t, RecipientIdentifier *, size_t *);
void   free_RecipientIdentifier  (RecipientIdentifier *);
size_t length_RecipientIdentifier(const RecipientIdentifier *);
int    copy_RecipientIdentifier  (const RecipientIdentifier *, RecipientIdentifier *);


/*
CMSAttributes ::= SET OF Attribute
*/

typedef struct CMSAttributes {
  unsigned int len;
  Attribute *val;
} CMSAttributes;

int    encode_CMSAttributes(unsigned char *, size_t, const CMSAttributes *, size_t *);
int    decode_CMSAttributes(const unsigned char *, size_t, CMSAttributes *, size_t *);
void   free_CMSAttributes  (CMSAttributes *);
size_t length_CMSAttributes(const CMSAttributes *);
int    copy_CMSAttributes  (const CMSAttributes *, CMSAttributes *);


/*
SignatureValue ::= OCTET STRING
*/

typedef heim_octet_string SignatureValue;

int    encode_SignatureValue(unsigned char *, size_t, const SignatureValue *, size_t *);
int    decode_SignatureValue(const unsigned char *, size_t, SignatureValue *, size_t *);
void   free_SignatureValue  (SignatureValue *);
size_t length_SignatureValue(const SignatureValue *);
int    copy_SignatureValue  (const SignatureValue *, SignatureValue *);


/*
SignerInfo ::= SEQUENCE {
  version              CMSVersion,
  sid                  SignerIdentifier,
  digestAlgorithm      DigestAlgorithmIdentifier,
  signedAttrs          [0] IMPLICIT SET OF Attribute OPTIONAL,
  signatureAlgorithm   SignatureAlgorithmIdentifier,
  signature            SignatureValue,
  unsignedAttrs        [1] IMPLICIT SET OF Attribute OPTIONAL,
}
*/

typedef struct SignerInfo {
  CMSVersion version;
  SignerIdentifier sid;
  DigestAlgorithmIdentifier digestAlgorithm;
  struct  {
    unsigned int len;
    Attribute *val;
  } *signedAttrs;
  SignatureAlgorithmIdentifier signatureAlgorithm;
  SignatureValue signature;
  struct  {
    unsigned int len;
    Attribute *val;
  } *unsignedAttrs;
} SignerInfo;

int    encode_SignerInfo(unsigned char *, size_t, const SignerInfo *, size_t *);
int    decode_SignerInfo(const unsigned char *, size_t, SignerInfo *, size_t *);
void   free_SignerInfo  (SignerInfo *);
size_t length_SignerInfo(const SignerInfo *);
int    copy_SignerInfo  (const SignerInfo *, SignerInfo *);


/*
SignerInfos ::= SET OF SignerInfo
*/

typedef struct SignerInfos {
  unsigned int len;
  SignerInfo *val;
} SignerInfos;

int    encode_SignerInfos(unsigned char *, size_t, const SignerInfos *, size_t *);
int    decode_SignerInfos(const unsigned char *, size_t, SignerInfos *, size_t *);
void   free_SignerInfos  (SignerInfos *);
size_t length_SignerInfos(const SignerInfos *);
int    copy_SignerInfos  (const SignerInfos *, SignerInfos *);


/*
SignedData ::= SEQUENCE {
  version            CMSVersion,
  digestAlgorithms   DigestAlgorithmIdentifiers,
  encapContentInfo   EncapsulatedContentInfo,
  certificates       [0] IMPLICIT SET OF heim_any OPTIONAL,
  crls               [1] IMPLICIT heim_any OPTIONAL,
  signerInfos        SignerInfos,
}
*/

typedef struct SignedData {
  CMSVersion version;
  DigestAlgorithmIdentifiers digestAlgorithms;
  EncapsulatedContentInfo encapContentInfo;
  struct  {
    unsigned int len;
    heim_any *val;
  } *certificates;
  heim_any *crls;
  SignerInfos signerInfos;
} SignedData;

int    encode_SignedData(unsigned char *, size_t, const SignedData *, size_t *);
int    decode_SignedData(const unsigned char *, size_t, SignedData *, size_t *);
void   free_SignedData  (SignedData *);
size_t length_SignedData(const SignedData *);
int    copy_SignedData  (const SignedData *, SignedData *);


/*
OriginatorInfo ::= SEQUENCE {
  certs           [0] IMPLICIT SET OF heim_any OPTIONAL,
  crls            [1] IMPLICIT heim_any OPTIONAL,
}
*/

typedef struct OriginatorInfo {
  struct  {
    unsigned int len;
    heim_any *val;
  } *certs;
  heim_any *crls;
} OriginatorInfo;

int    encode_OriginatorInfo(unsigned char *, size_t, const OriginatorInfo *, size_t *);
int    decode_OriginatorInfo(const unsigned char *, size_t, OriginatorInfo *, size_t *);
void   free_OriginatorInfo  (OriginatorInfo *);
size_t length_OriginatorInfo(const OriginatorInfo *);
int    copy_OriginatorInfo  (const OriginatorInfo *, OriginatorInfo *);


/*
KeyEncryptionAlgorithmIdentifier ::= AlgorithmIdentifier
*/

typedef AlgorithmIdentifier KeyEncryptionAlgorithmIdentifier;

int    encode_KeyEncryptionAlgorithmIdentifier(unsigned char *, size_t, const KeyEncryptionAlgorithmIdentifier *, size_t *);
int    decode_KeyEncryptionAlgorithmIdentifier(const unsigned char *, size_t, KeyEncryptionAlgorithmIdentifier *, size_t *);
void   free_KeyEncryptionAlgorithmIdentifier  (KeyEncryptionAlgorithmIdentifier *);
size_t length_KeyEncryptionAlgorithmIdentifier(const KeyEncryptionAlgorithmIdentifier *);
int    copy_KeyEncryptionAlgorithmIdentifier  (const KeyEncryptionAlgorithmIdentifier *, KeyEncryptionAlgorithmIdentifier *);


/*
ContentEncryptionAlgorithmIdentifier ::= AlgorithmIdentifier
*/

typedef AlgorithmIdentifier ContentEncryptionAlgorithmIdentifier;

int    encode_ContentEncryptionAlgorithmIdentifier(unsigned char *, size_t, const ContentEncryptionAlgorithmIdentifier *, size_t *);
int    decode_ContentEncryptionAlgorithmIdentifier(const unsigned char *, size_t, ContentEncryptionAlgorithmIdentifier *, size_t *);
void   free_ContentEncryptionAlgorithmIdentifier  (ContentEncryptionAlgorithmIdentifier *);
size_t length_ContentEncryptionAlgorithmIdentifier(const ContentEncryptionAlgorithmIdentifier *);
int    copy_ContentEncryptionAlgorithmIdentifier  (const ContentEncryptionAlgorithmIdentifier *, ContentEncryptionAlgorithmIdentifier *);


/*
EncryptedKey ::= OCTET STRING
*/

typedef heim_octet_string EncryptedKey;

int    encode_EncryptedKey(unsigned char *, size_t, const EncryptedKey *, size_t *);
int    decode_EncryptedKey(const unsigned char *, size_t, EncryptedKey *, size_t *);
void   free_EncryptedKey  (EncryptedKey *);
size_t length_EncryptedKey(const EncryptedKey *);
int    copy_EncryptedKey  (const EncryptedKey *, EncryptedKey *);


/*
KeyTransRecipientInfo ::= SEQUENCE {
  version                  CMSVersion,
  rid                      RecipientIdentifier,
  keyEncryptionAlgorithm   KeyEncryptionAlgorithmIdentifier,
  encryptedKey             EncryptedKey,
}
*/

typedef struct KeyTransRecipientInfo {
  CMSVersion version;
  RecipientIdentifier rid;
  KeyEncryptionAlgorithmIdentifier keyEncryptionAlgorithm;
  EncryptedKey encryptedKey;
} KeyTransRecipientInfo;

int    encode_KeyTransRecipientInfo(unsigned char *, size_t, const KeyTransRecipientInfo *, size_t *);
int    decode_KeyTransRecipientInfo(const unsigned char *, size_t, KeyTransRecipientInfo *, size_t *);
void   free_KeyTransRecipientInfo  (KeyTransRecipientInfo *);
size_t length_KeyTransRecipientInfo(const KeyTransRecipientInfo *);
int    copy_KeyTransRecipientInfo  (const KeyTransRecipientInfo *, KeyTransRecipientInfo *);


/*
RecipientInfo ::= KeyTransRecipientInfo
*/

typedef KeyTransRecipientInfo RecipientInfo;

int    encode_RecipientInfo(unsigned char *, size_t, const RecipientInfo *, size_t *);
int    decode_RecipientInfo(const unsigned char *, size_t, RecipientInfo *, size_t *);
void   free_RecipientInfo  (RecipientInfo *);
size_t length_RecipientInfo(const RecipientInfo *);
int    copy_RecipientInfo  (const RecipientInfo *, RecipientInfo *);


/*
RecipientInfos ::= SET OF RecipientInfo
*/

typedef struct RecipientInfos {
  unsigned int len;
  RecipientInfo *val;
} RecipientInfos;

int    encode_RecipientInfos(unsigned char *, size_t, const RecipientInfos *, size_t *);
int    decode_RecipientInfos(const unsigned char *, size_t, RecipientInfos *, size_t *);
void   free_RecipientInfos  (RecipientInfos *);
size_t length_RecipientInfos(const RecipientInfos *);
int    copy_RecipientInfos  (const RecipientInfos *, RecipientInfos *);


/*
EncryptedContent ::= OCTET STRING
*/

typedef heim_octet_string EncryptedContent;

int    encode_EncryptedContent(unsigned char *, size_t, const EncryptedContent *, size_t *);
int    decode_EncryptedContent(const unsigned char *, size_t, EncryptedContent *, size_t *);
void   free_EncryptedContent  (EncryptedContent *);
size_t length_EncryptedContent(const EncryptedContent *);
int    copy_EncryptedContent  (const EncryptedContent *, EncryptedContent *);


/*
EncryptedContentInfo ::= SEQUENCE {
  contentType                  ContentType,
  contentEncryptionAlgorithm   ContentEncryptionAlgorithmIdentifier,
  encryptedContent             [0] IMPLICIT OCTET STRING OPTIONAL,
}
*/

typedef struct EncryptedContentInfo {
  ContentType contentType;
  ContentEncryptionAlgorithmIdentifier contentEncryptionAlgorithm;
  heim_octet_string *encryptedContent;
} EncryptedContentInfo;

int    encode_EncryptedContentInfo(unsigned char *, size_t, const EncryptedContentInfo *, size_t *);
int    decode_EncryptedContentInfo(const unsigned char *, size_t, EncryptedContentInfo *, size_t *);
void   free_EncryptedContentInfo  (EncryptedContentInfo *);
size_t length_EncryptedContentInfo(const EncryptedContentInfo *);
int    copy_EncryptedContentInfo  (const EncryptedContentInfo *, EncryptedContentInfo *);


/*
UnprotectedAttributes ::= SET OF Attribute
*/

typedef struct UnprotectedAttributes {
  unsigned int len;
  Attribute *val;
} UnprotectedAttributes;

int    encode_UnprotectedAttributes(unsigned char *, size_t, const UnprotectedAttributes *, size_t *);
int    decode_UnprotectedAttributes(const unsigned char *, size_t, UnprotectedAttributes *, size_t *);
void   free_UnprotectedAttributes  (UnprotectedAttributes *);
size_t length_UnprotectedAttributes(const UnprotectedAttributes *);
int    copy_UnprotectedAttributes  (const UnprotectedAttributes *, UnprotectedAttributes *);


/*
CMSEncryptedData ::= SEQUENCE {
  version                CMSVersion,
  encryptedContentInfo   EncryptedContentInfo,
  unprotectedAttrs       [1] IMPLICIT heim_any OPTIONAL,
}
*/

typedef struct CMSEncryptedData {
  CMSVersion version;
  EncryptedContentInfo encryptedContentInfo;
  heim_any *unprotectedAttrs;
} CMSEncryptedData;

int    encode_CMSEncryptedData(unsigned char *, size_t, const CMSEncryptedData *, size_t *);
int    decode_CMSEncryptedData(const unsigned char *, size_t, CMSEncryptedData *, size_t *);
void   free_CMSEncryptedData  (CMSEncryptedData *);
size_t length_CMSEncryptedData(const CMSEncryptedData *);
int    copy_CMSEncryptedData  (const CMSEncryptedData *, CMSEncryptedData *);


/*
EnvelopedData ::= SEQUENCE {
  version                CMSVersion,
  originatorInfo         [0] IMPLICIT heim_any OPTIONAL,
  recipientInfos         RecipientInfos,
  encryptedContentInfo   EncryptedContentInfo,
  unprotectedAttrs       [1] IMPLICIT heim_any OPTIONAL,
}
*/

typedef struct EnvelopedData {
  CMSVersion version;
  heim_any *originatorInfo;
  RecipientInfos recipientInfos;
  EncryptedContentInfo encryptedContentInfo;
  heim_any *unprotectedAttrs;
} EnvelopedData;

int    encode_EnvelopedData(unsigned char *, size_t, const EnvelopedData *, size_t *);
int    decode_EnvelopedData(const unsigned char *, size_t, EnvelopedData *, size_t *);
void   free_EnvelopedData  (EnvelopedData *);
size_t length_EnvelopedData(const EnvelopedData *);
int    copy_EnvelopedData  (const EnvelopedData *, EnvelopedData *);


/*
CMSRC2CBCParameter ::= SEQUENCE {
  rc2ParameterVersion   INTEGER (0..-1),
  iv                    OCTET STRING,
}
*/

typedef struct CMSRC2CBCParameter {
  unsigned int rc2ParameterVersion;
  heim_octet_string iv;
} CMSRC2CBCParameter;

int    encode_CMSRC2CBCParameter(unsigned char *, size_t, const CMSRC2CBCParameter *, size_t *);
int    decode_CMSRC2CBCParameter(const unsigned char *, size_t, CMSRC2CBCParameter *, size_t *);
void   free_CMSRC2CBCParameter  (CMSRC2CBCParameter *);
size_t length_CMSRC2CBCParameter(const CMSRC2CBCParameter *);
int    copy_CMSRC2CBCParameter  (const CMSRC2CBCParameter *, CMSRC2CBCParameter *);


/*
CMSCBCParameter ::= OCTET STRING
*/

typedef heim_octet_string CMSCBCParameter;

int    encode_CMSCBCParameter(unsigned char *, size_t, const CMSCBCParameter *, size_t *);
int    decode_CMSCBCParameter(const unsigned char *, size_t, CMSCBCParameter *, size_t *);
void   free_CMSCBCParameter  (CMSCBCParameter *);
size_t length_CMSCBCParameter(const CMSCBCParameter *);
int    copy_CMSCBCParameter  (const CMSCBCParameter *, CMSCBCParameter *);


#endif /* __cms_asn1_h__ */
