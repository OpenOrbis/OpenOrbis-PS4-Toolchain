/* Generated from /usr/src/kerberos5/lib/libasn1/../../../crypto/heimdal/lib/asn1/digest.asn1 */
/* Do not edit */

#ifndef __digest_asn1_h__
#define __digest_asn1_h__

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

#include <krb5_asn1.h>
/*
DigestTypes ::= BIT STRING {
  ntlm-v1(0),
  ntlm-v1-session(1),
  ntlm-v2(2),
  digest-md5(3),
  chap-md5(4),
  ms-chap-v2(5)
}
*/

typedef struct DigestTypes {
  unsigned int ntlm_v1:1;
  unsigned int ntlm_v1_session:1;
  unsigned int ntlm_v2:1;
  unsigned int digest_md5:1;
  unsigned int chap_md5:1;
  unsigned int ms_chap_v2:1;
} DigestTypes;


int    encode_DigestTypes(unsigned char *, size_t, const DigestTypes *, size_t *);
int    decode_DigestTypes(const unsigned char *, size_t, DigestTypes *, size_t *);
void   free_DigestTypes  (DigestTypes *);
size_t length_DigestTypes(const DigestTypes *);
int    copy_DigestTypes  (const DigestTypes *, DigestTypes *);
unsigned DigestTypes2int(DigestTypes);
DigestTypes int2DigestTypes(unsigned);
#ifdef __PARSE_UNITS_H__
const struct units * asn1_DigestTypes_units(void);
#endif


/*
DigestInit ::= SEQUENCE {
  type              UTF8String,
  channel         [0] SEQUENCE {
    cb-type             UTF8String,
    cb-binding          UTF8String,
  } OPTIONAL,
  hostname        [1]   UTF8String OPTIONAL,
}
*/

typedef struct DigestInit {
  heim_utf8_string type;
  struct  {
    heim_utf8_string cb_type;
    heim_utf8_string cb_binding;
  } *channel;
  heim_utf8_string *hostname;
} DigestInit;

int    encode_DigestInit(unsigned char *, size_t, const DigestInit *, size_t *);
int    decode_DigestInit(const unsigned char *, size_t, DigestInit *, size_t *);
void   free_DigestInit  (DigestInit *);
size_t length_DigestInit(const DigestInit *);
int    copy_DigestInit  (const DigestInit *, DigestInit *);


/*
DigestInitReply ::= SEQUENCE {
  nonce             UTF8String,
  opaque            UTF8String,
  identifier      [0]   UTF8String OPTIONAL,
}
*/

typedef struct DigestInitReply {
  heim_utf8_string nonce;
  heim_utf8_string opaque;
  heim_utf8_string *identifier;
} DigestInitReply;

int    encode_DigestInitReply(unsigned char *, size_t, const DigestInitReply *, size_t *);
int    decode_DigestInitReply(const unsigned char *, size_t, DigestInitReply *, size_t *);
void   free_DigestInitReply  (DigestInitReply *);
size_t length_DigestInitReply(const DigestInitReply *);
int    copy_DigestInitReply  (const DigestInitReply *, DigestInitReply *);


/*
DigestRequest ::= SEQUENCE {
  type                    UTF8String,
  digest                  UTF8String,
  username                UTF8String,
  responseData            UTF8String,
  authid                [0]   UTF8String OPTIONAL,
  authentication-user   [1] Principal OPTIONAL,
  realm                 [2]   UTF8String OPTIONAL,
  method                [3]   UTF8String OPTIONAL,
  uri                   [4]   UTF8String OPTIONAL,
  serverNonce             UTF8String,
  clientNonce           [5]   UTF8String OPTIONAL,
  nonceCount            [6]   UTF8String OPTIONAL,
  qop                   [7]   UTF8String OPTIONAL,
  identifier            [8]   UTF8String OPTIONAL,
  hostname              [9]   UTF8String OPTIONAL,
  opaque                  UTF8String,
}
*/

typedef struct DigestRequest {
  heim_utf8_string type;
  heim_utf8_string digest;
  heim_utf8_string username;
  heim_utf8_string responseData;
  heim_utf8_string *authid;
  Principal *authentication_user;
  heim_utf8_string *realm;
  heim_utf8_string *method;
  heim_utf8_string *uri;
  heim_utf8_string serverNonce;
  heim_utf8_string *clientNonce;
  heim_utf8_string *nonceCount;
  heim_utf8_string *qop;
  heim_utf8_string *identifier;
  heim_utf8_string *hostname;
  heim_utf8_string opaque;
} DigestRequest;

int    encode_DigestRequest(unsigned char *, size_t, const DigestRequest *, size_t *);
int    decode_DigestRequest(const unsigned char *, size_t, DigestRequest *, size_t *);
void   free_DigestRequest  (DigestRequest *);
size_t length_DigestRequest(const DigestRequest *);
int    copy_DigestRequest  (const DigestRequest *, DigestRequest *);


