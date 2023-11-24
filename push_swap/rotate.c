/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:18:43 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 23:18:04 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	t_stack	*old_first;
	t_stack	*new_first;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	// stock first node
	old_first = data->stack_a;
	// move list along one
	data->stack_a = data->stack_a->next;
	// find end (lstlast)
	new_first = ft_lstlast(data->stack_a);
	// set end->next to first node
	new_first->next = old_first;
	// null terminate new end node
	old_first->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_data *data)
{
	t_stack	*old_first;
	t_stack	*new_first;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	old_first = data->stack_b;
	data->stack_b = data->stack_b->next;
	new_first = ft_lstlast(data->stack_b);
	new_first->next = old_first;
	old_first->next = NULL;
	ft_printf("rb\n");
}

void	reverse_rotate_a(t_data *data)
{
	t_stack	*old_last;
	t_stack	*new_last;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	// find last node
	old_last = ft_lstlast(data->stack_a);
	// find second to last node
	new_last = data->stack_a;
	while (new_last->next != old_last)
		new_last = new_last->next;
	// set second to last node's next to NULL
	new_last->next = NULL;
	// set last node's next to first node
	old_last->next = data->stack_a;
	// set stack_a to last node
	data->stack_a = old_last;
	printf("rra\n");
}

void	reverse_rotate_b(t_data *data)
{
	t_stack	*old_last;
	t_stack	*new_last;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	old_last = ft_lstlast(data->stack_b);
	new_last = data->stack_b;
	while (new_last->next != old_last)
		new_last = new_last->next;
	new_last->next = NULL;
	old_last->next = data->stack_b;
	data->stack_b = old_last;
	printf("rrb\n");
}
