#include "stdafx.h"
#include "cpuid.h"

bool cpuid_popcnt = false;
bool cpuid_lzcnt = false;

#if _MSC_VER

#include <intrin.h>

void cpuid_init()
{
	int cpui[4];
	__cpuid(cpui, 0x00000001);
	cpuid_popcnt = (cpui[2] >> 23) & 0x1;
	__cpuid(cpui, 0x80000001);
	cpuid_lzcnt = (cpui[2] >> 5) & 0x1;
}

#else

#include <cpuid.h>

void cpuid_init()
{
    int ecx, unused;
	__cpuid(0x00000001, unused, unused, ecx, unused);
	cpuid_popcnt = (ecx >> 23) & 0x1;
	__cpuid(0x80000001, unused, unused, ecx, unused);
	cpuid_lzcnt = (ecx >> 5) & 0x1;
}

#endif