/*
DigestError ::= SEQUENCE {
  reason            UTF8String,
  code            INTEGER (-2147483648..2147483647),
}
*/

typedef struct DigestError {
  heim_utf8_string reason;
  int code;
} DigestError;

int    encode_DigestError(unsigned char *, size_t, const DigestError *, size_t *);
int    decode_DigestError(const unsigned char *, size_t, DigestError *, size_t *);
void   free_DigestError  (DigestError *);
size_t length_DigestError(const DigestError *);
int    copy_DigestError  (const DigestError *, DigestError *);


/*
DigestResponse ::= SEQUENCE {
  success         BOOLEAN,
  rsp             [0]   UTF8String OPTIONAL,
  tickets         [1] SEQUENCE OF OCTET STRING OPTIONAL,
  channel         [2] SEQUENCE {
    cb-type             UTF8String,
    cb-binding          UTF8String,
  } OPTIONAL,
  session-key     [3] OCTET STRING OPTIONAL,
}
*/

typedef struct DigestResponse {
  int success;
  heim_utf8_string *rsp;
  struct  {
    unsigned int len;
    heim_octet_string *val;
  } *tickets;
  struct  {
    heim_utf8_string cb_type;
    heim_utf8_string cb_binding;
  } *channel;
  heim_octet_string *session_key;
} DigestResponse;

int    encode_DigestResponse(unsigned char *, size_t, const DigestResponse *, size_t *);
int    decode_DigestResponse(const unsigned char *, size_t, DigestResponse *, size_t *);
void   free_DigestResponse  (DigestResponse *);
size_t length_DigestResponse(const DigestResponse *);
int    copy_DigestResponse  (const DigestResponse *, DigestResponse *);


/*
NTLMInit ::= SEQUENCE {
  flags           [0] INTEGER (0..-1),
  hostname        [1]   UTF8String OPTIONAL,
  domain          [1]   UTF8String OPTIONAL,
}
*/

typedef struct NTLMInit {
  unsigned int flags;
  heim_utf8_string *hostname;
  heim_utf8_string *domain;
} NTLMInit;

int    encode_NTLMInit(unsigned char *, size_t, const NTLMInit *, size_t *);
int    decode_NTLMInit(const unsigned char *, size_t, NTLMInit *, size_t *);
void   free_NTLMInit  (NTLMInit *);
size_t length_NTLMInit(const NTLMInit *);
int    copy_NTLMInit  (const NTLMInit *, NTLMInit *);


/*
NTLMInitReply ::= SEQUENCE {
  flags           [0] INTEGER (0..-1),
  opaque          [1] OCTET STRING,
  targetname      [2]   UTF8String,
  challange       [3] OCTET STRING,
  targetinfo      [4] OCTET STRING OPTIONAL,
}
*/

typedef struct NTLMInitReply {
  unsigned int flags;
  heim_octet_string opaque;
  heim_utf8_string targetname;
  heim_octet_string challange;
  heim_octet_string *targetinfo;
} NTLMInitReply;

int    encode_NTLMInitReply(unsigned char *, size_t, const NTLMInitReply *, size_t *);
int    decode_NTLMInitReply(const unsigned char *, size_t, NTLMInitReply *, size_t *);
void   free_NTLMInitReply  (NTLMInitReply *);
size_t length_NTLMInitReply(const NTLMInitReply *);
int    copy_NTLMInitReply  (const NTLMInitReply *, NTLMInitReply *);


/*
NTLMRequest ::= SEQUENCE {
  flags           [0] INTEGER (0..-1),
  opaque          [1] OCTET STRING,
  username        [2]   UTF8String,
  targetname      [3]   UTF8String,
  targetinfo      [4] OCTET STRING OPTIONAL,
  lm              [5] OCTET STRING,
  ntlm            [6] OCTET STRING,
  sessionkey      [7] OCTET STRING OPTIONAL,
}
*/

typedef struct NTLMRequest {
  unsigned int flags;
  heim_octet_string opaque;
  heim_utf8_string username;
  heim_utf8_string targetname;
  heim_octet_string *targetinfo;
  heim_octet_string lm;
  heim_octet_string ntlm;
  heim_octet_string *sessionkey;
} NTLMRequest;

int    encode_NTLMRequest(unsigned char *, size_t, const NTLMRequest *, size_t *);
int    decode_NTLMRequest(const unsigned char *, size_t, NTLMRequest *, size_t *);
void   free_NTLMRequest  (NTLMRequest *);
size_t length_NTLMRequest(const NTLMRequest *);
int    copy_NTLMRequest  (const NTLMRequest *, NTLMRequest *);


