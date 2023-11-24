/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:50:51 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 22:02:13 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_value_index(t_stack *stack, int value)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack;
	while (current)
	{
		if (current->value == value)
			return (index);
		index++;
		current = current->next;
	}
	return (0);
}

void	choose_rotate(t_data *data, t_stack *smallest)
{
	int		smallest_position;

	smallest_position = find_value_index(data->stack_a, smallest->value) + 1;
	//ft_printf("smallest position = %d\n", smallest_position);
	while (data->stack_a)
	{
		if (data->stack_a != smallest && smallest_position <= (data->stack_a_size / 2))
			rotate_a(data);
		if (data->stack_a != smallest && smallest_position > (data->stack_a_size / 2))
			reverse_rotate_a(data);
		if (data->stack_a == smallest)
		{
			push_b(data);
			return ;
		}
	}
}

void	small_sort(int argc, t_data *data)
{
	t_stack	*smallest;
	t_stack	*biggest;

	smallest = find_smallest(data->stack_a);
	choose_rotate(data, smallest);
	if (argc == 6)
	{
		smallest = find_smallest(data->stack_a);
		choose_rotate(data, smallest);
	}
	tiny_sort_a(data);
	biggest = find_biggest(data->stack_b);
	// while (data->stack_b)
	// {
	// 	if (data->stack_b != biggest)
	// 		rotate_b(data);
	// 	if (data->stack_b == biggest)
	// 		break ;
	// }
	push_a(data);
	if (argc == 6)
		push_a(data);
}
