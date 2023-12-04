/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:04:59 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 21:25:36 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_prep(t_data *data)
{
	int	i;

	i = 2;
	data->biggest = find_biggest(data->stack_a);
	data->next_biggest = find_next_biggest(data);
	while (i--)
	{
		if (data->stack_a == data->biggest
			| data->stack_a == data->next_biggest)
			ra(data);
		else
		{
			pb(data);
			ra(data);
		}
	}
}

void	init_sort(t_data *data)
{
	set_stack_sizes(data);
	set_indexes(data->stack_a);
	set_indexes(data->stack_b);
	set_targets_for_b(data);
	set_push_cost(data);
	set_cheapest(data->stack_a);
}

void	set_targets_for_b(t_data *data)
{
	t_stack	*current;
	t_stack	*target_stack;
	int		next_smallest;

	current = data->stack_a;
	while (current)
	{
		next_smallest = INT_MIN;
		target_stack = data->stack_b;
		while (target_stack)
		{
			if (target_stack->value < current->value
				&& target_stack->value > next_smallest)
			{
				next_smallest = target_stack->value;
				current->target = target_stack;
			}
			target_stack = target_stack->next;
		}
		if (next_smallest == INT_MIN)
			current->target = find_biggest(data->stack_b);
		current = current->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		cheap_val;

	if (!stack)
		return ;
	cheap_val = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheap_val)
		{
			cheap_val = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	set_indexes(t_stack *stack)
{
	int		i;
	t_stack	*current;

	if (!stack)
		return ;
	current = stack;
	i = 0;
	while (current)
	{
		current->index = i;
		current->cheapest = false;
		i++;
		current = current->next;
	}
}
