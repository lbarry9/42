/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:25:43 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/12 23:16:23 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;
	char			*str;

	i = 0;
	d = (unsigned char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == d)
			return (&str[i]);
		i++;
	}
	if (str[i] == d)
		return (&str[i]);
	return (0);
}
