# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 17:59:28 by lbarry            #+#    #+#              #
#    Updated: 2024/02/10 18:00:24 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
			get_next_line_utils.c \
			end_of_docs.c

OBJS	= $(SRCS:.c=.o)
NAME	= gnl.a
CC		= cc -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c get_next_line.h
	$(CC) -I. -c $< -o $@

$(NAME): $(OBJS) get_next_line.h
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
