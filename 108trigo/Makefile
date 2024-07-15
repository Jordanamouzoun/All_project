##
## EPITECH PROJECT, 2023
## B-MAT-200-COT-2-1-108trigo-jordan.amouzoun
## File description:
## Makefile
##

CC = gcc
NAME = 108trigo
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
all:$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(SRCS) -o $(NAME) -lm
clean :
	rm -rf *.o
fclean: clean
	rm -rf *~ $(NAME)
re: fclean all
