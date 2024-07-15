/*
** EPITECH PROJECT, 2024
** events
** File description:
** events
*/
#include "paint.h"
#include <stdio.h>

int help_display(win_t *win)
{
    if (win->check2 == 1)
        sfRenderWindow_drawCircleShape(win->win, win->forme_circle, NULL);
    if (win->check1 == 1)
        sfRenderWindow_drawRectangleShape(win->win, win->forme_rec, NULL);
}

void display(win_t *win, tab_button_t *tab,
    sfCircleShape **points, int nbPoints)
{
    sfRenderWindow_clear(win->win, win->font_color);
    display1(win, tab);
    sfRenderWindow_drawSprite(win->win, win->file, NULL);
    sfRenderWindow_drawSprite(win->win, win->modify, NULL);
    sfRenderWindow_drawSprite(win->win, win->save, NULL);
    sfRenderWindow_drawSprite(win->win, win->tools, NULL);
    sfRenderWindow_drawSprite(win->win, win->size, NULL);
    sfRenderWindow_drawSprite(win->win, win->formes, NULL);
    sfRenderWindow_drawSprite(win->win, win->gum, NULL);
    sfRenderWindow_drawSprite(win->win, win->paint, NULL);
    sfRenderWindow_drawSprite(win->win, win->pinceau, NULL);
    sfRenderWindow_drawSprite(win->win, win->circle, NULL);
    help_display(win);
    for (int i = 0; i < nbPoints; i++)
            sfRenderWindow_drawCircleShape(win->win, points[i], NULL);
    if (win->pos_mouse.x >= 310 && win->pos_mouse.x <= 1600 &&
        win->pos_mouse.y >= 230 && win->pos_mouse.y <= 830)
    sfRenderWindow_drawSprite(win->win, win->actu_tool, NULL);
    drawing_search(win, tab);
    sfRenderWindow_display(win->win);
}

int help_events(win_t *win, sfColor *Colors)
{
    for (int i = 0; i < 10; i++) {
        if (verif_color(win->cercle[i], win) == sfTrue)
            sfCircleShape_setFillColor(win->point, Colors[i]);
    }
    if (win->pos_mouse.x >= 375 && win->pos_mouse.x <= 400 &&
        win->pos_mouse.y >= 15 && win->pos_mouse.y <= 35) {
        win->texture = sfTexture_createFromFile("./sp/gomme.png", NULL);
        sfCircleShape_setFillColor(win->point, sfWhite);
        sfCircleShape_setRadius(win->point, 30.0);
    }
    if (win->pos_mouse.x >= 314 && win->pos_mouse.x <= 334 &&
        win->pos_mouse.y >= 60 && win->pos_mouse.y <= 86) {
        win->font_color = sfCircleShape_getFillColor(win->point);
    }
    if (win->pos_mouse.x >= 382 && win->pos_mouse.x <= 411 &&
        win->pos_mouse.y >= 58 && win->pos_mouse.y <= 81) {
        win->texture = sfTexture_createFromFile("./sp/brush.png", NULL);
        sfCircleShape_setRadius(win->point, 5.0);
    }
    size_pen(win);
}

int help_events2(win_t *win)
{
    sfVector2f position1 = {550, 300};
    sfVector2f position = {650, 300};
    double radius = 70;

    win->forme_rec = create_rectangle(position1);
    if (win->check1 == 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            win->pos_mouse.x >= 603 && win->pos_mouse.x <= 650 &&
            win->pos_mouse.y >= 26 && win->pos_mouse.y <= 70) {
            win->check1 = 1;
        }
    }
    if (win->check2 == 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            win->pos_mouse.x >= 700 && win->pos_mouse.x <= 746 &&
            win->pos_mouse.y >= 30 && win->pos_mouse.y <= 66) {
            win->forme_circle = create_circle2(position, radius, win);
        }
    }
}
