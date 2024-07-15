/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** menu_about.c
*/

#include "../include/casino.h"

int menu_about(sfRenderWindow *window, sfEvent event)
{
    sfVector2i pos_mouse;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("Casino_menu/about/about.png", NULL);
    sfVector2f pos = {121.9, 80.8};
    sfVector2f size = {76, 76};
    sfBool open = sfTrue;

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(window)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (check_colliMouse(pos, size, pos_mouse) == sfTrue && event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft)
                open = sfFalse;
        }
        if (open == sfFalse)
            break;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}