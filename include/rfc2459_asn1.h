/* Generated from /usr/src/kerberos5/lib/libasn1/../../../crypto/heimdal/lib/asn1/rfc2459.asn1 */
/* Do not edit */

#ifndef __rfc2459_asn1_h__
#define __rfc2459_asn1_h__

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

#include <heim_asn1.h>
/*
Version ::= INTEGER {
  rfc3280_version_1(0),
  rfc3280_version_2(1),
  rfc3280_version_3(2)
}
*/

typedef enum Version {
  rfc3280_version_1 = 0,
  rfc3280_version_2 = 1,
  rfc3280_version_3 = 2
} Version;

int    encode_Version(unsigned char *, size_t, const Version *, size_t *);
int    decode_Version(const unsigned char *, size_t, Version *, size_t *);
void   free_Version  (Version *);
size_t length_Version(const Version *);
int    copy_Version  (const Version *, Version *);


/* OBJECT IDENTIFIER id-pkcs-1 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(1) } */
const heim_oid *oid_id_pkcs_1(void);

/* OBJECT IDENTIFIER id-pkcs1-rsaEncryption ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(1) label-less(1) } */
const heim_oid *oid_id_pkcs1_rsaEncryption(void);

/* OBJECT IDENTIFIER id-pkcs1-md2WithRSAEncryption ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(1) label-less(2) } */
const heim_oid *oid_id_pkcs1_md2WithRSAEncryption(void);

/* OBJECT IDENTIFIER id-pkcs1-md5WithRSAEncryption ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(1) label-less(4) } */
const heim_oid *oid_id_pkcs1_md5WithRSAEncryption(void);

/* OBJECT IDENTIFIER id-pkcs1-sha1WithRSAEncryption ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(1) label-less(5) } */
const heim_oid *oid_id_pkcs1_sha1WithRSAEncryption(void);

/* OBJECT IDENTIFIER id-pkcs1-sha256WithRSAEncryption ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(1) label-less(11) } */
const heim_oid *oid_id_pkcs1_sha256WithRSAEncryption(void);

/* OBJECT IDENTIFIER id-pkcs1-sha384WithRSAEncryption ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(1) label-less(12) } */
const heim_oid *oid_id_pkcs1_sha384WithRSAEncryption(void);

/* OBJECT IDENTIFIER id-pkcs1-sha512WithRSAEncryption ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(1) label-less(13) } */
const heim_oid *oid_id_pkcs1_sha512WithRSAEncryption(void);

/* OBJECT IDENTIFIER id-heim-rsa-pkcs1-x509 ::= { label-less(1) label-less(2) label-less(752) label-less(43) label-less(16) label-less(1) } */
const heim_oid *oid_id_heim_rsa_pkcs1_x509(void);

/* OBJECT IDENTIFIER id-pkcs-2 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(2) } */
const heim_oid *oid_id_pkcs_2(void);

/* OBJECT IDENTIFIER id-pkcs2-md2 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(2) label-less(2) } */
const heim_oid *oid_id_pkcs2_md2(void);

/* OBJECT IDENTIFIER id-pkcs2-md4 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(2) label-less(4) } */
const heim_oid *oid_id_pkcs2_md4(void);

/* OBJECT IDENTIFIER id-pkcs2-md5 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(2) label-less(5) } */
const heim_oid *oid_id_pkcs2_md5(void);

/* OBJECT IDENTIFIER id-rsa-digestAlgorithm ::= { iso(1) member-body(2) us(840) rsadsi(113549) label-less(2) } */
const heim_oid *oid_id_rsa_digestAlgorithm(void);

/* OBJECT IDENTIFIER id-rsa-digest-md2 ::= { iso(1) member-body(2) us(840) rsadsi(113549) label-less(2) label-less(2) } */
const heim_oid *oid_id_rsa_digest_md2(void);

/* OBJECT IDENTIFIER id-rsa-digest-md4 ::= { iso(1) member-body(2) us(840) rsadsi(113549) label-less(2) label-less(4) } */
const heim_oid *oid_id_rsa_digest_md4(void);

/* OBJECT IDENTIFIER id-rsa-digest-md5 ::= { iso(1) member-body(2) us(840) rsadsi(113549) label-less(2) label-less(5) } */
const heim_oid *oid_id_rsa_digest_md5(void);

/* OBJECT IDENTIFIER id-pkcs-3 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(3) } */
const heim_oid *oid_id_pkcs_3(void);

/* OBJECT IDENTIFIER id-pkcs3-rc2-cbc ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(3) label-less(2) } */
const heim_oid *oid_id_pkcs3_rc2_cbc(void);

/* OBJECT IDENTIFIER id-pkcs3-rc4 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(3) label-less(4) } */
const heim_oid *oid_id_pkcs3_rc4(void);

/* OBJECT IDENTIFIER id-pkcs3-des-ede3-cbc ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) label-less(3) label-less(7) } */
const heim_oid *oid_id_pkcs3_des_ede3_cbc(void);

/* OBJECT IDENTIFIER id-rsadsi-encalg ::= { iso(1) member-body(2) us(840) rsadsi(113549) label-less(3) } */
const heim_oid *oid_id_rsadsi_encalg(void);

/* OBJECT IDENTIFIER id-rsadsi-rc2-cbc ::= { iso(1) member-body(2) us(840) rsadsi(113549) label-less(3) label-less(2) } */
const heim_oid *oid_id_rsadsi_rc2_cbc(void);

/* OBJECT IDENTIFIER id-rsadsi-des-ede3-cbc ::= { iso(1) member-body(2) us(840) rsadsi(113549) label-less(3) label-less(7) } */
const heim_oid *oid_id_rsadsi_des_ede3_cbc(void);

/* OBJECT IDENTIFIER id-secsig-sha-1 ::= { iso(1) identified-organization(3) oiw(14) secsig(3) algorithm(2) label-less(26) } */
const heim_oid *oid_id_secsig_sha_1(void);

/* OBJECT IDENTIFIER id-nistAlgorithm ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) } */
const heim_oid *oid_id_nistAlgorithm(void);

/* OBJECT IDENTIFIER id-nist-aes-algs ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(1) } */
const heim_oid *oid_id_nist_aes_algs(void);

/* OBJECT IDENTIFIER id-aes-128-cbc ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(1) label-less(2) } */
const heim_oid *oid_id_aes_128_cbc(void);

/* OBJECT IDENTIFIER id-aes-192-cbc ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(1) label-less(22) } */
const heim_oid *oid_id_aes_192_cbc(void);

/* OBJECT IDENTIFIER id-aes-256-cbc ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(1) label-less(42) } */
const heim_oid *oid_id_aes_256_cbc(void);

/* OBJECT IDENTIFIER id-nist-sha-algs ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(2) } */
const heim_oid *oid_id_nist_sha_algs(void);

/* OBJECT IDENTIFIER id-sha256 ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(2) label-less(1) } */
const heim_oid *oid_id_sha256(void);

/* OBJECT IDENTIFIER id-sha224 ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(2) label-less(4) } */
const heim_oid *oid_id_sha224(void);

/* OBJECT IDENTIFIER id-sha384 ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(2) label-less(2) } */
const heim_oid *oid_id_sha384(void);

/* OBJECT IDENTIFIER id-sha512 ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) label-less(4) label-less(2) label-less(3) } */
const heim_oid *oid_id_sha512(void);

/* OBJECT IDENTIFIER id-dhpublicnumber ::= { iso(1) member-body(2) us(840) ansi-x942(10046) number-type(2) label-less(1) } */
const heim_oid *oid_id_dhpublicnumber(void);

/* OBJECT IDENTIFIER id-x9-57 ::= { iso(1) member-body(2) us(840) ansi-x942(10046) label-less(4) } */
const heim_oid *oid_id_x9_57(void);

