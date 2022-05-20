#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

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
