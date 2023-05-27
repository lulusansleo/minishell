##
## EPITECH PROJECT, 2022
## navy Makefile
## File description:
## compiles and builds lib and the source files runs unit tests
##

NAME		=	mysh

SRC			=	source/shell.c \
				source/free_them_memories.c \
				source/shelltwo.c \
				source/shellthree.c \
				source/builtin.c \
				source/builtin_env.c \

SRC_MAIN	=	source/main.c

CPPFLAGS = -Wall -Wextra -I./include/ -g3

OBJ	=	$(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

LIB 	=	-lmy

DIR	=	-L./lib/

TESTS = ##tests/

TEST_OBJ = $(TESTS:.c=.o)

LIB_TEST = libutest.a

TEST_INCLUDE = -L./ -lmy --coverage -lcriterion

TEST_NAME = unit_test

all: $(OBJ) $(OBJ_MAIN)
	$(MAKE) -C ./lib/my
	gcc -g3 -o $(NAME) $(OBJ) $(OBJ_MAIN) $(DIR) $(LIB)

clean:
	rm -f $(OBJ) $(OBJ_MAIN)
	$(MAKE) clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my

re: fclean all

unit_tests: fclean $(OBJ) $(TEST_OBJ)
		$(MAKE) -C ./lib/my
		$(MAKE) -C ./lib/printf
		ar rc $(LIB_TEST) $(OBJ)
		gcc -o $(TEST_NAME) $(TESTS) $(TEST_INCLUDE)

tests_run: unit_tests
			./$(TEST_NAME)

unit_clean: fclean
			rm -f $(LIB_TEST)
			rm -f unit_test*
			rm -f (TEST_OBJ)

.PHONY: all makelib clean fclean re
