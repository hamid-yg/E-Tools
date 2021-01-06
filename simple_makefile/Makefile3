##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

MAKE_CLEAN		=	make clean
MAKE_FCLEAN		=	make fclean

RED				=	\e[31m
GREEN			=	\e[32m
YELLOW			=	\e[33m
DEFAULT			=	\e[0m
BOLD			=	\e[1m

INC_DIR			=	./include/
SRC_DIR			=	./src/
LIB_DIR 		=	./lib/my
LIB				=	-sC lib/my

COMPILE			=	$$'$(BOLD)$(GREEN)[ Compiled the project ! ]\t$(DEFAULT)'
RE_COMPILE		=	$$'$(BOLD)$(GREEN)[ Recompiled the project ! ]\t$(DEFAULT)'
CLEAN			=	$$'$(BOLD)$(RED)[ Removing object files in [$(LIB_DIR)]... \t$(DEFAULT)'
FCLEAN			=	$$'$(BOLD)$(RED)[ Removing binary... ]\t$(DEFAULT)'
FILES_REMOVED	=   $$'$(BOLD)$(RED)[ Removing object files in [$(SRC_DIR)]... ]$(DEFAULT)'

SRC				=	$(shell find $(SRC_DIR) -name '*.c')

OBJS			=	$(SRC:.c=.o)

LIFLAGS			=	-I $(INC_DIR) -L $(LIB_DIR) -lmy

MAT				=	-lm

LDFLAGS			=	-Wall -Wextra -Werror -std=c99

NAME			=	108trigo

all:	$(NAME)

$(NAME):	$(OBJS)
		@make $(LIB)
		@gcc -o $(NAME) $(OBJS) $(LIFLAGS) $(LDFLAGS) $(MAT)
		@echo $(COMPILE)

%.o: %.c
	@gcc -o $@ -c $<

clean:
		@$(MAKE_CLEAN) $(LIB)
		@$(RM) $(OBJS)
		@echo $(FILES_REMOVED)

fclean: clean
		@$(MAKE_FCLEAN) $(LIB)
		@$(RM) $(NAME)
		@echo $(FCLEAN)

re:	fclean all
		@echo $(RE_COMPILE)

.PHONY:	all clean fclean re