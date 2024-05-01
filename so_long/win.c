/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:08:39 by lbarry            #+#    #+#             */
/*   Updated: 2023/10/27 20:05:29 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_left(t_data *data)
{
	data->bee_x--;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_left_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
}

void	win_right(t_data *data)
{
	data->bee_x++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_right_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
}

void	win_up(t_data *data)
{
	data->bee_y--;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_up_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
}

void	win_down(t_data *data)
{
	data->bee_y++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_down_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
}

void	win_game(t_data *data, char move)
{
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mini_background_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	if (move == 'l')
		win_left(data);
	if (move == 'r')
		win_right(data);
	if (move == 'u')
		win_up(data);
	if (move == 'd')
		win_down(data);
	ft_printf("WINNER! You must be BUZZING\n");
	on_destroy(data);
}
