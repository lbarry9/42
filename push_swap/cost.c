/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:12:19 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 15:26:52 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr_rounds(t_stack *cheapest)
{
	int	i;

	if (cheapest->index < cheapest->target->index)
		i = cheapest->index;
	else
		i = cheapest->target->index;
	return (i);
}

int	rrr_rounds(t_data *data, t_stack *cheapest)
{
	int	i;
	int	a_size;
	int	b_size;

	a_size = data->stack_a_size;
	b_size = data->stack_b_size;
	if ((a_size - cheapest->index) < (b_size - cheapest->target->index))
		i = a_size - cheapest->index;
	else
		i = b_size - cheapest->target->index;
	return (i);
}

void	optimise(t_data *data, t_stack *cheapest)
{
	int	rr_dif;
	int	rrr_dif;
	int	a_median;
	int	b_median;

	if (cheapest->push_cost < 1)
		return ;
	if (cheapest->index < 1 | cheapest->target->index < 1)
		return ;
	a_median = data->stack_a_size / 2;
	b_median = data->stack_b_size / 2;
	rr_dif = 0;
	rrr_dif = 0;
	if (cheapest->index < a_median && cheapest->target->index < b_median)
	{
		rr_dif = rr_rounds(cheapest);
		while (rr_dif--)
			rr(data);
	}
	else if (cheapest->index >= a_median && cheapest->target->index >= b_median)
	{
		rrr_dif = rrr_rounds(data, cheapest);
		while (rrr_dif--)
			rrr(data);
	}
}

void	set_push_cost(t_data *data)
{
	t_stack	*current;
	int		a_cost;
	int		b_cost;

	current = data->stack_a;
	a_cost = 0;
	b_cost = 0;
	while (current)
	{
		if (current == data->biggest | current == data->next_biggest)
			current->push_cost = INT_MAX;
		else
		{
			if (current->index < data->a_median)
				a_cost = current->index;
			else if (current->index >= data->a_median)
				a_cost = data->stack_a_size - current->index;
			if (current->target->index < data->b_median)
				b_cost = current->target->index;
			else if (current->target->index >= data->b_median)
				b_cost = data->stack_b_size - current->target->index;
			current->push_cost = a_cost + b_cost;
		}
		current = current->next;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}
