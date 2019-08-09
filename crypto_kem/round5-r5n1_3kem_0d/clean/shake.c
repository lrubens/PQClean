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
// #include "sp800-185.h"

/*******************************************************************************
 * Public functions
 ******************************************************************************/
// #ifndef cshake128_int_init
static size_t left_encode(uint8_t *encbuf, size_t value) {
    size_t n, i, v;

    for (v = value, n = 0; v && (n < sizeof(size_t)); n++, v >>= 8) {
        ; /* empty */
    }
    if (n == 0) {
        n = 1;
    }
    for (i = 1; i <= n; i++) {
        encbuf[i] = (uint8_t)(value >> (8 * (n-i)));
    }
    encbuf[0] = (uint8_t)n;
    return n + 1;
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_init(shake128incctx *state, const uint8_t *name, size_t namelen, const uint8_t *cstm, size_t cstmlen) {
    uint8_t encbuf[sizeof(size_t)+1];

    shake128_inc_init(state);

    shake128_inc_absorb(state, encbuf, left_encode(encbuf, SHAKE128_RATE));

    shake128_inc_absorb(state, encbuf, left_encode(encbuf, namelen * 8));
    shake128_inc_absorb(state, name, namelen);

    shake128_inc_absorb(state, encbuf, left_encode(encbuf, cstmlen * 8));
    shake128_inc_absorb(state, cstm, cstmlen);

    if (state->ctx[25] != 0) {
        state->ctx[25] = SHAKE128_RATE - 1;
        encbuf[0] = 0;
        shake128_inc_absorb(state, encbuf, 1);
    }
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_absorb(shake128incctx *state, const uint8_t *input, size_t inlen) {
    shake128_inc_absorb(state, input, inlen);
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_finalize(shake128incctx *state) {
    state->ctx[state->ctx[25] >> 3] ^= (uint64_t)0x04 << (8 * (state->ctx[25] & 0x07));
    state->ctx[(SHAKE128_RATE - 1) >> 3] ^= (uint64_t)128 << (8 * ((SHAKE128_RATE - 1) & 0x07));
    state->ctx[25] = 0;
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_squeeze(uint8_t *output, size_t outlen, shake128incctx *state) {
    shake128_inc_squeeze(output, outlen, state);
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_init(shake256incctx *state, const uint8_t *name, size_t namelen, const uint8_t *cstm, size_t cstmlen) {
    uint8_t encbuf[sizeof(size_t)+1];

    shake256_inc_init(state);

    shake256_inc_absorb(state, encbuf, left_encode(encbuf, SHAKE256_RATE));

    shake256_inc_absorb(state, encbuf, left_encode(encbuf, namelen * 8));
    shake256_inc_absorb(state, name, namelen);

    shake256_inc_absorb(state, encbuf, left_encode(encbuf, cstmlen * 8));
    shake256_inc_absorb(state, cstm, cstmlen);

    if (state->ctx[25] != 0) {
        state->ctx[25] = SHAKE256_RATE - 1;
        encbuf[0] = 0;
        shake256_inc_absorb(state, encbuf, 1);
    }
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_absorb(shake256incctx *state, const uint8_t *input, size_t inlen) {
    shake256_inc_absorb(state, input, inlen);
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_finalize(shake256incctx *state) {
    state->ctx[state->ctx[25] >> 3] ^= (uint64_t)0x04 << (8 * (state->ctx[25] & 0x07));
    state->ctx[(SHAKE256_RATE - 1) >> 3] ^= (uint64_t)128 << (8 * ((SHAKE256_RATE - 1) & 0x07));
    state->ctx[25] = 0;
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_squeeze(uint8_t *output, size_t outlen, shake256incctx *state) {
    shake256_inc_squeeze(output, outlen, state);
}

/*************************************************
 * Name:        cshake128
 *
 * Description: cSHAKE128 XOF with non-incremental API
 *
 * Arguments:   - uint8_t *output: pointer to output
 *              - size_t outlen: requested output length in bytes
 *              - const uint8_t *name: pointer to function-name string
 *              - size_t namelen: length of function-name string in bytes
 *              - const uint8_t *cstm: pointer to non-empty customization string
 *              - size_t cstmlen: length of customization string in bytes
 *              - const uint8_t *input: pointer to input
 *              - size_t inlen: length of input in bytes
 **************************************************/
void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128(uint8_t *output, size_t outlen,
               const uint8_t *name, size_t namelen,
               const uint8_t *cstm, size_t cstmlen,
               const uint8_t *input, size_t inlen) {
    shake128incctx state;
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_init(&state, name, namelen, cstm, cstmlen);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_absorb(&state, input, inlen);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_finalize(&state);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_squeeze(output, outlen, &state);
}

/*************************************************
 * Name:        cshake256
 *
 * Description: cSHAKE256 XOF with non-incremental API
 *
 * Arguments:   - uint8_t *output: pointer to output
 *              - size_t outlen: requested output length in bytes
 *              - const uint8_t *name: pointer to function-name string
 *              - size_t namelen: length of function-name string in bytes
 *              - const uint8_t *cstm: pointer to non-empty customization string
 *              - size_t cstmlen: length of customization string in bytes
 *              - const uint8_t *input: pointer to input
 *              - size_t inlen: length of input in bytes
 **************************************************/
void PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256(uint8_t *output, size_t outlen,
               const uint8_t *name, size_t namelen,
               const uint8_t *cstm, size_t cstmlen,
               const uint8_t *input, size_t inlen) {
    shake256incctx state;
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_init(&state, name, namelen, cstm, cstmlen);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_absorb(&state, input, inlen);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_finalize(&state);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_squeeze(output, outlen, &state);
}


void PQCLEAN_ROUND5R5N1_3KEM_0D_r5_xof_input(r5_xof_ctx_t *ctx,
                  const void *in, size_t in_len) {
    #if (PARAMS_KAPPA_BYTES > 16)
    shake256_inc_init(ctx);
    shake256_inc_absorb(ctx, in, in_len);
    shake256_inc_finalize(ctx);
    #else
    shake128_inc_init(ctx);
    shake128_inc_absorb(ctx, in, in_len);
    shake128_inc_finalize(ctx);
    #endif
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_r5_xof_squeeze(r5_xof_ctx_t *ctx,
                    void *out, size_t out_len) {
    #if (PARAMS_KAPPA_BYTES > 16)
    shake256_inc_squeeze(out, out_len, ctx);
    #else
    shake128_inc_squeeze(out, out_len, ctx);
    #endif
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_r5_xof(void *out, size_t out_len,
            const void *in, size_t in_len) {
    #if (PARAMS_KAPPA_BYTES > 16)
    shake256(out, out_len, in, in_len);
    #else
    shake128(out, out_len, in, in_len);
    #endif
}

void PQCLEAN_ROUND5R5N1_3KEM_0D_r5_xof_s_input(r5_xof_ctx_t *ctx,
                    const void *in, size_t in_len,
                    const void *sstr, size_t sstr_len) {
    #if (PARAMS_KAPPA_BYTES > 16)
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_init(ctx, (const uint8_t *)"", 0, sstr, sstr_len);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_absorb(ctx, in, in_len);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake256_inc_finalize(ctx);
    #else
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_init(ctx, (const uint8_t *)"", 0, sstr, sstr_len);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_absorb(ctx, in, in_len);
    PQCLEAN_ROUND5R5N1_3KEM_0D_cshake128_inc_finalize(ctx);
    #endif
}

