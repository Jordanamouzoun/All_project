/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** scan2.c
*/

#include "paint.h"

int help_scan(menu_t *win, lis_t *list, win_t *wins)
{
    for (; list != NULL; list = list->next) {
        sfRenderWindow_drawRectangleShape(win->win, list->rect, NULL);
        sfRenderWindow_drawText(win->win, list->text, NULL);
    }
}
