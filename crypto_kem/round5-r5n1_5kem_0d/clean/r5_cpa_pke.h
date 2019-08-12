/*
 * Copyright (c) 2018, PQShield and Koninklijke Philips N.V.
 * Markku-Juhani O. Saarinen, Koninklijke Philips N.V.
 */

#ifndef _R5_CPA_PKE_H_
#define _R5_CPA_PKE_H_

#include <stdint.h>

int PQCLEAN_ROUND5R5N1_5KEM_0D_CLEAN_r5_cpa_pke_keygen(uint8_t *pk, uint8_t *sk);

int PQCLEAN_ROUND5R5N1_5KEM_0D_CLEAN_r5_cpa_pke_encrypt(uint8_t *ct, const uint8_t *pk, const uint8_t *m, const uint8_t *rho);

int PQCLEAN_ROUND5R5N1_5KEM_0D_CLEAN_r5_cpa_pke_decrypt(uint8_t *m, const uint8_t *sk, const uint8_t *ct);

#endif /* _R5_CPA_PKE_H_ */