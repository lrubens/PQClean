/*
 * Copyright (c) 2019, Koninklijke Philips N.V.
 */

/**
 * @file
 * Declaration of the NIST API functions and setting of the NIST API
 * algorithm parameters: `CRYPTO_SECRETKEYBYTES`, `CRYPTO_PUBLICKEYBYTES`,
 * `CRYPTO_BYTES`, and `CRYPTO_CIPHERBYTES`.
 */

#ifndef PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_API_H
#define PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_API_H

#define PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_CRYPTO_ALGNAME "R5ND_5KEM_5d"
#define PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_CRYPTO_SECRETKEYBYTES 32
#define PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_CRYPTO_PUBLICKEYBYTES 972
#define PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_CRYPTO_BYTES 32
#define PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_CRYPTO_CIPHERTEXTBYTES 1063

int PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_crypto_kem_keypair(unsigned char *pk, unsigned char *sk);
int PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_crypto_kem_enc(unsigned char *ct, unsigned char *key, const unsigned char *pk);
int PQCLEAN_ROUND5R5ND_5KEM_5D_CLEAN_crypto_kem_dec(unsigned char *key, unsigned char *ct, const unsigned char *sk);

#endif /* _API_H_ */