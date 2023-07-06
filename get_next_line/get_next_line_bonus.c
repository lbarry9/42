/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:47:55 by lbarry            #+#    #+#             */
/*   Updated: 2023/07/06 15:12:24 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// create static array of pointers to t_lists, fd is index
char	*get_next_line(int fd)
{
	static t_list	*stash[1024];
	char			*line;
	t_list			*last;
	size_t			last_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_and_stash(fd, &stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	extract_line(stash[fd], &line);
	last = get_last_node(stash[fd]);
	last_size = ft_strlen(last->content);
	clean_stash(&stash[fd], &last, last_size);
	if (line[0] == '\0')
	{
		free_stash(stash[fd]);
		stash[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_stash(int fd, t_list **stash)
{
	char	*buffer;
	int		chars_read;

	chars_read = 1;
	while (!found_newline(*stash) && chars_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		chars_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*stash == NULL && chars_read == 0) || chars_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[chars_read] = '\0';
		add_to_stash(stash, buffer, chars_read);
		free(buffer);
	}
}

int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	current = get_last_node(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_last_node(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	add_to_stash(t_list **stash, char *buffer, int chars_read)
{
	int		i;
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (chars_read + 1));
	if (new->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < chars_read)
	{
		new->content[i] = buffer[i];
		i++;
	}
	new->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new;
		return ;
	}
	last = get_last_node(*stash);
	last->next = new;
}
