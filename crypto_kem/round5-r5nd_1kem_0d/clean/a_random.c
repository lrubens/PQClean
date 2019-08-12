/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Implementation of the random A matrix creation function.
 */

#include "a_random.h"

#include "misc.h"
#include "little_endian.h"
#include "shake.h"
// #include "drbg.h"

void PQCLEAN_ROUND5R5ND_1KEM_0D_CLEAN_create_A_random(modq_t *A_random, const unsigned char *seed) {
    #if PARAMS_TAU == 2
    PQCLEAN_ROUND5R5ND_1KEM_0D_CLEAN_r5_xof(A_random, PARAMS_TAU2_LEN * sizeof(uint16_t), seed, PARAMS_KAPPA_BYTES);
    #else
    PQCLEAN_ROUND5R5ND_1KEM_0D_CLEAN_r5_xof(A_random, PARAMS_D * PARAMS_K * sizeof(uint16_t), seed, PARAMS_KAPPA_BYTES);
    #endif
}