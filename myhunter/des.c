/*
** EPITECH PROJECT, 2023
** description
** File description:
** -h
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        my_putchar(str[a]);
    }
}

void describ(void)
{
    my_putstr("Dunk-hunter is game create in 1985 ");
    my_putstr("which consist to kill a flying dunk\n\n");
    my_putstr("you will try to to kill a dunk with the mouse\n");
    my_putstr("Goals:\nThe goals is to obtain the biggest score but ");
    my_putstr("you have only three lives and you lose one when the dunk ");
    my_putstr("go out the screen\n");
}
