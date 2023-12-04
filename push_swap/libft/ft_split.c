/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:50:28 by lbarry            #+#    #+#             */
/*   Updated: 2023/12/04 15:38:25 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf/ft_printf.h"

size_t	count_str(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			i = j;
			count++;
		}
		if (s[i] == '\0' && count == 0)
			return (0);
	}
	return (count);
}

static void	clear_arr(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (index > 0)
		free(arr[index--]);
	free(arr);
	ft_printf("Error\n");
	exit(1);
}

static char	**make_arr(char const *s, char **arr, char c)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			arr[index] = ft_substr(s, i, j - i);
			if (!arr[index])
				clear_arr(arr, index);
			i = j;
			index++;
		}
		if (s[i] == '\0' && index == 0)
			clear_arr(arr, index);
	}
	arr[index] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		str_count;

	arr = NULL;
	str_count = count_str(s, c);
	if (!s || !str_count)
		return (0);
	arr = ft_calloc((str_count + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	make_arr(s, arr, c);
	return (arr);
}
