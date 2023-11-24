/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:10:17 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/24 23:17:22 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		stack_a_size;
	int		stack_b_size;
}					t_data;

t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
void	tiny_sort_a(t_data *data);
void	small_sort(int argc, t_data *data);
int		find_index(t_stack *stack, int value);
void	choose_rotate(t_data *data, t_stack *smallest);
void	print_stack(t_stack *stack);
void	set_stack_size(t_stack *stack, int *size);
void	free_args(char **args);
void	init_stack(t_data *data, t_stack **stack_a, char **argv, int index);
void	free_stack(t_stack *stack);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	push_b(t_data *data);
void	push_a(t_data *data);
int		check_args(char **args, int argc, int index);
int		manage_args(int *argc, char *arg, t_data *data);
int		check_duplicates(char **args, int index);
int		check_chars(char **arg, int index);
int		check_sorted(char **args, int index);
void	push_swap(t_data *data);
void	set_indexes_above_median(t_stack *stack, int median);
void	set_target_in_b(t_data *data);
void	set_push_cost(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	prep_stacks_for_pb(t_data *data);

#endif
