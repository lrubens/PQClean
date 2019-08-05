/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Implementation of the SHAKE128, SHAKE256, cSHAKE128, and cSHAKE256 hash
 * functions.
 */

#include "shake.h"

#include "misc.h"

/* Use OpenSSL's Shake unless disabled/not supported */
#undef USE_OPENSSL_SHAKE
#ifndef NO_OPENSSL_SHAKE
#include <openssl/opensslv.h>
#if OPENSSL_VERSION_NUMBER >= 0x1010100f
#define USE_OPENSSL_SHAKE
#include <openssl/evp.h>
#endif
#endif

/*******************************************************************************
 * Public functions
 ******************************************************************************/
/**
 * Performs the initialisation step of the SHAKE-128 XOF.
 *
 * @param ctx the shake context
 */
void shake128_init(shake_ctx *ctx) {
    if (Keccak_HashInitialize_SHAKE128(ctx) != 0) {
        abort();
    }
}

/**
 * Performs the absorb step of the SHAKE-128 XOF.
 *
 * @param ctx the shake context
 * @param input the input absorbed into the state
 * @param input_len the length of the input
 */
void shake128_absorb(shake_ctx *ctx, const unsigned char *input, const size_t input_len) {
    if (Keccak_HashUpdate(ctx, input, input_len * 8) != 0) {
        abort();
    }
    if (Keccak_HashFinal(ctx, NULL) != 0) {
        abort();
    }
}

/**
 * Performs the squeeze step of the SHAKE-128 XOF. Squeezes full blocks of
 * SHAKE128_RATE bytes each. Can be called multiple times to keep squeezing
 * (i.e. this function is incremental).
 *
 * @param ctx the shake context
 * @param output the output
 * @param nr_blocks the number of blocks to squeeze
 */
void shake128_squeezeblocks(shake_ctx *ctx, unsigned char *output, const size_t nr_blocks) {
    if (Keccak_HashSqueeze(ctx, output, nr_blocks * SHAKE128_RATE * 8) != 0) {
        abort();
    }
}

/**
 * Performs the initialisation step of the SHAKE-256 XOF.
 *
 * @param ctx the shake context
 */
void shake256_init(shake_ctx *ctx) {
    if (Keccak_HashInitialize_SHAKE256(ctx) != 0) {
        abort();
    }
}

/**
 * Performs the absorb step of the SHAKE-256 XOF.
 *
 * @param ctx the shake context
 * @param input the input absorbed into the state
 * @param input_len the length of the input
 */
void shake256_absorb(shake_ctx *ctx, const unsigned char *input, const size_t input_len) {
    if (Keccak_HashUpdate(ctx, input, input_len * 8) != 0) {
        abort();
    }
    if (Keccak_HashFinal(ctx, NULL) != 0) {
        abort();
    }
}

/**
 * Performs the squeeze step of the SHAKE-256 XOF. Squeezes full blocks of
 * SHAKE256_RATE bytes each. Can be called multiple times to keep squeezing
 * (i.e. this function is incremental).
 *
 * @param ctx the shake context
 * @param output the output
 * @param nr_blocks the number of blocks to squeeze
 */
void shake256_squeezeblocks(shake_ctx *ctx, unsigned char *output, const size_t nr_blocks) {
    if (Keccak_HashSqueeze(ctx, output, nr_blocks * SHAKE256_RATE * 8) != 0) {
        abort();
    }
}

/**
 * Performs the initialisation step of the cSHAKE-128 XOF.
 *
 * @param ctx the cshake context
 * @param customization the customization string
 * @param customization_len the length of the customization string
 */
void cshake128_init(cshake_ctx *ctx, const unsigned char *customization, const size_t customization_len) {
    if (cSHAKE128_Initialize(ctx, 0, NULL, 0, customization, customization_len * 8) != 0) {
        abort();
    }
}

/**
 * Performs the absorb step of the cSHAKE-128 XOF.
 *
 * @param ctx the cshake context
 * @param input the input absorbed into the state
 * @param input_len the length of the input
 */
void cshake128_absorb(cshake_ctx *ctx, const unsigned char *input, const size_t input_len) {
    if (cSHAKE128_Update(ctx, input, input_len * 8) != 0) {
        abort();
    }
    if (cSHAKE128_Final(ctx, NULL) != 0) {
        abort();
    }
}

/**
 * Performs the squeeze step of the cSHAKE-128 XOF. Squeezes full blocks of
 * SHAKE128_RATE bytes each. Can be called multiple times to keep squeezing
 * (i.e. this function is incremental).
 *
 * @param ctx the cshake context
 * @param output the output
 * @param nr_blocks the number of blocks to squeeze
 */
