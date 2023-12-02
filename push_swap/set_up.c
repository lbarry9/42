/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:04:59 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/02 21:18:00 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_targets_for_b(t_data *data)
{
	t_stack	*current;
	t_stack *target_stack;
	int		next_smallest;

	current = data->stack_a;
	while (current)
	{
		next_smallest = INT_MIN;
		target_stack = data->stack_b;
		while (target_stack)
		{
			if (target_stack->value < current->value && target_stack->value > next_smallest)
			{
				next_smallest = target_stack->value;
				current->target = target_stack;
			}
			target_stack = target_stack->next;
		}
		if (next_smallest == INT_MIN)
			current->target = find_biggest(data->stack_b);
		//ft_printf("current: %d, target: %d\n", current->value, current->target->value);
		current = current->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack *cheapest_node;
	int		cheap_val;

	if (!stack)
	{
		ft_printf("stack empty\n");
		return ;
	}
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
	int		median;

	median = ft_lstsize(stack) / 2;
	if (!stack)
	{
		ft_printf("stack empty\n");
		return ;
	}
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

void	set_stack_indexes(t_data *data)
{
	set_indexes(data->stack_a);
	set_indexes(data->stack_b);
}
