#include "theshell.h"

/**
 * free_recurrent_data - a fxn dat free d fields needed 4 each loop of a program
 * By Kayode and Esther
 * @data: d structure of d program's data
 * Return: Nil
 */
void free_recurrent_data(data_of_program *data)
{
	if (data)
	{
		if (data->tokens)
		{
			free_array_of_pointers(data->tokens);
			data->tokens = NULL;
		}
		if (data->input_line)
		{
			free(data->input_line);
			data->input_line = NULL;
		}
		if (data->command_name)
		{
			free(data->command_name);
			data->command_name = NULL;
		}
	}
}

/**
  *free_all_data - a fxn dat free all fields of a program
  *@data: d structure of d program's data
  * By Kayode and Esther
  *Return: Nil
  */
void free_all_data(data_of_program *data)
{
	if (data)
	{
		if (data->file_descriptor != 0)
		{
			if (close(data->file_descriptor) == -1)
			{
				perror(data->program_name);
			}
		}
		free_recurrent_data(data);
		if (data->env)
		{
			free_array_of_pointers(data->env);
		}
		if (data->alias_list)
		{
			free_array_of_pointers(data->alias_list);
		}
	}
}

/**
  *free_array_of_pointers - a fxn dat free an array of pointers
  *@array: d array of pointers
  *By Kayode and Esther
  *Return: nil
  */
void free_array_of_pointers(char **array)
{
	int t;

	if (array == NULL)
	{
		return;
	}

	for (t = 0; array[t] != NULL; t++)
	{
		free(array[t]);
		array[t] = NULL;
	}

	free(array);
	array = NULL;
}
