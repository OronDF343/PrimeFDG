#pragma once

typedef enum { false = 0, true = 1 } bool;

#define BITS(t) (sizeof(t)*8)

#ifdef _M_X64
#define BITARRAY_WORD uint64_t
#else
#define BITARRAY_WORD uint32_t
#endif

#define NATIVE_ORDER LSB_LITTLE
