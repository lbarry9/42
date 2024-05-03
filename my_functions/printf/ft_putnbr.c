/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:05:36 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/23 13:12:10 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	char			c;
	long long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		(*len)++;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
		(*len)++;
	}
}
