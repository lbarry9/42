/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:29:10 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/12 23:15:09 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*bufsrc;
	char	*bufdst;
	size_t	i;

	bufsrc = (char *)src;
	bufdst = (char *)dst;
	i = 0;
	if (dst != src)
	{
		while (i < n)
		{
			bufdst[i] = bufsrc[i];
			i++;
		}
	}
	return (dst);
}
