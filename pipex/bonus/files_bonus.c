/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:00:27 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/10 18:32:46 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_infile(t_pipex *pipex)
{
	if (access(pipex->infile, F_OK) == -1)
	{
		perror(pipex->infile);
		close_fds(pipex);
		free_all(pipex);
		exit(1);
	}
	else
		pipex->fd_in = open(pipex->infile, O_RDONLY);
}

void	open_fds(int i, t_pipex *pipex)
{
	if (i == 0)
		open_infile(pipex);
	if (i == pipex->nb_cmds - 1)
	{
		if (pipex->is_hd)
			pipex->fd_out = open(pipex->outfile, O_WRONLY
					| O_CREAT | O_APPEND, 0666);
		else
			pipex->fd_out = open(pipex->outfile, O_WRONLY | O_CREAT
					| O_TRUNC, 0666);
		if (pipex->fd_out == -1)
		{
			perror(pipex->outfile);
			close_fds(pipex);
			free_all(pipex);
			exit(1);
		}
	}
}

void	close_fds(t_pipex *pipex)
{
	if (pipex->fd_in > 0)
		close(pipex->fd_in);
	if (pipex->fd_out > 0)
		close(pipex->fd_out);
	if (pipex->fd[0] > 0)
		close(pipex->fd[0]);
	if (pipex->fd[1] > 0)
		close(pipex->fd[1]);
	if (pipex->tmp > 0)
		close(pipex->tmp);
}
