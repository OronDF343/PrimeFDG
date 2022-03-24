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
			char* end2;
			unsigned long long exponent = strtoull(end + 1, &end2, 10);
			if (end2 != end + 1 && exponent < POWERS_LEN)
			{
				scale = powers[exponent];
				end = end2;
			}
			break;
		}

		if (*end != 0)
		{
			return false;
		}

		if (__builtin_umulll_overflow(value, scale, res))
		{
			return false;
		}
		else
		{
			return true;
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

	if (argc < 1)
	{
		args->error = pfdg_error_command;
		return args;
	}

	// Parse command in argv[0]
	if (STRICMP(argv[0], PFDG_STR_CMD(pfdg_command_help)))
	{
		args->command = pfdg_command_help;
	}
	else if (STRICMP(argv[0], PFDG_STR_CMD(pfdg_command_sieve)))
	{
		args->command = pfdg_command_sieve;
	}
	else if (STRICMP(argv[0], PFDG_STR_CMD(pfdg_command_mem)))
	{
		args->command = pfdg_command_mem;
	}
	else if (STRICMP(argv[0], PFDG_STR_CMD(pfdg_command_read)))
	{
		args->command = pfdg_command_read;
	}
	else if (STRICMP(argv[0], PFDG_STR_CMD(pfdg_command_test)))
	{
		args->command = pfdg_command_test;
	}
	else
	{
		// Unrecognized command
		args->error = pfdg_error_command;
		args->message = argv[0];
		return args;
	}

	// Some commands do not accept arguments
	if (args->command == pfdg_command_help || args->command == pfdg_command_test)
	{
		if (argc > 1)
		{
			args->error = pfdg_error_number_of_args;
		}
		return args;
	}

	// Parse arguments
	for (int i = 1; i < argc; ++i)
	{
		char* name_str = argv[i];
		char* value_str = strchr(argv[i], '=');
		if (!value_str)
		{
			args->error = pfdg_error_arg;
			args->message = argv[i];
			return args;
		}
		*value_str = '\0';
		++value_str;

		bool parse_success = false;
		if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_start)))
		{
			parse_success = pfdg_cli_parse_number(value_str, &args->start);
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_end)))
		{
			parse_success = pfdg_cli_parse_number(value_str, &args->end);
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_threads)))
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
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_chunks)))
		{
			parse_success = pfdg_cli_parse_number(value_str, &args->chunks);
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_maxmem)))
		{
			parse_success = pfdg_cli_parse_number(value_str, &args->maxmem);
		}

		// Stop if parse failed
		if (!parse_success)
		{
			args->error = pfdg_error_arg_value;
			args->message = argv[i];
			return args;
		}
	}

	return args;
}

void pfdg_cli_destroy(pfdg_args_t* args)
{
	free(args);
}
