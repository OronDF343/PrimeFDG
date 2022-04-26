#pragma once
#include "bitarray.h"

// LSb-first Big-endian: 3210
#define LSB_BIG 0xE4
// LSb-first Little-endian: 1032
#define LSB_LITTLE 0x4E
// MSb-first Big-endian: 0123
#define MSB_BIG 0x1B
// MSb-first Little-endian: 2301
#define MSB_LITTLE 0xB1

typedef struct
{
	// = "PFDG" (in ASCII)
	const char magic[4];
	const uint8_t version_major;
	const uint8_t version_minor;
	const uint8_t bit_byte_order;
	const uint8_t word_bytes;
	uint64_t data_start;
	uint64_t data_length;
	uint64_t number_first;
	uint64_t number_last;
	// Address: 40d / 28h
	uint64_t primes_found;

} pfdg_file_header;

#define PFDG_HEADER_INITIALIZER { "PFDG", 2, 0, NATIVE_ORDER, sizeof(BITARRAY_WORD), sizeof(pfdg_file_header) }

// Static pattern + prefix + known primes
uint64_t pfdg_mem_get_base(const uint64_t start, const uint64_t end);
// Maximum size for single chunk
uint64_t pfdg_mem_get_chunk_size(const uint64_t start, const uint64_t end, const uint64_t chunks);
// Get number of chunks by chunk size
uint64_t pfdg_mem_get_chunk_count_by_size(const uint64_t start, const uint64_t end, const uint64_t chunk_size);

bitarray* pfdg_init_bitarray(const uint64_t capacity, const uint64_t offset, const bool use_pattern);
void pfdg_mark(bitarray* const arr, const uint64_t prime, const uint64_t offset);
void pfdg_sieve_seed(bitarray* const arr, const bool skip);
void pfdg_sieve(bitarray* const arr, bitarray* const known, const uint64_t offset, const bool skip);
bool pfdg_sieve_parallel(const uint64_t start, const uint64_t end, uint64_t chunks, const uint64_t buffers, const char * const file, uint64_t * const prime_count);
bool pfdg_generate_pattern(const uint64_t last_prime, const char * const file);
