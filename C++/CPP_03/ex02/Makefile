# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 19:14:15 by lbarry            #+#    #+#              #
#    Updated: 2024/07/27 12:01:52 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fragtrap
SRC		= main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= include/ClapTrap.hpp \
			include/ScavTrap.hpp \
			include/FragTrap.hpp
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
