/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Declaration of the SHAKE128, SHAKE256, cSHAKE128, and cSHAKE256 hash
 * functions.
 *
 * Note: all sizes are in bytes, not bits!
 */

#ifndef _SHAKE_H_
#define _SHAKE_H_

#include "misc.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libkeccak.a.headers/KeccakHash.h>
#include <libkeccak.a.headers/SP800-185.h>

#ifdef DOXYGEN
/* Document SHAKE implementation option macro */
/**
 * The default implementation of the SHAKE algorithm when combining the absorb
 * and squeeze steps (i.e. when using the functions `shake128()` or `shake256()`)
 * is to make use of OpenSSL (if OpenSSL >= 1.1.1 is found). To use the
 * `libkeccak` implementation in this case too, define `NO_OPENSSL_SHAKE`.
 */
#define NO_OPENSSL_SHAKE
#endif

typedef Keccak_HashInstance shake_ctx; /**< The shake context (state) */
typedef cSHAKE_Instance cshake_ctx; /**< The cshake context (state) */

/**
 * The rate of the SHAKE-128 algorithm (i.e. internal block size, in bytes).
 */
#define SHAKE128_RATE 168

/**
 * The rate of the SHAKE-256 algorithm (i.e. internal block size, in bytes).
 */
#define SHAKE256_RATE 136

#ifdef __cplusplus
"C" {
#endif

    /**
     * Performs the full SHAKE-128 XOF to the given input.
     * @param output the final output
     * @param output_len the length of the output
     * @param input the input
     * @param input_len the length of the input
     */
    void shake128(unsigned char *output, size_t output_len, const unsigned char *input, const size_t input_len);

    /**
     * Performs the full SHAKE-256 XOF to the given input.
     * @param output the final output
     * @param output_len the length of the output
     * @param input the input
     * @param input_len the length of the input
     */
    void shake256(unsigned char *output, const size_t output_len, const unsigned char *input, const size_t input_len);

    void shake128_init(shake_ctx * ctx);
    void shake128_absorb(shake_ctx * ctx, const unsigned char *input, const size_t input_len);
    void shake128_squeezeblocks(shake_ctx * ctx, unsigned char *output, const size_t nr_blocks);
    void shake256_init(shake_ctx * ctx);
    void shake256_absorb(shake_ctx * ctx, const unsigned char *input, const size_t input_len);
    void shake256_squeezeblocks(shake_ctx * ctx, unsigned char *output, const size_t nr_blocks);
    void cshake128_init(cshake_ctx * ctx, const unsigned char *customization, const size_t customization_len);
    void cshake128_absorb(cshake_ctx * ctx, const unsigned char *input, const size_t input_len);
    void cshake128_squeezeblocks(cshake_ctx * ctx, unsigned char *output, const size_t nr_blocks);
    void cshake128(unsigned char *output, size_t output_len, const unsigned char *input, const size_t input_len, const unsigned char *customization, const size_t customization_len);

    void cshake256_init(cshake_ctx * ctx, const unsigned char *customization, const size_t customization_len);
    void cshake256_absorb(cshake_ctx * ctx, const unsigned char *input, const size_t input_len);
    void cshake256_squeezeblocks(cshake_ctx * ctx, unsigned char *output, const size_t nr_blocks);
    void cshake256(unsigned char *output, size_t output_len, const unsigned char *input, const size_t input_len, const unsigned char *customization, const size_t customization_len);


    #ifdef __cplusplus
}
    #endif

#endif /* SHAKE_H */
