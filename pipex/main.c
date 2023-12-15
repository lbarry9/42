#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int i = 0;
	// while (envp[i])
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }
	int fd[2];
	char *ls[] = {"cat", NULL};
	char *wc[] = {"wc", NULL};
	int infile_fd;
	int outfile_fd;

	infile_fd = open("infile", O_RDONLY);
	outfile_fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("Before execve\n");
	pipe(fd);
	int cmd1 = fork();
	if (cmd1 == 0)
	{
		// instead of writing in the termuinale, we write in the pipe
		dup2(infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		//execve with the cat command
		execve("/bin/cat/", ls, NULL);

	}
	int cmd2 = fork();
	if (cmd2 == 0)
	{
		// instead of reading from the terminal, we read from the pipe
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/cat", ls, NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(cmd1, NULL, 0);
	waitpid(cmd2, NULL, 0);
	printf("after execve\n");
	return (0);
}
