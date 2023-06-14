/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:01:22 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/12 23:17:09 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)ft_calloc(1, (sizeof(char) * (s1len + s2len + 1)));
	if (!str)
		return (NULL);
	i = -1;
	while (i++, s1[i])
		str[i] = s1[i];
	j = -1;
	while (j++, s2[j])
	{
		str[i] = s2[j];
		i++;
	}
	return (str);
}
