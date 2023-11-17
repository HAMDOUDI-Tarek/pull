#include "shell.h"

/**
 * stoa - converts a string to an array based on a delimiter
 * @str: the string to be converted to an array
 * @dl: the delimiter used to break string
 *
 * Return: array of the tokenized string, else NULl if not converted
 */
char **stoa(char *str, char dl)
{
	int i = 0, j = 0, k = 0;
	int string_length = _strlen(str);
	char **arr = (char **)malloc(sizeof(char *) * (string_length + 1));
	char *buf = (char *)malloc(sizeof(char) * (string_length + 1));


	for (; i < string_length + 1; i++)
	{
		if (str[i] != dl && str[i] != '\0')
		{
			buf[k] = str[i];
			k++;
		}
		else
		{
			if (k > 0)
			{
				buf[k] = '\0';
				arr[j] = malloc(sizeof(char) * (k + 1));
				_strcpy(arr[j], buf);
				j++;
				k = 0;
			}
		}
	}

	arr[j] = NULL;
	free(buf);

	return (arr);
}

/**
 * _strncmp - compares 2 strings till n char
 * @str1: first string to be compared with
 * @str2: second string compared on/with first string
 * @n: nmber of string to be compared
 * Return: 0 if equal, positive if s1 < s2, negative if s1 > s2
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (!str1[i] || !str2[i])
			return (str1[i] - str2[i]);

		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
