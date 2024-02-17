/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:00:09 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/10 18:29:43 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	static t_pipex	pipex = {0};
	int				i;

	i = 0;
	if (argc < 5)
	{
		ft_printf("Error: insufficient arguments\n");
		return (1);
	}
	if (ft_strcmp("here_doc", argv[1]) == 0)
		init_here_doc(argc, &pipex);
	init_pipex(&pipex, argc, argv);
	if (pipex.is_hd == 1)
		here_doc(&pipex);
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
