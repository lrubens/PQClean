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
#include "r5_parameter_sets.h"
#include "fips202.h"
// #include "sp800-185.h"

// #define cshake128 OQS_SHA3_cshake128
// #define cshake256 OQS_SHA3_cshake256
// #define cshake128_inc_init OQS_SHA3_cshake128_inc_init
// #define cshake256_inc_init OQS_SHA3_cshake256_inc_init
// #define cshake128_inc_absorb OQS_SHA3_cshake128_inc_absorb
// #define cshake256_inc_absorb OQS_SHA3_cshake256_inc_absorb
// #define cshake128_inc_finalize OQS_SHA3_cshake128_inc_finalize
// #define cshake256_inc_finalize OQS_SHA3_cshake256_inc_finalize

#if (PARAMS_KAPPA_BYTES > 16)
typedef shake256incctx r5_xof_ctx_t;
#else
typedef shake128incctx r5_xof_ctx_t;
#endif

void PQCLEAN_ROUND5R5ND_3KEM_0D_r5_xof(void *out, const size_t out_len,
            const void *in, const size_t in_len);

void PQCLEAN_ROUND5R5ND_3KEM_0D_r5_xof_input(r5_xof_ctx_t *ctx,
                  const void *in, size_t in_len);

void PQCLEAN_ROUND5R5ND_3KEM_0D_r5_xof_s_input(r5_xof_ctx_t *ctx,
                    const void *in, size_t in_len,
                    const void *sstr, size_t sstr_len);

void PQCLEAN_ROUND5R5ND_3KEM_0D_r5_xof_squeeze(r5_xof_ctx_t *ctx,
                    void *out, size_t out_len);
                    
void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake128_inc_init(shake128incctx *state, const uint8_t *name, size_t namelen, const uint8_t *cstm, size_t cstmlen);
void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake128_inc_absorb(shake128incctx *state, const uint8_t *input, size_t inlen);
void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake128_inc_finalize(shake128incctx *state);
void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake128_inc_squeeze(uint8_t *output, size_t outlen, shake128incctx *state);

void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake128(uint8_t *output, size_t outlen, const uint8_t *name, size_t namelen, const uint8_t *cstm, size_t cstmlen, const uint8_t *input, size_t inlen);

void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake256_inc_init(shake256incctx *state, const uint8_t *name, size_t namelen, const uint8_t *cstm, size_t cstmlen);
void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake256_inc_absorb(shake256incctx *state, const uint8_t *input, size_t inlen);
void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake256_inc_finalize(shake256incctx *state);
void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake256_inc_squeeze(uint8_t *output, size_t outlen, shake256incctx *state);

void PQCLEAN_ROUND5R5ND_3KEM_0D_cshake256(uint8_t *output, size_t outlen, const uint8_t *name, size_t namelen, const uint8_t* cstm, size_t cstmlen, const uint8_t *input, size_t inlen);

#endif /* SHAKE_H */