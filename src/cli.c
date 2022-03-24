#include "cli.h"
#include <stdlib.h>
#include <string.h>

#if _MSC_VER
#define STRNICMP _strnicmp
#define STRICMP _stricmp
#else
#define STRNICMP strncasecmp
#define STRICMP strcasecmp
#endif

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
		if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_start)))
		{
			char* end;
			unsigned long long value = strtoull(value_str, &end, 0);
			if (end == value_str || value >= UINT64_MAX)
			{
				args->error = pfdg_error_arg_value;
				args->message = argv[i];
				return args;
			}
			args->start = (uint64_t)value;
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_end)))
		{
			char* end;
			unsigned long long value = strtoull(value_str, &end, 0);
			if (end == value_str || value >= UINT64_MAX)
			{
				args->error = pfdg_error_arg_value;
				args->message = argv[i];
				return args;
			}
			args->end = (uint64_t)value;
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_threads)))
		{
			char* end;
			unsigned long value = strtoul(value_str, &end, 0);
			if (end == value_str || value >= INT_MAX)
			{
				args->error = pfdg_error_arg_value;
				args->message = argv[i];
				return args;
			}
			args->threads = (int)value;
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_chunks)))
		{
			char* end;
			unsigned long long value = strtoull(value_str, &end, 0);
			if (end == value_str || value >= UINT64_MAX || value < 1)
			{
				args->error = pfdg_error_arg_value;
				args->message = argv[i];
				return args;
			}
			args->chunks = (uint64_t)value;
		}
		else if (STRICMP(name_str, PFDG_STR_ARG(pfdg_arg_maxmem)))
		{
			char* end;
			unsigned long long value = strtoull(value_str, &end, 0);
			if (end == value_str || value == UINT64_MAX || value < 1)
			{
				args->error = pfdg_error_arg_value;
				args->message = argv[i];
				return args;
			}
			args->maxmem = (uint64_t)value;
		}
	}

	return args;
}

void pfdg_cli_destroy(pfdg_args_t* args)
{
	free(args);
}
