#include "cli.h"
#include <stdlib.h>
#include <string.h>
#include "utils.h"

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

	if (args->chunks == 0)
	{
		uint64_t l = (uint64_t)log10floor(args->end);
		if (l > 0) l--;
		args->chunks = (uint64_t)args->threads << l;
	}
	
	// TODO: Apply defaults for maxmem

	return args;
}

void pfdg_cli_destroy(pfdg_args_t* args)
{
	free(args);
}
