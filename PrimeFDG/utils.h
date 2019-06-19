#pragma once
#include "stdafx.h"
#include <xmmintrin.h>
#include <immintrin.h>

static void memcpy_aligned64_avx2(void*       const destination,
				 rsize_t     const destination_size,
				 void const* const source,
				 rsize_t     const source_size)
{
	uint64_t* src = (uint64_t*) source;
	uint64_t* dest = (uint64_t*) destination;
	rsize_t i;
	for (i = 0; i < __min(source_size, destination_size) / 64; ++i)
	{
		__m512 tmp = _mm512_loadu_ps(src);
		_mm512_storeu_ps(dest, tmp);
		dest += 8;
		src += 8;
	}
	_mm256_zeroupper();
}

static void memcpy_aligned32_avx(void*       const destination,
				 rsize_t     const destination_size,
				 void const* const source,
				 rsize_t     const source_size)
{
	uint64_t* src = (uint64_t*) source;
	uint64_t* dest = (uint64_t*) destination;
	rsize_t i;
	for (i = 0; i < __min(source_size, destination_size) / 32; ++i)
	{
		__m256 tmp = _mm256_loadu_ps((float*)src);
		_mm256_storeu_ps((float*)dest, tmp);
		dest += 4;
		src += 4;
	}
	_mm256_zeroupper();
}

static void memcpy_aligned16_sse(void*       const destination,
				 rsize_t     const destination_size,
				 void const* const source,
				 rsize_t     const source_size)
{
	uint64_t* src = (uint64_t*) source;
	uint64_t* dest = (uint64_t*) destination;
	rsize_t i;
	for (i = 0; i < __min(source_size, destination_size) / 16; ++i)
	{
		__m128 tmp = _mm_loadu_ps((float*)src);
		_mm_storeu_ps((float*)dest, tmp);
		dest += 2;
		src += 2;
	}
}

static void memcpy_aligned8(void*       const destination,
				 rsize_t     const destination_size,
				 void const* const source,
				 rsize_t     const source_size)
{
	uint64_t* src = (uint64_t*) source;
	uint64_t* dest = (uint64_t*) destination;
	rsize_t i;
	for (i = 0; i < __min(source_size, destination_size) / 8; ++i)
	{
		dest[i] = src[i];
	}
}