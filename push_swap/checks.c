/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:21:40 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 23:01:26 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_min(char **args, int index)
{
	while (args[index])
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
		{
			j++;
			if (!ft_isdigit(args[index][j]))
				return (0);
		}
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

int	check_args(char **args, int index)
{
	if (!check_chars(args, index))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_max_min(args, index))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_duplicates(args, index))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_sorted(args, index))
		return (0);
	return (1);
}
