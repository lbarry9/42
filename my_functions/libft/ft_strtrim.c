/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:56:54 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/12 23:25:47 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*new;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_calloc(0, 0));
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) != 0)
		start++;
	while (ft_strchr(set, s1[end]) != 0)
	{
		if (end <= start)
			return (ft_strdup(""));
		end--;
	}
	new = ft_substr(s1, start, end + 1 - start);
	return (new);
}
