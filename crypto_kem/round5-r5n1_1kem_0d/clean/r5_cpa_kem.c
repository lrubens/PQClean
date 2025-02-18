/*
 * Copyright (c) 2018, PQShield and Koninklijke Philips N.V.
 * Markku-Juhani O. Saarinen, Koninklijke Philips N.V.
 */

//  CPA Versions of KEM functionality

#include "r5_cpa_kem.h"
#include "r5_parameter_sets.h"
#include "r5_cpa_pke.h"
#include "r5_hash.h"
// #include "rng.h"
#include "randombytes.h"
#include "misc.h"

#include <stdlib.h>
#include <string.h>

// CPA-KEM KeyGen()

int PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_r5_cpa_kem_keygen(uint8_t *pk, uint8_t *sk) {
    PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_r5_cpa_pke_keygen(pk, sk);

    return 0;
}

// CPA-KEM Encaps()

int PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_r5_cpa_kem_encapsulate(uint8_t *ct, uint8_t *k, const uint8_t *pk) {
    uint8_t hash_input[PARAMS_KAPPA_BYTES + PARAMS_CT_SIZE];

    uint8_t m[PARAMS_KAPPA_BYTES];
    uint8_t rho[PARAMS_KAPPA_BYTES];

    /* Generate a random m and rho */
    randombytes(m, PARAMS_KAPPA_BYTES);
    randombytes(rho, PARAMS_KAPPA_BYTES);

    PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_r5_cpa_pke_encrypt(ct, pk, m, rho);

    /* k = H(m, ct) */
    memcpy(hash_input, m, PARAMS_KAPPA_BYTES);
    memcpy(hash_input + PARAMS_KAPPA_BYTES, ct, PARAMS_CT_SIZE);
    PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_hash(k, PARAMS_KAPPA_BYTES, hash_input, PARAMS_KAPPA_BYTES + PARAMS_CT_SIZE, PARAMS_KAPPA_BYTES);

    return 0;
}

// CPA-KEM Decaps()

int PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_r5_cpa_kem_decapsulate(uint8_t *k, const uint8_t *ct, const uint8_t *sk) {
    uint8_t hash_input[PARAMS_KAPPA_BYTES + PARAMS_CT_SIZE];
    uint8_t m[PARAMS_KAPPA_BYTES];

    /* Decrypt m */
    PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_r5_cpa_pke_decrypt(m, sk, ct);

    /* k = H(m, ct) */
    memcpy(hash_input, m, PARAMS_KAPPA_BYTES);
    memcpy(hash_input + PARAMS_KAPPA_BYTES, ct, PARAMS_CT_SIZE);
    PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_hash(k, PARAMS_KAPPA_BYTES, hash_input, PARAMS_KAPPA_BYTES + PARAMS_CT_SIZE, PARAMS_KAPPA_BYTES);

    return 0;
}