/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** scan.c
*/

#include "paint.h"
#include <string.h>

void calling(menu_t *win, win_t *wins, lis_t *list)
{
    win->mod.width = 1200;
    win->mod.height = 800;
    win->mod.bitsPerPixel = 32;
    win->win = sfRenderWindow_create(win->mod, "File",
    sfClose | sfResize, NULL);
    setting_file(&list, win, wins);
}

void displaying(menu_t *win, lis_t *list, win_t *wins)
{
    lis_t *temp = (list);

    sfRenderWindow_clear(win->win, creat_color(255, 255, 206, 200));
    win->pos_mouse = sfMouse_getPositionRenderWindow(win->win);
    for (; temp != NULL; temp = temp->next) {
        if (verif_hovering(temp->rect, win->pos_mouse.x, win->pos_mouse.x)
        == sfTrue)
            sfRectangleShape_setFillColor(temp->rect,
            creat_color(255, 128, 128, 128));
        else
            sfRectangleShape_setFillColor(temp->rect, sfTransparent);
        if (verif_hovering(temp->rect, win->pos_mouse.x, win->pos_mouse.x)
        == sfTrue && sfMouse_isButtonPressed(sfMouseLeft)) {
            wins->src = my_strdup(temp->str);
            sfRenderWindow_close(win->win);
        }
    }
    temp = list;
    help_scan(win, list, wins);
    sfRenderWindow_display(win->win);
}

void destroying(menu_t *win, lis_t *list)
{
    lis_t *temp = list;

    sfRenderWindow_destroy(win->win);
    for (; temp != NULL; temp = temp->next) {
        sfRectangleShape_destroy(temp->rect);
        sfText_destroy(temp->text);
        free(temp->str);
    }
    free(list);
    free(temp);
}

void evens(menu_t *evt)
{
    while (sfRenderWindow_pollEvent(evt->win, &(evt->event))) {
        if (evt->event.type == sfEvtClosed)
            sfRenderWindow_close(evt->win);
    }
}

char *scan(win_t *wins)
{
    menu_t *win = malloc(sizeof(menu_t));
    lis_t *list = NULL;

    show2(&list);
    calling(win, wins, list);
    while (sfRenderWindow_isOpen(win->win)) {
        evens(win);
        displaying(win, list, wins);
    }
    destroying(win, list);
}
