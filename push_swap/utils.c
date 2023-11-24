/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:43:55 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 21:36:02 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
	{
		//ft_printf("stack empty\n");
		return ;
	}
	current = stack;
	//ft_printf("printing stack\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

void	set_stack_size(t_stack *stack, int *size)
{
	t_stack	*current;

	current = stack;
	*size = 0;
	while (current)
	{
		(*size)++;
		current = current->next;
	}
}
