##
## EPITECH PROJECT, 2019
## my_printf
## File description:
## makefile
##

#COMMANDS
MAKE_CLEAN		=	make clean
MAKE_FCLEAN		=	make fclean
RM				=	rm -rf

#COLOR
RED				=	\e[31m
GREEN			=	\e[32m
YELLOW			=	\e[33m
DEFAULT			=	\e[0m
BOLD			=	\e[1m

#DIR
INC_DIR			=	./include/
SRC_DIR			=	./src/
LIB_DIR 		=	./lib/my
LIB				=	-sC lib/my

#TEXT
COMPILE			=	$$'$(BOLD)$(GREEN)[ Compiled the project ! ]\t$(DEFAULT)'
RE_COMPILE		=	$$'$(BOLD)$(GREEN)[ Recompiled the project ! ]\t$(DEFAULT)'
TEST_RUN		= 	$$'$(BOLD)$(GREEN)[ Running Test ...]$(DEFAULT)'
CLEAN			=	$$'$(BOLD)$(RED)[ Removing object files in [$(LIB_DIR)]... }\t$(DEFAULT)'
FCLEAN			=	$$'$(BOLD)$(RED)[ Removing binary... ]\t$(DEFAULT)'
FILES_REMOVED	=   $$'$(BOLD)$(RED)[ Removing object files in [$(SRC_DIR)]... ]$(DEFAULT)'

#COMPILE TOOLS
LIFLAGS			=	-I $(INC_DIR) -L $(LIB_DIR) -lmy
CRITERION		=	--coverage -lcriterion
LDFLAGS			=	-Wall -Wextra -Werror -std=c99
USELESS			=	$(shell find . -type f -name "*~" -o -name "*.gcda" -o -name "*.gcno" -o -name "\#*\#")

SRC				=	$(shell find $(SRC_DIR) -name '*.c')

TESTS			=	$(shell find ./tests -name '*.c')

OBJS			=	$(SRC:.c=.o)

NAME			=	binary

all:	$(NAME)

$(NAME):	$(OBJS)
		@gcc -o $(NAME) $(OBJS) $(LDFLAGS)
		@echo $(COMPILE)

%.o: %.c
		@gcc -o $@ -c $< -g

tests_run:
		@gcc -o unit_tests $(SRC) $(TESTS) $(CRITERION)
		@./unit_tests
		@echo $(TEST_RUN)

clean:
		@$(RM) $(OBJS) $(USELESS)
		@echo $(FILES_REMOVED)

fclean: clean
		@$(RM) $(NAME) unit_tests
		@echo $(FCLEAN)

re:	fclean all
		@echo $(RE_COMPILE)

.PHONY:	all clean fclean re