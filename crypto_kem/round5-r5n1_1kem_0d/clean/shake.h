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

void r5_xof(void *out, const size_t out_len,
            const void *in, const size_t in_len);

void r5_xof_input(r5_xof_ctx_t *ctx,
                  const void *in, size_t in_len);

void r5_xof_s_input(r5_xof_ctx_t *ctx,
                    const void *in, size_t in_len,
                    const void *sstr, size_t sstr_len);

void r5_xof_squeeze(r5_xof_ctx_t *ctx,
                    void *out, size_t out_len);


#endif /* SHAKE_H */