/* OBJECT IDENTIFIER id-dsa ::= { iso(1) member-body(2) us(840) ansi-x942(10046) label-less(4) label-less(1) } */
const heim_oid *oid_id_dsa(void);

/* OBJECT IDENTIFIER id-dsa-with-sha1 ::= { iso(1) member-body(2) us(840) ansi-x942(10046) label-less(4) label-less(3) } */
const heim_oid *oid_id_dsa_with_sha1(void);

/* OBJECT IDENTIFIER id-x520-at ::= { joint-iso-ccitt(2) ds(5) label-less(4) } */
const heim_oid *oid_id_x520_at(void);

/* OBJECT IDENTIFIER id-at-commonName ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(3) } */
const heim_oid *oid_id_at_commonName(void);

/* OBJECT IDENTIFIER id-at-surname ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(4) } */
const heim_oid *oid_id_at_surname(void);

/* OBJECT IDENTIFIER id-at-serialNumber ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(5) } */
const heim_oid *oid_id_at_serialNumber(void);

/* OBJECT IDENTIFIER id-at-countryName ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(6) } */
const heim_oid *oid_id_at_countryName(void);

/* OBJECT IDENTIFIER id-at-localityName ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(7) } */
const heim_oid *oid_id_at_localityName(void);

/* OBJECT IDENTIFIER id-at-stateOrProvinceName ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(8) } */
const heim_oid *oid_id_at_stateOrProvinceName(void);

/* OBJECT IDENTIFIER id-at-streetAddress ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(9) } */
const heim_oid *oid_id_at_streetAddress(void);

/* OBJECT IDENTIFIER id-at-organizationName ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(10) } */
const heim_oid *oid_id_at_organizationName(void);

/* OBJECT IDENTIFIER id-at-organizationalUnitName ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(11) } */
const heim_oid *oid_id_at_organizationalUnitName(void);

/* OBJECT IDENTIFIER id-at-name ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(41) } */
const heim_oid *oid_id_at_name(void);

/* OBJECT IDENTIFIER id-at-givenName ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(42) } */
const heim_oid *oid_id_at_givenName(void);

/* OBJECT IDENTIFIER id-at-initials ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(43) } */
const heim_oid *oid_id_at_initials(void);

/* OBJECT IDENTIFIER id-at-generationQualifier ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(44) } */
const heim_oid *oid_id_at_generationQualifier(void);

/* OBJECT IDENTIFIER id-at-pseudonym ::= { joint-iso-ccitt(2) ds(5) label-less(4) label-less(65) } */
const heim_oid *oid_id_at_pseudonym(void);

/* OBJECT IDENTIFIER id-Userid ::= { label-less(0) label-less(9) label-less(2342) label-less(19200300) label-less(100) label-less(1) label-less(1) } */
const heim_oid *oid_id_Userid(void);

/* OBJECT IDENTIFIER id-domainComponent ::= { label-less(0) label-less(9) label-less(2342) label-less(19200300) label-less(100) label-less(1) label-less(25) } */
const heim_oid *oid_id_domainComponent(void);

/* OBJECT IDENTIFIER id-x509-ce ::= { joint-iso-ccitt(2) ds(5) label-less(29) } */
const heim_oid *oid_id_x509_ce(void);

/*
AlgorithmIdentifier ::= SEQUENCE {
  algorithm         OBJECT IDENTIFIER,
  parameters      heim_any OPTIONAL,
}
*/

typedef struct AlgorithmIdentifier {
  heim_oid algorithm;
  heim_any *parameters;
} AlgorithmIdentifier;

int    encode_AlgorithmIdentifier(unsigned char *, size_t, const AlgorithmIdentifier *, size_t *);
int    decode_AlgorithmIdentifier(const unsigned char *, size_t, AlgorithmIdentifier *, size_t *);
void   free_AlgorithmIdentifier  (AlgorithmIdentifier *);
size_t length_AlgorithmIdentifier(const AlgorithmIdentifier *);
int    copy_AlgorithmIdentifier  (const AlgorithmIdentifier *, AlgorithmIdentifier *);


/*
AttributeType ::= OBJECT IDENTIFIER
*/

typedef heim_oid AttributeType;

int    encode_AttributeType(unsigned char *, size_t, const AttributeType *, size_t *);
int    decode_AttributeType(const unsigned char *, size_t, AttributeType *, size_t *);
void   free_AttributeType  (AttributeType *);
size_t length_AttributeType(const AttributeType *);
int    copy_AttributeType  (const AttributeType *, AttributeType *);


/*
AttributeValue ::= heim_any
*/

typedef heim_any AttributeValue;

int    encode_AttributeValue(unsigned char *, size_t, const AttributeValue *, size_t *);
int    decode_AttributeValue(const unsigned char *, size_t, AttributeValue *, size_t *);
void   free_AttributeValue  (AttributeValue *);
size_t length_AttributeValue(const AttributeValue *);
int    copy_AttributeValue  (const AttributeValue *, AttributeValue *);


/*
TeletexStringx ::= IMPLICIT OCTET STRING
*/

typedef heim_octet_string TeletexStringx;

int    encode_TeletexStringx(unsigned char *, size_t, const TeletexStringx *, size_t *);
int    decode_TeletexStringx(const unsigned char *, size_t, TeletexStringx *, size_t *);
void   free_TeletexStringx  (TeletexStringx *);
size_t length_TeletexStringx(const TeletexStringx *);
int    copy_TeletexStringx  (const TeletexStringx *, TeletexStringx *);


/*
DirectoryString ::= CHOICE {
  ia5String           IA5String,
  teletexString     TeletexStringx,
  printableString     PrintableString,
  universalString     UniversalString,
  utf8String          UTF8String,
  bmpString           BMPString,
}
*/

typedef struct DirectoryString {
  enum {
    choice_DirectoryString_ia5String = 1,
    choice_DirectoryString_teletexString,
    choice_DirectoryString_printableString,
    choice_DirectoryString_universalString,
    choice_DirectoryString_utf8String,
    choice_DirectoryString_bmpString
  } element;
  union {
    heim_ia5_string ia5String;
    TeletexStringx teletexString;
    heim_printable_string printableString;
    heim_universal_string universalString;
    heim_utf8_string utf8String;
    heim_bmp_string bmpString;
  } u;
} DirectoryString;

int    encode_DirectoryString(unsigned char *, size_t, const DirectoryString *, size_t *);
int    decode_DirectoryString(const unsigned char *, size_t, DirectoryString *, size_t *);
void   free_DirectoryString  (DirectoryString *);
size_t length_DirectoryString(const DirectoryString *);
int    copy_DirectoryString  (const DirectoryString *, DirectoryString *);


/*
Attribute ::= SEQUENCE {
  type            AttributeType,
  value           SET OF heim_any,
}
*/

typedef struct Attribute {
  AttributeType type;
  struct  {
    unsigned int len;
    heim_any *val;
  } value;
} Attribute;

int    encode_Attribute(unsigned char *, size_t, const Attribute *, size_t *);
int    decode_Attribute(const unsigned char *, size_t, Attribute *, size_t *);
void   free_Attribute  (Attribute *);
size_t length_Attribute(const Attribute *);
int    copy_Attribute  (const Attribute *, Attribute *);


/*
AttributeTypeAndValue ::= SEQUENCE {
  type            AttributeType,
  value           DirectoryString,
}
*/

typedef struct AttributeTypeAndValue {
  AttributeType type;
  DirectoryString value;
} AttributeTypeAndValue;

