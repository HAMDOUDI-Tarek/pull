#include "shell.h"
/**
 * _atoi - convert a string into an integer.
 * @s: the string.
 * Return: int.
 */

int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int final = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		final = (final * 10) + (s[i] - '0');
		i++;
	}
	final *= sign;
	return (final);
}

