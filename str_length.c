#include "theshell.h"
/**
 * str_length - Fns That Returns Length Of A Null Terminated String.
 * By Kayode, & Esther...
 * @str: Ptr String.
 * Return: Length Of String.
 */
int str_length(char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);

	while (str[length++] != '\0')
	{
	}
	return (--length);
}


/**
 * str_duplicate - Fns That Duplicate String.
 * @str: String To Duplicate...
 * Return: Ptr To Array.
 * By Kayode, & Esther.
 */
char *str_duplicate(char *str)
{
	char *result;
	int length, t;

	if (str == NULL)
		return (NULL);

	length = str_length(str) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (t = 0; t < length ; t++)
	{
		result[t] = str[t];
	}

	return (result);
}

/**
 * str_compare - Fns To Compare Two Strings...
 * @str1: Shorter String One...
 * @str2: Longer String Two...
 * @number: Nos Of Chars To Be Compared, 0 If Infinite.
 * Return: 1 If Strings Are Equivalent; Else 0.
 */
int str_compare(char *str1, char *str2, int number)
{
	int iterator;

	if (str1 == NULL && str2 == NULL)
		return (1);

	if (str1 == NULL || str2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_length(str1) != str_length(str2))
			return (0);
		for (iterator = 0; str1[iterator]; iterator++)
		{
			if (str1[iterator] != str2[iterator])
				return (0);
		}
		return (1);
	}
	else
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (str1[iterator] != str2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat - Fns That Concatenate Strings.
 * @str1: 1st String For Concatenation.
 * @str2: 2nd String For Concatenation.
 * Return: Ptr To Array...
 */
char *str_concat(char *str1, char *str2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (str1 == NULL)
		str1 = "";
	length1 = str_length(str1);

	if (str2 == NULL)
		str2 = "";
	length2 = str_length(str2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (length1 = 0; str1[length1] != '\0'; length1++)
		result[length1] = str1[length1];
	free(str1);

	for (length2 = 0; str2[length2] != '\0'; length2++)
	{
		result[length1] = str2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}


/**
 * str_reverse - Fns For Reversing String.
 * By Kayode, & Esther.
 * @str: Ptr To String.
 * Return: Void.
 */
void str_reverse(char *str)
{

	int t = 0, length = str_length(str) - 1;
	char hold;

	while (t < length)
	{
		hold = str[t];
		str[t++] = str[length];
		str[length--] = hold;
	}
}
