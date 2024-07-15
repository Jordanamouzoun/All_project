##
## EPITECH PROJECT, 2024
## CasinoLand
## File description:
## Makefile
##

SRCS = src/menu.c\
		src/main.c\
		src/menu_about.c\
		src/menu_setting.c\
		src/loading.c\
		src/login.c\
		src/mise.c\
		src/error.c\
		src/roue.c\
		src/answers.c\
		src/record.c\
		src/string.c

all:
	gcc -o casino ${SRCS} -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
clean:
	rm -rf *# *~
fclean: clean
	rm -rf casino
re: fclean all