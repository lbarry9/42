#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void	my_print(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}
void	cd(char **argv, int i)
{
	if (i != 2)
	{
		my_print("error: cd: bad arguments\n");
		return ;
	}
	if (chdir(argv[i]) == -1)
	{
		my_print("error: cd: cannot change directory to ");
		my_print(argv[1]);
		my_print("\n");
		return ;
	}
}

void	exec(char **argv, char **envp, int i)
{
	int fd[2];
	int has_pipe = 0;
	int pid;

	if (argv[i] && !strcmp(argv[i], "|"))
		has_pipe = 1;
	if (has_pipe)
	{
		if (pipe(fd) == -1)
		{
			my_print("error: fatal\n");
			return ;
		}
	}
	pid = fork();
	if (pid == -1)
	{
		my_print("error: fatal\n");
		return ;
	}
	if (pid == 0)
	{
		argv[i] = 0;
		if (has_pipe)
		{
			if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
			{
				my_print("error: fatal\n");
				return ;
			}
		}
		execve(argv[0], argv, envp);
		my_print("error: cannot execute ");
		my_print(argv[0]);
		my_print("\n");
		return ;
	}
	waitpid(pid, 0, 0);
	if (has_pipe)
	{
		if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
		{
			my_print("error: fatal\n");
			return ;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int i = 0;
	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(argv[0], "cd"))
				cd(argv, i);
			else if (i)
				exec(argv, envp, i);
		}
	}
	return(0);
}
