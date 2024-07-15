/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** window.c
*/

#include "paint.h"
#include <stdio.h>
void destroy(win_t *win, tab_button_t *tab)
{
    sfRenderWindow_destroy(win->win);
    sfFont_destroy(win->font);
    for (int a = 0; a < 16; a++) {
        if (a < 11)
            sfRectangleShape_destroy(tab[a].button->rect);
        if (a < 16)
            sfCircleShape_destroy(win->cercle[a]);
        if (a < 7)
            sfText_destroy(win->text[a]);
    }
    if (win->verif3 != 0) {
        sfSprite_destroy(win->image_spt);
        sfTexture_destroy(win->image_txt);
    }
    sfText_destroy(win->test);
    sfRectangleShape_destroy(win->help_rect);
    sfSprite_destroy(win->help_spt);
    sfTexture_destroy(win->help_txt);
}

int help_paint(win_t *win, tab_button_t *tab)
{
    win->nbPoints = 0;
    win->i = 0;
    win->verif = 0;
    win->verif2 = 1;
    win->verif3 = 0;
    call(win, tab);
    outils(win);
    win->font_color = creat_color(255, 255, 206, 200);
    helping(win);
}

int help2(win_t *win)
{
    if (win->pos_mouse.x >= 310 && win->pos_mouse.x <= 1600 &&
        win->pos_mouse.y >= 230 && win->pos_mouse.y <= 660)
        sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
    else
        sfRenderWindow_setMouseCursorVisible(win->win, sfTrue);
}

int help_crt_window(win_t *win)
{
    sfVector2f positionPoint = {0, 0};

    if (sfMouse_isButtonPressed(sfMouseLeft) && win->pos_mouse.x >= 311
        && win->pos_mouse.x <= 1600 &&
        win->pos_mouse.y >= 229 && win->pos_mouse.y <= 860) {
        positionPoint.x = (float)win->pos_mouse.x;
        positionPoint.y = (float)win->pos_mouse.y;
        win->points[win->nbPoints] = sfCircleShape_create();
        sfCircleShape_setRadius(win->points[win->nbPoints],
            sfCircleShape_getRadius(win->point));
        sfCircleShape_setFillColor(win->points[win->nbPoints],
            sfCircleShape_getFillColor(win->point));
        sfCircleShape_setPosition(win->points[win->nbPoints], positionPoint);
        sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
        win->nbPoints++;
    }
    help2(win);
}

int destroy_points(sfCircleShape **points, int nbPoints)
{
    for (int i = 0; i < nbPoints; i++)
        sfCircleShape_destroy(points[i]);
}
