/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:10:51 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/12 23:20:13 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	if ((!dst || !src) && size == 0)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (size <= dstlen)
		return (size + srclen);
	while (src[i] && (dstlen + i) < (size - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
		dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
