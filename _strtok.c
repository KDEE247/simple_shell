#include "theshell.h"
/**
 * _strtok - Fns To Split Strings With Delimiters...
 * By Kayode, & Esther...
 * @line: Ptr To Array 4rm Getline.
 * @delimiters: Char We Mark Off Strings In Parts.
 * Return: Ptr To Created Token.
*/
char *_strtok(char *line, char *delimiters)
{
	int v;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (v = 0; delimiters[v] != '\0'; v++)
		{
			if (*str == delimiters[v])
			break;
		}
		if (delimiters[v] == '\0')
			break;
	}
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (v = 0; delimiters[v] != '\0'; v++)
		{
			if (*str == delimiters[v])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
