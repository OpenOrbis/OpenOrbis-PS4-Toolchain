/* Generated from /usr/src/kerberos5/lib/libasn1/../../../crypto/heimdal/lib/asn1/kx509.asn1 */
/* Do not edit */

#ifndef __kx509_asn1_h__
#define __kx509_asn1_h__

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

/*
Kx509Request ::= SEQUENCE {
  authenticator   OCTET STRING,
  pk-hash         OCTET STRING,
  pk-key          OCTET STRING,
}
*/

typedef struct Kx509Request {
  heim_octet_string authenticator;
  heim_octet_string pk_hash;
  heim_octet_string pk_key;
} Kx509Request;

int    encode_Kx509Request(unsigned char *, size_t, const Kx509Request *, size_t *);
int    decode_Kx509Request(const unsigned char *, size_t, Kx509Request *, size_t *);
void   free_Kx509Request  (Kx509Request *);
size_t length_Kx509Request(const Kx509Request *);
int    copy_Kx509Request  (const Kx509Request *, Kx509Request *);


/*
Kx509Response ::= SEQUENCE {
  error-code      [0] INTEGER (-2147483648..2147483647) OPTIONAL,
  hash            [1] OCTET STRING OPTIONAL,
  certificate     [2] OCTET STRING OPTIONAL,
  e-text          [3]   VisibleString OPTIONAL,
}
*/

typedef struct Kx509Response {
  int *error_code;
  heim_octet_string *hash;
  heim_octet_string *certificate;
  heim_visible_string *e_text;
} Kx509Response;

int    encode_Kx509Response(unsigned char *, size_t, const Kx509Response *, size_t *);
int    decode_Kx509Response(const unsigned char *, size_t, Kx509Response *, size_t *);
void   free_Kx509Response  (Kx509Response *);
size_t length_Kx509Response(const Kx509Response *);
int    copy_Kx509Response  (const Kx509Response *, Kx509Response *);


#endif /* __kx509_asn1_h__ */
