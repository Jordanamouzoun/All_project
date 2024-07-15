/*
** EPITECH PROJECT, 2024
** outils
** File description:
** outils
*/
#include "paint.h"
int size(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/expand.png", NULL);
    sfVector2f position = {450, 10};
    sfVector2f scale = {0.15, 0.15};

    win->size = sfSprite_create();
    sfSprite_setTexture(win->size, texture, sfTrue);
    sfSprite_setScale(win->size, scale);
    sfSprite_setPosition(win->size, position);
}

int actu_tool(win_t *win)
{
    sfVector2f position = {win->pos_mouse.x - 2, win->pos_mouse.y - 20};
    sfVector2f scale = {0.15, 0.15};

    win->actu_tool = sfSprite_create();
    sfSprite_setTexture(win->actu_tool, win->texture, sfTrue);
    sfSprite_setScale(win->actu_tool, scale);
    sfSprite_setPosition(win->actu_tool, position);
}
