#include "stdafx.h"
#include "pfdg.h"
#include <math.h>
#include "pattern.h"

bitarray* pfdg_init_bitarray(const uint64_t capacity, const uint64_t offset, const bool use_pattern)
{
	bitarray* arr = bitarray_create(capacity, true);

	// Length of data in words
	const uint64_t len = arr->actual_capacity / BITS(BITARRAY_WORD);

	if (use_pattern)
	{
		// i stores the number of words copied so far
		uint64_t i = 0;
		// Copy prefix if necessary
		if (offset < 2)
		{
			arr->data[0] = pfdg_pattern_prefix;
			++i;
		}
		// Start in the middle of the pattern if not aligned
		const uint64_t align = (offset / BITS(BITARRAY_WORD) / 2 - 1 + i) % PFDG_PATTERN_LENGTH;
		if (align > 0)
		{
			const uint64_t cp = (PFDG_PATTERN_LENGTH - align) * sizeof(BITARRAY_WORD);
			memcpy_s(arr->data, cp, pfdg_pattern + align, cp);
			i += PFDG_PATTERN_LENGTH - align;
		}
		// Fill the rest with the pattern
		for (; i < len; i += PFDG_PATTERN_LENGTH)
		{
			const uint64_t cp = (len - i) * sizeof(BITARRAY_WORD);
			memcpy_s(arr->data + i, cp, pfdg_pattern, __min(cp, PFDG_PATTERN_LENGTH * sizeof(BITARRAY_WORD)));
		}
	}
	else
	{
		// Zero out the array
		for (uint64_t i = 0; i < len; ++i)
			arr->data[i] = 0;
	}

	// 1 is not prime
	if (offset < 2) bitarray_set(arr, 1);

	// Fill the extra space with ones
	const uint64_t extra_bits = arr->actual_capacity - DIVUP(capacity, 2);
	arr->data[len - 1] |= (((BITARRAY_WORD)1 << extra_bits) - 1) << (BITS(BITARRAY_WORD) - extra_bits);
	return arr;
}

void pfdg_mark(bitarray* const arr, const uint64_t prime, const uint64_t offset)
{
	uint64_t i = DIVUP(offset, prime);
	// Start from the square of the prime
	if (i < prime) i = prime;
	// Odd multiples only
	else if (i % 2 == 0) ++i;
	// 
	for (; i * prime - offset < arr->capacity; i += 2)
		bitarray_set(arr, i * prime - offset);
}

void pfdg_sieve_seed(bitarray* const arr, const bool skip)
{
	for (uint64_t i = skip ? PFDG_PATTERN_SKIP : 3; i < arr->capacity; i += 2)
		if (!bitarray_get(arr, i))
			pfdg_mark(arr, i, 0);
}

void pfdg_sieve(bitarray* const arr, bitarray* const known, const uint64_t offset, const bool skip)
{
	for (uint64_t i = skip ? PFDG_PATTERN_SKIP : 3; i < known->capacity; i += 2)
		if (!bitarray_get(known, i))
			pfdg_mark(arr, i, offset);
}

uint64_t pfdg_sieve_parallel(const uint64_t start, const uint64_t end, const uint64_t chunks, const char * const file)
{
	// Step 1
	bitarray* const known = pfdg_init_bitarray((uint64_t)sqrt((double)end) + 1, 0, true);
	pfdg_sieve_seed(known, true);
	/*FILE* k;
	fopen_s(&k, "C:\\Users\\Oron\\k.2", "ab");
	bitarray_serialize_to_file(known, k);*/

	// Step 2 parameters
	const uint64_t len = end - start;
	uint64_t prime_count = 0;
	uint64_t chunk_size = DIVUP(len, chunks);
	chunk_size = DIVUP(chunk_size, BITS(BITARRAY_WORD) * 2) * BITS(BITARRAY_WORD) * 2;

	// Prepare file: Write the header
	FILE * f;
	const int err = fopen_s(&f, file, "w+b");
	if (err == 0)
	{
		pfdg_file_header h = PFDG_HEADER_INITIALIZER;
		h.data_length = DIVUP(len, BITS(BITARRAY_WORD) * 2) * sizeof(BITARRAY_WORD);
		h.number_first = start;
		h.number_last = end;
		fwrite(&h, sizeof(pfdg_file_header), 1, f);
	}

	// Step 2
	// Run loop in parallel, but must be ORDERED when saving files!
	// IMPORTANT: DO NOT JOIN DECLARATION AND ASSIGNMENT for OpenMP iterators!!! MSVC hates this!!!
	// ReSharper disable CppJoinDeclarationAndAssignment
	int64_t i;
#pragma omp parallel for ordered schedule(static,1)
	for (i = 0; i < (int64_t)chunks; ++i)
	{
		// ReSharper restore CppJoinDeclarationAndAssignment
		const uint64_t offset = start + chunk_size * i;
		// Create bitarray
		bitarray* const arr = pfdg_init_bitarray(i == chunks - 1 ? len - chunk_size * i : chunk_size, offset, true);
		// Sieve it!
		pfdg_sieve(arr, known, offset, true);
		// Count the primes
		const uint64_t count = bitarray_count(arr, false);
		// Increment counter atomically to prevent race conditions
#pragma omp atomic
		prime_count += count;
		// Write chunks to file in order!
#pragma omp ordered
		{
			bitarray_serialize_to_file(arr, f);
		}
		// Free up the memory
		bitarray_delete(arr);
	}

	// Write number of primes found
	fseek(f, 40, SEEK_SET);
	fwrite(&prime_count, sizeof(uint64_t), 1, f);
	// Close file
	fclose(f);
	return prime_count;
}

void pfdg_generate_pattern(const uint64_t last_prime, const char * const file)
{
	bitarray* known = pfdg_init_bitarray(last_prime + 1, 0, true);
	pfdg_sieve_seed(known, false);
	uint64_t len = 1;
	for (uint64_t i = 3; i <= last_prime; i+=2)
		if (!bitarray_get(known, i))
			len *= i;

	bitarray* arr = pfdg_init_bitarray((len + 1) * 2 * BITS(BITARRAY_WORD), 0, false);
	pfdg_sieve(arr, known, 0, false);
	bitarray_delete(known);

	FILE * f;
	fopen_s(&f, file, "w+");
	uint64_t next_prime = last_prime + 2;
	for (; next_prime < arr->capacity; next_prime += 2)
		if (!bitarray_get(arr, next_prime))
			break;
	fprintf_s(f, "#pragma once\n\n#include \"stdafx.h\"\n\n// The prime from which to start the sieveing loop\n#define PFDG_PATTERN_SKIP %llu\n// The length of the precomputed pattern\n#define PFDG_PATTERN_LENGTH %llu\n", next_prime, len);

	fprintf_s(f, "// The prefix of the precomputed pattern\nconst BITARRAY_WORD pfdg_pattern_prefix = 0x%.16llX;\n// The precomputed pattern data\nconst BITARRAY_WORD pfdg_pattern[PFDG_PATTERN_LENGTH] =\n{\n", arr->data[0]);
	for (uint64_t i = 1; i < arr->actual_capacity / BITS(BITARRAY_WORD); ++i)
		fprintf_s(f, "\t0x%.16llX,\n", arr->data[i]);
	fprintf_s(f, "};\n");
	fclose(f);
	bitarray_delete(arr);
}
