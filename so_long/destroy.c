/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:39:02 by lbarry            #+#    #+#             */
/*   Updated: 2023/10/24 22:24:23 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_data *data)
{
	t_list	*current;
	t_list	*next;
	int		i;

	if (data->map)
	{
		current = data->map;
		while (current)
		{
			free(current->content);
			next = current->next;
			free(current);
			current = next;
		}
	}
	if (data->dup_map)
	{
		i = 0;
		while (data->dup_map[i])
		{
			free(data->dup_map[i]);
			i++;
		}
		free(data->dup_map);
	}
}

void	destroy_images(t_data *data)
{
	if (data->background_ptr)
		mlx_destroy_image(data->mlx_ptr, data->background_ptr);
	if (data->mini_background_ptr)
		mlx_destroy_image(data->mlx_ptr, data->mini_background_ptr);
	if (data->wall_ptr)
		mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
	if (data->bee_down_ptr)
		mlx_destroy_image(data->mlx_ptr, data->bee_down_ptr);
	if (data->bee_left_ptr)
		mlx_destroy_image(data->mlx_ptr, data->bee_left_ptr);
	if (data->bee_right_ptr)
		mlx_destroy_image(data->mlx_ptr, data->bee_right_ptr);
	if (data->bee_up_ptr)
		mlx_destroy_image(data->mlx_ptr, data->bee_up_ptr);
	if (data->flower_ptr)
		mlx_destroy_image(data->mlx_ptr, data->flower_ptr);
	if (data->hive_ptr)
		mlx_destroy_image(data->mlx_ptr, data->hive_ptr);
}

int	on_destroy(t_data *data)
{
	destroy_images(data);
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_maps(data);
	exit(0);
}
