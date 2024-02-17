/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:03:56 by lbarry            #+#    #+#             */
/*   Updated: 2024/01/31 21:11:26 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursive_ptr(unsigned long long int nbr, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_recursive_ptr(nbr / 16, len);
		ft_recursive_ptr(nbr % 16, len);
	}
	if (nbr < 16)
	{
		write(2, &base[nbr], 1);
		(*len)++;
	}
}

void	ft_putptr(unsigned long long int nbr, int *len)
{
	if (nbr == 0)
	{
		write(2, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	else
	{
		write(2, "0x", 2);
		(*len) += 2;
		ft_recursive_ptr(nbr, len);
	}
}
