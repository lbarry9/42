/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:42:57 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 23:02:28 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	manage_args(int *argc, char *arg, t_data *data)
{
	*argc = count_str(arg, ' ');
	data->args = ft_split(arg, ' ');
	if (!data->args)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_args(data->args, 0))
	{
		free_args(data->args);
		return (0);
	}
	if (*argc == 1)
		return (0);
	init_stack(data, &(data->stack_a), data->args, 0);
	free_args(data->args);
	return (1);
}

void	choose_sort(t_data *data)
{
	if (data->stack_a_size == 2)
	{
		if (data->stack_a->value > data->stack_a->next->value)
			sa(data);
	}
	else if (data->stack_a_size == 3)
		tiny_sort_a(data);
	else if (data->stack_a_size > 3 && data->stack_a_size <= 5)
		small_sort(data);
	else if (data->stack_a_size > 5)
		push_swap(data);
}

int	main(int argc, char **argv)
{
	static t_data	data = {0};

	if (argc > 1 && argv[1][0])
	{
		if (argc == 2)
		{
			if (!manage_args(&argc, argv[1], &data))
				return (1);
		}
		else if (argc > 2)
		{
			if (!check_args(argv, 1))
				return (1);
			init_stack(&data, &(data.stack_a), argv, 1);
		}
		set_stack_sizes(&data);
		choose_sort(&data);
		free_stack(data.stack_a);
		free_stack(data.stack_b);
	}
	return (0);
}
