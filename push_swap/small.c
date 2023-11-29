/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:50:51 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/28 10:40:36 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_value_index(t_stack *stack, int value)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack;
	while (current)
	{
		if (current->value == value)
			return (index);
		index++;
		current = current->next;
	}
	return (0);
}

void	choose_rotate(t_data *data, t_stack *smallest)
{
	int		smallest_position;

	smallest_position = find_value_index(data->stack_a, smallest->value) + 1;
	while (data->stack_a)
	{
		if (data->stack_a != smallest && smallest_position <= (data->stack_a_size / 2))
			ra(data);
		if (data->stack_a != smallest && smallest_position > (data->stack_a_size / 2))
			rra(data);
		if (data->stack_a == smallest)
		{
			pb(data);
			return ;
		}
	}
}

void	small_sort(t_data *data)
{
	t_stack	*smallest;

	smallest = find_smallest(data->stack_a);
	choose_rotate(data, smallest);
	if (data->stack_a_size == 5)
	{
		smallest = find_smallest(data->stack_a);
		choose_rotate(data, smallest);
	}
	tiny_sort_a(data);
	pa(data);
	if (data->stack_a_size == 5)
		pa(data);
}
