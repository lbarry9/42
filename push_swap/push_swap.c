/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:05:23 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/02 21:22:50 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_stack_b_for_pa(t_data *data)
{
	t_stack *biggest;
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
	t_stack *cheapest;

	cheapest = get_cheapest(data->stack_a);
	optimise(data, cheapest);
	prep_stack_a_for_pb(data, cheapest);
	prep_stack_b_for_pb(data, cheapest);
	pb(data);
}
void	init_sort(t_data *data)
{
	set_stack_sizes(data);
	set_stack_indexes(data);
	set_targets_for_b(data);
	set_push_cost(data);
	set_cheapest(data->stack_a);
}
void	push_swap(t_data *data)
{
	t_stack *biggest;
	int i;

	i = 2;
	biggest = find_biggest(data->stack_a);
	while (i--)
	{
		if (data->stack_a != biggest)
			pb(data);
		else
			ra(data);
	}
	while (data->stack_a)
	{
		init_sort(data);
		sort_it_out(data);
	}
	prep_stack_b_for_pa(data);
	while (data->stack_b)
		pa(data);
}
