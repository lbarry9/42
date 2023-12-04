/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:50:51 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 15:08:24 by lbarry           ###   ########.fr       */
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
