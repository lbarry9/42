/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:08:54 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/12 20:18:59 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	find_env_path(char **envp, t_pipex *pipex)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			pipex->envp_path = ft_strnstr(envp[i], "PATH=", 5);
		}
		i++;
	}
}

char	*find_cmd_path(char **paths, char *arg)
{
	int		j;
	char	*cmd_path;

	j = 0;
	while (paths[j++])
	{
		cmd_path = ft_strjoin(paths[j], arg);
		if (!cmd_path)
		{
			free_arr(paths);
			return (NULL);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_arr(paths);
			return (cmd_path);
		}
		else
			free(cmd_path);
	}
	free_arr(paths);
	return (NULL);
}

int	already_path(t_pipex *pipex, char *arg)
{
	if (access(arg, F_OK | X_OK) == 0)
		return (1);
	else
	{
		perror(arg);
		free_all(pipex);
		close_fds(pipex);
		exit(1);
	}
}

char	*test_cmd_path(char **envp, char *arg, t_pipex *pipex)
{
	int		i;
	char	*cmd_path;
	char	**paths;

	i = 0;
	if (ft_strchr(arg, '/'))
		if (already_path(pipex, arg))
			return (strdup(arg));
	find_env_path(envp, pipex);
	if (!pipex->envp_path)
	{
		ft_printf("Error: PATH not found\n");
		free_all(pipex);
		exit(1);
	}
	paths = ft_split(pipex->envp_path, ':');
	if (!paths)
	{
		close_fds(pipex);
		free_all(pipex);
		exit(1);
	}
	cmd_path = find_cmd_path(paths, arg);
	return (cmd_path);
}
