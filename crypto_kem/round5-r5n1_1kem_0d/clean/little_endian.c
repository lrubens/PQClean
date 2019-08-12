/*
 * Copyright (c) 2018, Koninklijke Philips N.V.
 */

/**
 * @file
 * Implementation of little-endian byte array conversion functions.
 */

#include "little_endian.h"

/* Force symbols to be emitted when no compiler optimisation is applied. */
extern inline uint8_t PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_u8_from_le(const unsigned char *x);
extern inline void PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_u8_to_le(unsigned char *x, const uint8_t u);
extern inline uint16_t PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_u16_from_le(const unsigned char *x);
extern inline void PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_u16_to_le(unsigned char *x, const uint16_t u);
extern inline uint32_t PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_u32_from_le(const unsigned char *x);
extern inline void PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_u32_to_le(unsigned char *x, const uint32_t u);
extern inline uint64_t PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_u64_from_le(const unsigned char *x);
extern inline void PQCLEAN_ROUND5R5N1_1KEM_0D_CLEAN_u64_to_le(unsigned char *x, const uint64_t u);