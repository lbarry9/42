/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:00:09 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/07 00:47:27 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	static t_pipex	pipex = {0};
	int				i;

	i = 0;
	if (argc != 5)
	{
		ft_printf("Error: incorrect number of arguments\n");
		return (1);
	}
	init_pipex(&pipex, argc, argv);
	while (i < pipex.nb_cmds)
	{
		ft_pipex(i, argv, envp, &pipex);
		i++;
	}
	i = 0;
	while (i < pipex.nb_cmds)
		waitpid(pipex.pid[i++], NULL, 0);
	close(pipex.fd[0]);
	return (0);
}
