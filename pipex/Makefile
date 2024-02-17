# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 21:34:49 by lbarry            #+#    #+#              #
#    Updated: 2024/02/05 11:26:09 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
		paths.c \
		pipex.c \
		files.c \
		utils.c
SRCS_BONUS = bonus/main_bonus.c \
		bonus/paths_bonus.c \
		bonus/pipex_bonus.c \
		bonus/files_bonus.c \
		bonus/utils_bonus.c \
		bonus/here_doc.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
NAME = pipex
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
BONUS_HEADER = bonus/pipex_bonus.h
INCLUDES = -I. -Ilibft -Iprintf -Ignl -Ibonus
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
GNL = gnl/gnl.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

$(GNL):
	make -C gnl

%.o: %.c $(HEADER) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

bonus : $(OBJS_BONUS) $(LIBFT) $(PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_BONUS) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make -C libft clean
	make -C printf clean
	make -C gnl clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean
	make -C gnl fclean

re: fclean all

.PHONY: all clean fclean re
