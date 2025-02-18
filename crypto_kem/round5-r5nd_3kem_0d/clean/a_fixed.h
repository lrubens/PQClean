/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Declaration of the fixed A matrix as well as the function to generate it.
 */

#ifndef A_FIXED_H
#define A_FIXED_H

#include "r5_parameter_sets.h"

#if PARAMS_TAU == 1
/**
 * The fixed A matrix for use inside with the non-ring algorithm when τ=1.
 * This matrix is generated by `create_A_fixed()`.
 */
extern modq_t A_fixed[PARAMS_D * 2 * PARAMS_K];
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Function to generate a fixed A matrix from the given seed and algorithm parameters.
 *
 * @param[in] seed the seed to use to generate the fixed A matrix (KAPPA_BYTES bytes)
 * @return __0__ in case of success
 */
int PQCLEAN_ROUND5R5ND_3KEM_0D_CLEAN_create_A_fixed(const unsigned char *seed);

#ifdef __cplusplus
}
#endif

#endif /* A_FIXED_H */