/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** display.c
*/

#include "paint.h"

void display1(win_t *win, tab_button_t *tab)
{
    for (int a = 0; a < 8; a++) {
        sfRenderWindow_drawRectangleShape(win->win, tab[a].button->rect, NULL);
    }
    win->pos_mouse = sfMouse_getPositionRenderWindow(win->win);
    for (int a = 0; a < 3; a++)
        if (verif_hover(tab[a].button, win->pos_mouse.x,
        win->pos_mouse.y) == sfTrue)
            sfRectangleShape_setFillColor(tab[a].button->rect,
            creat_color(255, 128, 128, 128));
        else
            sfRectangleShape_setFillColor(tab[a].button->rect, sfWhite);
    create_button(win, tab);
    if (win->verif3 != 0)
        sfRenderWindow_drawSprite(win->win, win->image_spt, NULL);
    new_file(win);
}
