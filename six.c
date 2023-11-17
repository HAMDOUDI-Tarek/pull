#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 for success, others for failure
 */
int main(int argc, char *argv[])
{
	shell = argv[0];
	shell_index = 0;
	status = 0;

	(void)argc;
	while (++shell_index)
	{
		pmpt_print("#Islam-Tarek$ ");

		get_line(&line);

		command = stoa(line, ' ');

		status = com_ex();

		free(line);
		arr_free(command);
	}

	return (status);
}
