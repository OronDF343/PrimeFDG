// PrimeFDG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pfdg.h"
#include "timer.h"

int main(const int argc, const char** argv)
{
	if (argc < 5)
	{
		printf("PrimeFDG\nCopyright (c) 2018 by Oron Feinerman\n\nUsage: primefdg <start> <end> <num_threads> [<chunks>] <file>\n");
		return 0;
	}

	// Parse args
	const uint64_t start = _atoi64(argv[1]);
	const uint64_t end = _atoi64(argv[2]);
	const int num_threads = atoi(argv[3]);
	const uint64_t chunks = argc == 5 ? num_threads : _atoi64(argv[4]);
	const char* file = argv[argc == 5 ? 4 : 5];

	pfdg_timestamp_init();
	omp_set_num_threads(num_threads);

	PFDG_TIMESTAMP t_start, t_end;
	pfdg_timestamp_get(&t_start);

	uint64_t res;
	bool r = pfdg_sieve_parallel(start, end, chunks, file, &res);
	if (!r)
	{
		printf("Out of memory!");
		return 1;
	}
	pfdg_timestamp_get(&t_end);
	const PFDG_TIMESTAMP diff = pfdg_timestamp_diff(t_start, t_end);
	printf("Time: %f seconds\n", pfdg_timestamp_microseconds(diff) / 1000000.0);
	printf("Number of primes found: %llu\n", res);
	/*r = pfdg_generate_pattern(11, "D:\\pattern.h");
	if (!r)
	{
		printf("Out of memory!");
		return 1;
	}*/
	return 0;
}