int    encode_AttributeTypeAndValue(unsigned char *, size_t, const AttributeTypeAndValue *, size_t *);
int    decode_AttributeTypeAndValue(const unsigned char *, size_t, AttributeTypeAndValue *, size_t *);
void   free_AttributeTypeAndValue  (AttributeTypeAndValue *);
size_t length_AttributeTypeAndValue(const AttributeTypeAndValue *);
int    copy_AttributeTypeAndValue  (const AttributeTypeAndValue *, AttributeTypeAndValue *);


/*
RelativeDistinguishedName ::= SET OF AttributeTypeAndValue
*/

typedef struct RelativeDistinguishedName {
  unsigned int len;
  AttributeTypeAndValue *val;
} RelativeDistinguishedName;

int    encode_RelativeDistinguishedName(unsigned char *, size_t, const RelativeDistinguishedName *, size_t *);
int    decode_RelativeDistinguishedName(const unsigned char *, size_t, RelativeDistinguishedName *, size_t *);
void   free_RelativeDistinguishedName  (RelativeDistinguishedName *);
size_t length_RelativeDistinguishedName(const RelativeDistinguishedName *);
int    copy_RelativeDistinguishedName  (const RelativeDistinguishedName *, RelativeDistinguishedName *);


/*
RDNSequence ::= SEQUENCE OF RelativeDistinguishedName
*/

typedef struct RDNSequence {
  unsigned int len;
  RelativeDistinguishedName *val;
} RDNSequence;

int    encode_RDNSequence(unsigned char *, size_t, const RDNSequence *, size_t *);
int    decode_RDNSequence(const unsigned char *, size_t, RDNSequence *, size_t *);
void   free_RDNSequence  (RDNSequence *);
size_t length_RDNSequence(const RDNSequence *);
int    copy_RDNSequence  (const RDNSequence *, RDNSequence *);


/*
Name ::= CHOICE {
  rdnSequence     RDNSequence,
}
*/

typedef struct Name {
  heim_octet_string _save;
  enum {
    choice_Name_rdnSequence = 1
  } element;
  union {
    RDNSequence rdnSequence;
  } u;
} Name;

int    encode_Name(unsigned char *, size_t, const Name *, size_t *);
int    decode_Name(const unsigned char *, size_t, Name *, size_t *);
void   free_Name  (Name *);
size_t length_Name(const Name *);
int    copy_Name  (const Name *, Name *);


/*
CertificateSerialNumber ::= INTEGER
*/

typedef heim_integer CertificateSerialNumber;

int    encode_CertificateSerialNumber(unsigned char *, size_t, const CertificateSerialNumber *, size_t *);
int    decode_CertificateSerialNumber(const unsigned char *, size_t, CertificateSerialNumber *, size_t *);
void   free_CertificateSerialNumber  (CertificateSerialNumber *);
size_t length_CertificateSerialNumber(const CertificateSerialNumber *);
int    copy_CertificateSerialNumber  (const CertificateSerialNumber *, CertificateSerialNumber *);


/*
Time ::= CHOICE {
  utcTime         UTCTime,
  generalTime     GeneralizedTime,
}
*/

typedef struct Time {
  enum {
    choice_Time_utcTime = 1,
    choice_Time_generalTime
  } element;
  union {
    time_t utcTime;
    time_t generalTime;
  } u;
} Time;

int    encode_Time(unsigned char *, size_t, const Time *, size_t *);
int    decode_Time(const unsigned char *, size_t, Time *, size_t *);
void   free_Time  (Time *);
size_t length_Time(const Time *);
int    copy_Time  (const Time *, Time *);


/*
Validity ::= SEQUENCE {
  notBefore       Time,
  notAfter        Time,
}
*/

typedef struct Validity {
  Time notBefore;
  Time notAfter;
} Validity;

int    encode_Validity(unsigned char *, size_t, const Validity *, size_t *);
int    decode_Validity(const unsigned char *, size_t, Validity *, size_t *);
void   free_Validity  (Validity *);
size_t length_Validity(const Validity *);
int    copy_Validity  (const Validity *, Validity *);


/*
UniqueIdentifier ::= BIT STRING {
}
*/

typedef heim_bit_string UniqueIdentifier;

int    encode_UniqueIdentifier(unsigned char *, size_t, const UniqueIdentifier *, size_t *);
int    decode_UniqueIdentifier(const unsigned char *, size_t, UniqueIdentifier *, size_t *);
void   free_UniqueIdentifier  (UniqueIdentifier *);
size_t length_UniqueIdentifier(const UniqueIdentifier *);
int    copy_UniqueIdentifier  (const UniqueIdentifier *, UniqueIdentifier *);


/*
SubjectPublicKeyInfo ::= SEQUENCE {
  algorithm          AlgorithmIdentifier,
  subjectPublicKey     BIT STRING {
  },
}
*/

typedef struct SubjectPublicKeyInfo {
  AlgorithmIdentifier algorithm;
  heim_bit_string subjectPublicKey;
} SubjectPublicKeyInfo;

int    encode_SubjectPublicKeyInfo(unsigned char *, size_t, const SubjectPublicKeyInfo *, size_t *);
int    decode_SubjectPublicKeyInfo(const unsigned char *, size_t, SubjectPublicKeyInfo *, size_t *);
void   free_SubjectPublicKeyInfo  (SubjectPublicKeyInfo *);
size_t length_SubjectPublicKeyInfo(const SubjectPublicKeyInfo *);
int    copy_SubjectPublicKeyInfo  (const SubjectPublicKeyInfo *, SubjectPublicKeyInfo *);


/*
Extension ::= SEQUENCE {
  extnID            OBJECT IDENTIFIER,
  critical        BOOLEAN OPTIONAL,
  extnValue       OCTET STRING,
}
*/

typedef struct Extension {
  heim_oid extnID;
  int *critical;
  heim_octet_string extnValue;
} Extension;

int    encode_Extension(unsigned char *, size_t, const Extension *, size_t *);
int    decode_Extension(const unsigned char *, size_t, Extension *, size_t *);
void   free_Extension  (Extension *);
size_t length_Extension(const Extension *);
int    copy_Extension  (const Extension *, Extension *);


/*
Extensions ::= SEQUENCE OF Extension
*/

typedef struct Extensions {
  unsigned int len;
  Extension *val;
} Extensions;

int    encode_Extensions(unsigned char *, size_t, const Extensions *, size_t *);
int    decode_Extensions(const unsigned char *, size_t, Extensions *, size_t *);
void   free_Extensions  (Extensions *);
size_t length_Extensions(const Extensions *);
int    copy_Extensions  (const Extensions *, Extensions *);
int   add_Extensions  (Extensions *, const Extension *);
int   remove_Extensions  (Extensions *, unsigned int);


/*
TBSCertificate ::= SEQUENCE {
  version                [0] Version OPTIONAL,
  serialNumber           CertificateSerialNumber,
  signature              AlgorithmIdentifier,
  issuer                 Name,
  validity               Validity,
  subject                Name,
  subjectPublicKeyInfo   SubjectPublicKeyInfo,
  issuerUniqueID         [1] IMPLICIT   BIT STRING {
  } OPTIONAL,
  subjectUniqueID        [2] IMPLICIT   BIT STRING {
  } OPTIONAL,
  extensions             [3] Extensions OPTIONAL,
}
*/

typedef struct TBSCertificate {
  heim_octet_string _save;
  Version *version;
  CertificateSerialNumber serialNumber;
  AlgorithmIdentifier signature;
  Name issuer;
  Validity validity;
  Name subject;
  SubjectPublicKeyInfo subjectPublicKeyInfo;
  heim_bit_string *issuerUniqueID;
  heim_bit_string *subjectUniqueID;
  Extensions *extensions;
} TBSCertificate;

