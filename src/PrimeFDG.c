// PrimeFDG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pfdg.h"
#include "timer.h"
#include "utils.h"
#include "pattern.h"
#include "cpuid.h"
#include <math.h>

void print_timestamp_diff(const PFDG_TIMESTAMP t_start, const PFDG_TIMESTAMP t_end)
{
	const PFDG_TIMESTAMP diff = pfdg_timestamp_diff(t_start, t_end);
	printf("Time: %f seconds\n", pfdg_timestamp_microseconds(diff) / 1000000.0);
}

void fill_test_omp(const uint64_t test_size, const int threads)
{
	const uint64_t pattern_length = 1152;
	printf("\n\nPattern fill %llu bytes to %llu MiB, %d threads test:\n", pattern_length * sizeof(BITARRAY_WORD), test_size / 1048576, threads);
	omp_set_num_threads(threads);
	uint64_t i;
	PFDG_TIMESTAMP t_start, t_end;

	pfdg_timestamp_get(&t_start);
	uint64_t* mem1 = ALIGNED_MALLOC(test_size, 32);
	// Fill the rest with the pattern
#pragma omp parallel for
	for (i = 0; i < test_size / pattern_length / 8; ++i)
	{
		const uint64_t cp = (test_size - i * pattern_length) * sizeof(BITARRAY_WORD);
		memcpy_aligned32_avx(mem1 + i * pattern_length, cp, pfdg_pattern, MIN(cp, pattern_length * sizeof(BITARRAY_WORD)));
	}
	printf("AVX-256 ");
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	ALIGNED_FREE(mem1);
			
	pfdg_timestamp_get(&t_start);
	mem1 = ALIGNED_MALLOC(test_size, 16);
	// Fill the rest with the pattern
#pragma omp parallel for
	for (i = 0; i < test_size / pattern_length / 8; ++i)
	{
		const uint64_t cp = (test_size - i * pattern_length) * sizeof(BITARRAY_WORD);
		memcpy_aligned16_sse(mem1 + i * pattern_length, cp, pfdg_pattern, MIN(cp, pattern_length * sizeof(BITARRAY_WORD)));
	}
	printf("AVX/SSE-128 ");
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	ALIGNED_FREE(mem1);
			
	pfdg_timestamp_get(&t_start);
	mem1 = malloc(test_size);
	// Fill the rest with the pattern
#pragma omp parallel for
	for (i = 0; i < test_size / pattern_length / 8; ++i)
	{
		const uint64_t cp = (test_size - i * pattern_length) * sizeof(BITARRAY_WORD);
		memcpy_aligned8(mem1 + i * pattern_length, cp, pfdg_pattern, MIN(cp, pattern_length * sizeof(BITARRAY_WORD)));
	}
	printf("64-bit ");
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	free(mem1);
			
	pfdg_timestamp_get(&t_start);
	mem1 = malloc(test_size);
	// Fill the rest with the pattern
#pragma omp parallel for
	for (i = 0; i < test_size / pattern_length / 8; ++i)
	{
		const uint64_t cp = (test_size - i * pattern_length) * sizeof(BITARRAY_WORD);
		memcpy(mem1 + i * pattern_length, pfdg_pattern, MIN(cp, pattern_length * sizeof(BITARRAY_WORD)));
	}
	printf("Built-in ");
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	free(mem1);
}

