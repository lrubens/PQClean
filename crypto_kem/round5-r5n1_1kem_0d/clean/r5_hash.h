/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Definition of the hash function as used within Round5.
 */

#ifndef R5_HASH_H
#define R5_HASH_H

#include "shake.h"
#include "fips202.h"
// #include "sp800-185.h"

/**
 * The hash function as used within Round5.
 *
 * @param[out] output      buffer for the output of the hash
 * @param[in]  output_len  the number of hash bytes to produce
 * @param[in]  input       the input to produce the hash for
 * @param[in]  input_len   the number of input bytes
 * @param[in]  kappa_bytes the number of bytes of kappa (used to determine
 *                         the implementation of the hash function)
 */
inline void PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_hash(uint8_t *output, const size_t output_len, const uint8_t *input, const size_t input_len, const uint8_t kappa_bytes) {
    uint8_t dummy = 0;
    dummy = kappa_bytes;
    dummy = dummy * 2;      // trying to avoid warning
    /* Since without customization, SHAKE == CSHAKE, we can use SHAKE here directly. */
    PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_r5_xof(output, output_len, input, input_len);
}

/**
 * The hash function as used within Round5.
 *
 * @param[out] output            buffer for the output of the hash
 * @param[in]  output_len        the number of hash bytes to produce
 * @param[in]  input             the input to produce the hash for
 * @param[in]  input_len         the number of input bytes
 * @param[in]  customization     the customization string to use
 * @param[in]  customization_len the length of the customization string
 * @param kappa_bytes            the number of bytes of kappa (used to
 *                               determine the the implementation of the
 *                               hash function)
 */
inline void PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_hash_customization(uint8_t *output, const size_t output_len, const uint8_t *input, const size_t input_len, const uint8_t *customization, const size_t customization_len, const uint8_t kappa_bytes) {
    if (kappa_bytes > 16) {
        PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_cshake256(output, output_len, NULL, 0, customization, customization_len, input, input_len);
    } else {
        PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_cshake128(output, output_len, NULL, 0, customization, customization_len, input, input_len);
    }
}

#endif /* R5_HASH_H */