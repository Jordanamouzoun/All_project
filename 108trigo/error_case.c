/*
** EPITECH PROJECT, 2023
** bs108
** File description:
** trigo.c
*/

#include "trigo.h"
#include <math.h>
#include <stdbool.h>

void is_fun(char *str, int ac)
{
    if (ac <= 3)
        exit(84);
    if (strcmp(str, "EXP") != 0 && strcmp(str, "COS") != 0 &&
        strcmp(str, "SIN") != 0 && strcmp(str, "COSH") != 0 &&
        strcmp(str, "SINH") != 0)
        exit(84);
}

int is_nmbr(char **av)
{
    int j = 2;

    while (av[j] != NULL){
        for (int i = 0; av[j][i] != '\0'; i++)
            if (!(av[j][i] <= 57 && av[j][i] >= 48) &&
                av[j][i] != '.' && av[j][i] != '-')
                exit(84);
        j++;
    }
}

void is_perfect_square(int ac)
{
    int rac = sqrt(ac);

    if (rac * rac != ac)
        exit(84);
}
