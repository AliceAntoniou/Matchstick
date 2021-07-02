##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

MAIN	=		main.c

SRC		=		src/matchstick.c			\
				src/game.c					\
				src/map.c					\
				src/get_param.c				\
				src/ia/ia.c					\
				src/ia/end_game.c

BONUS	=		src/matchstick.c			\
				bonus/iavia.c				\
				src/map.c					\
				src/get_param.c				\
				src/ia/ia.c					\
				src/ia/end_game.c

TO_TEST	=		src/ia/end_game.c			\
				src/ia/ia.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

BOBJ	=		$(BONUS:.c=.o) $(MAIN:.c=.o)

TESTS	=		tests/two_per_line.c		\
				tests/two_lines_left.c		\
				tests/one_line_left.c		\
				tests/can_I_win.c			\
				tests/get_matches.c

NAME	=		matchstick

LIB		=		lib/libmy.a

CFLAGS 	=		-W -Wall -Wextra -g

CPPFLAGS	=	-I./include

LDFLAGS	=	-Llib/

LDIBS	=	-lmy -lcurses

all:		$(NAME)

$(NAME):	$(OBJ) $(LIB)
			gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)

$(LIB):
			make -C lib/my

run:		$(NAME)
			./$(NAME)

1V1:		$(BOBJ) $(LIB)
			gcc -o $(NAME) $(BOBJ) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)

tests_run:	LDIBS += -lcriterion --coverage
tests_run:	all
			gcc -o $@ $(TO_TEST) $(TESTS) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)
			-./$@
			gcovr --branches

clean:
		$(RM) *.o
		$(RM) src/*.o
		$(RM) src/ia/*.o
		$(RM) bonus/*.o
		$(RM) *~
		$(RM) *.gc*

fclean:	clean
		$(RM) tests_run
		$(RM) $(NAME)
		$(RM) $(LIB)
		make -C lib/my fclean

re:		fclean all

.PHONY: re fclean clean tests_run run all