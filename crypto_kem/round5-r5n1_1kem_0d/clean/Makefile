# This Makefile can be used with GNU Make or BSD Make

LIB=libround5-r5n1_1kem_0d_clean.a
HEADERS=a_fixed.h a_random.h api.h cca_encrypt.h cpa_kem.h little_endian.h matmul.h misc.h probe_cm.h r5_cca_kem.h r5_cca_pke.h r5_cpa_kem.h r5_cpa_pke.h r5_dem.h r5_memory.h r5_parameter_sets.h ringmul.h rng.h xef.h shake.h #libkeccak.a.headers/SP800-185.h libkeccak.a.header/SP800-185.inc libkeccak.a.headers/KeccakHash.h #sha3/opt64/KeccakP-1600-SnP.h
OBJECTS=a_fixed.o a_random.o cca_encrypt.o cpa_kem.o kem.o little_endian.o matmul.o matmul_avx2.o matmul_cm.o misc.o nist_rng.o probe_cm.o r5_cca_kem.o r5_cca_pke.o r5_cpa_kem.o r5_cpa_pke_n1.o r5_cpa_pke_nd.o r5_dem.o r5_memory.o ringmul.o ringmul_cm.o xe2_c16.o xe4_c64.o xe5_c64.o xef_ref.o shake.o 

CFLAGS=-O3 -Wall -Wextra -Wpedantic -Werror -I../../../common -Iexternal -Iexternal/sha3 -Iexternal/sha3/opt64 -std=c99 $(EXTRAFLAGS)

all: $(LIB)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB): $(OBJECTS)
	$(AR) -r $@ $(OBJECTS) 

clean:
	$(RM) $(OBJECTS)
	$(RM) $(LIB)
