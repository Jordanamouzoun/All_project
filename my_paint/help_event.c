/*
** EPITECH PROJECT, 2024
** help
** File description:
** help
*/
#include "paint.h"
#include <stdio.h>
int events(win_t *win)
{
    sfColor Colors[10] = {sfColor_fromRGB(255, 0, 0),
        sfColor_fromRGB(255, 165, 0),
        sfColor_fromRGB(255, 255, 0), sfColor_fromRGB(0, 255, 0),
        sfColor_fromRGB(0, 0, 255), sfColor_fromRGB(75, 0, 130),
        sfColor_fromRGB(128, 0, 128), sfColor_fromRGB(255, 192, 203),
        sfBlack, sfWhite
    };

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (win->pos_mouse.x >= 310 && win->pos_mouse.x <= 340 &&
            win->pos_mouse.y >= 10 && win->pos_mouse.y <= 38) {
            sfCircleShape_setFillColor(win->point, sfBlack);
            win->texture = sfTexture_createFromFile("./sp/crayon.png", NULL);
            sfCircleShape_setRadius(win->point, 2.0);
        }
        help_events(win, Colors);
    }
}

void even(win_t *evt, tab_button_t *tab)
{
    while (sfRenderWindow_pollEvent(evt->win, &(evt->event))) {
        if (evt->event.type == sfEvtClosed)
            sfRenderWindow_close(evt->win);
    }
    events(evt);
}

void call(win_t *win, tab_button_t *tab)
{
    win->mod.width = 1920;
    win->mod.height = 1080;
    win->mod.bitsPerPixel = 32;
    win->win = sfRenderWindow_create(win->mod, "myPaint",
    sfClose | sfResize, NULL);
    call2(win, tab);
    setting_text(win);
}
