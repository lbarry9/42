# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 19:55:38 by marvin            #+#    #+#              #
#    Updated: 2024/07/04 14:06:14 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= moar_brainz
SRC		= main.cpp \
			src/Zombie.cpp \
			src/zombieHorde.cpp
OBJ		= $(SRC:.cpp=.o)
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
INCLUDE	= include/Zombie.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
