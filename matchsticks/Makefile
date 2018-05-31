##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC =	-gcc

SRC		=	./src/tab.c \
			./src/my_putchar.c \
			./src/my_putstr.c \
			./src/my_put_nbr.c \
			./src/error_gestion.c \
			./src/my_strlen.c \
			./src/my_atoi.c \
			./src/get_next_line.c\
			./src/game_loop.c

LIBS	=	libs/libmy.a

OBJ		=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	+=	-I./include -Wextra -Wall -g3 -ofast

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o  $(NAME) $(OBJ) $(LIBS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

