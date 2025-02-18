/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Implementation of the encrypt and decrypt functions based on the CCA KEM
 * algorithm (NIST api).
 */

#include "cca_encrypt.h"

#if CRYPTO_CIPHERTEXTBYTES == 0

extern int PQCLEAN_ROUND5R5ND_3KEM_5D_CLEAN_crypto_encrypt_keypair(unsigned char *pk, unsigned char *sk);
extern int PQCLEAN_ROUND5R5ND_3KEM_5D_CLEAN_crypto_encrypt(unsigned char *ct, unsigned long long *ct_len, const unsigned char *m, const unsigned long long m_len, const unsigned char *pk);
extern int PQCLEAN_ROUND5R5ND_3KEM_5D_CLEAN_crypto_encrypt_open(unsigned char *m, unsigned long long *m_len, const unsigned char *ct, const unsigned long long ct_len, const unsigned char *sk);

#endif