void memcpy_test()
{
	// Test memcpy performance
	const uint64_t test_size = 1048576 * 1024;
	const uint64_t check_value = 0xFFEEDDCCBBAA9988;
	pfdg_timestamp_init();
	PFDG_TIMESTAMP t_start, t_end;
	printf("Sequential copy %llu MiB test:\n", test_size / 1048576);

	pfdg_timestamp_get(&t_start);
	uint64_t* mem1 = ALIGNED_MALLOC(test_size, 32);
	uint64_t* mem2 = ALIGNED_MALLOC(test_size, 32);
	mem1[test_size / 8 - 1] = check_value;
	mem2[test_size / 8 - 1] = 0;
	memcpy_aligned32_avx(mem2, test_size, mem1, test_size);
	printf("\nAVX-256: ");
	if (mem2[test_size / 8 - 1] == check_value) printf("Success\n");
	else printf("Failed\n");
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	ALIGNED_FREE(mem1);
	ALIGNED_FREE(mem2);

	pfdg_timestamp_get(&t_start);
	mem1 = ALIGNED_MALLOC(test_size, 16);
	mem2 = ALIGNED_MALLOC(test_size, 16);
	mem1[test_size / 8 - 1] = check_value;
	mem2[test_size / 8 - 1] = 0;
	memcpy_aligned16_sse(mem2, test_size, mem1, test_size);
	printf("\nAVX/SSE-128: ");
	if (mem2[test_size / 8 - 1] == check_value) printf("Success\n");
	else printf("Failed\n");
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	ALIGNED_FREE(mem1);
	ALIGNED_FREE(mem2);

	pfdg_timestamp_get(&t_start);
	mem1 = malloc(test_size);
	mem2 = malloc(test_size);
	mem1[test_size / 8 - 1] = check_value;
	mem2[test_size / 8 - 1] = 0;
	memcpy_aligned8(mem2, test_size, mem1, test_size);
	printf("\n64-bit: ");
	if (mem2[test_size / 8 - 1] == check_value) printf("Success\n");
	else printf("Failed\n");
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	free(mem1);
	free(mem2);

	pfdg_timestamp_get(&t_start);
	mem1 = malloc(test_size);
	mem2 = malloc(test_size);
	mem1[test_size / 8 - 1] = check_value;
	mem2[test_size / 8 - 1] = 0;
	memcpy(mem2, mem1, test_size);
	printf("\nBuilt-in: ");
	if (mem2[test_size / 8 - 1] == check_value) printf("Success\n");
	else printf("Failed\n");
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	free(mem1);
	free(mem2);

	fill_test_omp(test_size * 2, 4);
	fill_test_omp(test_size * 2, 3);
	fill_test_omp(test_size * 2, 2);
	fill_test_omp(test_size * 2, 1);
}

int main(const int argc, char** argv)
{
	cpuid_init();
	if (argc < 4)
	{
		if (argc == 2 && strcmp(argv[1], "test") == 0)
		{
			memcpy_test();
			return 0;
		}
		printf("PrimeFDG\nCopyright (c) 2022 by Oron Feinerman\n\nUsage: primefdg <start> <end> <num_threads>[:<chunks>] [<file>]\ndefault chunks = num_threads * 2^MAX(floor(log10(end)) - 1, 0)\n");
		return 0;
	}

	// Parse args
	const uint64_t start = ATOI64(argv[1]);
	const uint64_t end = ATOI64(argv[2]);

	char* num_str = argv[3];
	char* threads_str = num_str;
	char* chunks_str = NULL;
	char* colon = strchr(num_str, ':');
	if (colon)
	{
		*colon = '\0';
		chunks_str = colon + 1;
	}

	const int num_threads = atoi(threads_str);
	uint64_t l = (uint64_t)log10floor(end);
	if (l > 0) l--;
	const uint64_t chunks = chunks_str == NULL ? (uint64_t)num_threads << l : ATOI64(chunks_str);
	const char* file = argc < 5 ? NULL : argv[4];

	printf("Using %i threads, %llu chunks\n", num_threads, chunks);

	pfdg_timestamp_init();
	omp_set_num_threads(num_threads);

	PFDG_TIMESTAMP t_start, t_end;
	pfdg_timestamp_get(&t_start);

	uint64_t res;
	const bool r = pfdg_sieve_parallel(start, end, chunks, file, &res);
	if (!r)
	{
		printf("Out of memory!");
		return 1;
	}
	pfdg_timestamp_get(&t_end);
	print_timestamp_diff(t_start, t_end);
	printf("Number of primes found: %llu\n", res);
	/*r = pfdg_generate_pattern(11, "D:\\pattern.h");
	if (!r)
	{
		printf("Out of memory!");
		return 1;
	}*/
	return 0;
}
