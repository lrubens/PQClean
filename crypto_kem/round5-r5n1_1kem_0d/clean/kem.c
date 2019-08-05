#include <stdint.h>

#include "api.h"
#include "cpa_kem.h"
#include <stdlib.h>



int PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_crypto_kem_keypair(unsigned char *pk, unsigned char *sk) {
    crypto_kem_keypair((unsigned char *)pk, (unsigned char *)sk);
    return 0;
}

int PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_crypto_kem_enc(unsigned char *ct, unsigned char *key, const unsigned char *pk) {
    crypto_kem_enc((unsigned char *)ct, (unsigned char *)key, (unsigned char *)pk);
    return 0;
}

int PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_crypto_kem_dec(unsigned char *key, unsigned char *ct, const unsigned char *sk) {
    crypto_kem_dec((unsigned char *)key, (unsigned char *)ct, (unsigned char *)sk);
    return 0;
}