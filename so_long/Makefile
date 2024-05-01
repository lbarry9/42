# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 20:07:32 by lbarry            #+#    #+#              #
#    Updated: 2023/10/27 20:44:08 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c \
			checks.c \
			path.c \
			init.c \
			moves.c \
			utils.c \
			win.c \
			destroy.c
OBJS	= $(SRCS:.c=.o)
NAME	= so_long
HEADER	= so_long.h
CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror
INCL	= -I. -I/usr/include -Imlx -Ilibft
MFLAGS	= -lmlx_Linux -lXext -lX11 -lm -lz -Lmlx -L/usr/lib
LIBFT	= libft/libft.a
PRINTF	= ft_printf/libftprintf.a
GNL		= gnl/gnl.a
MLX		= mlx/libmlx_Linux.a

all: $(NAME)

#go into libft/printf/gnl/mlx folders and make first, then make so_long
$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MFLAGS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)

$(LIBFT):
	make -C libft
	make bonus -C libft

$(PRINTF):
	make -C ft_printf

$(GNL):
	make -C gnl

$(MLX):
	make -C mlx

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C ft_printf clean
	make -C gnl clean
	make -C mlx clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean
	make -C gnl fclean

re: fclean all

.PHONY: all clean fclean re
