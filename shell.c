#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	size_t bufsize = 100;
	char *buffer;
	char *comm[2];

	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		printf("unable to allocate memory");
		return (0);
	}
	printf("$ ");
	getline(&buffer, &bufsize, stdin);

	printf("the command is %s\n", buffer);
	printf("the length of command is %ld\n", strlen(buffer));
	comm[0] = buffer;
	strcat(comm[0], "0");
	comm[1] = NULL;
	printf("%s\n", comm[0]);

	if(execve(comm[0], comm, NULL) == -1)
	{
		perror("Error");
	}

	return (0);
}
