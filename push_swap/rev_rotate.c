/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:12:39 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 15:04:54 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (!data->stack_a || !data->stack_a->next)
		return ;
	rev_rotate_a(data);
	ft_printf("rra\n");
}

void	rev_rotate_a(t_data *data)
{
	t_stack	*old_last;
	t_stack	*new_last;

	old_last = ft_lstlast(data->stack_a);
	new_last = data->stack_a;
	while (new_last->next != old_last)
		new_last = new_last->next;
	new_last->next = NULL;
	old_last->next = data->stack_a;
	data->stack_a = old_last;
}

void	rrb(t_data *data)
{
	if (!data->stack_b || !data->stack_b->next)
		return ;
	rev_rotate_b(data);
	ft_printf("rrb\n");
}

void	rev_rotate_b(t_data *data)
{
	t_stack	*old_last;
	t_stack	*new_last;

	old_last = ft_lstlast(data->stack_b);
	new_last = data->stack_b;
	while (new_last->next != old_last)
		new_last = new_last->next;
	new_last->next = NULL;
	old_last->next = data->stack_b;
	data->stack_b = old_last;
}

void	rrr(t_data *data)
{
	rev_rotate_a(data);
	rev_rotate_b(data);
	ft_printf("rrr\n");
}
