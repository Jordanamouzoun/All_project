##
## EPITECH PROJECT, 2023
## my_radar
## File description:
## Makefile
##

EX = my_paint

SRCS = $(wildcard *.c)

all:
	gcc $(SRCS) -o $(EX) -lcsfml-graphics \
    -lcsfml-window -lcsfml-system -lcsfml-audio -lm -g3

clean:
	rm -rf *~ *# *.o

fclean:	clean
	rm -rf $(EX)

re:	fclean all
