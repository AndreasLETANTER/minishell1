##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME	=	libmy.a

COMP	=	gcc

DEL	=	rm -f

SRC	=	*.c

OBJ	=	$(SRC:.c=o)

all:	$(NAME)

$(NAME):
	$(COMP) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	make clean

clean:
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all
