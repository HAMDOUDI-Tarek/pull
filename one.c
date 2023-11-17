#include "shell.h"

/**
 * com_ex -  a function to execute a command
 *
 * Return: the status of the command executed
 */
int com_ex(void)
{
	char *pth;
	pid_t cpid;
	int st_exit;

	if (command[0] && btin_func())
	{
		pth = pathfinder();
		if (pth)
		{
			cpid = fork();
			if (cpid == -1)
				return (0);
			else if (cpid == 0)
			{
				execve(pth, command, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(cpid, &st_exit, 0);
				if (WIFEXITED(st_exit))
					status = WEXITSTATUS(st_exit);
			}
		}
		else
		{
			_eprintf(2, "%a: %b: %c: not found\n", shell, shell_index, command[0]);
			return (127);
		}
		free(pth);
	}

	return (status);
}
