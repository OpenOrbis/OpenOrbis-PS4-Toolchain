/* Generated from /usr/src/kerberos5/lib/libasn1/../../../crypto/heimdal/lib/asn1/pkcs8.asn1 */
/* Do not edit */

#ifndef __pkcs8_asn1_h__
#define __pkcs8_asn1_h__

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
/*
PKCS8PrivateKeyAlgorithmIdentifier ::= AlgorithmIdentifier
*/

typedef AlgorithmIdentifier PKCS8PrivateKeyAlgorithmIdentifier;

int    encode_PKCS8PrivateKeyAlgorithmIdentifier(unsigned char *, size_t, const PKCS8PrivateKeyAlgorithmIdentifier *, size_t *);
int    decode_PKCS8PrivateKeyAlgorithmIdentifier(const unsigned char *, size_t, PKCS8PrivateKeyAlgorithmIdentifier *, size_t *);
void   free_PKCS8PrivateKeyAlgorithmIdentifier  (PKCS8PrivateKeyAlgorithmIdentifier *);
size_t length_PKCS8PrivateKeyAlgorithmIdentifier(const PKCS8PrivateKeyAlgorithmIdentifier *);
int    copy_PKCS8PrivateKeyAlgorithmIdentifier  (const PKCS8PrivateKeyAlgorithmIdentifier *, PKCS8PrivateKeyAlgorithmIdentifier *);


/*
PKCS8PrivateKey ::= OCTET STRING
*/

typedef heim_octet_string PKCS8PrivateKey;

int    encode_PKCS8PrivateKey(unsigned char *, size_t, const PKCS8PrivateKey *, size_t *);
int    decode_PKCS8PrivateKey(const unsigned char *, size_t, PKCS8PrivateKey *, size_t *);
void   free_PKCS8PrivateKey  (PKCS8PrivateKey *);
size_t length_PKCS8PrivateKey(const PKCS8PrivateKey *);
int    copy_PKCS8PrivateKey  (const PKCS8PrivateKey *, PKCS8PrivateKey *);


/*
PKCS8Attributes ::= SET OF Attribute
*/

typedef struct PKCS8Attributes {
  unsigned int len;
  Attribute *val;
} PKCS8Attributes;

int    encode_PKCS8Attributes(unsigned char *, size_t, const PKCS8Attributes *, size_t *);
int    decode_PKCS8Attributes(const unsigned char *, size_t, PKCS8Attributes *, size_t *);
void   free_PKCS8Attributes  (PKCS8Attributes *);
size_t length_PKCS8Attributes(const PKCS8Attributes *);
int    copy_PKCS8Attributes  (const PKCS8Attributes *, PKCS8Attributes *);


/*
PKCS8PrivateKeyInfo ::= SEQUENCE {
  version               INTEGER,
  privateKeyAlgorithm   PKCS8PrivateKeyAlgorithmIdentifier,
  privateKey            PKCS8PrivateKey,
  attributes            [0] IMPLICIT SET OF Attribute OPTIONAL,
}
*/

typedef struct PKCS8PrivateKeyInfo {
  heim_integer version;
  PKCS8PrivateKeyAlgorithmIdentifier privateKeyAlgorithm;
  PKCS8PrivateKey privateKey;
  struct  {
    unsigned int len;
    Attribute *val;
  } *attributes;
} PKCS8PrivateKeyInfo;

int    encode_PKCS8PrivateKeyInfo(unsigned char *, size_t, const PKCS8PrivateKeyInfo *, size_t *);
int    decode_PKCS8PrivateKeyInfo(const unsigned char *, size_t, PKCS8PrivateKeyInfo *, size_t *);
void   free_PKCS8PrivateKeyInfo  (PKCS8PrivateKeyInfo *);
size_t length_PKCS8PrivateKeyInfo(const PKCS8PrivateKeyInfo *);
int    copy_PKCS8PrivateKeyInfo  (const PKCS8PrivateKeyInfo *, PKCS8PrivateKeyInfo *);


/*
PKCS8EncryptedData ::= OCTET STRING
*/

typedef heim_octet_string PKCS8EncryptedData;

int    encode_PKCS8EncryptedData(unsigned char *, size_t, const PKCS8EncryptedData *, size_t *);
int    decode_PKCS8EncryptedData(const unsigned char *, size_t, PKCS8EncryptedData *, size_t *);
void   free_PKCS8EncryptedData  (PKCS8EncryptedData *);
size_t length_PKCS8EncryptedData(const PKCS8EncryptedData *);
int    copy_PKCS8EncryptedData  (const PKCS8EncryptedData *, PKCS8EncryptedData *);


/*
PKCS8EncryptedPrivateKeyInfo ::= SEQUENCE {
  encryptionAlgorithm   AlgorithmIdentifier,
  encryptedData         PKCS8EncryptedData,
}
*/

typedef struct PKCS8EncryptedPrivateKeyInfo {
  AlgorithmIdentifier encryptionAlgorithm;
  PKCS8EncryptedData encryptedData;
} PKCS8EncryptedPrivateKeyInfo;

int    encode_PKCS8EncryptedPrivateKeyInfo(unsigned char *, size_t, const PKCS8EncryptedPrivateKeyInfo *, size_t *);
int    decode_PKCS8EncryptedPrivateKeyInfo(const unsigned char *, size_t, PKCS8EncryptedPrivateKeyInfo *, size_t *);
void   free_PKCS8EncryptedPrivateKeyInfo  (PKCS8EncryptedPrivateKeyInfo *);
size_t length_PKCS8EncryptedPrivateKeyInfo(const PKCS8EncryptedPrivateKeyInfo *);
int    copy_PKCS8EncryptedPrivateKeyInfo  (const PKCS8EncryptedPrivateKeyInfo *, PKCS8EncryptedPrivateKeyInfo *);


#endif /* __pkcs8_asn1_h__ */
