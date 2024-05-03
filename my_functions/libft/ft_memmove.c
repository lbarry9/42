/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:30:17 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/12 23:15:17 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*bufsrc;
	char	*bufdst;

	if (!src && !dst)
		return (0);
	if (src > dst)
		dst = ft_memcpy(dst, src, n);
	else
	{
		bufsrc = (char *)src;
		bufdst = (char *)dst;
		while (n--)
			bufdst[n] = bufsrc[n];
	}
	return (dst);
}
