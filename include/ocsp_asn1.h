/* Generated from /usr/src/kerberos5/lib/libhx509/../../../crypto/heimdal/lib/hx509/ocsp.asn1 */
/* Do not edit */

#ifndef __ocsp_asn1_h__
#define __ocsp_asn1_h__

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
/*
OCSPVersion ::= INTEGER {
  ocsp_v1(0)
}
*/

typedef enum OCSPVersion {
  ocsp_v1 = 0
} OCSPVersion;

int    encode_OCSPVersion(unsigned char *, size_t, const OCSPVersion *, size_t *);
int    decode_OCSPVersion(const unsigned char *, size_t, OCSPVersion *, size_t *);
void   free_OCSPVersion  (OCSPVersion *);
size_t length_OCSPVersion(const OCSPVersion *);
int    copy_OCSPVersion  (const OCSPVersion *, OCSPVersion *);


/*
OCSPCertStatus ::= CHOICE {
  good            [0] IMPLICIT   NULL,
  revoked         [1] IMPLICIT SEQUENCE {
    revocationTime     GeneralizedTime,
    revocationReason   [0] CRLReason OPTIONAL,
  },
  unknown         [2] IMPLICIT   NULL,
}
*/

typedef struct OCSPCertStatus {
  enum {
    choice_OCSPCertStatus_good = 1,
    choice_OCSPCertStatus_revoked,
    choice_OCSPCertStatus_unknown
  } element;
  union {
    int good;
    struct  {
      time_t revocationTime;
      CRLReason *revocationReason;
    } revoked;
    int unknown;
  } u;
} OCSPCertStatus;

int    encode_OCSPCertStatus(unsigned char *, size_t, const OCSPCertStatus *, size_t *);
int    decode_OCSPCertStatus(const unsigned char *, size_t, OCSPCertStatus *, size_t *);
void   free_OCSPCertStatus  (OCSPCertStatus *);
size_t length_OCSPCertStatus(const OCSPCertStatus *);
int    copy_OCSPCertStatus  (const OCSPCertStatus *, OCSPCertStatus *);


/*
OCSPCertID ::= SEQUENCE {
  hashAlgorithm    AlgorithmIdentifier,
  issuerNameHash   OCTET STRING,
  issuerKeyHash    OCTET STRING,
  serialNumber     CertificateSerialNumber,
}
*/

typedef struct OCSPCertID {
  AlgorithmIdentifier hashAlgorithm;
  heim_octet_string issuerNameHash;
  heim_octet_string issuerKeyHash;
  CertificateSerialNumber serialNumber;
} OCSPCertID;

int    encode_OCSPCertID(unsigned char *, size_t, const OCSPCertID *, size_t *);
int    decode_OCSPCertID(const unsigned char *, size_t, OCSPCertID *, size_t *);
void   free_OCSPCertID  (OCSPCertID *);
size_t length_OCSPCertID(const OCSPCertID *);
int    copy_OCSPCertID  (const OCSPCertID *, OCSPCertID *);


/*
OCSPSingleResponse ::= SEQUENCE {
  certID             OCSPCertID,
  certStatus         OCSPCertStatus,
  thisUpdate         GeneralizedTime,
  nextUpdate         [0] GeneralizedTime OPTIONAL,
  singleExtensions   [1] Extensions OPTIONAL,
}
*/

typedef struct OCSPSingleResponse {
  OCSPCertID certID;
  OCSPCertStatus certStatus;
  time_t thisUpdate;
  time_t *nextUpdate;
  Extensions *singleExtensions;
} OCSPSingleResponse;

int    encode_OCSPSingleResponse(unsigned char *, size_t, const OCSPSingleResponse *, size_t *);
int    decode_OCSPSingleResponse(const unsigned char *, size_t, OCSPSingleResponse *, size_t *);
void   free_OCSPSingleResponse  (OCSPSingleResponse *);
size_t length_OCSPSingleResponse(const OCSPSingleResponse *);
int    copy_OCSPSingleResponse  (const OCSPSingleResponse *, OCSPSingleResponse *);


/*
OCSPInnerRequest ::= SEQUENCE {
  reqCert                   OCSPCertID,
  singleRequestExtensions   [0] Extensions OPTIONAL,
}
*/

typedef struct OCSPInnerRequest {
  OCSPCertID reqCert;
  Extensions *singleRequestExtensions;
} OCSPInnerRequest;

int    encode_OCSPInnerRequest(unsigned char *, size_t, const OCSPInnerRequest *, size_t *);
int    decode_OCSPInnerRequest(const unsigned char *, size_t, OCSPInnerRequest *, size_t *);
void   free_OCSPInnerRequest  (OCSPInnerRequest *);
size_t length_OCSPInnerRequest(const OCSPInnerRequest *);
int    copy_OCSPInnerRequest  (const OCSPInnerRequest *, OCSPInnerRequest *);


