# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 14:15:56 by lbarry            #+#    #+#              #
#    Updated: 2023/11/24 20:51:12 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c \
			tiny.c \
			small.c \
			swap.c \
			push.c \
			rotate.c \
			memory.c \
			checks.c \
			push_swap.c \
			utils.c

OBJS	= ${SRCS:.c=.o}
NAME	= push_swap
HEADER	= push_swap.h
CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror
PRINTF	= ft_printf/libftprintf.a
LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

$(PRINTF):
	make -C ft_printf

$(LIBFT):
	make -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f $(OBJS)
	make -C ft_printf clean
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
