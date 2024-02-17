/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:32 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/05 16:07:55 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv)
{
	if (pipex->is_hd)
	{
		pipex->nb_cmds = 2;
		pipex->limiter = argv[2];
		pipex->infile = "here_doc";
	}
	else
	{
		pipex->nb_cmds = argc - 3;
		pipex->infile = argv[1];
	}
	pipex->outfile = argv[argc - 1];
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free_all(t_pipex *pipex)
{
	if (pipex->cmd)
		free_arr(pipex->cmd);
	if (pipex->cmd_path)
		free(pipex->cmd_path);
}
