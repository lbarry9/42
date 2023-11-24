/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:51:07 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 17:32:39 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_data *data, t_stack **stack, char **argv, int index)
{
	*stack = ft_lstnew(atoi(argv[index]));
	index++;
	data->stack_a_size = 1;
	while (argv[index] && argv[index][0])
	{
		ft_lstadd_back(stack, ft_lstnew(atoi(argv[index])));
		index++;
		data->stack_a_size++;
	}
	// ft_printf("stack a size = %d\n", data->stack_a_size);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
