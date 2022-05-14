#include <stdio.h>`
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>



int main(void)
{
	char *buffer[100];
	char cmd[100];
	size_t buffsize = 100;

	char *envp[] = { (char *) "PATH=/bin", 0};

	while (1)
	{
		printf("$");
		getline(&buffer, &buffsize, stdin);
		read_command(command, parameters);
		if (buffer == "quit")
		{
			printf("an exit");
			return (0);
		}
		if (fork() != 0)
		{
			wait(NULL);
		}
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, buffer);
			execve(cmd, cmd, envp);
		}
	}
	return (0);
}	
