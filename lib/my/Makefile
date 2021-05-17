##
## EPITECH PROJECT, 2019
## minishell1
## File description:
## lib_Makefile
##

LIBSRC	=	my_putchar.c		\
		my_putstr.c		\
		my_put_nbr.c		\
		my_put_error.c		\
		my_printf.c		\
		my_put_nbr_pos.c	\
		convert_binary.c	\
		convert_octals.c	\
		convert_hex_lowercase.c	\
		convert_hex_uppercase.c	\
		pointer_adress.c	\
		convert_out_octals.c	\
		my_strlen.c		\
		my_strcat.c		\
		my_strcmp.c		\
		my_str_to_word_array.c

LIBOBJ	=	$(LIBSRC:.c=.o)

RM	=	rm -f

CPPFLAGS	=	-I ../../include -g

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(LIBOBJ)
	ar rc libmy.a $(LIBOBJ)

clean:
	$(RM) $(LIBOBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *~

re:	fclean all

.PHONY: all clean fclean re
