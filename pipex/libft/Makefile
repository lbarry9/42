
SRCS	=		ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c

OBJS	= $(SRCS:.c=.o)
NAME	= libft.a
CC		= cc -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c libft.h
	$(CC) -I. -c $< -o $@

$(NAME): $(OBJS) libft.h
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
