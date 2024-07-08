# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 19:55:38 by marvin            #+#    #+#              #
#    Updated: 2024/07/04 16:02:16 by lbarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= attack
SRC		= main.cpp \
			src/Weapon.cpp \
			src/HumanA.cpp \
			src/HumanB.cpp
OBJ		= $(SRC:.cpp=.o)
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
INCLUDE = include/Weapon.hpp \
			include/HumanA.hpp \
			include/HumanB.hpp

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
