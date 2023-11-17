#include "shell.h"

/**
 * pathfinder - searches through the directories to find a command
 *
 * Return: absolute path to the command if found, else NULL
 */
char *pathfinder(void)
{
	int i = 0;
	char *pth = get_environment("PATH");
	char **pth_directory, *abs_path;

	if (_strncmp(command[0], "./", 2) == 0 || command[0][0] == '/'
			|| _strncmp(command[0], "../", 3))
	{
		if (access(command[0], F_OK) == 0)
			return (_strdup(command[0]));
	}

	if (!pth)
		return (NULL);

	pth_directory = stoa(pth, ':');

	for (i = 0; pth_directory[i]; i++)
	{
		abs_path = malloc(1024);
		_strcpy(abs_path, pth_directory[i]);
		_strcat(abs_path, "/");
		_strcat(abs_path, command[0]);

		if (access(abs_path, F_OK) == 0)
		{
			arr_free(pth_directory);
			return (abs_path);
		}
		free(abs_path);
	}
	arr_free(pth_directory);

	return (NULL);
}
