/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:55:22 by lbarry            #+#    #+#             */
/*   Updated: 2023/05/24 18:14:30 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*ptr;

	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = 1;
	}
	if (nelem != 0 && nelem * elsize / elsize != nelem)
		return (0);
	ptr = malloc(nelem * elsize);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (nelem * elsize));
	return ((void *)ptr);
}
