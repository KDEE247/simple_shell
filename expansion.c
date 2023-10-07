#include "theshell.h"
/**
 * variables_expansion - a fxn dat expand variables
 * By Kayode and Esther
 * @data: The structure 4 program data
 */
void variables_expansion(data_of_program *data)
{
	int m, q;
	char lines[BUFFER_SIZE] = {0}, expansions[BUFFER_SIZE] = {'\0'}
		, *temporary;

	if (data->input_line == NULL)
		return;

	add_to_buffer(lines, data->input_line);
	for (m = 0; lines[m]; m++)
		if (lines[m] == '#')
			lines[m--] = '\0';
		else if (lines[m] == '$' && lines[m + 1] == '?')
		{
			lines[m] = '\0';
			long_to_string(errno, expansions, 10);
			add_to_buffer(lines, expansions);
			add_to_buffer(lines, data->input_line + m + 2);
		}
		else if (lines[m] == '$' && (lines[m + 1] == ' ' || lines[m + 1] == '\0'))
			continue;
		else if (lines[m] == '$')
		{
			for (q = 1; lines[m + q] && lines[m + q] != ' '; q++)
				expansions[q - 1] = lines[m + q];
			temporary = environment_get_key(expansions, data);
			lines[m] = '\0', expansions[0] = '\0';
			add_to_buffer(expansions, lines + m + q);
			temporary ? add_to_buffer(lines, temporary) : 1;
			add_to_buffer(lines, expansions);
		}
	if (!str_compare(data->input_line, lines, 0))
	{
		free(data->input_line);
		data->input_line = str_duplicate(lines);
	}
}
/**
 * alias_expansion - a fxn dat expand alias
 * @data: The structure 4 program data
 * By Kayode and Esther
 */
void alias_expansion(data_of_program *data)
{
	int m, q, expanded = 0;
	char lines[BUFFER_SIZE] = {0}, expansions[BUFFER_SIZE] = {'\0'}
		, *temporary;

	if (data->input_line == NULL)
		return;
	add_to_buffer(lines, data->input_line);

	for (m = 0; lines[m]; m++)
	{
		for (q = 0; lines[m + q] && lines[m + q] != ' '; q++)
			expansions[q] = lines[m + q];
		expansions[q] = '\0';

		temporary = fetch_alias(data, expansions);
		if (temporary)
		{
			expansions[0] = '\0';
			add_to_buffer(expansions, lines + m + q);
			lines[m] = '\0';
			add_to_buffer(lines, temporary);
			lines[str_length(lines)] = '\0';
			add_to_buffer(lines, expansions);
			expanded = 1;
		}
		break;
	}
	if (expanded)
	{
		free(data->input_line);
		data->input_line = str_duplicate(lines);
	}
}
/**
 * add_to_buffer - a fxn dat append 2 buffer
 * @buffer: The buffer
 * By Kayode and Esther
 * @strings: d string 2 add
 * Return: d len
 */
int add_to_buffer(char *buffer, char *strings)
{
	int len, m;

	len = str_length(buffer);
	for (m = 0; strings[m]; m++)
		buffer[len + m] = strings[m];
	buffer[len + m] = '\0';
	return (len + m);
}
