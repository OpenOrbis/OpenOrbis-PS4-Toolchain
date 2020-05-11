/* Generated from /usr/src/kerberos5/lib/libasn1/../../../crypto/heimdal/lib/asn1/pkcs9.asn1 */
/* Do not edit */

#ifndef __pkcs9_asn1_h__
#define __pkcs9_asn1_h__

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

/* OBJECT IDENTIFIER id-pkcs-9 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) } */
const heim_oid *oid_id_pkcs_9(void);

/* OBJECT IDENTIFIER id-pkcs9-emailAddress ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(1) } */
const heim_oid *oid_id_pkcs9_emailAddress(void);

/* OBJECT IDENTIFIER id-pkcs9-contentType ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(3) } */
const heim_oid *oid_id_pkcs9_contentType(void);

/* OBJECT IDENTIFIER id-pkcs9-messageDigest ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(4) } */
const heim_oid *oid_id_pkcs9_messageDigest(void);

/* OBJECT IDENTIFIER id-pkcs9-signingTime ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(5) } */
const heim_oid *oid_id_pkcs9_signingTime(void);

/* OBJECT IDENTIFIER id-pkcs9-countersignature ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(6) } */
const heim_oid *oid_id_pkcs9_countersignature(void);

/* OBJECT IDENTIFIER id-pkcs-9-at-friendlyName ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(20) } */
const heim_oid *oid_id_pkcs_9_at_friendlyName(void);

/* OBJECT IDENTIFIER id-pkcs-9-at-localKeyId ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(21) } */
const heim_oid *oid_id_pkcs_9_at_localKeyId(void);

/* OBJECT IDENTIFIER id-pkcs-9-at-certTypes ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(22) } */
const heim_oid *oid_id_pkcs_9_at_certTypes(void);

/* OBJECT IDENTIFIER id-pkcs-9-at-certTypes-x509 ::= { iso(1) member-body(2) us(840) rsadsi(113549) pkcs(1) pkcs-9(9) label-less(22) label-less(1) } */
const heim_oid *oid_id_pkcs_9_at_certTypes_x509(void);

/*
PKCS9-BMPString ::= BMPString
*/

typedef heim_bmp_string PKCS9_BMPString;

int    encode_PKCS9_BMPString(unsigned char *, size_t, const PKCS9_BMPString *, size_t *);
int    decode_PKCS9_BMPString(const unsigned char *, size_t, PKCS9_BMPString *, size_t *);
void   free_PKCS9_BMPString  (PKCS9_BMPString *);
size_t length_PKCS9_BMPString(const PKCS9_BMPString *);
int    copy_PKCS9_BMPString  (const PKCS9_BMPString *, PKCS9_BMPString *);


/*
PKCS9-friendlyName ::= SET OF PKCS9-BMPString
*/

typedef struct PKCS9_friendlyName {
  unsigned int len;
  PKCS9_BMPString *val;
} PKCS9_friendlyName;

int    encode_PKCS9_friendlyName(unsigned char *, size_t, const PKCS9_friendlyName *, size_t *);
int    decode_PKCS9_friendlyName(const unsigned char *, size_t, PKCS9_friendlyName *, size_t *);
void   free_PKCS9_friendlyName  (PKCS9_friendlyName *);
size_t length_PKCS9_friendlyName(const PKCS9_friendlyName *);
int    copy_PKCS9_friendlyName  (const PKCS9_friendlyName *, PKCS9_friendlyName *);


#endif /* __pkcs9_asn1_h__ */
