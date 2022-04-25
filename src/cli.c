#include "cli.h"
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "pfdg.h"

#if _MSC_VER
#define STRNICMP _strnicmp
#define STRICMP _stricmp
#else
#define STRNICMP strncasecmp
#define STRICMP strcasecmp
#endif

bool pfdg_cli_parse_number(char* value_str, uint64_t* res)
{
	char* end;
	unsigned long long value = strtoull(value_str, &end, 0);
	if (end == value_str || value >= UINT64_MAX)
	{
		return false;
	}
	// If string did not end, continue parsing
	if (*end != 0)
	{
		uint64_t scale = 1;
		switch (*end)
		{
		case 'k':
			scale = 1000ull;
			++end;
			break;
		case 'K':
			scale = 1ull << 10;
			++end;
			break;
		case 'm':
			scale = 1000000ull;
			++end;
			break;
		case 'M':
			scale = 1ull << 20;
			++end;
			break;
		case 'g':
			scale = 1000000000ull;
			++end;
			break;
		case 'G':
			scale = 1ull << 30;
			++end;
			break;
		case 't':
			scale = 1000000000000ull;
			++end;
			break;
		case 'T':
			scale = 1ull << 40;
			++end;
			break;
		case 'e':
		case 'E':
		{
			char* end2;
			unsigned long long exponent = strtoull(end + 1, &end2, 10);
			if (end2 != end + 1 && exponent < POWERS_LEN)
			{
				scale = powers[exponent];
				end = end2;
			}
		}
			break;
		}

		if (*end != 0)
		{
			return false;
		}

		if (__builtin_umulll_overflow(value, scale, &value))
		{
			return false;
		}
	}
	*res = value;
	return true;
}

