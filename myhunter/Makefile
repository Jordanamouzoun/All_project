##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

EX = my_hunter

SC =	hunter.c\
	hunter2.c\
	des.c\
	hunter3.c

OB = $(SRCS:.c=.o)

all:	$(OB)
	gcc -o $(EX) $(SC) -lcsfml-graphics \
	-lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	rm -rf *.0 *~ *#

fclean:	clean
	rm -rf $(EX)

re:	fclean all
