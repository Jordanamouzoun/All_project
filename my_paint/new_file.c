/*
** EPITECH PROJECT, 2024
** new file
** File description:
** new file
*/
#include "paint.h"
int new_file(win_t *win)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (win->pos_mouse.x >= 0 && win->pos_mouse.x <= 95 &&
            win->pos_mouse.y >= 3 && win->pos_mouse.y <= 132) {
            sfRenderWindow_drawRectangleShape(win->win,
            win->new_file.button->rect, NULL);
            win->nbPoints = 0;
        }
    }
}
