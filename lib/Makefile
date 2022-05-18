##
## EPITECH PROJECT, 2021
## makefile
## File description:
## Compil programme for project my_printf
##

SRC	=	tools/tools.c	\
		my_strlen.c	\
		my_strcat.c	\
		move_rect.c	\
		add_tab_int.c	\
		set_texture.c	\
		my_itoa.c	\
		my_getnbr.c	\
		my_strcpy.c	\
		my_strcmp.c	\
		create_array_int.c	\
		create_tab.c	\
		create_str_int.c	\
		my_atoi.c	\
		is_point_in_circle.c	\
		f_get_rand.c

SRC_FILES	=	files/open_file.c	\
				files/read_file_wo_stat.c	\

SRC_CSFML	=	CSFML/set_texture_sprite.c	\
				CSFML/set_rect.c	\
				CSFML/move_rect.c	\
				CSFML/create_sprite.c	\
				CSFML/create_object.c	\
				CSFML/find_player_in_array.c

OBJ	=	$(SRC:.c=.o) $(SRC_CSFML:.c=.o) $(SRC_FILES:.c=.o)

NAME	=	libmy.a

CPPFLAGS = -Wall -Wextra

CPPFLAGS = -I../includes -g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C array2/
	ar rc $(NAME) $(OBJ)

clean:
	$(MAKE) clean -C array2/
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C array2/
	rm -f $(NAME)

debug: CPPFLAGS += -g
debug: re

re: fclean all
	$(MAKE) re -C array2/

.PHONY:	all clean fclean re
