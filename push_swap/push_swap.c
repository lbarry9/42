/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:05:23 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 17:36:53 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 // loop round real lists?
void	set_target_in_b(t_data *data)
{
	t_stack	*current;
	t_stack *target_stack;
	int		next_smallest;

	// ft_printf("setting target in b\n");
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
		// ft_printf("target for %d is %d\n", current->value, current->target->value);
		current = current->next;
	}
}

void	set_push_cost(t_stack *stack)
{
	t_stack *current;

	current = stack;
	while (current)
	{
		current->push_cost = current->index + current->target->index;
		// ft_printf("push cost = %d\n", current->push_cost);
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
			// ft_printf("current cheapest push cost: %d\n", cheap_val);
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack *current;

	if (!stack)
	{
		ft_printf("stack empty\n");
		return (NULL);
	}
	current = stack;
	while (current)
	{
		if (current->cheapest)
		{
			// ft_printf("cheapest node: %d\n", current->value);
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

void	prep_stacks_for_pb(t_data *data)
{
	t_stack *cheapest;

	if (!get_cheapest(data->stack_a))
	{
		ft_printf("no cheapest, error prep\n");
		return ;
	}
	cheapest = get_cheapest(data->stack_a);
	while (data->stack_a && data->stack_a != cheapest)
	{
		if (data->stack_a->above_median)
			rotate_a(data);
		else if (!data->stack_a->above_median)
			reverse_rotate_a(data);
		else
			return ;
	}
	while (data->stack_b && data->stack_b != cheapest->target)
	{
		if (data->stack_b->above_median)
			rotate_b(data);
		else if (data->stack_b->above_median)
			reverse_rotate_b(data);
		else
			return ;
	}
}

void	set_indexes_above_median(t_stack *stack, int median)
{
	int		i;
	t_stack	*current;

	if (!stack)
	{
		ft_printf("stack empty\n");
		return ;
	}
	current = stack;
	i = 0;
	// ft_printf("median = %d\n", median);
	while(current)
	{
		current->index = i;
		// ft_printf("index %d = %d\n", current->index, current->value);
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		// ft_printf("above median %d\n", current->above_median);
		current = current->next;
		i++;
	}
}

void	push_swap(t_data *data)
{
	int	stack_len;

	push_b(data);
	push_b(data);
	set_stack_size(data->stack_a, &data->stack_a_size);
	stack_len = data->stack_a_size;
	while (stack_len-- > 0)
	{
		// ft_printf("STACK LENNNN: %d\n", stack_len);
		set_stack_size(data->stack_a, &data->stack_a_size);
		set_indexes_above_median(data->stack_a, data->stack_a_size / 2);
		set_stack_size(data->stack_b, &data->stack_b_size);
		set_indexes_above_median(data->stack_b, data->stack_b_size / 2);
		set_target_in_b(data);
		set_push_cost(data->stack_a);
		set_cheapest(data->stack_a);
		// print_stack(data->stack_a);
		// print_stack(data->stack_b);
		// ft_printf("before prep\n");
		prep_stacks_for_pb(data);
		// ft_printf("after prep\n");
		// opti (cost analysis_a)
		push_b(data);
	}
	//tiny_sort_a(data);
}
