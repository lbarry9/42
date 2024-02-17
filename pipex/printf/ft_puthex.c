/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:06:07 by lbarry            #+#    #+#             */
/*   Updated: 2024/01/31 21:11:05 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long long int nbr, char c, int *len)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, c, len);
		ft_puthex(nbr % 16, c, len);
	}
	if (nbr < 16)
	{
		write(2, &base[nbr], 1);
		(*len)++;
	}
}
