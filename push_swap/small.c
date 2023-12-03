/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:50:51 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/03 20:20:10 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_rotate(t_data *data, t_stack *smallest)
{
	int	median;

	median = data->stack_a_size / 2;
	while (data->stack_a && data->stack_a != smallest)
	{
		if (data->stack_a != smallest && smallest->index < median)
			ra(data);
		else if (data->stack_a != smallest && smallest->index >= median)
			rra(data);
	}
	if (data->stack_a == smallest)
		pb(data);
}

void	small_sort(t_data *data)
{
	t_stack	*smallest;

	set_indexes(data->stack_a);
	smallest = find_smallest(data->stack_a);
	choose_rotate(data, smallest);
	if (data->stack_a_size == 5)
	{
		set_indexes(data->stack_a);
		smallest = find_smallest(data->stack_a);
		choose_rotate(data, smallest);
	}
	tiny_sort_a(data);
	pa(data);
	if (data->stack_a_size == 5)
		pa(data);
}
