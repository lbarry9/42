/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:58:47 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/12 23:16:32 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	strlen;

	strlen = ft_strlen(s);
	str = (char *)malloc((strlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	else
		ft_strlcpy(str, s, (strlen + 1));
	str[strlen] = '\0';
	return (str);
}
