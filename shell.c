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
	char *buffer;
	char *piece;
	int i = 0;
	int j = 0;
	char **comm = malloc(sizeof(char) * 100);
	char *uname = malloc(sizeof(char) * 10);

	while (j < 10)
	{
	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		printf("unable to allocate memory");
		return (0);
	}
	getlogin_r(uname, 10);
	printf("%s## ", uname);
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

	if (execve(comm[0], comm, NULL) == -1)
	{
		perror("Error");
	}
	}
	return (0);
}
