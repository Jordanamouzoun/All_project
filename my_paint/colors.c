/*
** EPITECH PROJECT, 2024
** colors
** File description:
** colors
*/
#include "paint.h"
sfCircleShape *create_circle(sfVector2f position, double radius)
{
    sfCircleShape *cercle = sfCircleShape_create();

    sfCircleShape_setPosition(cercle, position);
    sfCircleShape_setOutlineThickness(cercle, 2);
    sfCircleShape_setRadius(cercle, radius);
    return cercle;
}

sfCircleShape *create_circle2(sfVector2f position,
    double radius, win_t *win)
{
    sfCircleShape *cercle = sfCircleShape_create();

    sfCircleShape_setPosition(cercle, position);
    sfCircleShape_setOutlineThickness(cercle, 4);
    sfCircleShape_setRadius(cercle, radius);
    sfCircleShape_setOutlineColor(cercle, sfBlack);
    win->check2 = 1;
    return cercle;
}

int circle_create(win_t *win)
{
    int i = 0;
    float x = 900;
    sfVector2f position = {x, 40};
    sfColor Colors[10] = {sfColor_fromRGB(255, 0, 0), sfColor_fromRGB(255, 165,
    0), sfColor_fromRGB(255, 255, 0), sfColor_fromRGB(0, 255, 0),
    sfColor_fromRGB(0, 0, 255), sfColor_fromRGB(75, 0, 130), sfColor_fromRGB(
    128, 0, 128), sfColor_fromRGB(255, 192, 203), sfBlack, sfWhite
    };

    win->cercle = malloc(16 * sizeof(sfCircleShape *));
    for (i = 0; i < 10; i++) {
        win->cercle[i] = create_circle(position, 15);
        position.x += 50;
        sfCircleShape_setOutlineColor(win->cercle[i], sfBlack);
        sfCircleShape_setFillColor(win->cercle[i], Colors[i]);
        if (i == 4) {
            position.y += 50;
            position.x = 900;
        }
    }
}

int draw_cercle(win_t *win)
{
    int i;

    for (i = 0; i < 10; i++) {
        sfRenderWindow_drawCircleShape(win->win, win->cercle[i], NULL);
    }
}
