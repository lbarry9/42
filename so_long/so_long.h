/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:07:41 by lbarry            #+#    #+#             */
/*   Updated: 2023/10/27 20:41:57 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define PIXELS 64
# define MAX_HEIGHT 15
# define MAX_WIDTH 30
# define MIN_HEIGHT 3
# define MIN_WIDTH 3

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*background_ptr;
	void	*mini_background_ptr;
	void	*wall_ptr;
	void	*bee_right_ptr;
	void	*bee_left_ptr;
	void	*bee_up_ptr;
	void	*bee_down_ptr;
	void	*flower_ptr;
	void	*hive_ptr;
	int		height;
	int		width;
	t_list	*map;
	int		bee_x;
	int		bee_y;
	int		c_count;
	int		collected;
	int		e_count;
	int		p_count;
	int		moves;
	char	**dup_map;
	int		start_x;
	int		start_y;
}	t_data;

int		on_destroy(t_data *data);
void	free_maps(t_data *data);
void	destroy_images(t_data *data);
int		check_arg(char *str);
void	set_size_get_line(t_data *data, char *map);
int		read_file(t_data *data, char *map);
int		ft_linelen(char *s);
int		stock_map(t_data *data, char *line);
int		parse_map(t_data *data);
int		check_rectangle(t_data *data);
int		check_size(t_data *data);
int		check_chars(t_data *data);
int		check_walls(t_data *data);
int		e_p_c_count(t_data *data);
int		check_valid_path(t_data *data);
int		set_dup_map(t_data *data);
int		flood_fill(int x, int y, t_data *data);
int		check_flood_fill(t_data *data);
int		set_up(t_data *data);
void	init_images(t_data *data);
void	set_images(t_data *data);
void	set_player(t_data *data);
int		on_keypress(int keysym, t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	win_game(t_data *data, char move);
void	win_left(t_data *data);
void	win_right(t_data *data);
void	win_up(t_data *data);
void	win_down(t_data *data);
char	check_next_move(t_data *data, int x, int y);
void	check_collected(t_data *data, int x, int y);

#endif
