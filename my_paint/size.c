/*
** EPITECH PROJECT, 2024
** size
** File description:
** size
*/
#include "paint.h"
int size_pen(win_t *win)
{
    if (win->pos_mouse.x >= 440 && win->pos_mouse.x <= 538 &&
        win->pos_mouse.y >= 141 && win->pos_mouse.y <= 227) {
        sfCircleShape_setRadius(win->point, 15.0);
    }
    if (win->pos_mouse.x >= 440 && win->pos_mouse.x <= 538 &&
        win->pos_mouse.y >= 235 && win->pos_mouse.y <= 327) {
        sfCircleShape_setRadius(win->point, 10.0);
    }
    if (win->pos_mouse.x >= 440 && win->pos_mouse.x <= 538 &&
        win->pos_mouse.y >= 334 && win->pos_mouse.y <= 437) {
        sfCircleShape_setRadius(win->point, 5.0);
    }
}