int    encode_TBSCertificate(unsigned char *, size_t, const TBSCertificate *, size_t *);
int    decode_TBSCertificate(const unsigned char *, size_t, TBSCertificate *, size_t *);
void   free_TBSCertificate  (TBSCertificate *);
size_t length_TBSCertificate(const TBSCertificate *);
int    copy_TBSCertificate  (const TBSCertificate *, TBSCertificate *);


/*
Certificate ::= SEQUENCE {
  tbsCertificate       TBSCertificate,
  signatureAlgorithm   AlgorithmIdentifier,
  signatureValue         BIT STRING {
  },
}
*/

typedef struct Certificate {
  TBSCertificate tbsCertificate;
  AlgorithmIdentifier signatureAlgorithm;
  heim_bit_string signatureValue;
} Certificate;

int    encode_Certificate(unsigned char *, size_t, const Certificate *, size_t *);
int    decode_Certificate(const unsigned char *, size_t, Certificate *, size_t *);
void   free_Certificate  (Certificate *);
size_t length_Certificate(const Certificate *);
int    copy_Certificate  (const Certificate *, Certificate *);


/*
Certificates ::= SEQUENCE OF Certificate
*/

typedef struct Certificates {
  unsigned int len;
  Certificate *val;
} Certificates;

int    encode_Certificates(unsigned char *, size_t, const Certificates *, size_t *);
int    decode_Certificates(const unsigned char *, size_t, Certificates *, size_t *);
void   free_Certificates  (Certificates *);
size_t length_Certificates(const Certificates *);
int    copy_Certificates  (const Certificates *, Certificates *);


/*
ValidationParms ::= SEQUENCE {
  seed              BIT STRING {
  },
  pgenCounter     INTEGER,
}
*/

typedef struct ValidationParms {
  heim_bit_string seed;
  heim_integer pgenCounter;
} ValidationParms;

int    encode_ValidationParms(unsigned char *, size_t, const ValidationParms *, size_t *);
int    decode_ValidationParms(const unsigned char *, size_t, ValidationParms *, size_t *);
void   free_ValidationParms  (ValidationParms *);
size_t length_ValidationParms(const ValidationParms *);
int    copy_ValidationParms  (const ValidationParms *, ValidationParms *);


/*
DomainParameters ::= SEQUENCE {
  p                 INTEGER,
  g                 INTEGER,
  q                 INTEGER,
  j                 INTEGER OPTIONAL,
  validationParms   ValidationParms OPTIONAL,
}
*/

typedef struct DomainParameters {
  heim_integer p;
  heim_integer g;
  heim_integer q;
  heim_integer *j;
  ValidationParms *validationParms;
} DomainParameters;

int    encode_DomainParameters(unsigned char *, size_t, const DomainParameters *, size_t *);
int    decode_DomainParameters(const unsigned char *, size_t, DomainParameters *, size_t *);
void   free_DomainParameters  (DomainParameters *);
size_t length_DomainParameters(const DomainParameters *);
int    copy_DomainParameters  (const DomainParameters *, DomainParameters *);


/*
DHPublicKey ::= INTEGER
*/

typedef heim_integer DHPublicKey;

int    encode_DHPublicKey(unsigned char *, size_t, const DHPublicKey *, size_t *);
int    decode_DHPublicKey(const unsigned char *, size_t, DHPublicKey *, size_t *);
void   free_DHPublicKey  (DHPublicKey *);
size_t length_DHPublicKey(const DHPublicKey *);
int    copy_DHPublicKey  (const DHPublicKey *, DHPublicKey *);


/*
OtherName ::= SEQUENCE {
  type-id           OBJECT IDENTIFIER,
  value           [0] heim_any,
}
*/

typedef struct OtherName {
  heim_oid type_id;
  heim_any value;
} OtherName;

int    encode_OtherName(unsigned char *, size_t, const OtherName *, size_t *);
int    decode_OtherName(const unsigned char *, size_t, OtherName *, size_t *);
void   free_OtherName  (OtherName *);
size_t length_OtherName(const OtherName *);
int    copy_OtherName  (const OtherName *, OtherName *);


/*
GeneralName ::= CHOICE {
  otherName                   [0] IMPLICIT SEQUENCE {
    type-id             OBJECT IDENTIFIER,
    value           [0] heim_any,
  },
  rfc822Name                  [1] IMPLICIT   IA5String,
  dNSName                     [2] IMPLICIT   IA5String,
  directoryName               [4] IMPLICIT CHOICE {
    rdnSequence     RDNSequence,
  },
  uniformResourceIdentifier   [6] IMPLICIT   IA5String,
  iPAddress                   [7] IMPLICIT OCTET STRING,
  registeredID                [8] IMPLICIT   OBJECT IDENTIFIER,
}
*/

typedef struct GeneralName {
  enum {
    choice_GeneralName_otherName = 1,
    choice_GeneralName_rfc822Name,
    choice_GeneralName_dNSName,
    choice_GeneralName_directoryName,
    choice_GeneralName_uniformResourceIdentifier,
    choice_GeneralName_iPAddress,
    choice_GeneralName_registeredID
  } element;
  union {
    struct  {
      heim_oid type_id;
      heim_any value;
    } otherName;
    heim_ia5_string rfc822Name;
    heim_ia5_string dNSName;
    struct  {
      enum {
        choice_GeneralName_directoryName_rdnSequence = 1
      } element;
      union {
        RDNSequence rdnSequence;
      } u;
    } directoryName;
    heim_ia5_string uniformResourceIdentifier;
    heim_octet_string iPAddress;
    heim_oid registeredID;
  } u;
} GeneralName;

int    encode_GeneralName(unsigned char *, size_t, const GeneralName *, size_t *);
int    decode_GeneralName(const unsigned char *, size_t, GeneralName *, size_t *);
void   free_GeneralName  (GeneralName *);
size_t length_GeneralName(const GeneralName *);
int    copy_GeneralName  (const GeneralName *, GeneralName *);


/*
GeneralNames ::= SEQUENCE OF GeneralName
*/

typedef struct GeneralNames {
  unsigned int len;
  GeneralName *val;
} GeneralNames;

int    encode_GeneralNames(unsigned char *, size_t, const GeneralNames *, size_t *);
int    decode_GeneralNames(const unsigned char *, size_t, GeneralNames *, size_t *);
void   free_GeneralNames  (GeneralNames *);
size_t length_GeneralNames(const GeneralNames *);
int    copy_GeneralNames  (const GeneralNames *, GeneralNames *);
int   add_GeneralNames  (GeneralNames *, const GeneralName *);
int   remove_GeneralNames  (GeneralNames *, unsigned int);


/* OBJECT IDENTIFIER id-x509-ce-keyUsage ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(15) } */
const heim_oid *oid_id_x509_ce_keyUsage(void);

/*
KeyUsage ::= BIT STRING {
  digitalSignature(0),
  nonRepudiation(1),
  keyEncipherment(2),
  dataEncipherment(3),
  keyAgreement(4),
  keyCertSign(5),
  cRLSign(6),
  encipherOnly(7),
  decipherOnly(8)
}
*/

typedef struct KeyUsage {
  unsigned int digitalSignature:1;
  unsigned int nonRepudiation:1;
  unsigned int keyEncipherment:1;
  unsigned int dataEncipherment:1;
  unsigned int keyAgreement:1;
  unsigned int keyCertSign:1;
  unsigned int cRLSign:1;
  unsigned int encipherOnly:1;
  unsigned int decipherOnly:1;
} KeyUsage;


