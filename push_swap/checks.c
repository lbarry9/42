/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:21:40 by lbarry            #+#    #+#             */
/*   Updated: 2023/11/27 15:02:41 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_min(char **args, int argc, int index)
{
	while (index < argc)
	{
		if (ft_strlen(args[index]) > 12)
			return (0);
		if (ft_atoi(args[index]) > INT_MAX || ft_atoi(args[index]) < INT_MIN)
			return (0);
		index++;
	}
	return (1);
}

int	check_chars(char **args, int index)
{
	int	j;

	while (args[index])
	{
		j = 0;
		if (args[index][j] == '-' || args[index][j] == '+')
			j++;
		while (args[index][j])
		{
			if (!ft_isdigit(args[index][j]))
				return (0);
			j++;
		}
		index++;
	}
	return (1);
}

int	check_duplicates(char **args, int index)
{
	int	j;

	while (args[index])
	{
		j = index + 1;
		while (args[j])
		{
			if (ft_atoi(args[index]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		index++;
	}
	return (1);
}

int	check_sorted(char **args, int index)
{
	while (args[index + 1])
	{
		if (ft_atoi(args[index]) > ft_atoi(args[index + 1]))
			return (1);
		index++;
	}
	return (0);
}

int	check_args(char **args, int argc, int index)
{
	if (!check_chars(args, index))
	{
		ft_printf("Error chars\n");
		return (0);
	}
	if (!check_max_min(args, argc, index))
	{
		ft_printf("Error max min\n");
		return (0);
	}
	if (!check_duplicates(args, index))
	{
		ft_printf("Error dups\n");
		return (0);
	}
	if (!check_sorted(args, index))
	{
		ft_printf("Error sorted\n");
		return (0);
	}
	return (1);
}
