#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *comm[] = {"/bin/ls", "-l", NULL};
	execve(comm[0], comm, NULL);
	printf("thi is dumb");
	return (0);
}
