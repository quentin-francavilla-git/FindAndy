##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## M
##

SRC	=	./lib/my/*.c \
		./src/*.c \
		./src/game/*.c \
		./src/menu/*.c \
		./src/player/*.c \
		./src/levels/*.c \
		./src/util/*.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	FindAndy.exe

FLAG	=	-W -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	gcc $(SRC) csfml/*.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#.PHONY