int    encode_KeyUsage(unsigned char *, size_t, const KeyUsage *, size_t *);
int    decode_KeyUsage(const unsigned char *, size_t, KeyUsage *, size_t *);
void   free_KeyUsage  (KeyUsage *);
size_t length_KeyUsage(const KeyUsage *);
int    copy_KeyUsage  (const KeyUsage *, KeyUsage *);
unsigned KeyUsage2int(KeyUsage);
KeyUsage int2KeyUsage(unsigned);
#ifdef __PARSE_UNITS_H__
const struct units * asn1_KeyUsage_units(void);
#endif


/* OBJECT IDENTIFIER id-x509-ce-authorityKeyIdentifier ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(35) } */
const heim_oid *oid_id_x509_ce_authorityKeyIdentifier(void);

/*
KeyIdentifier ::= OCTET STRING
*/

typedef heim_octet_string KeyIdentifier;

int    encode_KeyIdentifier(unsigned char *, size_t, const KeyIdentifier *, size_t *);
int    decode_KeyIdentifier(const unsigned char *, size_t, KeyIdentifier *, size_t *);
void   free_KeyIdentifier  (KeyIdentifier *);
size_t length_KeyIdentifier(const KeyIdentifier *);
int    copy_KeyIdentifier  (const KeyIdentifier *, KeyIdentifier *);


/*
AuthorityKeyIdentifier ::= SEQUENCE {
  keyIdentifier               [0] IMPLICIT OCTET STRING OPTIONAL,
  authorityCertIssuer         [1] IMPLICIT SEQUENCE OF GeneralName OPTIONAL,
  authorityCertSerialNumber   [2] IMPLICIT INTEGER OPTIONAL,
}
*/

typedef struct AuthorityKeyIdentifier {
  heim_octet_string *keyIdentifier;
  struct  {
    unsigned int len;
    GeneralName *val;
  } *authorityCertIssuer;
  heim_integer *authorityCertSerialNumber;
} AuthorityKeyIdentifier;

int    encode_AuthorityKeyIdentifier(unsigned char *, size_t, const AuthorityKeyIdentifier *, size_t *);
int    decode_AuthorityKeyIdentifier(const unsigned char *, size_t, AuthorityKeyIdentifier *, size_t *);
void   free_AuthorityKeyIdentifier  (AuthorityKeyIdentifier *);
size_t length_AuthorityKeyIdentifier(const AuthorityKeyIdentifier *);
int    copy_AuthorityKeyIdentifier  (const AuthorityKeyIdentifier *, AuthorityKeyIdentifier *);


/* OBJECT IDENTIFIER id-x509-ce-subjectKeyIdentifier ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(14) } */
const heim_oid *oid_id_x509_ce_subjectKeyIdentifier(void);

/*
SubjectKeyIdentifier ::= KeyIdentifier
*/

typedef KeyIdentifier SubjectKeyIdentifier;

int    encode_SubjectKeyIdentifier(unsigned char *, size_t, const SubjectKeyIdentifier *, size_t *);
int    decode_SubjectKeyIdentifier(const unsigned char *, size_t, SubjectKeyIdentifier *, size_t *);
void   free_SubjectKeyIdentifier  (SubjectKeyIdentifier *);
size_t length_SubjectKeyIdentifier(const SubjectKeyIdentifier *);
int    copy_SubjectKeyIdentifier  (const SubjectKeyIdentifier *, SubjectKeyIdentifier *);


/* OBJECT IDENTIFIER id-x509-ce-basicConstraints ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(19) } */
const heim_oid *oid_id_x509_ce_basicConstraints(void);

/*
BasicConstraints ::= SEQUENCE {
  cA                  BOOLEAN OPTIONAL,
  pathLenConstraint   INTEGER (0..-1) OPTIONAL,
}
*/

typedef struct BasicConstraints {
  int *cA;
  unsigned int *pathLenConstraint;
} BasicConstraints;

int    encode_BasicConstraints(unsigned char *, size_t, const BasicConstraints *, size_t *);
int    decode_BasicConstraints(const unsigned char *, size_t, BasicConstraints *, size_t *);
void   free_BasicConstraints  (BasicConstraints *);
size_t length_BasicConstraints(const BasicConstraints *);
int    copy_BasicConstraints  (const BasicConstraints *, BasicConstraints *);


/* OBJECT IDENTIFIER id-x509-ce-nameConstraints ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(30) } */
const heim_oid *oid_id_x509_ce_nameConstraints(void);

/*
BaseDistance ::= INTEGER
*/

typedef heim_integer BaseDistance;

int    encode_BaseDistance(unsigned char *, size_t, const BaseDistance *, size_t *);
int    decode_BaseDistance(const unsigned char *, size_t, BaseDistance *, size_t *);
void   free_BaseDistance  (BaseDistance *);
size_t length_BaseDistance(const BaseDistance *);
int    copy_BaseDistance  (const BaseDistance *, BaseDistance *);


/*
GeneralSubtree ::= SEQUENCE {
  base            GeneralName,
  minimum         [0] IMPLICIT INTEGER OPTIONAL,
  maximum         [1] IMPLICIT INTEGER OPTIONAL,
}
*/

typedef struct GeneralSubtree {
  GeneralName base;
  heim_integer *minimum;
  heim_integer *maximum;
} GeneralSubtree;

int    encode_GeneralSubtree(unsigned char *, size_t, const GeneralSubtree *, size_t *);
int    decode_GeneralSubtree(const unsigned char *, size_t, GeneralSubtree *, size_t *);
void   free_GeneralSubtree  (GeneralSubtree *);
size_t length_GeneralSubtree(const GeneralSubtree *);
int    copy_GeneralSubtree  (const GeneralSubtree *, GeneralSubtree *);


/*
GeneralSubtrees ::= SEQUENCE OF GeneralSubtree
*/

typedef struct GeneralSubtrees {
  unsigned int len;
  GeneralSubtree *val;
} GeneralSubtrees;

int    encode_GeneralSubtrees(unsigned char *, size_t, const GeneralSubtrees *, size_t *);
int    decode_GeneralSubtrees(const unsigned char *, size_t, GeneralSubtrees *, size_t *);
void   free_GeneralSubtrees  (GeneralSubtrees *);
size_t length_GeneralSubtrees(const GeneralSubtrees *);
int    copy_GeneralSubtrees  (const GeneralSubtrees *, GeneralSubtrees *);


/*
NameConstraints ::= SEQUENCE {
  permittedSubtrees   [0] IMPLICIT SEQUENCE OF GeneralSubtree OPTIONAL,
  excludedSubtrees    [1] IMPLICIT SEQUENCE OF GeneralSubtree OPTIONAL,
}
*/

typedef struct NameConstraints {
  struct  {
    unsigned int len;
    GeneralSubtree *val;
  } *permittedSubtrees;
  struct  {
    unsigned int len;
    GeneralSubtree *val;
  } *excludedSubtrees;
} NameConstraints;

int    encode_NameConstraints(unsigned char *, size_t, const NameConstraints *, size_t *);
int    decode_NameConstraints(const unsigned char *, size_t, NameConstraints *, size_t *);
void   free_NameConstraints  (NameConstraints *);
size_t length_NameConstraints(const NameConstraints *);
int    copy_NameConstraints  (const NameConstraints *, NameConstraints *);


/* OBJECT IDENTIFIER id-x509-ce-privateKeyUsagePeriod ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(16) } */
const heim_oid *oid_id_x509_ce_privateKeyUsagePeriod(void);

/* OBJECT IDENTIFIER id-x509-ce-certificatePolicies ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(32) } */
const heim_oid *oid_id_x509_ce_certificatePolicies(void);

/* OBJECT IDENTIFIER id-x509-ce-policyMappings ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(33) } */
const heim_oid *oid_id_x509_ce_policyMappings(void);

/* OBJECT IDENTIFIER id-x509-ce-subjectAltName ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(17) } */
const heim_oid *oid_id_x509_ce_subjectAltName(void);

