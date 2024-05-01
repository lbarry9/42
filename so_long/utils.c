/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:29:25 by lbarry            #+#    #+#             */
/*   Updated: 2023/10/27 20:24:31 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_linelen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	read_file(t_data *data, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd <= 0 || read(fd, &line, 0) < 0)
	{
		ft_printf("Error\nCannot read file\n");
		on_destroy(data);
	}
	return (fd);
}

char	check_next_move(t_data *data, int x, int y)
{
	t_list	*current;
	int		i;

	current = data->map;
	i = 0;
	while (i < y && current)
	{
		current = current->next;
		i++;
	}
	if (current->content[x] == '1')
		return ('1');
	if (current->content[x] == 'C')
		return ('C');
	if (current->content[x] == 'E')
		return ('E');
	if (current->content[x] == '0')
		return ('0');
	return ('0');
}

void	check_collected(t_data *data, int x, int y)
{
	if (data->dup_map[y][x] != 'D')
	{
		data->dup_map[y][x] = 'D';
		data->collected++;
	}
}
