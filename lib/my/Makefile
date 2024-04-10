##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile (Lib)
##

SRC 	=	globals/globals_methods.c \
			input/int_to_str.c \
			input/my_getnbr.c \
			input/my_memset.c \
			input/my_strdup.c \
			input/my_strappend.c \
			input/my_strncmp.c \
			input/my_tabdup.c \
			input/my_strconcat.c \

OBJ		=	$(SRC:.c=.o)

NAME =		libmy.a

FLAGS	=	-Wall -Wextra

all: compile build header

compile:
	@echo -e "\033[1;34m#####= Compiling lib's files... =#####\e[0m"

build: $(OBJ)
	@echo -e "\033[1;34m#####= Creating library... =#####\e[0m"
	ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@cp $(NAME) ../
	@mv $(NAME) ".."

header:
	@mkdir -p ../../include
	@cp include/*.h ../../include
	@mkdir -p ../../include/lib
	@cp include/lib/*.h ../../include/lib

clean:
	rm -f $(OBJ)

fclean:
	@echo -e "\033[1;31m#####= Deleting library... =#####\e[0m"
	rm -f ../$(NAME)
	rm -f ../../$(NAME)

re:	fclean all
