##
## EPITECH PROJECT, 2023
## MAKE FILE
## File description:
## ~
##

SRCS	=	bsai/free_array.c	\
			bsai/str_array.c	\
			bsai/n4steek.c

OBJS	=	$(SRCS:.c=.o)

NAME =	ai

all: $(NAME)

$(NAME): $(SRCS)
	gcc -g3 -o $(NAME) $(SRCS) bsai/main.c -lm

unit_tests: fclean $(NAME)
	gcc -o unit_tests tests/test.c $(SRCS) -lcriterion --coverage

tests_run: unit_tests
	./unit_tests
	gcovr --exclude unit_tests/ --branches
	gcovr --exclude unit_tests/

clean:
	find . -type f -name "*.o" -delete
	find . -type f -name "*~" -delete
	find . -type f -name "#*#" -delete
	find . -type f -name "a.out" -delete
	find . -type f -name "vgcore*" -delete
	find . -type f -name "*.gcda" -delete
	find . -type f -name "*.gcno" -delete

fclean: clean
	rm -f $(NAME) unit_tests
	rm -rf coding-style-reports.log

re: fclean all

.PHONY: all clean fclean re
