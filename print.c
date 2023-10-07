#include "theshell.h"

/**
 * _print - a fxn dat writes an array of chars in the stdout
 * By Kayode and Esther
 * @string: d pointer 2 d array of chars
 * Return: d numb of bytes written or
 * on error, -1 is returned, and errno is set appropriately.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}


/**
 * _printe - a fxn writes an array of chars in the stderr
 * By Kayode and Esther
 * @string: d pointer 2 d array of chars
 * Return: d numb of bytes written or
 * on error, -1 is returned, and errno is set appropriately.
 */
int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - a fxn dat writes an array of chars in d stderr
 * @data: d pointer 2 d program's data'
 * @errorcode: error code 2 print
 * Return: d numb of bytes written or
 * on error, -1 is returned, and errno is set appropriately.
 */
int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
