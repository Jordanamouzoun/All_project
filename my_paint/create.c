/*
** EPITECH PROJECT, 2023
** bspaint
** File description:
** create.c
*/
#include <stdio.h>
#include "paint.h"

int verif_button(win_t *win, tab_button_t *tab)
{
    int b = 0;

    for (int a = 8; a < 11; a++) {
        if (verif_hover(tab[a].button, win->pos_mouse.x,
        win->pos_mouse.y) == sfTrue) {
            sfRectangleShape_setFillColor(tab[a].button->rect,
            creat_color(255, 128, 128, 128));
            b++;
        } else
            sfRectangleShape_setFillColor(tab[a].button->rect, sfWhite);
    }
    sfRenderWindow_drawRectangleShape(win->win, tab[8].button->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, tab[9].button->rect, NULL);
    sfRenderWindow_drawRectangleShape(win->win, tab[10].button->rect, NULL);
    drawing_circle(win);
    return b;
}

int create_button(win_t *win, tab_button_t *tab)
{
    draw_cercle(win);
    if (verif_hover(tab[4].button, win->pos_mouse.x, win->pos_mouse.y) ==
    sfTrue) {
        sfRectangleShape_setFillColor(tab[4].button->rect,
        creat_color(255, 128, 128, 128));
        win->verif = 1;
    } else
        sfRectangleShape_setFillColor(tab[4].button->rect, sfWhite);
    if (win->verif == 1) {
        for (int a = 8; a < 11; a++)
            sfRenderWindow_drawRectangleShape(win->win,
            tab[a].button->rect, NULL);
        drawing_circle(win);
    }
    if (win->verif == 1 && verif_button(win, tab) != 0)
        win->verif = 1;
    else
        win->verif = 0;
    for (int a = 0; a < 6; a++)
        sfRenderWindow_drawText(win->win, win->text[a], NULL);
}

int create_ep(win_t *win)
{
    win->cercle[10] = create_circle((sfVector2f){460, 160}, 30);
    sfCircleShape_setOutlineColor(win->cercle[10], sfBlack);
    sfCircleShape_setFillColor(win->cercle[10], sfWhite);
    win->cercle[11] = create_circle((sfVector2f){475, 175}, 15);
    sfCircleShape_setOutlineColor(win->cercle[11], sfBlack);
    sfCircleShape_setFillColor(win->cercle[11], sfBlack);
    win->cercle[12] = create_circle((sfVector2f){460, 260}, 30);
    sfCircleShape_setOutlineColor(win->cercle[12], sfBlack);
    sfCircleShape_setFillColor(win->cercle[12], sfWhite);
    win->cercle[13] = create_circle((sfVector2f){478, 278}, 12);
    sfCircleShape_setOutlineColor(win->cercle[13], sfBlack);
    sfCircleShape_setFillColor(win->cercle[13], sfBlack);
    win->cercle[14] = create_circle((sfVector2f){460, 360}, 30);
    sfCircleShape_setOutlineColor(win->cercle[14], sfBlack);
    sfCircleShape_setFillColor(win->cercle[14], sfWhite);
    win->cercle[15] = create_circle((sfVector2f){481, 381}, 9);
    sfCircleShape_setOutlineColor(win->cercle[15], sfBlack);
    sfCircleShape_setFillColor(win->cercle[15], sfBlack);
}

int drawing_circle(win_t *win)
{
    for (int a = 10; a < 16; a++)
        sfRenderWindow_drawCircleShape(win->win, win->cercle[a], NULL);
}

int drawing_search(win_t *win, tab_button_t *tab)
{
    if (verif_click(tab[1].button, win->pos_mouse.x, win->pos_mouse.y, 0)
    == sfTrue) {
        scan(win);
        draw_image(win);
    }
    if (verif_click(tab[0].button, win->pos_mouse.x, win->pos_mouse.y, 0)
    == sfTrue) {
        sfRectangleShape_setFillColor(tab[7].button->rect, sfWhite);
        sfRenderWindow_drawRectangleShape(win->win,
            tab[7].button->rect, NULL);
    }
    display2(win, tab);
}