/*
OCSPTBSRequest ::= SEQUENCE {
  version             [0] OCSPVersion OPTIONAL,
  requestorName       [1] GeneralName OPTIONAL,
  requestList         SEQUENCE OF OCSPInnerRequest,
  requestExtensions   [2] Extensions OPTIONAL,
}
*/

typedef struct OCSPTBSRequest {
  heim_octet_string _save;
  OCSPVersion *version;
  GeneralName *requestorName;
  struct  {
    unsigned int len;
    OCSPInnerRequest *val;
  } requestList;
  Extensions *requestExtensions;
} OCSPTBSRequest;

int    encode_OCSPTBSRequest(unsigned char *, size_t, const OCSPTBSRequest *, size_t *);
int    decode_OCSPTBSRequest(const unsigned char *, size_t, OCSPTBSRequest *, size_t *);
void   free_OCSPTBSRequest  (OCSPTBSRequest *);
size_t length_OCSPTBSRequest(const OCSPTBSRequest *);
int    copy_OCSPTBSRequest  (const OCSPTBSRequest *, OCSPTBSRequest *);


/*
OCSPSignature ::= SEQUENCE {
  signatureAlgorithm   AlgorithmIdentifier,
  signature              BIT STRING {
  },
  certs                [0] SEQUENCE OF Certificate OPTIONAL,
}
*/

typedef struct OCSPSignature {
  AlgorithmIdentifier signatureAlgorithm;
  heim_bit_string signature;
  struct  {
    unsigned int len;
    Certificate *val;
  } *certs;
} OCSPSignature;

int    encode_OCSPSignature(unsigned char *, size_t, const OCSPSignature *, size_t *);
int    decode_OCSPSignature(const unsigned char *, size_t, OCSPSignature *, size_t *);
void   free_OCSPSignature  (OCSPSignature *);
size_t length_OCSPSignature(const OCSPSignature *);
int    copy_OCSPSignature  (const OCSPSignature *, OCSPSignature *);


/*
OCSPRequest ::= SEQUENCE {
  tbsRequest          OCSPTBSRequest,
  optionalSignature   [0] OCSPSignature OPTIONAL,
}
*/

typedef struct OCSPRequest {
  OCSPTBSRequest tbsRequest;
  OCSPSignature *optionalSignature;
} OCSPRequest;

int    encode_OCSPRequest(unsigned char *, size_t, const OCSPRequest *, size_t *);
int    decode_OCSPRequest(const unsigned char *, size_t, OCSPRequest *, size_t *);
void   free_OCSPRequest  (OCSPRequest *);
size_t length_OCSPRequest(const OCSPRequest *);
int    copy_OCSPRequest  (const OCSPRequest *, OCSPRequest *);


/*
OCSPResponseBytes ::= SEQUENCE {
  responseType      OBJECT IDENTIFIER,
  response        OCTET STRING,
}
*/

typedef struct OCSPResponseBytes {
  heim_oid responseType;
  heim_octet_string response;
} OCSPResponseBytes;

int    encode_OCSPResponseBytes(unsigned char *, size_t, const OCSPResponseBytes *, size_t *);
int    decode_OCSPResponseBytes(const unsigned char *, size_t, OCSPResponseBytes *, size_t *);
void   free_OCSPResponseBytes  (OCSPResponseBytes *);
size_t length_OCSPResponseBytes(const OCSPResponseBytes *);
int    copy_OCSPResponseBytes  (const OCSPResponseBytes *, OCSPResponseBytes *);


/*
OCSPResponseStatus ::= INTEGER {
  successful(0),
  malformedRequest(1),
  internalError(2),
  tryLater(3),
  sigRequired(5),
  unauthorized(6)
}
*/

typedef enum OCSPResponseStatus {
  successful = 0,
  malformedRequest = 1,
  internalError = 2,
  tryLater = 3,
  sigRequired = 5,
  unauthorized = 6
} OCSPResponseStatus;

int    encode_OCSPResponseStatus(unsigned char *, size_t, const OCSPResponseStatus *, size_t *);
int    decode_OCSPResponseStatus(const unsigned char *, size_t, OCSPResponseStatus *, size_t *);
void   free_OCSPResponseStatus  (OCSPResponseStatus *);
size_t length_OCSPResponseStatus(const OCSPResponseStatus *);
int    copy_OCSPResponseStatus  (const OCSPResponseStatus *, OCSPResponseStatus *);


/*
OCSPResponse ::= SEQUENCE {
  responseStatus   OCSPResponseStatus,
  responseBytes    [0] OCSPResponseBytes OPTIONAL,
}
*/

typedef struct OCSPResponse {
  OCSPResponseStatus responseStatus;
  OCSPResponseBytes *responseBytes;
} OCSPResponse;

