/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:42:57 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/02 21:18:05 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	manage_args(int *argc, char *arg, t_data *data)
{
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
int	choose_sort(t_data *data)
{
	if (data->stack_a_size == 2)
	{
		if (data->stack_a->value > data->stack_a->next->value)
			sa(data);
		return (1);
	}
	else if (data->stack_a_size == 3)
		tiny_sort_a(data);
	else if (data->stack_a_size == 4 || data->stack_a_size == 5)
	 	small_sort(data);
	else if (data->stack_a_size > 5)
		push_swap(data);
	return (1);
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
			if (!check_args(argv, argc, 1))
				return (1);
			init_stack(&data, &(data.stack_a), argv, 1);
		}
		// print_stack(data.stack_a);
		set_stack_sizes(&data);
		choose_sort(&data);
		// print_stack(data.stack_a);
		// print_stack(data.stack_b);
		free_stack(data.stack_a);
		free_stack(data.stack_b);
	}
	return (0);
}
