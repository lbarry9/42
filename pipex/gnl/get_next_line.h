/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:28:32 by lbarry            #+#    #+#             */
/*   Updated: 2024/02/10 18:17:08 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_stock
{
	char			*content;
	struct s_stock	*next;
}					t_stock;

char		*get_next_line(int fd, int flag);
int			read_and_stash(int fd, t_stock **stash);
int			found_newline(t_stock *stash);
t_stock		*get_last_node(t_stock *stash);
void		add_to_stash(t_stock **stash, char *buffer, int chars_read);
int			extract_line(t_stock *stash, char **line);
int			make_new_line(char **line, t_stock *stash);
void		clean_stash(t_stock **stash, t_stock **last, size_t last_size);
void		free_stash(t_stock *stash);
size_t		line_len(const char *str);
char		*end_of_heredoc(t_stock *stash);
char		*end_of_doc(t_stock *stash, char *line);

#endif
