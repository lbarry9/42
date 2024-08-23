# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 19:14:15 by lbarry            #+#    #+#              #
#    Updated: 2024/07/26 11:54:57 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= scavtrap
SRC		= main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= include/ClapTrap.hpp \
			include/ScavTrap.hpp
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

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
