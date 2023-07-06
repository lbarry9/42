/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:01:44 by lbarry            #+#    #+#             */
/*   Updated: 2023/07/06 15:12:32 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	make_new_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	make_new_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	clean_stash(t_list **stash, t_list **last, size_t last_size)
{
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
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

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
