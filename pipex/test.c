#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char *args[3];

	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;

	fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (access("outfile", W_OK) != -1)
		printf("i have permission\n");
	else
		printf("i don't have permission\n");

	execve("/bin/ls", args, NULL);
	printf("this won't be printed\n");

	int	pid;
	pid = fork();
	if (pid == 0)
	{
		printf("child process : %d\n", pid);
	}
	else
	{
		wait(NULL);
		printf("parent process : %d\n", pid);
	}
	return (0);
}
