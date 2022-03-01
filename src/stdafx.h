// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
//#include <tchar.h>

#include <stdint.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <limits.h>
#include <string.h>

typedef enum { false = 0, true = 1 } bool;

#define BITS(t) (sizeof(t)*8)

#if _M_X64 || __LP64__

#define BITARRAY_WORD uint64_t

#ifdef __GNUC__
#define POPCNT _popcnt64
#else
#define POPCNT __popcnt64
#endif

#else

#define BITARRAY_WORD uint32_t

#ifdef __GNUC__
#define POPCNT _popcnt
#else
#define POPCNT __popcnt
#endif

#endif

#ifdef __GNUC__

#define FINLINE __attribute__((always_inline))
#define ALIGN32 __attribute__((aligned(32)))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ALIGNED_MALLOC(size, alignment) (aligned_alloc((alignment), (size)))
#define ALIGNED_FREE free
#define ATOI64 atoi
#define inline

#else

#define FINLINE __forceinline
#define ALIGN32 __declspec(align(32))
#define MIN __min
#define MAX __max
#define ALIGNED_MALLOC _aligned_malloc
#define ALIGNED_FREE _aligned_free
#define ATOI64 _atoi64
#define _CRT_SECURE_NO_WARNINGS 1

#endif

#define NATIVE_ORDER LSB_LITTLE
