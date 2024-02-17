/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:49:39 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/12 20:17:02 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		nb_cmds;
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;
	int		fd[2];
	int		pid[1024];
	int		tmp;
	char	**cmd;
	char	*cmd_path;
	char	*envp_path;
}			t_pipex;

void	free_arr(char **arr);
void	find_env_path(char **envp, t_pipex *pipex);
char	*find_cmd_path(char **paths, char *arg);
char	*test_cmd_path(char **envp, char *arg, t_pipex *pipex);
int		already_path(t_pipex *pipex, char *arg);
void	child_process(int i, char **argv, char **envp, t_pipex *pipex);
void	parent_process(int i, t_pipex *pipex);
void	ft_pipex(int i, char **argv, char **envp, t_pipex *pipex);
void	redirections(int i, t_pipex *pipex);
void	free_all(t_pipex *pipex);
void	init_pipex(t_pipex *pipex, int argc, char **argv);
void	open_fds(int i, t_pipex *pipex);
void	open_infile(t_pipex *pipex);
void	close_fds(t_pipex *pipex);

#endif
