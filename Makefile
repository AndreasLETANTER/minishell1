##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for eval_expr
##

SRC	=	src/*.c \
		src/commands/*.c

NEW_SRC = 	src/analyze_input.c \
			src/env.c \
			src/execute_command.c \
			src/my_sh.c \
			src/new_env.c \
			src/sig_hander.c \
			src/split_string.c \
			src/tool.c \
			src/commands/cd.c \
			src/commands/setenv_tools.c \
			src/commands/setenv.c \
			src/commands/unsetenv.c

TESTS_SRC = tests/*.c

NAME	=	mysh

LIB	=	-L./lib/my -lmy

CFLAGS = -Iinclude

TESTS_FLAGS = --coverage -lcriterion

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	make makelib
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LIB)

makelib:
	make -C ./lib/my

clean:
	rm -f *~
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re:	fclean all

unit_tests: fclean makelib
	make clean
	gcc -o unit_tests $(TESTS_SRC) $(NEW_SRC) $(CFLAGS) $(LIB) $(TESTS_FLAGS)
	./unit_tests
	make coverage
	make branch_coverage

coverage:
	gcovr --exclude tests

branch_coverage:
	gcovr -b --exclude tests

push:
	make fclean
	git add .
	@read -p "Give a commit message " TAG \
    && git commit -m "$${TAG}"
	git push

.PHONY: all makelib clean fclean re
