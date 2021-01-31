##
## EPITECH PROJECT, 2018
## makefile
## File description:
## 
##

SRC	=	my_put_nbr.c \
		my_putstr.c \
		my_putchar.c \
		my_getnbr.c \
		my_strcmp.c \
		my_strlen.c \
		my_strcat.c \
		my_revstr.c \
		my_strcpy.c \
		my_memset.c \
		my_strncmp.c \
		my_strncpy.c \
		my_str_to_wordtab.c \
		my_itoa.c \
		my_convert_char_int.c \
		my_getnbr_base.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp $(NAME) ../$(NAME)
	cp lib.h ../../include/lib.h
	rm -f       my_putchar.o \
                my_put_nbr.o \
                my_putstr.o \
				my_getnbr.o \
				my_strcmp.o \
				my_strlen.o \
				my_strcat.o \
				my_revstr.o \
				my_strcpy.o \
				my_memset.o \
				my_strncmp.o \
				my_strncpy.o \
				my_str_to_wordtab.o \
				my_itoa.o \
				my_convert_char_int.o \
				my_getnbr_base.o \

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *~

fclean:	clean
	rm -f $(NAME)
	rm -f *.o

re:	fclean all
