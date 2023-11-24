/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:21:51 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 17:32:49 by lbarry           ###   ########.fr       */
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
	//ft_printf("biggest = %d\n", biggest->value);
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
	//ft_printf("smallest = %d\n", smallest->value);
	return (smallest);
}

void	tiny_sort_a(t_data *data)
{
	t_stack	*smallest;
	t_stack	*biggest;
	t_stack	*end;
	t_stack	*current;

	current = data->stack_a;
	biggest = find_biggest(data->stack_a);
	smallest = find_smallest(data->stack_a);
	if (data->stack_a == biggest)
		rotate_a(data);
	end = ft_lstlast(data->stack_a);
	if (end != biggest)
		reverse_rotate_a(data);
	if (data->stack_a->value > data->stack_a->next->value)
		swap_a(data);
}