/* OBJECT IDENTIFIER id-x509-ce-issuerAltName ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(18) } */
const heim_oid *oid_id_x509_ce_issuerAltName(void);

/* OBJECT IDENTIFIER id-x509-ce-subjectDirectoryAttributes ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(9) } */
const heim_oid *oid_id_x509_ce_subjectDirectoryAttributes(void);

/* OBJECT IDENTIFIER id-x509-ce-policyConstraints ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(36) } */
const heim_oid *oid_id_x509_ce_policyConstraints(void);

/* OBJECT IDENTIFIER id-x509-ce-extKeyUsage ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(37) } */
const heim_oid *oid_id_x509_ce_extKeyUsage(void);

/*
ExtKeyUsage ::= SEQUENCE OF OBJECT IDENTIFIER
*/

typedef struct ExtKeyUsage {
  unsigned int len;
  heim_oid *val;
} ExtKeyUsage;

int    encode_ExtKeyUsage(unsigned char *, size_t, const ExtKeyUsage *, size_t *);
int    decode_ExtKeyUsage(const unsigned char *, size_t, ExtKeyUsage *, size_t *);
void   free_ExtKeyUsage  (ExtKeyUsage *);
size_t length_ExtKeyUsage(const ExtKeyUsage *);
int    copy_ExtKeyUsage  (const ExtKeyUsage *, ExtKeyUsage *);


/* OBJECT IDENTIFIER id-x509-ce-cRLDistributionPoints ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(31) } */
const heim_oid *oid_id_x509_ce_cRLDistributionPoints(void);

/* OBJECT IDENTIFIER id-x509-ce-deltaCRLIndicator ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(27) } */
const heim_oid *oid_id_x509_ce_deltaCRLIndicator(void);

/* OBJECT IDENTIFIER id-x509-ce-issuingDistributionPoint ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(28) } */
const heim_oid *oid_id_x509_ce_issuingDistributionPoint(void);

/* OBJECT IDENTIFIER id-x509-ce-holdInstructionCode ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(23) } */
const heim_oid *oid_id_x509_ce_holdInstructionCode(void);

/* OBJECT IDENTIFIER id-x509-ce-invalidityDate ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(24) } */
const heim_oid *oid_id_x509_ce_invalidityDate(void);

/* OBJECT IDENTIFIER id-x509-ce-certificateIssuer ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(29) } */
const heim_oid *oid_id_x509_ce_certificateIssuer(void);

/* OBJECT IDENTIFIER id-x509-ce-inhibitAnyPolicy ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(54) } */
const heim_oid *oid_id_x509_ce_inhibitAnyPolicy(void);

/*
DistributionPointReasonFlags ::= BIT STRING {
  unused(0),
  keyCompromise(1),
  cACompromise(2),
  affiliationChanged(3),
  superseded(4),
  cessationOfOperation(5),
  certificateHold(6),
  privilegeWithdrawn(7),
  aACompromise(8)
}
*/

typedef struct DistributionPointReasonFlags {
  unsigned int unused:1;
  unsigned int keyCompromise:1;
  unsigned int cACompromise:1;
  unsigned int affiliationChanged:1;
  unsigned int superseded:1;
  unsigned int cessationOfOperation:1;
  unsigned int certificateHold:1;
  unsigned int privilegeWithdrawn:1;
  unsigned int aACompromise:1;
} DistributionPointReasonFlags;


int    encode_DistributionPointReasonFlags(unsigned char *, size_t, const DistributionPointReasonFlags *, size_t *);
int    decode_DistributionPointReasonFlags(const unsigned char *, size_t, DistributionPointReasonFlags *, size_t *);
void   free_DistributionPointReasonFlags  (DistributionPointReasonFlags *);
size_t length_DistributionPointReasonFlags(const DistributionPointReasonFlags *);
int    copy_DistributionPointReasonFlags  (const DistributionPointReasonFlags *, DistributionPointReasonFlags *);
unsigned DistributionPointReasonFlags2int(DistributionPointReasonFlags);
DistributionPointReasonFlags int2DistributionPointReasonFlags(unsigned);
#ifdef __PARSE_UNITS_H__
const struct units * asn1_DistributionPointReasonFlags_units(void);
#endif


/*
DistributionPointName ::= CHOICE {
  fullName                  [0] IMPLICIT SEQUENCE OF GeneralName,
  nameRelativeToCRLIssuer   [1] RelativeDistinguishedName,
}
*/

typedef struct DistributionPointName {
  enum {
    choice_DistributionPointName_fullName = 1,
    choice_DistributionPointName_nameRelativeToCRLIssuer
  } element;
  union {
    struct  {
      unsigned int len;
      GeneralName *val;
    } fullName;
    RelativeDistinguishedName nameRelativeToCRLIssuer;
  } u;
} DistributionPointName;

int    encode_DistributionPointName(unsigned char *, size_t, const DistributionPointName *, size_t *);
int    decode_DistributionPointName(const unsigned char *, size_t, DistributionPointName *, size_t *);
void   free_DistributionPointName  (DistributionPointName *);
size_t length_DistributionPointName(const DistributionPointName *);
int    copy_DistributionPointName  (const DistributionPointName *, DistributionPointName *);


/*
DistributionPoint ::= SEQUENCE {
  distributionPoint   [0] IMPLICIT heim_any OPTIONAL,
  reasons             [1] IMPLICIT heim_any OPTIONAL,
  cRLIssuer           [2] IMPLICIT heim_any OPTIONAL,
}
*/

typedef struct DistributionPoint {
  heim_any *distributionPoint;
  heim_any *reasons;
  heim_any *cRLIssuer;
} DistributionPoint;

int    encode_DistributionPoint(unsigned char *, size_t, const DistributionPoint *, size_t *);
int    decode_DistributionPoint(const unsigned char *, size_t, DistributionPoint *, size_t *);
void   free_DistributionPoint  (DistributionPoint *);
size_t length_DistributionPoint(const DistributionPoint *);
int    copy_DistributionPoint  (const DistributionPoint *, DistributionPoint *);


/*
CRLDistributionPoints ::= SEQUENCE OF DistributionPoint
*/

typedef struct CRLDistributionPoints {
  unsigned int len;
  DistributionPoint *val;
} CRLDistributionPoints;

int    encode_CRLDistributionPoints(unsigned char *, size_t, const CRLDistributionPoints *, size_t *);
int    decode_CRLDistributionPoints(const unsigned char *, size_t, CRLDistributionPoints *, size_t *);
void   free_CRLDistributionPoints  (CRLDistributionPoints *);
size_t length_CRLDistributionPoints(const CRLDistributionPoints *);
int    copy_CRLDistributionPoints  (const CRLDistributionPoints *, CRLDistributionPoints *);
int   add_CRLDistributionPoints  (CRLDistributionPoints *, const DistributionPoint *);
int   remove_CRLDistributionPoints  (CRLDistributionPoints *, unsigned int);


/*
DSASigValue ::= SEQUENCE {
  r               INTEGER,
  s               INTEGER,
}
*/

typedef struct DSASigValue {
  heim_integer r;
  heim_integer s;
} DSASigValue;

int    encode_DSASigValue(unsigned char *, size_t, const DSASigValue *, size_t *);
int    decode_DSASigValue(const unsigned char *, size_t, DSASigValue *, size_t *);
void   free_DSASigValue  (DSASigValue *);
size_t length_DSASigValue(const DSASigValue *);
int    copy_DSASigValue  (const DSASigValue *, DSASigValue *);


/*
DSAPublicKey ::= INTEGER
*/

typedef heim_integer DSAPublicKey;

