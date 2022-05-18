##
## EPITECH PROJECT, 2022
## Makefile_arrya
## File description:
## Makefile
##

SRC	=	my_array_len.c	\
		my_arraycpy.c	\
		my_free_array.c	\
		put_str_to_word_array.c	\
		my_str_to_word_array/get_array.c	\
		my_str_to_word_array/my_str_to_word_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS	=	-I includes -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY:	all clean fclean re
