/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:21:34 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/05 18:59:40 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// extracts chars from stash in line --> \n, checks line malloc
int	extract_line(t_stock *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL || !(make_new_line(line, stash)))
		return (0);
	if (*line == NULL)
		return (0);
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
				break ;
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
	return (1);
}

// calculates chars in line incl /n and mallocs accordingly
int	make_new_line(char **line, t_stock *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n' && stash->content[i + 1] == '\0')
				break ;
			else if (stash->content[i] == '\n' && stash->content[i + 1] != '\0')
				i++;
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (!(*line))
		return (0);
	return (1);
}

// after extracting line, clean stash --> \n
// malloc enough memory for leftover chars, stock in static stash
void	clean_stash(t_stock **stash, t_stock **last, size_t last_size)
{
	t_stock	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_stock));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	i = 0;
	while ((*last)->content[i] && (*last)->content[i] != '\n')
		i++;
	if ((*last)->content && (*last)->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (last_size - i) + 1);
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while ((*last)->content[i])
		clean_node->content[j++] = (*last)->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

// frees entire stash
void	free_stash(t_stock *stash)
{
	t_stock	*current;
	t_stock	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

size_t	line_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
