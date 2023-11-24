/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:42:57 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 23:21:27 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	manage_args(int *argc, char *arg, t_data *data)
{
	if (!count_str(arg, ' '))
	{
		ft_printf("Error\n");
		return (0);
	}
	*argc = count_str(arg, ' ') + 1;
	data->args = ft_split(arg, ' ');
	if (!data->args)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_args(data->args, *argc, 0))
	{
		free_args(data->args);
		return (0);
	}
	init_stack(data, &(data->stack_a), data->args, 0);
	free_args(data->args);
	return (1);
}

int	main(int argc, char **argv)
{
	static t_data	data = {0};
	t_stack			*current;

	current = NULL;
	if (argc > 1 && argv[1][0])
	{
		if (argc == 2)
		{
			if (!manage_args(&argc, argv[1], &data))
				return (1);
		}
		else if (argc > 2)
		{
			if (!check_args(argv, argc, 1))
				return (1);
			init_stack(&data, &(data.stack_a), argv, 1);
		}
		print_stack(data.stack_a);
		if (argc == 3)
		{
			if (data.stack_a->value > data.stack_a->next->value)
				swap_a(&data);
		}
		else if (argc == 4)
			tiny_sort_a(&data);
		else if (argc == 5 || argc == 6)
			small_sort(argc, &data);
		else if (argc > 6)
			push_swap(&data);
		print_stack(data.stack_b);
		free_stack(data.stack_a);
		free_stack(data.stack_b);
	}
	return (0);
}
