# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 19:14:15 by lbarry            #+#    #+#              #
#    Updated: 2024/08/07 21:15:31 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= diamondtrap
SRC		= main.cpp \
			src/ClapTrap.cpp \
			src/ScavTrap.cpp \
			src/FragTrap.cpp \
			src/DiamondTrap.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= include/ClapTrap.hpp \
			include/ScavTrap.hpp \
			include/FragTrap.hpp \
			include/DiamondTrap.hpp
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -Wshadow

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
