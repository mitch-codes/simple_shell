#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * exitProgram - Exit program if a statement is given
 *
 * @command: the statement being checked
 * Return: 0 on success
 */
int exitProgram(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		printf("we exit\n");
		return (1);
	}
	return (0);
}

/**
 * main - Entry point
 *
 * Return: 0 on success
 */

int main(void)
{
	size_t bufsize = 100;
	char *buffer = malloc(sizeof(char) * bufsize);
	char *piece;
	char **comm = malloc(sizeof(char) * 100);

	while (1)
	{
		int i = 0;

	if (buffer == NULL)
	{
		printf("unable to allocate memory");
		return (0);
	}
	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	buffer[strlen(buffer) - 1] = ' ';
	piece = strtok(buffer, " ");
	while (piece != NULL)
	{
		comm[i] = piece;
		piece = strtok(NULL, " ");
		i++;
	}
	if (exitProgram(comm[0]) == 1)
		return (0);
	comm[i] = NULL;
	if (fork() != 0)
	{
		wait(NULL);
	}
	else
	{
		if (execve(comm[0], comm, NULL) == -1)
		{
			perror("Error");
		}
	}
	}
	return (0);
}
