/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:23:28 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/27 15:49:04 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	input_check(char c, va_list *args, int *len)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), len);
	if (c == 'c')
		ft_putchar(va_arg(*args, int), len);
	if (c == 's')
		ft_putstr(va_arg(*args, char *), len);
	if (c == 'x' || c == 'X')
		ft_puthex(va_arg(*args, unsigned int), c, len);
	if (c == 'p')
		ft_putptr((unsigned long long int)va_arg(*args, void *), len);
	if (c == 'u')
		ft_u_putnbr(va_arg(*args, unsigned int), len);
	if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			input_check(str[i], &args, &len);
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
