/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:21:51 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/28 10:44:19 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*current;
	t_stack	*biggest;
	int		big;

	big = INT_MIN;
	current = stack;
	while (current)
	{
		if (current->value > big)
		{
			big = current->value;
			biggest = current;
		}
		current = current->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*current;
	t_stack	*smallest;
	int		small;

	small = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->value < small)
		{
			small = current->value;
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

void	tiny_sort_a(t_data *data)
{
	t_stack	*biggest;
	t_stack	*end;

	biggest = find_biggest(data->stack_a);
	if (data->stack_a == biggest)
		ra(data);
	end = ft_lstlast(data->stack_a);
	if (end != biggest)
		rra(data);
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
}
