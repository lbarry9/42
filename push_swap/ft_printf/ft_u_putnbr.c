/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:58:14 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/23 13:12:37 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_putnbr(unsigned int n, int *len)
{
	char					c;
	unsigned long long int	nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_u_putnbr(nbr / 10, len);
		ft_u_putnbr(nbr % 10, len);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
		(*len)++;
	}
}