pfdg_args_t* pfdg_cli_parse(const int argc, char** argv)
{
	pfdg_args_t* args = malloc(sizeof(pfdg_args_t));
	if (!args) return NULL;
	args->command = pfdg_command_none;
	args->start = 1;
	args->end = 0;
	args->threads = 0;
	args->buffer_count = 0;
	args->chunks = 0;
	args->maxmem = 0;
	args->outfile = NULL;
	args->infile = NULL;
	args->error = pfdg_success;
	args->message = NULL;

	if (argc < 2)
	{
		args->error = pfdg_error_command;
		return args;
	}

	// Parse command in argv[1]
	if (STRICMP(argv[1], PFDG_STR_CMD(pfdg_command_help)) == 0)
	{
		args->command = pfdg_command_help;
	}
	else if (STRICMP(argv[1], PFDG_STR_CMD(pfdg_command_sieve)) == 0)
	{
		args->command = pfdg_command_sieve;
	}
	else if (STRICMP(argv[1], PFDG_STR_CMD(pfdg_command_mem)) == 0)
	{
		args->command = pfdg_command_mem;
	}
	else if (STRICMP(argv[1], PFDG_STR_CMD(pfdg_command_read)) == 0)
	{
		args->command = pfdg_command_read;
	}
	else if (STRICMP(argv[1], PFDG_STR_CMD(pfdg_command_test)) == 0)
	{
		args->command = pfdg_command_test;
	}
	else
	{
		// Unrecognized command
		args->error = pfdg_error_command;
		args->message = argv[1];
		return args;
	}

	// Some commands do not accept arguments
	if (args->command == pfdg_command_help || args->command == pfdg_command_test)
	{
		if (argc > 2)
		{
			// Invalid number of arguments
			args->error = pfdg_error_number_of_args;
		}
		return args;
	}

	// Parse arguments
	for (int i = 2; i < argc; ++i)
	{
		char* name_str = argv[i];
		char* value_str = strchr(argv[i], '=');
		if (!value_str)
		{
			// Invalid argument
			args->error = pfdg_error_arg;
			args->message = argv[i];
			return args;
		}
		*value_str = '\0';
		++value_str;

		bool parse_success = false;
		if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_start)) == 0)
		{
			parse_success = pfdg_cli_parse_number(value_str, &args->start);
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_end)) == 0)
		{
			parse_success = pfdg_cli_parse_number(value_str, &args->end);
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_threads)) == 0)
		{
			char* end;
			unsigned long value = strtoul(value_str, &end, 0);
			if (end == value_str || value >= INT_MAX)
			{
				parse_success = false;
			}
			args->threads = (int)value;
			parse_success = true;
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_chunks)) == 0)
		{
			parse_success = pfdg_cli_parse_number(value_str, &args->chunks);
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_maxmem)) == 0)
		{
			parse_success = pfdg_cli_parse_number(value_str, &args->maxmem);
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_outfile)) == 0)
		{
			args->outfile = value_str;
			parse_success = true;
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_infile)) == 0)
		{
			args->infile = value_str;
			parse_success = true;
		}
		else
		{
			// Invalid argument name
			args->error = pfdg_error_arg;
			args->message = name_str;
			return args;
		}

		// Stop if parse failed
		if (!parse_success)
		{
			// Invalid argument value
			args->error = pfdg_error_arg_value;
			args->message = value_str;
			return args;
		}
	}

	// Validate arguments
	// End must be greater than start
	if (args->end <= args->start)
	{
		args->error = pfdg_error_arg_value;
		args->message = PFDG_STR_ARG(pfdg_arg_end);
		return args;
	}

	if (args->threads > 0)
		omp_set_num_threads(args->threads);
	else
		args->threads = omp_get_max_threads();

	bool chunk_count_user_specified = true;
	if (args->chunks == 0)
	{
		chunk_count_user_specified = false;
		uint64_t l = (uint64_t)log10floor(args->end);
		if (l > 0) l--;
		args->chunks = (uint64_t)args->threads << l;
	}
	
	args->buffer_count = args->threads;
	if (args->outfile)
	{
		args->buffer_count += 1;
	}
	
	if (args->maxmem > 0)
	{
		// Apply defaults for maxmem
		// Step 1. Determine required memory for supporting data
		// static pattern + prefix + known primes
		uint64_t base_mem = pfdg_mem_get_base(args->start, args->end);
		// Step 2. Determine maximum possible usage for specified number of chunks - limit requested memory to that
		uint64_t chunk_size = pfdg_mem_get_chunk_size(args->start, args->end, args->chunks);
		uint64_t max_chunk_mem = base_mem + chunk_size * args->chunks;
		if (args->maxmem > max_chunk_mem)
		{
			args->maxmem = max_chunk_mem;
		}
		// Step 3. Determine minimum possible usage for specified number of chunks
		uint64_t min_chunk_mem = base_mem;
		min_chunk_mem += chunk_size * args->buffer_count;
		// Step 4. Verify and calculate final parameters
		// If requested memory usage is not possible, error
		if (args->maxmem < base_mem) 
		{
			args->error = pfdg_error_mem_base;
			//args->message = value_str;
			return args;
		}
		// If minimum memory usage is higher than requested and a specific chunk count was specified, error
		if (args->maxmem < min_chunk_mem && chunk_count_user_specified)
		{
			args->error = pfdg_error_mem_min;
			//args->message = value_str;
			return args;
		}
		// If minimum memory usage is higher than requested, try to reduce memory usage
		if (args->maxmem < min_chunk_mem)
		{
            // Calculate max chunk size
            chunk_size = (args->maxmem - base_mem) / args->buffer_count;
            // Make sure that the chunks are not too tiny
            if (chunk_size < 8)
			{
				args->error = pfdg_error_mem_chunk_size;
				//args->message = value_str;
				return args;
			}
            // Calculate chunk count
			args->chunks = pfdg_mem_get_chunk_count_by_size(args->start, args->end, chunk_size);
		}
		// If requested memory usage is higher than minimum, and if writing to file, allow allocating more buffer space
		else if (args->maxmem > min_chunk_mem && args->outfile)
		{
            uint64_t extra_mem = args->maxmem - min_chunk_mem;
			// TODO: Maybe limit the amount of extra buffering
            args->buffer_count += extra_mem / chunk_size;
		}
	}

	return args;
}

void pfdg_cli_destroy(pfdg_args_t* args)
{
	free(args);
}