/*
NTLMResponse ::= SEQUENCE {
  success         [0] BOOLEAN,
  flags           [1] INTEGER (0..-1),
  sessionkey      [2] OCTET STRING OPTIONAL,
  tickets         [3] SEQUENCE OF OCTET STRING OPTIONAL,
}
*/

typedef struct NTLMResponse {
  int success;
  unsigned int flags;
  heim_octet_string *sessionkey;
  struct  {
    unsigned int len;
    heim_octet_string *val;
  } *tickets;
} NTLMResponse;

int    encode_NTLMResponse(unsigned char *, size_t, const NTLMResponse *, size_t *);
int    decode_NTLMResponse(const unsigned char *, size_t, NTLMResponse *, size_t *);
void   free_NTLMResponse  (NTLMResponse *);
size_t length_NTLMResponse(const NTLMResponse *);
int    copy_NTLMResponse  (const NTLMResponse *, NTLMResponse *);


/*
DigestReqInner ::= CHOICE {
  init             [0] DigestInit,
  digestRequest    [1] DigestRequest,
  ntlmInit         [2] NTLMInit,
  ntlmRequest      [3] NTLMRequest,
  supportedMechs   [4]   NULL,
}
*/

typedef struct DigestReqInner {
  enum {
    choice_DigestReqInner_init = 1,
    choice_DigestReqInner_digestRequest,
    choice_DigestReqInner_ntlmInit,
    choice_DigestReqInner_ntlmRequest,
    choice_DigestReqInner_supportedMechs
  } element;
  union {
    DigestInit init;
    DigestRequest digestRequest;
    NTLMInit ntlmInit;
    NTLMRequest ntlmRequest;
    int supportedMechs;
  } u;
} DigestReqInner;

int    encode_DigestReqInner(unsigned char *, size_t, const DigestReqInner *, size_t *);
int    decode_DigestReqInner(const unsigned char *, size_t, DigestReqInner *, size_t *);
void   free_DigestReqInner  (DigestReqInner *);
size_t length_DigestReqInner(const DigestReqInner *);
int    copy_DigestReqInner  (const DigestReqInner *, DigestReqInner *);


/*
DigestREQ ::= [APPLICATION 128] SEQUENCE {
  apReq           [0] OCTET STRING,
  innerReq        [1] EncryptedData,
}
*/

typedef struct DigestREQ {
  heim_octet_string apReq;
  EncryptedData innerReq;
} DigestREQ;

int    encode_DigestREQ(unsigned char *, size_t, const DigestREQ *, size_t *);
int    decode_DigestREQ(const unsigned char *, size_t, DigestREQ *, size_t *);
void   free_DigestREQ  (DigestREQ *);
size_t length_DigestREQ(const DigestREQ *);
int    copy_DigestREQ  (const DigestREQ *, DigestREQ *);


/*
DigestRepInner ::= CHOICE {
  error            [0] DigestError,
  initReply        [1] DigestInitReply,
  response         [2] DigestResponse,
  ntlmInitReply    [3] NTLMInitReply,
  ntlmResponse     [4] NTLMResponse,
  supportedMechs   [5] DigestTypes,
  ...,
}
*/

typedef struct DigestRepInner {
  enum {
    choice_DigestRepInner_asn1_ellipsis = 0,
    choice_DigestRepInner_error,
    choice_DigestRepInner_initReply,
    choice_DigestRepInner_response,
    choice_DigestRepInner_ntlmInitReply,
    choice_DigestRepInner_ntlmResponse,
    choice_DigestRepInner_supportedMechs
    /* ... */
  } element;
  union {
    DigestError error;
    DigestInitReply initReply;
    DigestResponse response;
    NTLMInitReply ntlmInitReply;
    NTLMResponse ntlmResponse;
    DigestTypes supportedMechs;
    heim_octet_string asn1_ellipsis;
  } u;
} DigestRepInner;

int    encode_DigestRepInner(unsigned char *, size_t, const DigestRepInner *, size_t *);
int    decode_DigestRepInner(const unsigned char *, size_t, DigestRepInner *, size_t *);
void   free_DigestRepInner  (DigestRepInner *);
size_t length_DigestRepInner(const DigestRepInner *);
int    copy_DigestRepInner  (const DigestRepInner *, DigestRepInner *);


/*
DigestREP ::= [APPLICATION 129] SEQUENCE {
  apRep           [0] OCTET STRING,
  innerRep        [1] EncryptedData,
}
*/

typedef struct DigestREP {
  heim_octet_string apRep;
  EncryptedData innerRep;
} DigestREP;

int    encode_DigestREP(unsigned char *, size_t, const DigestREP *, size_t *);
int    decode_DigestREP(const unsigned char *, size_t, DigestREP *, size_t *);
void   free_DigestREP  (DigestREP *);
size_t length_DigestREP(const DigestREP *);
int    copy_DigestREP  (const DigestREP *, DigestREP *);


#endif /* __digest_asn1_h__ */
