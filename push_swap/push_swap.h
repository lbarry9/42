/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:10:17 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 21:32:06 by lbarry           ###   ########.fr       */
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
	t_stack	*biggest;
	t_stack	*next_biggest;
	int		stack_a_size;
	int		stack_b_size;
	int		a_median;
	int		b_median;
}					t_data;

void	choose_sort(t_data *data);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_next_biggest(t_data *data);
t_stack	*find_smallest(t_stack *stack);
int		find_index(t_stack *stack, t_stack *node);
void	tiny_sort_a(t_data *data);
void	small_sort(t_data *data);
void	choose_rotate(t_data *data, t_stack *smallest);
void	print_stack(t_stack *stack);
void	set_stack_sizes(t_data *data);
void	free_args(char **args);
void	init_stack(t_data *data, t_stack **stack_a, char **argv, int index);
void	free_stack(t_stack *stack);
void	sa(t_data *data);
void	sb(t_data *data);
void	rev_rotate_a(t_data *data);
void	rev_rotate_b(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	pb(t_data *data);
void	pa(t_data *data);
int		check_args(char **args, int index);
int		manage_args(int *argc, char *arg, t_data *data);
int		check_duplicates(char **args, int index);
int		check_chars(char **arg, int index);
int		check_sorted(char **args, int index);
int		check_max_min(char **args, int index);
void	push_swap(t_data *data);
void	push_prep(t_data *data);
void	init_sort(t_data *data);
void	sort_it_out(t_data *data);
void	set_indexes(t_stack *stack);
void	set_targets_for_b(t_data *data);
void	set_push_cost(t_data *data);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	optimise(t_data *data, t_stack *cheapest);
int		rr_rounds(t_stack *cheapest);
int		rrr_rounds(t_data *data, t_stack *cheapest);
void	prep_stack_a_for_pb(t_data *data, t_stack *cheapest);
void	prep_stack_b_for_pb(t_data *data, t_stack *cheapest);
void	prep_stack_b_for_pa(t_data *data);

#endif