int    encode_DSAPublicKey(unsigned char *, size_t, const DSAPublicKey *, size_t *);
int    decode_DSAPublicKey(const unsigned char *, size_t, DSAPublicKey *, size_t *);
void   free_DSAPublicKey  (DSAPublicKey *);
size_t length_DSAPublicKey(const DSAPublicKey *);
int    copy_DSAPublicKey  (const DSAPublicKey *, DSAPublicKey *);


/*
DSAParams ::= SEQUENCE {
  p               INTEGER,
  q               INTEGER,
  g               INTEGER,
}
*/

typedef struct DSAParams {
  heim_integer p;
  heim_integer q;
  heim_integer g;
} DSAParams;

int    encode_DSAParams(unsigned char *, size_t, const DSAParams *, size_t *);
int    decode_DSAParams(const unsigned char *, size_t, DSAParams *, size_t *);
void   free_DSAParams  (DSAParams *);
size_t length_DSAParams(const DSAParams *);
int    copy_DSAParams  (const DSAParams *, DSAParams *);


/*
RSAPublicKey ::= SEQUENCE {
  modulus          INTEGER,
  publicExponent   INTEGER,
}
*/

typedef struct RSAPublicKey {
  heim_integer modulus;
  heim_integer publicExponent;
} RSAPublicKey;

int    encode_RSAPublicKey(unsigned char *, size_t, const RSAPublicKey *, size_t *);
int    decode_RSAPublicKey(const unsigned char *, size_t, RSAPublicKey *, size_t *);
void   free_RSAPublicKey  (RSAPublicKey *);
size_t length_RSAPublicKey(const RSAPublicKey *);
int    copy_RSAPublicKey  (const RSAPublicKey *, RSAPublicKey *);


/*
RSAPrivateKey ::= SEQUENCE {
  version           INTEGER (0..-1),
  modulus           INTEGER,
  publicExponent    INTEGER,
  privateExponent   INTEGER,
  prime1            INTEGER,
  prime2            INTEGER,
  exponent1         INTEGER,
  exponent2         INTEGER,
  coefficient       INTEGER,
}
*/

typedef struct RSAPrivateKey {
  unsigned int version;
  heim_integer modulus;
  heim_integer publicExponent;
  heim_integer privateExponent;
  heim_integer prime1;
  heim_integer prime2;
  heim_integer exponent1;
  heim_integer exponent2;
  heim_integer coefficient;
} RSAPrivateKey;

int    encode_RSAPrivateKey(unsigned char *, size_t, const RSAPrivateKey *, size_t *);
int    decode_RSAPrivateKey(const unsigned char *, size_t, RSAPrivateKey *, size_t *);
void   free_RSAPrivateKey  (RSAPrivateKey *);
size_t length_RSAPrivateKey(const RSAPrivateKey *);
int    copy_RSAPrivateKey  (const RSAPrivateKey *, RSAPrivateKey *);


/*
DigestInfo ::= SEQUENCE {
  digestAlgorithm   AlgorithmIdentifier,
  digest            OCTET STRING,
}
*/

typedef struct DigestInfo {
  AlgorithmIdentifier digestAlgorithm;
  heim_octet_string digest;
} DigestInfo;

int    encode_DigestInfo(unsigned char *, size_t, const DigestInfo *, size_t *);
int    decode_DigestInfo(const unsigned char *, size_t, DigestInfo *, size_t *);
void   free_DigestInfo  (DigestInfo *);
size_t length_DigestInfo(const DigestInfo *);
int    copy_DigestInfo  (const DigestInfo *, DigestInfo *);


/*
TBSCRLCertList ::= SEQUENCE {
  version               Version OPTIONAL,
  signature             AlgorithmIdentifier,
  issuer                Name,
  thisUpdate            Time,
  nextUpdate            Time OPTIONAL,
  revokedCertificates   SEQUENCE OF SEQUENCE {
  userCertificate      CertificateSerialNumber,
  revocationDate       Time,
  crlEntryExtensions   Extensions OPTIONAL,
} OPTIONAL,
  crlExtensions         [0] Extensions OPTIONAL,
}
*/

typedef struct TBSCRLCertList {
  heim_octet_string _save;
  Version *version;
  AlgorithmIdentifier signature;
  Name issuer;
  Time thisUpdate;
  Time *nextUpdate;
  struct  {
    unsigned int len;
    struct  {
      CertificateSerialNumber userCertificate;
      Time revocationDate;
      Extensions *crlEntryExtensions;
    } *val;
  } *revokedCertificates;
  Extensions *crlExtensions;
} TBSCRLCertList;

int    encode_TBSCRLCertList(unsigned char *, size_t, const TBSCRLCertList *, size_t *);
int    decode_TBSCRLCertList(const unsigned char *, size_t, TBSCRLCertList *, size_t *);
void   free_TBSCRLCertList  (TBSCRLCertList *);
size_t length_TBSCRLCertList(const TBSCRLCertList *);
int    copy_TBSCRLCertList  (const TBSCRLCertList *, TBSCRLCertList *);


/*
CRLCertificateList ::= SEQUENCE {
  tbsCertList          TBSCRLCertList,
  signatureAlgorithm   AlgorithmIdentifier,
  signatureValue         BIT STRING {
  },
}
*/

typedef struct CRLCertificateList {
  TBSCRLCertList tbsCertList;
  AlgorithmIdentifier signatureAlgorithm;
  heim_bit_string signatureValue;
} CRLCertificateList;

int    encode_CRLCertificateList(unsigned char *, size_t, const CRLCertificateList *, size_t *);
int    decode_CRLCertificateList(const unsigned char *, size_t, CRLCertificateList *, size_t *);
void   free_CRLCertificateList  (CRLCertificateList *);
size_t length_CRLCertificateList(const CRLCertificateList *);
int    copy_CRLCertificateList  (const CRLCertificateList *, CRLCertificateList *);


/* OBJECT IDENTIFIER id-x509-ce-cRLNumber ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(20) } */
const heim_oid *oid_id_x509_ce_cRLNumber(void);

/* OBJECT IDENTIFIER id-x509-ce-freshestCRL ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(46) } */
const heim_oid *oid_id_x509_ce_freshestCRL(void);

/* OBJECT IDENTIFIER id-x509-ce-cRLReason ::= { joint-iso-ccitt(2) ds(5) label-less(29) label-less(21) } */
const heim_oid *oid_id_x509_ce_cRLReason(void);

/*
CRLReason ::= INTEGER {
  unspecified(0),
  keyCompromise(1),
  cACompromise(2),
  affiliationChanged(3),
  superseded(4),
  cessationOfOperation(5),
  certificateHold(6),
  removeFromCRL(8),
  privilegeWithdrawn(9),
  aACompromise(10)
}
*/

typedef enum CRLReason {
  unspecified = 0,
  keyCompromise = 1,
  cACompromise = 2,
  affiliationChanged = 3,
  superseded = 4,
  cessationOfOperation = 5,
  certificateHold = 6,
  removeFromCRL = 8,
  privilegeWithdrawn = 9,
  aACompromise = 10
} CRLReason;

int    encode_CRLReason(unsigned char *, size_t, const CRLReason *, size_t *);
int    decode_CRLReason(const unsigned char *, size_t, CRLReason *, size_t *);
void   free_CRLReason  (CRLReason *);
size_t length_CRLReason(const CRLReason *);
int    copy_CRLReason  (const CRLReason *, CRLReason *);


/*
PKIXXmppAddr ::= UTF8String
*/

typedef heim_utf8_string PKIXXmppAddr;

int    encode_PKIXXmppAddr(unsigned char *, size_t, const PKIXXmppAddr *, size_t *);
int    decode_PKIXXmppAddr(const unsigned char *, size_t, PKIXXmppAddr *, size_t *);
void   free_PKIXXmppAddr  (PKIXXmppAddr *);
size_t length_PKIXXmppAddr(const PKIXXmppAddr *);
int    copy_PKIXXmppAddr  (const PKIXXmppAddr *, PKIXXmppAddr *);


