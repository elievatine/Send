##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##



CC	=	gcc -g3

SRC	=	src/map_create.c	\
		src/map_changes.c	\
		src/my_put_nbr.c	\
		src/my_putchar.c	\
		src/my_putstr.c		\
		my_world.c

CFLAGS	+=	-Wall -Wextra -I./include

LIBS	=	-lc_graph_prog -lm

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

all:	$(NAME) clean

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re:	fclean all

.PHONY:	all clean fclean re
