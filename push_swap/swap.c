/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:50:52 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 22:15:45 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	t_stack	*tmp;

	if (!data->stack_a && !data->stack_a->next)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = data->stack_a->next;
	data->stack_a->next = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_data *data)
{
	t_stack	*tmp;

	if (!data->stack_b && !data->stack_b->next)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp->next = data->stack_b->next;
	data->stack_b->next = tmp;
	ft_printf("sb\n");
}
