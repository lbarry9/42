/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:04:18 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/10 18:42:37 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_here_doc(int argc, t_pipex *pipex)
{
	if (argc != 6)
	{
		ft_printf("Error: incorrect number of arguments for heredoc\n");
		exit (1);
	}
	pipex->is_hd = 1;
}

void	here_doc(t_pipex *pipex)
{
	char	*line;

	line = NULL;
	pipex->fd_in = open("here_doc", O_RDWR | O_CREAT, 0666);
	if (pipex->fd_in == -1)
	{
		perror("here_doc");
		exit(1);
	}
	while (1)
	{
		ft_printf("heredoc> ");
		line = get_next_line(STDIN_FILENO, 0);
		if (ft_strcmp(line, pipex->limiter) == 0)
		{
			get_next_line(STDIN_FILENO, 1);
			free(line);
			break ;
		}
		write(pipex->fd_in, line, ft_strlen(line));
		write(pipex->fd_in, "\n", 1);
		free(line);
	}
	close(pipex->fd_in);
}
