#pragma once
#include "stdafx.h"

#define DIVUP(x, y) (((x) % (y) > 0 ? (x) / (y) + 1 : (x) / (y)))

//uint32_t bitcount32(const uint32_t n)
//{
//	uint32_t m = n - (n >> 1 & 0x55555555);
//	m = (m & 0x33333333) + (m >> 2 & 0x33333333);
//	return (m + (m >> 4) & 0xF0F0F0F) * 0x1010101 >> 24;
//}

#define BITCOUNT_IMP(T, NAME) inline T NAME(const T n) \
{ \
	T v = n - ((n >> 1) & (T)~(T)0 / 3); \
	v = (v & (T)~(T)0 / 15 * 3) + ((v >> 2) & (T)~(T)0 / 15 * 3); \
	v = (v + (v >> 4)) & (T)~(T)0 / 255 * 15; \
	return (T)(v * ((T)~(T)0 / 255)) >> (sizeof(T) - 1) * CHAR_BIT; \
}

//BITCOUNT_IMP(uint32_t, bitcount32)
//BITCOUNT_IMP(uint64_t, bitcount64)

BITCOUNT_IMP(BITARRAY_WORD, bitcount)

#define OR_MASK(x) ((BITARRAY_WORD)1 << (x))
#define AND_MASK(x) (~OR_MASK(x))
