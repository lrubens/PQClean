#include <stdint.h>
#include <stdlib.h>
#include "api.h"
#include "cpa_kem.h"

int PQCLEAN_ROUND5R5ND_3KEM_0D_CLEAN_crypto_kem_keypair(unsigned char *pk, unsigned char *sk) {
    PQCLEAN_ROUND5R5ND_3KEM_0D_crypto_kem_keypair(pk, sk);
    return 0;
}

int PQCLEAN_ROUND5R5ND_3KEM_0D_CLEAN_crypto_kem_enc(unsigned char *ct, unsigned char *key, const unsigned char *pk) {
    PQCLEAN_ROUND5R5ND_3KEM_0D_crypto_kem_enc(ct, key, pk);
    return 0;
}

int PQCLEAN_ROUND5R5ND_3KEM_0D_CLEAN_crypto_kem_dec(unsigned char *key, unsigned char *ct, const unsigned char *sk) {
    PQCLEAN_ROUND5R5ND_3KEM_0D_crypto_kem_dec(key, ct, sk);
    return 0;
}