#include "theshell.h"
/**
 * output_alias - Fns To Add, Remove, Or Show Aliases.
 * By Kayode, & Esther...
 * @data: Structure For Prog Data.
 * @alias: Alias To Output...
 * Return: 0 upon Success; Or if declared.
 */
int output_alias(data_of_program *data, char *alias)
{
	int m, q, length_of_alias;
	char buff[250] = {'\0'};

	if (data->alias_list)
	{
		length_of_alias = str_length(alias);
		for (m = 0; data->alias_list[m]; m++)
		{
			if (!alias || (str_compare(data->alias_list[m]
				, alias, length_of_alias) && data->alias_list
						[m][length_of_alias] == '='))
			{
				for (q = 0; data->alias_list[m][q]; q++)
				{
					buff[q] = data->alias_list[m][q];
					if (data->alias_list[m][q] == '=')
						break;
				}
				buff[q + 1] = '\0';
				add_to_buffer(buff, "'");
				add_to_buffer(buff, data->alias_list[m] + q + 1);
				add_to_buffer(buff, "'\n");
				_print(buff);
			}
		}
	}
	return (0);
}
/**
 * fetch_alias - Fns To Get Alias.
 * @data: Structure For Prog Data.
 * By Kayode, & Esther...
 * @name: Name Of Alias.
 * Return: 0 upon Success; Or If Declared.
 */
char *fetch_alias(data_of_program *data, char *name)
{
	int m, length_of_alias;

	/** check 4 nulls */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);
	length_of_alias = str_length(name);
	for (m = 0; data->alias_list[m]; m++)
	{
		if (str_compare(name, data->alias_list[m]
					, length_of_alias) && data->alias_list[m][length_of_alias] == '=')
		{
			return (data->alias_list[m] + length_of_alias + 1);
		}
	}
	return (NULL);
}
/**
 * write_alias - Fns To Add Alias.
 * @string_alias: Alias.
 * @data: Structure For Program Data.
 * By Kayode, & Esther...
 * Return: 0 upon Success; Or If Declared.
 */
int write_alias(char *string_alias, data_of_program *data)
{
	int m, q;
	char buff[250] = {'0'}, *temporary = NULL;

	/* check 4 nulls */
	if (string_alias == NULL || data->alias_list == NULL)
		return (1);
	for (m = 0; string_alias[m]; m++)
	{
		if (string_alias[m] != '=')
			buff[m] = string_alias[m];
		else
		{
			temporary = fetch_alias(data, string_alias + m + 1);
			break;
		}
	}
	for (q = 0; data->alias_list[q]; q++)
	{
		if (str_compare(buff, data->alias_list[q]
					, m) && data->alias_list[q][m] == '=')
		{
			free(data->alias_list[q]);
			break;
		}
	}
	if (temporary)
	{
		add_to_buffer(buff, "=");
		add_to_buffer(buff, temporary);
		data->alias_list[q] = str_duplicate(buff);
	}
	else
		data->alias_list[q] = str_duplicate(string_alias);
	return (0);
}
