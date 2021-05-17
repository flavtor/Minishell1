##
## EPITECH PROJECT, 2019
## minishell1
## File description:
## Compilation's Makefile
##

SOURCE	=	./src/

SRC	=	main.c		\
		minishell.c	\
		$(SOURCE)my_exit.c	\
		$(SOURCE)my_env.c	\
		$(SOURCE)my_setenv.c	\
		$(SOURCE)my_unsetenv.c	\
		$(SOURCE)my_exec.c	\
		$(SOURCE)my_cd.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	mysh

CPPFLAGS	=	-I ./include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
	make clean -C ./lib/my/

fclean: clean
	$(RM) *~
	$(RM) include/*~
	make fclean -C ./lib/my/

re:	fclean all

tests_run:
	make -C ./tests/

.PHONY: all clean fclean re
