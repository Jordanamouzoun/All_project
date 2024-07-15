/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** loading.c
*/

#include "../include/casino.h"

int loading(sfRenderWindow *window, sfEvent event)
{
    sfVector2i pos_mouse;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("Casino_menu/loading/roleta.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfTexture *textures = sfTexture_createFromFile("Casino_menu/loading/loading.png", NULL);
    sfVector2f pos = {1697.9, 857.9};
    sfVector2f posi = {0, 0};
    sfVector2f scale = {0.296103896, 0.298429319};
    sfBool open = sfTrue;
    sfClock *clock = sfClock_create();
    int minutor = 0;

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprites, textures, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setPosition(sprites, posi);
    sfSprite_setScale(sprite, scale);
    sfVector2u size = sfTexture_getSize(texture);
    sfVector2f origin = {(float)size.x / 2, (float)size.y / 2};
    sfSprite_setOrigin(sprite, origin);
    while (sfRenderWindow_isOpen(window)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfTime elapsed = sfClock_getElapsedTime(clock);
        float seconds = elapsed.microseconds / 100000.0;
        if (seconds > 0.1) {
            sfSprite_rotate(sprite, 1);
            minutor++;
            sfClock_restart(clock);
        }
        if (minutor == 150)
            break;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprites, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprites);
    sfSprite_destroy(sprite);
    sfClock_destroy(clock);
    sfTexture_destroy(textures);
    sfTexture_destroy(texture);
}