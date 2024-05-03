/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:16:06 by lbarry            #+#    #+#             */
/*   Updated: 2023/05/24 14:17:09 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	if (!s || fd < 0)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}
