/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:13:31 by lbarry            #+#    #+#             */
/*   Updated: 2023/05/24 18:15:43 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	dst = s;
	i = 0;
	while (i < n)
	{
		dst[i] = c;
		i++;
	}
	return (s);
}
