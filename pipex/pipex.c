/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:15:00 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/12 19:58:17 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(int i, char **argv, char **envp, t_pipex *pipex)
{
	pipe(pipex->fd);
	if (pipex->fd[0] == -1 || pipex->fd[1] == -1)
	{
		perror("Error: pipe failed\n");
		exit(1);
	}
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
	{
		perror("Error: fork failed\n");
		exit(1);
	}
	if (pipex->pid[i] == 0)
		child_process(i, argv, envp, pipex);
	else
		parent_process(i, pipex);
}

void	child_process(int i, char **argv, char **envp, t_pipex *pipex)
{
	pipex->cmd = ft_split(argv[i + 2], ' ');
	open_fds(i, pipex);
	pipex->cmd_path = test_cmd_path(envp, pipex->cmd[0], pipex);
	if (!pipex->cmd_path)
	{
		ft_printf("%s: command not found\n", argv[i + 2]);
		free_all(pipex);
		close_fds(pipex);
		exit(1);
	}
	redirections(i, pipex);
	execve(pipex->cmd_path, pipex->cmd, NULL);
	exit(1);
}

void	parent_process(int i, t_pipex *pipex)
{
	close(pipex->fd[1]);
	if (i != 0)
		close(pipex->tmp);
	pipex->tmp = pipex->fd[0];
}

void	redirections(int i, t_pipex *pipex)
{
	if (i == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		close(pipex->fd_in);
	}
	else
	{
		dup2(pipex->tmp, STDIN_FILENO);
		close(pipex->tmp);
	}
	if (i != pipex->nb_cmds - 1)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[1]);
	}
	else
	{
		dup2(pipex->fd_out, STDOUT_FILENO);
		close(pipex->fd_out);
	}
	if (pipex->fd[0] > 0)
		close(pipex->fd[0]);
	if (pipex->fd[1] > 0)
		close(pipex->fd[1]);
}
