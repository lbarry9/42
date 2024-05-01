/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:28:32 by lbarry            #+#    #+#             */
/*   Updated: 2023/07/05 16:13:21 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	read_and_stash(int fd, t_list **stash);
int		found_newline(t_list *stash);
t_list	*get_last_node(t_list *stash);
void	add_to_stash(t_list **stash, char *buffer, int chars_read);
void	extract_line(t_list *stash, char **line);
void	make_new_line(char **line, t_list *stash);
void	clean_stash(t_list **stash, t_list **last, size_t last_size);
void	free_stash(t_list *stash);
size_t	ft_strlen(const char *str);

#endif
