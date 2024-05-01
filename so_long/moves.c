/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:00:04 by lbarry            #+#    #+#             */
/*   Updated: 2023/10/27 20:21:58 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data)
{
	char	next_move;

	next_move = check_next_move(data, data->bee_x - 1, data->bee_y);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, 'l');
	if (check_next_move(data, data->bee_x, data->bee_y) == 'E'
		&& data->collected != data->c_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hive_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mini_background_ptr, data->bee_x * PIXELS,
			data->bee_y * PIXELS);
	data->bee_x--;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_left_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->bee_x, data->bee_y);
}

void	move_right(t_data *data)
{
	char	next_move;

	next_move = check_next_move(data, data->bee_x + 1, data->bee_y);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, 'r');
	if (check_next_move(data, data->bee_x, data->bee_y) == 'E'
		&& data->collected != data->c_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hive_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mini_background_ptr, data->bee_x * PIXELS,
			data->bee_y * PIXELS);
	data->bee_x++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_right_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->bee_x, data->bee_y);
}

void	move_up(t_data *data)
{
	char	next_move;

	next_move = check_next_move(data, data->bee_x, data->bee_y - 1);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, 'u');
	if (check_next_move(data, data->bee_x, data->bee_y) == 'E'
		&& data->collected != data->c_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hive_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mini_background_ptr, data->bee_x * PIXELS,
			data->bee_y * PIXELS);
	data->bee_y--;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_up_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->bee_x, data->bee_y);
}

void	move_down(t_data *data)
{
	char	next_move;

	next_move = check_next_move(data, data->bee_x, data->bee_y + 1);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, 'd');
	if (check_next_move(data, data->bee_x, data->bee_y) == 'E'
		&& data->collected != data->c_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->hive_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mini_background_ptr, data->bee_x * PIXELS,
			data->bee_y * PIXELS);
	data->bee_y++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->bee_down_ptr, data->bee_x * PIXELS, data->bee_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->bee_x, data->bee_y);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == 65361 || keysym == 113)
		move_left(data);
	if (keysym == 65363 || keysym == 100)
		move_right(data);
	if (keysym == 65362 || keysym == 122)
		move_up(data);
	if (keysym == 65364 || keysym == 115)
		move_down(data);
	if (keysym == 65307)
		on_destroy(data);
	return (0);
}
