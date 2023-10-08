#include "theshell.h"
/**
 * _getlines - a fxn dat allow 2 read a line frm cmd prompt
 * By Kayode and Esther
 * @data: The structure containing data of program
 * Return: The numb of bytes
 */
int _getlines(data_of_program *data)
{
	char buffer[BUFFER_SIZE] = {'\0'};
	static char *array_of_commands[10] = {NULL};
	static char array_of_operators[10] = {'\0'};
	ssize_t read_bytes, m = 0;

	/* check if cmd is in array nd logical operators */
	if (!array_of_commands[0] || (array_of_operators[0] == '&' && errno != 0) || (
				array_of_operators[0] == '|' && errno == 0))
	{
		/* free allocated mem if it exist */
		for (m = 0; array_of_commands[m]; m++)
		{
			free(array_of_commands[m]);
			array_of_commands[m] = NULL;
		}
		/* write 2 buffer frm file descriptor */
		read_bytes = read(data->file_descriptor, &buffer, BUFFER_SIZE - 1);
		if (read_bytes == 0)
		{
			return (-1);
		}
		m = 0;
		do {
			array_of_commands[m] = str_duplicate(_strtok
					(m ? NULL : buffer, "\n;"));
			m = check_ops_logic(array_of_commands, m, array_of_operators);
		} while (array_of_commands[m++]);
	}

	data->input_line = array_of_commands[0];

	for (m = 0; array_of_commands[m]; m++)
	{
		array_of_commands[m] = array_of_commands[m + 1];
		array_of_operators[m] = array_of_operators[m + 1];
	}

	return (str_length(data->input_line));
}

/**
 * check_ops_logic - a fxn dat check 4 logical operators nd split
 * @array_of_commands: The array of various cmds
 * @m: The index in array of cmds being checked
 * @array_of_operators: The array of previous cmd's logical operators
 * Return: The index of last cmd in array of cmds
 */
int check_ops_logic(char *array_of_commands[], int m,
		char array_of_operators[])
{
	char *temporary = NULL;
	int q;

	/* check 4 & in cmd */
	for (q = 0; array_of_commands[m] != NULL && array_of_commands[m][q]; q++)
	{
		if (array_of_commands[m][q] == '&' && array_of_commands[m][q + 1] == '&')
		{
			/** splitting line at && */
			temporary = array_of_commands[m];
			array_of_commands[m][q] = '\0';
			array_of_commands[m] = str_duplicate(array_of_commands[m]);
			array_of_commands[m + 1] = str_duplicate(temporary + q + 2);
			m++;
			array_of_operators[m] = '&';
			free(temporary);
		}
		if (array_of_commands[m][q] == '|' && array_of_commands[m][q + 1] == '|')
		{
			/* splitting line at || */
			temporary = array_of_commands[m];
			array_of_commands[m][q] = '\0';
			array_of_commands[m] = str_duplicate(array_of_commands[q]);
			array_of_commands[m + 1] = str_duplicate(temporary + q + 2);
			m++;
			array_of_operators[m] = '|';
			free(temporary);
			q = 0;
		}
	}
	return (m);
}
