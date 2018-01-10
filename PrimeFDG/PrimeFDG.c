// PrimeFDG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pfdg.h"
#include "timer.h"

// /FI "stdafx.h" -Xclang -fopenmp 
int main()
{
	pfdg_timestamp_init();
	const int num_threads = 4;
	omp_set_num_threads(num_threads);

	PFDG_TIMESTAMP start, end;
	pfdg_timestamp_get(&start);
	// 1 billion test
	const uint64_t res = pfdg_sieve_parallel(0, 1000000000, num_threads, "C:\\Users\\Oron\\t.2");
	pfdg_timestamp_get(&end);
	const PFDG_TIMESTAMP diff = pfdg_timestamp_diff(start, end);
	printf("Time: %f seconds\n", pfdg_timestamp_microseconds(diff) / 1000000.0);
	printf("Number of primes found: %llu\n", res);
	//pfdg_generate_pattern(7, "C:\\Users\\Oron\\Documents\\GitHub\\PrimeFDG\\PrimeFDG\\pattern.h");
	system("pause");
    return 0;
}