void cshake128_squeezeblocks(cshake_ctx *ctx, unsigned char *output, const size_t nr_blocks) {
    if (cSHAKE128_Squeeze(ctx, output, nr_blocks * SHAKE128_RATE * 8) != 0) {
        abort();
    }
}

/**
 * Performs the full cSHAKE-128 XOF to the given input.
 * @param output the final output
 * @param output_len the length of the output
 * @param input the input
 * @param input_len the length of the input
 * @param customization the customization string
 * @param customization_len the length of the customization string
 */
void cshake128(unsigned char *output, size_t output_len, const unsigned char *input, const size_t input_len, const unsigned char *customization, const size_t customization_len) {
    if (cSHAKE128(input, input_len * 8, output, output_len * 8, NULL, 0, customization, customization_len) != 0) {
        abort();
    }
}

/**
 * Performs the initialisation step of the cSHAKE-256 XOF.
 *
 * @param ctx the cshake context
 * @param customization the customization string
 * @param customization_len the length of the customization string
 */
void cshake256_init(cshake_ctx *ctx, const unsigned char *customization, const size_t customization_len) {
    if (cSHAKE256_Initialize(ctx, 0, NULL, 0, customization, customization_len * 8) != 0) {
        abort();
    }
}

/**
 * Performs the absorb step of the cSHAKE-256 XOF.
 *
 * @param ctx the cshake context
 * @param input the input absorbed into the state
 * @param input_len the length of the input
 */
void cshake256_absorb(cshake_ctx *ctx, const unsigned char *input, const size_t input_len) {
    if (cSHAKE256_Update(ctx, input, input_len * 8) != 0) {
        abort();
    }
    if (cSHAKE256_Final(ctx, NULL) != 0) {
        abort();
    }
}

/**
 * Performs the squeeze step of the cSHAKE-256 XOF. Squeezes full blocks of
 * SHAKE256_RATE bytes each. Can be called multiple times to keep squeezing
 * (i.e. this function is incremental).
 *
 * @param ctx the cshake context
 * @param output the output
 * @param nr_blocks the number of blocks to squeeze
 */
void cshake256_squeezeblocks(cshake_ctx *ctx, unsigned char *output, const size_t nr_blocks) {
    if (cSHAKE256_Squeeze(ctx, output, nr_blocks * SHAKE256_RATE * 8) != 0) {
        abort();
    }
}

/**
 * Performs the full cSHAKE-256 XOF to the given input.
 * @param output the final output
 * @param output_len the length of the output
 * @param input the input
 * @param input_len the length of the input
 * @param customization the customization string
 * @param customization_len the length of the customization string
 */
void cshake256(unsigned char *output, size_t output_len, const unsigned char *input, const size_t input_len, const unsigned char *customization, const size_t customization_len) {
    if (cSHAKE256(input, input_len * 8, output, output_len * 8, NULL, 0, customization, customization_len) != 0) {
        abort();
    }
}

void shake128(unsigned char *output, size_t output_len, const unsigned char *input, const size_t input_len) {
    #if defined(USE_OPENSSL_SHAKE)
    EVP_MD_CTX *md_ctx;
    if (!(md_ctx = EVP_MD_CTX_new())) {
        abort();
    }
    if (EVP_DigestInit_ex(md_ctx, EVP_shake128(), NULL) != 1) {
        abort();
    }
    if (EVP_DigestUpdate(md_ctx, input, input_len) != 1) {
        abort();
    }
    if (EVP_DigestFinalXOF(md_ctx, (unsigned char *) output, output_len) != 1) {
        abort();
    }
    EVP_MD_CTX_free(md_ctx);
    #else
    shake_ctx ctx;
    shake128_init(&ctx);
    shake128_absorb(&ctx, input, input_len);
    if (Keccak_HashSqueeze(&ctx, output, output_len * 8) != 0) {
        abort();
    }
    #endif
}

void shake256(unsigned char *output, size_t output_len, const unsigned char *input, const size_t input_len) {
    #if defined(USE_OPENSSL_SHAKE)
    EVP_MD_CTX *md_ctx;
    if (!(md_ctx = EVP_MD_CTX_new())) {
        abort();
    }
    if (EVP_DigestInit_ex(md_ctx, EVP_shake256(), NULL) != 1) {
        abort();
    }
    if (EVP_DigestUpdate(md_ctx, input, input_len) != 1) {
        abort();
    }
    if (EVP_DigestFinalXOF(md_ctx, (unsigned char *) output, output_len) != 1) {
        abort();
    }
    EVP_MD_CTX_free(md_ctx);
    #else
    shake_ctx ctx;
    shake256_init(&ctx);
    shake256_absorb(&ctx, input, input_len);
    if (Keccak_HashSqueeze(&ctx, output, output_len * 8) != 0) {
        abort();
    }
    #endif
}
