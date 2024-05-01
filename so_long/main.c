/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:39:35 by lbarry            #+#    #+#             */
/*   Updated: 2023/10/29 21:14:43 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_up(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * PIXELS,
			data->height * PIXELS, "don't worry, bee happy");
	if (!data->win_ptr)
	{
		ft_printf("Error\nCannot open window\n");
		on_destroy(data);
		return (0);
	}
	init_images(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background_ptr, 0, 0);
	set_images(data);
	set_player(data);
	data->moves = 0;
	data->collected = 0;
	return (1);
}

int	parse_map(t_data *data)
{
	if (!check_rectangle(data))
		return (0);
	if (!check_size(data))
		return (0);
	if (!check_chars(data))
		return (0);
	if (!check_walls(data))
	{
		ft_printf("Error\nInvalid walls\n");
		return (0);
	}
	data->c_count = 0;
	data->e_count = 0;
	data->p_count = 0;
	e_p_c_count(data);
	if (data->c_count < 1 || data->e_count != 1 || data->p_count != 1)
	{
		ft_printf("Error\nInvalid exit, start position or collectible count\n");
		return (0);
	}
	if (!check_valid_path(data))
		return (0);
	return (1);
}

int	check_arg(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'r' || str[len - 2] != 'e'
		|| str[len - 3] != 'b' || str[len - 4] != '.')
	{
		ft_printf("Error\nInvalid file name\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	static t_data	data = {0};

	if (argc != 2)
	{
		ft_printf("Error\nSo long needs a map")
		return (0);
	}
	if (!check_arg(argv[1]))
		on_destroy(&data);
	set_size_get_line(&data, argv[1]);
	if (!parse_map(&data))
		on_destroy(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		on_destroy(&data);
	if (!set_up(&data))
		on_destroy(&data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
