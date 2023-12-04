/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:05:23 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 21:51:12 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_stack_b_for_pa(t_data *data)
{
	t_stack	*biggest;
	int		median;

	set_stack_sizes(data);
	set_indexes(data->stack_b);
	biggest = find_biggest(data->stack_b);
	median = data->stack_b_size / 2;
	while (data->stack_b && data->stack_b != biggest)
	{
		if (biggest->index < median)
			rb(data);
		else if (biggest->index >= median)
			rrb(data);
	}
}

void	prep_stack_a_for_pb(t_data *data, t_stack *cheapest)
{
	int	median;

	median = data->stack_a_size / 2;
	while (data->stack_a && data->stack_a != cheapest)
	{
		if (cheapest->index < median)
			ra(data);
		else if (cheapest->index >= median)
			rra(data);
	}
}

void	prep_stack_b_for_pb(t_data *data, t_stack *cheapest)
{
	int	median;

	median = data->stack_b_size / 2;
	while (data->stack_b && data->stack_b != cheapest->target)
	{
		if (cheapest->target->index < median)
			rb(data);
		else if (cheapest->target->index >= median)
			rrb(data);
	}
}

void	sort_it_out(t_data *data)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(data->stack_a);
	optimise(data, cheapest);
	prep_stack_a_for_pb(data, cheapest);
	prep_stack_b_for_pb(data, cheapest);
	pb(data);
}

void	push_swap(t_data *data)
{
	int	size;

	push_prep(data);
	size = ft_lstsize(data->stack_a) - 2;
	while (size--)
	{
		init_sort(data);
		sort_it_out(data);
	}
	prep_stack_b_for_pa(data);
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
	while (data->stack_b)
		pa(data);
}