int    encode_OCSPResponse(unsigned char *, size_t, const OCSPResponse *, size_t *);
int    decode_OCSPResponse(const unsigned char *, size_t, OCSPResponse *, size_t *);
void   free_OCSPResponse  (OCSPResponse *);
size_t length_OCSPResponse(const OCSPResponse *);
int    copy_OCSPResponse  (const OCSPResponse *, OCSPResponse *);


/*
OCSPKeyHash ::= OCTET STRING
*/

typedef heim_octet_string OCSPKeyHash;

int    encode_OCSPKeyHash(unsigned char *, size_t, const OCSPKeyHash *, size_t *);
int    decode_OCSPKeyHash(const unsigned char *, size_t, OCSPKeyHash *, size_t *);
void   free_OCSPKeyHash  (OCSPKeyHash *);
size_t length_OCSPKeyHash(const OCSPKeyHash *);
int    copy_OCSPKeyHash  (const OCSPKeyHash *, OCSPKeyHash *);


/*
OCSPResponderID ::= CHOICE {
  byName          [1] Name,
  byKey           [2] OCSPKeyHash,
}
*/

typedef struct OCSPResponderID {
  enum {
    choice_OCSPResponderID_byName = 1,
    choice_OCSPResponderID_byKey
  } element;
  union {
    Name byName;
    OCSPKeyHash byKey;
  } u;
} OCSPResponderID;

int    encode_OCSPResponderID(unsigned char *, size_t, const OCSPResponderID *, size_t *);
int    decode_OCSPResponderID(const unsigned char *, size_t, OCSPResponderID *, size_t *);
void   free_OCSPResponderID  (OCSPResponderID *);
size_t length_OCSPResponderID(const OCSPResponderID *);
int    copy_OCSPResponderID  (const OCSPResponderID *, OCSPResponderID *);


/*
OCSPResponseData ::= SEQUENCE {
  version              [0] OCSPVersion OPTIONAL,
  responderID          OCSPResponderID,
  producedAt           GeneralizedTime,
  responses            SEQUENCE OF OCSPSingleResponse,
  responseExtensions   [1] Extensions OPTIONAL,
}
*/

typedef struct OCSPResponseData {
  heim_octet_string _save;
  OCSPVersion *version;
  OCSPResponderID responderID;
  time_t producedAt;
  struct  {
    unsigned int len;
    OCSPSingleResponse *val;
  } responses;
  Extensions *responseExtensions;
} OCSPResponseData;

int    encode_OCSPResponseData(unsigned char *, size_t, const OCSPResponseData *, size_t *);
int    decode_OCSPResponseData(const unsigned char *, size_t, OCSPResponseData *, size_t *);
void   free_OCSPResponseData  (OCSPResponseData *);
size_t length_OCSPResponseData(const OCSPResponseData *);
int    copy_OCSPResponseData  (const OCSPResponseData *, OCSPResponseData *);


/*
OCSPBasicOCSPResponse ::= SEQUENCE {
  tbsResponseData      OCSPResponseData,
  signatureAlgorithm   AlgorithmIdentifier,
  signature              BIT STRING {
  },
  certs                [0] SEQUENCE OF Certificate OPTIONAL,
}
*/

typedef struct OCSPBasicOCSPResponse {
  OCSPResponseData tbsResponseData;
  AlgorithmIdentifier signatureAlgorithm;
  heim_bit_string signature;
  struct  {
    unsigned int len;
    Certificate *val;
  } *certs;
} OCSPBasicOCSPResponse;

int    encode_OCSPBasicOCSPResponse(unsigned char *, size_t, const OCSPBasicOCSPResponse *, size_t *);
int    decode_OCSPBasicOCSPResponse(const unsigned char *, size_t, OCSPBasicOCSPResponse *, size_t *);
void   free_OCSPBasicOCSPResponse  (OCSPBasicOCSPResponse *);
size_t length_OCSPBasicOCSPResponse(const OCSPBasicOCSPResponse *);
int    copy_OCSPBasicOCSPResponse  (const OCSPBasicOCSPResponse *, OCSPBasicOCSPResponse *);


/* OBJECT IDENTIFIER id-pkix-ocsp ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) pkix-ad(48) label-less(1) } */
const heim_oid *oid_id_pkix_ocsp(void);

/* OBJECT IDENTIFIER id-pkix-ocsp-basic ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) pkix-ad(48) label-less(1) label-less(1) } */
const heim_oid *oid_id_pkix_ocsp_basic(void);

/* OBJECT IDENTIFIER id-pkix-ocsp-nonce ::= { iso(1) identified-organization(3) dod(6) internet(1) security(5) mechanisms(5) pkix(7) pkix-ad(48) label-less(1) label-less(2) } */
const heim_oid *oid_id_pkix_ocsp_nonce(void);

#endif /* __ocsp_asn1_h__ */
