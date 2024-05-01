/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:06:02 by lbarry            #+#    #+#             */
/*   Updated: 2023/10/27 19:20:23 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_data *data)
{
	t_list	*current;

	current = data->map;
	while (current)
	{
		if (ft_linelen(current->content) != data->width)
		{
			ft_printf("Error\nMap not rectangle\n");
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	check_size(t_data *data)
{
	if (data->height < MIN_HEIGHT || data->width < MIN_WIDTH
		|| data->width > MAX_WIDTH || data->height > MAX_HEIGHT)
	{
		ft_printf("Error\nSize not adapted for game\n");
		return (0);
	}
	return (1);
}

int	e_p_c_count(t_data *data)
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
			if (current->content[x] == 'C')
				data->c_count++;
			if (current->content[x] == 'E')
				data->e_count++;
			if (current->content[x] == 'P')
				data->p_count++;
			x++;
		}
		current = current->next;
		y++;
	}
	return (1);
}

int	check_chars(t_data *data)
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
			if (current->content[x] != '0' && current->content[x] != '1'
				&& current->content[x] != 'C' && current->content[x] != 'E'
				&& current->content[x] != 'P')
			{
				ft_printf("Error\nInvalid char in map\n");
				return (0);
			}
			x++;
		}
		current = current->next;
		y++;
	}
	return (1);
}

int	check_walls(t_data *data)
{
	t_list	*current;
	int		x;
	int		y;

	current = data->map;
	y = 0;
	while (current)
	{
		if (y == 0 || y == (data->height - 1))
		{
			x = 0;
			while (current->content[x])
			{
				if (current->content[x] != '1')
					return (0);
				x++;
			}
		}
		if (current->content[0] != '1'
			|| current->content[data->width - 1] != '1')
			return (0);
		current = current->next;
		y++;
	}
	return (1);
}
