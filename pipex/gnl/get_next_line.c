/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:12:17 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/10 18:16:12 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// read file, add chars to linked list, extract line from stash, clean up stash
// check if overread file and last extracted line is empty
char	*get_next_line(int fd, int flag)
{
	static t_stock	*stash = NULL;
	char			*line;
	t_stock			*last;
	size_t			last_size;

	if (flag == 1)
		return (end_of_heredoc(stash));
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_and_stash(fd, &stash))
		return (NULL);
	if (stash == NULL)
		return (NULL);
	if (!extract_line(stash, &line))
		return (NULL);
	last = get_last_node(stash);
	last_size = line_len(last->content);
	clean_stash(&stash, &last, last_size);
	if (line[0] == '\0')
		return (end_of_doc(stash, line));
	return (line);
}

// reads BUFFER_SIZE until finds '\n' stocking in buffer
// sends stash and buffer to add_to_stash, frees buffer ready for next read
int	read_and_stash(int fd, t_stock **stash)
{
	char	*buffer;
	int		chars_read;

	chars_read = 1;
	while (!found_newline(*stash) && chars_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (0);
		chars_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*stash == NULL && chars_read == 0) || chars_read == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[chars_read] = '\0';
		add_to_stash(stash, buffer, chars_read);
		free(buffer);
	}
	return (1);
}

// Looks for \n in stash- to know how many times to read BUFFER_SIZE
// uses get_last_node to go to latest stash of BUFFER_SIZE
int	found_newline(t_stock *stash)
{
	int		i;
	t_stock	*current;

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

// returns pointer to most recently added node
t_stock	*get_last_node(t_stock *stash)
{
	t_stock	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

// add content of buffer after each read to end of stash
// initialises and mallocs new list and its content
void	add_to_stash(t_stock **stash, char *buffer, int chars_read)
{
	int		i;
	t_stock	*last;
	t_stock	*new;

	new = malloc(sizeof(t_stock));
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
