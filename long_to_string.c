#include "theshell.h"
/**
 * long_to_string - Fns That Converts Nos To String Type.
 * By Kayode, & Esther.
 * @number: Nos To Be Converted To String Format.
 * @string: Buffer To Save Nos As String.
 * @base: Base To Convert Nos.
 * Return: NIL...
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - Fns That Convert String Of Digits To Integer...
 * @s: Ptr To String Origin...
 * By Kayode, & Esther.
 * Return: Integer Of String, Or Zero.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - Fns That Count Coincidences Of Char In String.
 * @string: Ptr To String Origin.
 * By Kayode, & Esther.
 * @character: String With Chars Counted.
 * Return: Int Of String, Or Zero.
 */
int count_characters(char *string, char *character)
{
	int t = 0, counter = 0;

	for (; string[t]; t++)
	{
		if (string[t] == character[0])
			counter++;
	}
	return (counter);
}
