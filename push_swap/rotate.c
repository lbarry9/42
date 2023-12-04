/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:18:43 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 15:04:42 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (!data->stack_a || !data->stack_a->next)
		return ;
	rotate_a(data);
	ft_printf("ra\n");
}

void	rotate_a(t_data *data)
{
	t_stack	*old_first;
	t_stack	*tmp;

	old_first = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp = ft_lstlast(data->stack_a);
	tmp->next = old_first;
	old_first->next = NULL;
}

void	rb(t_data *data)
{
	if (!data->stack_b || !data->stack_b->next)
		return ;
	rotate_b(data);
	ft_printf("rb\n");
}

void	rotate_b(t_data *data)
{
	t_stack	*old_first;
	t_stack	*tmp;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	old_first = data->stack_b;
	data->stack_b = data->stack_b->next;
	tmp = ft_lstlast(data->stack_b);
	tmp->next = old_first;
	old_first->next = NULL;
}

void	rr(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
	ft_printf("rr\n");
}
