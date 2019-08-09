/*
 * Copyright (c) 2018, PQShield and Koninklijke Philips N.V.
 * Markku-Juhani O. Saarinen, Koninklijke Philips N.V.
 */

/**
 * @file
 * Implementation of the CPA KEM functions (NIST api).
 */

#include "cpa_kem.h"

#if CRYPTO_CIPHERTEXTBYTES != 0

/**
     * Generates a CPA KEM key pair.
     *
     * @param[out] pk public key
     * @param[out] sk secret key
     * @return __0__ in case of success
     */
int PQCLEAN_ROUND5R5ND_3KEM_5D_crypto_kem_keypair(unsigned char *pk, unsigned char *sk) {
    return PQCLEAN_ROUND5R5ND_3KEM_5D_r5_cpa_kem_keygen(pk, sk);
}

/**
 * CPA KEM encapsulate.
 *
 * @param[out] ct    key encapsulation message (ciphertext)
 * @param[out] k     shared secret
 * @param[in]  pk    public key with which the message is encapsulated
 * @return __0__ in case of success
 */
int PQCLEAN_ROUND5R5ND_3KEM_5D_crypto_kem_enc(unsigned char *ct, unsigned char *k, const unsigned char *pk) {
    return PQCLEAN_ROUND5R5ND_3KEM_5D_r5_cpa_kem_encapsulate(ct, k, pk);
}

/**
 * CPA KEM de-capsulate.
 *
 * @param[out] k     shared secret
 * @param[in]  ct    key encapsulation message (ciphertext)
 * @param[in]  sk    secret key with which the message is to be de-capsulated
 * @return __0__ in case of success
 */
int PQCLEAN_ROUND5R5ND_3KEM_5D_crypto_kem_dec(unsigned char *k, const unsigned char *ct, const unsigned char *sk) {
    return PQCLEAN_ROUND5R5ND_3KEM_5D_r5_cpa_kem_decapsulate(k, ct, sk);
}

#endif