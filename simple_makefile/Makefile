##
## EPITECH PROJECT, 2019
## my_printf
## File description:
## makefile
##

LIB	=	$(shell find ./src -name '*.c')

USELESS	=	$(shell find -name '*~')

TEST_GCDA= $(shell find -name '*.gcda')

TEST_GCNO= $(shell find -name '*.gcno')

OBJ	=	$(LIB:.c=.o)

RM	=	rm -rf

NAME	=	libmy.a

CRITERION	=	--coverage -lcriterion

TEST    =   test

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

tests_run:
	gcc -o $(TEST) $(LIB) tests/test_my_printf.c $(CRITERION)

clean:
	$(RM) $(OBJ) $(USELESS)
	$(RM) $(TEST_GCDA) $(TEST_GCNO)

fclean: clean
	$(RM) $(NAME) $(USELESS)
	$(RM) $(TEST)

re:	fclean all

.PHONY: all clean fclean re