/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:43:55 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/27 15:03:41 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, t_stack *node)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack;
	while (current)
	{
		if (current == node)
			return (index);
		index++;
		current = current->next;
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
	{
		ft_printf("stack empty\n");
		return ;
	}
	current = stack;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

void	set_stack_sizes(t_data *data)
{
	t_stack	*current;

	current = data->stack_a;
	data->stack_a_size = 0;
	while (current)
	{
		data->stack_a_size++;
		current = current->next;
	}
	current = data->stack_b;
	data->stack_b_size = 0;
	while (current)
	{
		data->stack_b_size++;
		current = current->next;
	}
}
