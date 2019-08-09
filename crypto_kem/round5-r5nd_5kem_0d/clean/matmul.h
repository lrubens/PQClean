/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

#ifndef _MATMUL_H_
#define _MATMUL_H_

#include "r5_parameter_sets.h"

#if PARAMS_K != 1

// create a sparse ternary vector from a seed
#ifdef CM_CACHE
void PQCLEAN_ROUND5R5ND_5KEM_0D_create_secret_matrix_s_t(int16_t s_t[PARAMS_N_BAR][PARAMS_D], const uint8_t *seed);
void PQCLEAN_ROUND5R5ND_5KEM_0D_create_secret_matrix_r_t(int16_t r_t[PARAMS_M_BAR][PARAMS_D], const uint8_t *seed);

#if PARAMS_TAU == 0
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_as_q(modq_t d[PARAMS_D][PARAMS_N_BAR], modq_t a[PARAMS_D][PARAMS_D], int16_t s_t[PARAMS_N_BAR][PARAMS_D]);
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_rta_q(modq_t d[PARAMS_M_BAR][PARAMS_D], modq_t a[PARAMS_D][PARAMS_D], int16_t r_t[PARAMS_M_BAR][PARAMS_D]);
#elif PARAMS_TAU == 1
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_as_q(modq_t d[PARAMS_D][PARAMS_N_BAR], modq_t a[2 * PARAMS_D * PARAMS_D], uint32_t a_permutation[PARAMS_D], int16_t s_t[PARAMS_N_BAR][PARAMS_D]);
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_rta_q(modq_t d[PARAMS_M_BAR][PARAMS_D], modq_t a[2 * PARAMS_D * PARAMS_D], uint32_t a_permutation[PARAMS_D], int16_t r_t[PARAMS_M_BAR][PARAMS_D]);
#else
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_as_q(modq_t d[PARAMS_D][PARAMS_N_BAR], modq_t a[PARAMS_TAU2_LEN + PARAMS_D], uint16_t a_permutation[PARAMS_D], int16_t s_t[PARAMS_N_BAR][PARAMS_D]);
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_rta_q(modq_t d[PARAMS_M_BAR][PARAMS_D], modq_t a[PARAMS_TAU2_LEN + PARAMS_D], uint16_t a_permutation[PARAMS_D], int16_t r_t[PARAMS_M_BAR][PARAMS_D]);
#endif

void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_stu_p(modp_t d[PARAMS_MU], modp_t u_t[PARAMS_M_BAR][PARAMS_D], int16_t s_t[PARAMS_N_BAR][PARAMS_D]);

void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_btr_p(modp_t d[PARAMS_MU], modp_t b[PARAMS_D][PARAMS_N_BAR], int16_t r_t[PARAMS_M_BAR][PARAMS_D]);

#else
void PQCLEAN_ROUND5R5ND_5KEM_0D_create_secret_matrix_s_t(uint16_t s_t[PARAMS_N_BAR][PARAMS_H / 2][2], const uint8_t *seed);
void PQCLEAN_ROUND5R5ND_5KEM_0D_create_secret_matrix_r_t(uint16_t r_t[PARAMS_M_BAR][PARAMS_H / 2][2], const uint8_t *seed);

#if PARAMS_TAU == 0
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_as_q(modq_t d[PARAMS_D][PARAMS_N_BAR], modq_t a[PARAMS_D][PARAMS_D], uint16_t s_t[PARAMS_N_BAR][PARAMS_H / 2][2]);
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_rta_q(modq_t d[PARAMS_M_BAR][PARAMS_D], modq_t a[PARAMS_D][PARAMS_D], uint16_t r_t[PARAMS_M_BAR][PARAMS_H / 2][2]);
#elif PARAMS_TAU == 1
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_as_q(modq_t d[PARAMS_D][PARAMS_N_BAR], modq_t a[2 * PARAMS_D * PARAMS_D], uint32_t a_permutation[PARAMS_D], uint16_t s_t[PARAMS_N_BAR][PARAMS_H / 2][2]);
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_rta_q(modq_t d[PARAMS_M_BAR][PARAMS_D], modq_t a[2 * PARAMS_D * PARAMS_D], uint32_t a_permutation[PARAMS_D], uint16_t r_t[PARAMS_M_BAR][PARAMS_H / 2][2]);
#else
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_as_q(modq_t d[PARAMS_D][PARAMS_N_BAR], modq_t a[PARAMS_TAU2_LEN + PARAMS_D], uint16_t a_permutation[PARAMS_D], uint16_t s_t[PARAMS_N_BAR][PARAMS_H / 2][2]);
void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_rta_q(modq_t d[PARAMS_M_BAR][PARAMS_D], modq_t a[PARAMS_TAU2_LEN + PARAMS_D], uint16_t a_permutation[PARAMS_D], uint16_t r_t[PARAMS_M_BAR][PARAMS_H / 2][2]);
#endif

void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_stu_p(modp_t d[PARAMS_MU], modp_t u_t[PARAMS_M_BAR][PARAMS_D], uint16_t s_t[PARAMS_N_BAR][PARAMS_H / 2][2]);

void PQCLEAN_ROUND5R5ND_5KEM_0D_matmul_btr_p(modp_t d[PARAMS_MU], modp_t b[PARAMS_D][PARAMS_N_BAR], uint16_t r_t[PARAMS_M_BAR][PARAMS_H / 2][2]);

#endif

#endif /* PARAMS_K != 1 */

#endif /* _MATMUL_H_ */