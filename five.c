#include "shell.h"

/**
 * _ehandchar - writes the character c to stdout
 * @file_desc: file descriptor
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _ehandchar(int file_desc, char c)
{
	return (write(file_desc, &c, 1));
}

/**
 * _ehandstr - Prints a string to standard output
 * @file_desc: file descriptor
 * @str: The string to be printed
 *
 * Return: Length of string printed - 1
 */
int _ehandstr(int file_desc, char *str)
{
	int i;

	if (!str)
		return (_ehandstr(file_desc, "(null)"));
	for (i = 0; str[i]; i++)
		_ehandchar(file_desc, str[i]);

	return (i);
}

/**
 * _ehandint - Prints an integer to standard output
 * @file_desc: file desriptor
 * @nm: The nmber to be printed
 *
 * Return: Length of string printed - 1
 */
int _ehandint(int file_desc, int nm)
{
	int val, len = 0;

	if (!nm)
	{
		len += _ehandchar(file_desc, '0');
		return (len);
	}
	if (nm == _INT_MIN)
	{
		len += _ehandstr(file_desc, "-2147483648");
		return (len);
	}
	if (nm < 0)
	{
		len += _ehandchar(file_desc, '-');
		nm = -nm;
	}

	val = nm % 10;
	nm = nm / 10;
	if (nm)
		len += _ehandint(file_desc, nm);
	len += _ehandchar(file_desc, val + '0');

	return (len);
}

/**
 * _eprintf - Prints to the standar output like regular printf
 * @file_desc: file descriptor
 * @fmt: The string to be printed adn its fmt specifiers
 * @s1: string 1
 * @s2: string 2
 * @n1: nm 1
 *
 * Return: Length of printed string
 */
int _eprintf(int file_desc, const char *fmt, char *s1, int n1, char *s2)
{

	int i = 0, len = 0;

	while (fmt[i])
	{
		if (fmt[i] != '%')
			len += _ehandchar(file_desc, fmt[i]);
		else
		{
			i++;
			if (fmt[i] == 'a')
				len += _ehandstr(file_desc, s1);
			else if (fmt[i] == 'b')
				len += _ehandint(file_desc, n1);
			else if (fmt[i] == 'c')
				len += _ehandstr(file_desc, s2);
		}
		i++;
	}

	return (len);
}

/**
 * arr_print - prints an array to standard output
 * @array: The array to be printed
 *
 * Return: Numbers of elements printed
 */
int arr_print(char *array[])
{
	int i = 0;

	while (array[i])
	{
		_eprintf(1, "%a\n", array[i], 0, "nill");
		i++;
	}
	return (0);
}
