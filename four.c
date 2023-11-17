#include "shell.h"

/**
 * btin_func - Handles builtin commands like exit, env, e.t.c
 *
 * Return: 0 for success, else status
 */
int btin_func(void)
{
	if (!command[0])
		return (0);
	if (!_strcmp(command[0], "exit"))
	{
		status = Exit_st(command[1]);
		return (0);
	}

	if (!_strcmp(command[0], "env"))
	{
		arr_print(environ);
		return (0);
	}

	return (-1);
}
