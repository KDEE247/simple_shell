#include "theshell.h"
/**
 * environment_get_key - a fxn dat get env variable
 * By Kayode and Esther
 * @key: The env variable
 * @data: The structure of program data
 * Return: The pointer 2 variable or NULL
 */
char *environment_get_key(char *key, data_of_program *data)
{
	int m, length_of_key = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);
	length_of_key = str_length(key);
	for (m = 0; data->env[m]; m++)
	{
		if (str_compare(key, data->env[m], length_of_key) && data->
				env[m][length_of_key] == '=')
		{
			return (data->env[m] + length_of_key + 1);
		}
	}
	return (NULL);
}
/**
 * environment_set_key - a fxn dat overwrite env variable
 * @key: The env variable
 * By Kayode and Esther
 * @value: The new value
 * @data: The structure 4 program data
 * Return: 1 if parameters re NULL, 2 on err and 0 on success
 */
int environment_set_key(char *key, char *value, data_of_program *data)
{
	int m, length_of_key = 0, new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);
	length_of_key = str_length(key);

	for (m = 0; data->env[m]; m++)
	{
		if (str_compare(key, data->env[m], length_of_key) && data->
				env[m][length_of_key] == '=')
		{
			new_key = 0;
			free(data->env[m]);
			break;
		}
	}
	data->env[m] = str_concat(str_duplicate(key), "=");
	data->env[m] = str_concat(data->env[m], value);

	if (new_key)
	{
		data->env[m + 1] = NULL;
	}
	return (0);
}
/**
 * environment_remove_key - a fxn dat remove key
 * @key: The key
 * @data: The structure 4 program data
 * By Kayode and Esther
 * Return: 1 if removed, 0 if nt exist
 */
int environment_remove_key(char *key, data_of_program *data)
{
	int m, length_of_key = 0;

	if (key == NULL || data->env == NULL)
		return  (0);
	length_of_key = str_length(key);

	for (m = 0; data->env[m]; m++)
	{
		if (str_compare(key, data->env[m], length_of_key) && data
				->env[m][length_of_key] == '=')
		{
			free(data->env[m]);
			m++;
			for (; data->env[m]; m++)
			{
				data->env[m - 1] = data->env[m];
			}
			data->env[m - 1] = NULL;
			return (1);
		}
	}
	return (0);
}
/**
 * print_environment - a fxn dat prints current env
 * By Kayode and Esther
 * @data: The structure 4 program data
 */
void print_environment(data_of_program *data)
{
	int q;

	for (q = 0; data->env[q]; q++)
	{
		_print(data->env[q]);
		_print("\n");
	}
}
