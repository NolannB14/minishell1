##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/binary.c	\
		src/env_transformation.c	\
		src/features.c	\
		src/get_args.c	\
		src/reset_var.c	\
		src/minishell1.c	\
		src/builtins/cd.c	\
		src/builtins/env.c	\
		src/builtins/list_env.c	\
		src/builtins/setenv.c	\
		src/builtins/unsetenv.c	\
		src/builtins/exit.c

TEST_SRC	=	tests/tests_get_args.c	\
				tests/tests_env.c	\
				tests/tests_exit.c	\
				tests/get_env_from_file.c	\
				src/builtins/exit.c	\
				src/builtins/env.c	\
				src/builtins/list_env.c	\
				src/get_args.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

TEST_NAME	=	unit_tests

CFLAGS	=	-Wall -Werror

CPPFLAGS	=	-I ./include

LDFLAGS	=	-L ./lib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

tests_run: LDFLAGS += --coverage -lcriterion
tests_run:
	make -C lib/my
	$(CC) -o $(TEST_NAME) $(TEST_SRC) $(CPPFLAGS) $(LDFLAGS)
	./$(TEST_NAME)

clean_tests:
	make fclean -C lib/my
	rm -f *.gc*
	rm -f $(TEST_NAME)

coverage:
	gcovr --exclude tests/ && gcovr --exclude tests/ -b

clean:
	make fclean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY	=	all re fclean clean
