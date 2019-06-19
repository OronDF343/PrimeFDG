#include "stdafx.h"
#include "cpuid.h"
#include "bitarray.h"
#include <intrin.h>

bitarray * bitarray_create(const uint64_t capacity, const bool oddonly)
{
	// Number of bits required
	const uint64_t br = DIVUP(capacity, (oddonly + 1));
	// Number of words required
	const uint64_t wr = DIVUP(br, BITS(BITARRAY_WORD));
	// Allocate memory
	bitarray * b = malloc(sizeof(bitarray));
	if (!b) return 0;
	// Aligned just in case we ever use SIMD
	b->data = _aligned_malloc(wr * sizeof(BITARRAY_WORD), 32);
	if (!b->data) return 0;
	// Set fields
	b->oddonly = oddonly;
	b->capacity = capacity;
	b->actual_capacity = BITS(BITARRAY_WORD) * wr;
	return b;
}

void __forceinline bitarray_set(bitarray * const b, const uint64_t i)
{
	const uint64_t ia = b->oddonly ? i / 2 : i;
	b->data[ia / BITS(BITARRAY_WORD)] |= OR_MASK(ia & (BITS(BITARRAY_WORD) - 1));
}

void bitarray_unset(bitarray * const b, const uint64_t i)
{
	const uint64_t ia = b->oddonly ? i / 2 : i;
	b->data[ia / BITS(BITARRAY_WORD)] &= AND_MASK(ia & (BITS(BITARRAY_WORD) - 1));
}

void bitarray_setval(bitarray * const b, const uint64_t i, const bool val)
{
	val ? bitarray_set(b, i) : bitarray_unset(b, i);
}

bool bitarray_get(bitarray * const b, const uint64_t i)
{
	const uint64_t ia = b->oddonly ? i / 2 : i;
	return (b->data[ia / BITS(BITARRAY_WORD)] >> ia & (BITS(BITARRAY_WORD) - 1)) & 1;
}

uint64_t bitarray_count(bitarray * const arr, const bool value)
{
	uint64_t count = 0;
	if (cpuid_popcnt)
	{
		for (uint64_t c = 0; c < arr->actual_capacity / BITS(BITARRAY_WORD); ++c)
		{
			if (value)
				count += POPCNT(arr->data[c]);
			else
				count += POPCNT(~arr->data[c]);
		}
	}
	else
	{
		for (uint64_t c = 0; c < arr->actual_capacity / BITS(BITARRAY_WORD); ++c)
		{
			if (value)
				count += bitcount(arr->data[c]);
			else
				count += bitcount(~arr->data[c]);
		}
	}
	return count;
}

void bitarray_delete(bitarray * arr)
{
	_aligned_free(arr->data);
	free(arr);
}

BITARRAY_WORD bitarray_serialize_to_file(const bitarray * const arr, FILE * const file)
{
	const uint64_t r = fwrite(arr->data, sizeof(BITARRAY_WORD), arr->actual_capacity / BITS(BITARRAY_WORD), file) * sizeof(BITARRAY_WORD);
	return r;
}
