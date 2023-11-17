#include "shell.h"

/**
 * get_environment - Finds a environment variable name and returns it's val
 * @var: The variable name to be found
 *
 * Return: a pointer to the varible's val
 */
char *get_environment(char *var)
{
	int i, string_length = _strlen(var);
	char *val = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(environ[i], var, string_length) && environ[i][string_length] == '=')
		{
			val = environ[i] + _strlen(var) + 1;
			return (val);
		}
	}
	return (val);
}