/* OBJECT IDENTIFIER id-pkix ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) } */
const heim_oid *oid_id_pkix(void);

/* OBJECT IDENTIFIER id-pkix-on ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(8) } */
const heim_oid *oid_id_pkix_on(void);

/* OBJECT IDENTIFIER id-pkix-on-xmppAddr ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(8) label-less(5) } */
const heim_oid *oid_id_pkix_on_xmppAddr(void);

/* OBJECT IDENTIFIER id-pkix-on-dnsSRV ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(8) label-less(7) } */
const heim_oid *oid_id_pkix_on_dnsSRV(void);

/* OBJECT IDENTIFIER id-pkix-kp ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(3) } */
const heim_oid *oid_id_pkix_kp(void);

/* OBJECT IDENTIFIER id-pkix-kp-serverAuth ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(3) label-less(1) } */
const heim_oid *oid_id_pkix_kp_serverAuth(void);

/* OBJECT IDENTIFIER id-pkix-kp-clientAuth ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(3) label-less(2) } */
const heim_oid *oid_id_pkix_kp_clientAuth(void);

/* OBJECT IDENTIFIER id-pkix-kp-emailProtection ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(3) label-less(4) } */
const heim_oid *oid_id_pkix_kp_emailProtection(void);

/* OBJECT IDENTIFIER id-pkix-kp-timeStamping ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(3) label-less(8) } */
const heim_oid *oid_id_pkix_kp_timeStamping(void);

/* OBJECT IDENTIFIER id-pkix-kp-OCSPSigning ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(3) label-less(9) } */
const heim_oid *oid_id_pkix_kp_OCSPSigning(void);

/* OBJECT IDENTIFIER id-pkix-pe ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(1) } */
const heim_oid *oid_id_pkix_pe(void);

/* OBJECT IDENTIFIER id-pkix-pe-authorityInfoAccess ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(1) label-less(1) } */
const heim_oid *oid_id_pkix_pe_authorityInfoAccess(void);

/*
AccessDescription ::= SEQUENCE {
  accessMethod       OBJECT IDENTIFIER,
  accessLocation   GeneralName,
}
*/

typedef struct AccessDescription {
  heim_oid accessMethod;
  GeneralName accessLocation;
} AccessDescription;

int    encode_AccessDescription(unsigned char *, size_t, const AccessDescription *, size_t *);
int    decode_AccessDescription(const unsigned char *, size_t, AccessDescription *, size_t *);
void   free_AccessDescription  (AccessDescription *);
size_t length_AccessDescription(const AccessDescription *);
int    copy_AccessDescription  (const AccessDescription *, AccessDescription *);


/*
AuthorityInfoAccessSyntax ::= SEQUENCE OF AccessDescription
*/

typedef struct AuthorityInfoAccessSyntax {
  unsigned int len;
  AccessDescription *val;
} AuthorityInfoAccessSyntax;

int    encode_AuthorityInfoAccessSyntax(unsigned char *, size_t, const AuthorityInfoAccessSyntax *, size_t *);
int    decode_AuthorityInfoAccessSyntax(const unsigned char *, size_t, AuthorityInfoAccessSyntax *, size_t *);
void   free_AuthorityInfoAccessSyntax  (AuthorityInfoAccessSyntax *);
size_t length_AuthorityInfoAccessSyntax(const AuthorityInfoAccessSyntax *);
int    copy_AuthorityInfoAccessSyntax  (const AuthorityInfoAccessSyntax *, AuthorityInfoAccessSyntax *);


/* OBJECT IDENTIFIER id-pkix-pe-proxyCertInfo ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(1) label-less(14) } */
const heim_oid *oid_id_pkix_pe_proxyCertInfo(void);

/* OBJECT IDENTIFIER id-pkix-ppl ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(21) } */
const heim_oid *oid_id_pkix_ppl(void);

/* OBJECT IDENTIFIER id-pkix-ppl-anyLanguage ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(21) label-less(0) } */
const heim_oid *oid_id_pkix_ppl_anyLanguage(void);

/* OBJECT IDENTIFIER id-pkix-ppl-inheritAll ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(21) label-less(1) } */
const heim_oid *oid_id_pkix_ppl_inheritAll(void);

/* OBJECT IDENTIFIER id-pkix-ppl-independent ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) label-less(21) label-less(2) } */
const heim_oid *oid_id_pkix_ppl_independent(void);

/*
ProxyPolicy ::= SEQUENCE {
  policyLanguage     OBJECT IDENTIFIER,
  policy           OCTET STRING OPTIONAL,
}
*/

typedef struct ProxyPolicy {
  heim_oid policyLanguage;
  heim_octet_string *policy;
} ProxyPolicy;

int    encode_ProxyPolicy(unsigned char *, size_t, const ProxyPolicy *, size_t *);
int    decode_ProxyPolicy(const unsigned char *, size_t, ProxyPolicy *, size_t *);
void   free_ProxyPolicy  (ProxyPolicy *);
size_t length_ProxyPolicy(const ProxyPolicy *);
int    copy_ProxyPolicy  (const ProxyPolicy *, ProxyPolicy *);


/*
ProxyCertInfo ::= SEQUENCE {
  pCPathLenConstraint   INTEGER (0..-1) OPTIONAL,
  proxyPolicy           ProxyPolicy,
}
*/

typedef struct ProxyCertInfo {
  unsigned int *pCPathLenConstraint;
  ProxyPolicy proxyPolicy;
} ProxyCertInfo;

int    encode_ProxyCertInfo(unsigned char *, size_t, const ProxyCertInfo *, size_t *);
int    decode_ProxyCertInfo(const unsigned char *, size_t, ProxyCertInfo *, size_t *);
void   free_ProxyCertInfo  (ProxyCertInfo *);
size_t length_ProxyCertInfo(const ProxyCertInfo *);
int    copy_ProxyCertInfo  (const ProxyCertInfo *, ProxyCertInfo *);


/* OBJECT IDENTIFIER id-uspkicommon-card-id ::= { label-less(2) label-less(16) label-less(840) label-less(1) label-less(101) label-less(3) label-less(6) label-less(6) } */
const heim_oid *oid_id_uspkicommon_card_id(void);

/* OBJECT IDENTIFIER id-uspkicommon-piv-interim ::= { label-less(2) label-less(16) label-less(840) label-less(1) label-less(101) label-less(3) label-less(6) label-less(9) label-less(1) } */
const heim_oid *oid_id_uspkicommon_piv_interim(void);

/* OBJECT IDENTIFIER id-netscape ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) netscape(113730) } */
const heim_oid *oid_id_netscape(void);

/* OBJECT IDENTIFIER id-netscape-cert-comment ::= { joint-iso-itu-t(2) country(16) us(840) organization(1) netscape(113730) label-less(1) label-less(13) } */
const heim_oid *oid_id_netscape_cert_comment(void);

/* OBJECT IDENTIFIER id-ms-cert-enroll-domaincontroller ::= { label-less(1) label-less(3) label-less(6) label-less(1) label-less(4) label-less(1) label-less(311) label-less(20) label-less(2) } */
const heim_oid *oid_id_ms_cert_enroll_domaincontroller(void);

/* OBJECT IDENTIFIER id-ms-client-authentication ::= { label-less(1) label-less(3) label-less(6) label-less(1) label-less(5) label-less(5) label-less(7) label-less(3) label-less(2) } */
const heim_oid *oid_id_ms_client_authentication(void);

#endif /* __rfc2459_asn1_h__ */
