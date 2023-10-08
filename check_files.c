#include "theshell.h"
/**
 * check_files - Fns That Check If File Exists.
 * @file_path: Filename For path.
 * By Kayode, & Esther.
 * Return: 0 on Success; Or Prompt Error Code.
 */
int check_files(char *file_path)
{
	struct stat s;

	if (stat(file_path, &s) != -1)
	{
		if (S_ISDIR(s.st_mode) || access(file_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
/**
 * finding_program - Fns That Find Program.
 * @data: Structure For Program Data.
 * By Kayode, & Esther.
 * Return: 0 on Success; Or Prompt Error Code.
 */
int finding_program(data_of_program *data)
{
	int m = 0, r_code = 0;
	char **dir;

	if (!data->command_name)
		return (2);

	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (check_files(data->command_name));
	free(data->tokens[0]);
	data->tokens[0] = str_concat(str_duplicate("/")
			, data->command_name);
	if (!data->tokens[0])
		return (2);
	dir = tokenize_paths(data);
	if (!dir || !dir[0])
	{
		errno = 127;
		return (127);
	}
	for (m = 0; dir[m]; m++)
	{
		dir[m] = str_concat(dir[m], data->tokens[0]);
		r_code = check_files(dir[m]);
		if (r_code == 0 || r_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_duplicate(dir[m]);
			free_array_of_pointers(dir);
			return (r_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_of_pointers(dir);
	return (r_code);
}
/**
 * tokenize_paths - Fns That Tokenizes Required Path.
 * @data: Program Data.
 * By Kayode, & Esther.
 * Return: Array Of Paths.
 */
char **tokenize_paths(data_of_program *data)
{
	int m = 0, count_dir = 2;
	char **tok = NULL, *path;

	path = environment_get_key("PATH", data);
	if ((path == NULL || path[0] == '\0'))
		return (NULL);

	path = str_duplicate(path);
	for (m = 0; path[m]; m++)
	{
		if (path[m] == ':')
			count_dir++;
	}
	tok = malloc(sizeof(char *) * count_dir);
	m = 0;
	tok[m] = str_duplicate(_strtok(path, ":"));
	while (tok[m++])
	{
		tok[m] = str_duplicate(_strtok(NULL, ":"));
	}
	free(path);
	path = NULL;
	return (tok);
}
