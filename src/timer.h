#pragma once
#include "stdafx.h"

#ifdef _WIN32

#include <Windows.h>

#define PFDG_TIMESTAMP LARGE_INTEGER

PFDG_TIMESTAMP freq;

inline void pfdg_timestamp_init()
{
	QueryPerformanceFrequency(&freq);
}

inline void pfdg_timestamp_get(PFDG_TIMESTAMP* ts)
{
	QueryPerformanceCounter(ts);
}

inline PFDG_TIMESTAMP pfdg_timestamp_diff(const PFDG_TIMESTAMP start, const PFDG_TIMESTAMP end)
{
	PFDG_TIMESTAMP res;
	res.QuadPart = end.QuadPart - start.QuadPart;
	return res;
}

inline uint64_t pfdg_timestamp_microseconds(const PFDG_TIMESTAMP ts)
{
	return (ts.QuadPart * 1000000Ui64) / freq.QuadPart;
}

#else
#include <time.h>

#define PFDG_TIMESTAMP clock_t

inline void pfdg_timestamp_init() { }

inline void pfdg_timestamp_get(PFDG_TIMESTAMP* ts)
{
	*ts = clock();
}

inline PFDG_TIMESTAMP pfdg_timestamp_diff(const PFDG_TIMESTAMP start, const PFDG_TIMESTAMP end)
{
	return end - start;
}

inline uint64_t pfdg_timestamp_microseconds(const PFDG_TIMESTAMP ts)
{
	return (ts * 1000000ULL) / CLOCKS_PER_SEC;
}

#endif
