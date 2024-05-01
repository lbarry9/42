/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:27:13 by lbarry            #+#    #+#             */
/*   Updated: 2023/10/27 19:32:32 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_data *data)
{
	data->background_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/background.xpm", &(data->width), &(data->height));
	data->mini_background_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/mini_background.xpm", &(data->width), &(data->height));
	data->flower_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/flower.xpm", &(data->width), &(data->height));
	data->hive_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/hive.xpm", &(data->width), &(data->height));
	data->wall_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/bush.xpm", &(data->width), &(data->height));
	data->bee_left_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/bee_left.xpm", &(data->width), &(data->height));
	data->bee_right_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/bee_right.xpm", &(data->width), &(data->height));
	data->bee_up_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/bee_up.xpm", &(data->width), &(data->height));
	data->bee_down_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/bee_down.xpm", &(data->width), &(data->height));
	if (!data->background_ptr || !data->mini_background_ptr || !data->flower_ptr
		|| !data->hive_ptr || !data->wall_ptr || !data->bee_left_ptr
		|| !data->bee_right_ptr || !data->bee_up_ptr || !data->bee_down_ptr)
	{
		ft_printf("Error\nImage not loaded");
		on_destroy(data);
	}
}

int	stock_map(t_data *data, char *line)
{
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = ft_strdup(line);
	if (!new->content)
		return (0);
	new->next = NULL;
	if (!data->map)
	{
		data->map = new;
		return (1);
	}
	last = ft_lstlast(data->map);
	last->next = new;
	return (1);
}

void	set_size_get_line(t_data *data, char *map)
{
	int		fd;
	char	*line;

	fd = read_file(data, map);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nCannot read map\n");
		on_destroy(data);
	}
	while (line)
	{
		if (!line)
			on_destroy(data);
		data->width = ft_linelen(line) - 1;
		data->height++;
		if (!stock_map(data, line))
			on_destroy(data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	set_player(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (current->content[x])
		{
			if (current->content[x] == 'P')
			{
				data->bee_x = x;
				data->bee_y = y;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->bee_right_ptr, data->bee_x * PIXELS,
					data->bee_y * PIXELS);
			}
			x++;
		}
		y++;
		current = current->next;
	}
}

void	set_images(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		x = 0;
		while (current->content[x])
		{
			if (current->content[x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall_ptr, x * PIXELS, y * PIXELS);
			if (current->content[x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->flower_ptr, x * PIXELS, y * PIXELS);
			if (current->content[x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->hive_ptr, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
		current = current->next;
	}
}
