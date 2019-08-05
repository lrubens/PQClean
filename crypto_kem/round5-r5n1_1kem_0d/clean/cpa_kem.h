/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Declaration of the CPA KEM functions (NIST api).
 */

#ifndef _CPA_KEM_H_
#define _CPA_KEM_H_

#include "r5_parameter_sets.h"

/*
 * Conditionally provide the KEM NIST API functions.
 */

#if CRYPTO_CIPHERTEXTBYTES != 0

#include "r5_cpa_kem.h"

#ifdef __cplusplus
extern "C" {
#endif

int crypto_kem_keypair(unsigned char *pk, unsigned char *sk);
int crypto_kem_enc(unsigned char *ct, unsigned char *k, const unsigned char *pk);
int crypto_kem_dec(unsigned char *k, const unsigned char *ct, const unsigned char *sk);

#ifdef __cplusplus
}
#endif

#endif

#endif /* _CPA_KEM_H_ */
