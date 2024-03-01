# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 21:47:54 by lbarry            #+#    #+#              #
#    Updated: 2024/03/01 02:49:38 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
		philo.c \
		init.c \
		utils.c \
		philo_life.c \
		monitoring.c
OBJS = $(SRCS:.c=.o)
NAME = philo
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -pthread
HEADER = philosophers.h
INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
