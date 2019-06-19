#include "stdafx.h"
#include "cpuid.h"
#include <intrin.h>

bool cpuid_popcnt = false;

void cpuid_init()
{
	int cpui[4];
	__cpuid(cpui, 0x00000001);
	cpuid_popcnt = (cpui[2] >> 23) & 0x1;
}
