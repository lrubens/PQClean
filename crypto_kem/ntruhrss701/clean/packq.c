#include "poly.h"


void PQCLEAN_NTRUHRSS701_CLEAN_poly_Sq_tobytes(unsigned char *r, const poly *a) {
    int i, j;
    uint16_t t[8];

    for (i = 0; i < NTRU_PACK_DEG / 8; i++) {
        for (j = 0; j < 8; j++) {
            t[j] = a->coeffs[8 * i + j];
        }

        r[13 * i + 0] =  t[0]        & 0xff;
        r[13 * i + 1] = (t[0] >>  8) | ((t[1] & 0x07) << 5);
        r[13 * i + 2] = (t[1] >>  3) & 0xff;
        r[13 * i + 3] = (t[1] >> 11) | ((t[2] & 0x3f) << 2);
        r[13 * i + 4] = (t[2] >>  6) | ((t[3] & 0x01) << 7);
        r[13 * i + 5] = (t[3] >>  1) & 0xff;
        r[13 * i + 6] = (t[3] >>  9) | ((t[4] & 0x0f) << 4);
        r[13 * i + 7] = (t[4] >>  4) & 0xff;
        r[13 * i + 8] = (t[4] >> 12) | ((t[5] & 0x7f) << 1);
        r[13 * i + 9] = (t[5] >>  7) | ((t[6] & 0x03) << 6);
        r[13 * i + 10] = (t[6] >>  2) & 0xff;
        r[13 * i + 11] = (t[6] >> 10) | ((t[7] & 0x1f) << 3);
        r[13 * i + 12] = (t[7] >>  5);
    }

    for (j = 0; j < NTRU_PACK_DEG - 8 * i; j++) {
        t[j] = a->coeffs[8 * i + j];
    }
    for (; j < 8; j++) {
        t[j] = 0;
    }

    switch (NTRU_PACK_DEG - 8 * (NTRU_PACK_DEG / 8)) {
    case 6:
        r[13 * i + 9] = (t[5] >>  7) | ((t[6] & 0x03) << 6);
        r[13 * i + 8] = (t[4] >> 12) | ((t[5] & 0x7f) << 1);
        r[13 * i + 7] = (t[4] >>  4) & 0xff;
    // fallthrough
    case 4:
        r[13 * i + 6] = (t[3] >>  9) | ((t[4] & 0x0f) << 4);
        r[13 * i + 5] = (t[3] >>  1) & 0xff;
        r[13 * i + 4] = (t[2] >>  6) | ((t[3] & 0x01) << 7);
    // fallthrough
    case 2:
        r[13 * i + 3] = (t[1] >> 11) | ((t[2] & 0x3f) << 2);
        r[13 * i + 2] = (t[1] >>  3) & 0xff;
        r[13 * i + 1] = (t[0] >>  8) | ((t[1] & 0x07) << 5);
        r[13 * i + 0] =  t[0]        & 0xff;
    }
}

void PQCLEAN_NTRUHRSS701_CLEAN_poly_Sq_frombytes(poly *r, const unsigned char *a) {
    int i;
    for (i = 0; i < NTRU_PACK_DEG / 8; i++) {
        r->coeffs[8 * i + 0] =  a[13 * i + 0]       | (((uint16_t)a[13 * i + 1] & 0x1f) << 8);
        r->coeffs[8 * i + 1] = (a[13 * i + 1] >> 5) | (((uint16_t)a[13 * i + 2]       ) << 3) | (((uint16_t)a[13 * i + 3] & 0x03) << 11);
        r->coeffs[8 * i + 2] = (a[13 * i + 3] >> 2) | (((uint16_t)a[13 * i + 4] & 0x7f) << 6);
        r->coeffs[8 * i + 3] = (a[13 * i + 4] >> 7) | (((uint16_t)a[13 * i + 5]       ) << 1) | (((uint16_t)a[13 * i + 6] & 0x0f) <<  9);
        r->coeffs[8 * i + 4] = (a[13 * i + 6] >> 4) | (((uint16_t)a[13 * i + 7]       ) << 4) | (((uint16_t)a[13 * i + 8] & 0x01) << 12);
        r->coeffs[8 * i + 5] = (a[13 * i + 8] >> 1) | (((uint16_t)a[13 * i + 9] & 0x3f) << 7);
        r->coeffs[8 * i + 6] = (a[13 * i + 9] >> 6) | (((uint16_t)a[13 * i + 10]       ) << 2) | (((uint16_t)a[13 * i + 11] & 0x07) << 10);
        r->coeffs[8 * i + 7] = (a[13 * i + 11] >> 3) | (((uint16_t)a[13 * i + 12]       ) << 5);
    }
    switch (NTRU_PACK_DEG - 8 * (NTRU_PACK_DEG / 8)) {
    case 6:
        r->coeffs[8 * i + 5] = (a[13 * i + 8] >> 1) | (((uint16_t)a[13 * i + 9] & 0x3f) << 7);
        r->coeffs[8 * i + 4] = (a[13 * i + 6] >> 4) | (((uint16_t)a[13 * i + 7]       ) << 4) | (((uint16_t)a[13 * i + 8] & 0x01) << 12);
    // fallthrough
    case 4:
        r->coeffs[8 * i + 3] = (a[13 * i + 4] >> 7) | (((uint16_t)a[13 * i + 5]       ) << 1) | (((uint16_t)a[13 * i + 6] & 0x0f) <<  9);
        r->coeffs[8 * i + 2] = (a[13 * i + 3] >> 2) | (((uint16_t)a[13 * i + 4] & 0x7f) << 6);
    // fallthrough
    case 2:
        r->coeffs[8 * i + 1] = (a[13 * i + 1] >> 5) | (((uint16_t)a[13 * i + 2]       ) << 3) | (((uint16_t)a[13 * i + 3] & 0x03) << 11);
        r->coeffs[8 * i + 0] =  a[13 * i + 0]       | (((uint16_t)a[13 * i + 1] & 0x1f) << 8);
    }
}

void PQCLEAN_NTRUHRSS701_CLEAN_poly_Rq_sum_zero_tobytes(unsigned char *r, const poly *a) {
    PQCLEAN_NTRUHRSS701_CLEAN_poly_Sq_tobytes(r, a);
}

void PQCLEAN_NTRUHRSS701_CLEAN_poly_Rq_sum_zero_frombytes(poly *r, const unsigned char *a) {
    int i;
    PQCLEAN_NTRUHRSS701_CLEAN_poly_Sq_frombytes(r, a);

    /* Set r[n-1] so that the sum of coefficients is zero mod q */
    r->coeffs[NTRU_N - 1] = 0;
    for (i = 0; i < NTRU_PACK_DEG; i++) {
        r->coeffs[NTRU_N - 1] += r->coeffs[i];
    }
    r->coeffs[NTRU_N - 1] = MODQ(-(r->coeffs[NTRU_N - 1]));
}
