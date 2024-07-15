/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** error.c
*/

#include "../include/casino.h"

int error(sfRenderWindow *window, sfEvent event)
{
    sfSprite *sprit = sfSprite_create();
    sfTexture *textur = sfTexture_createFromFile("Casino_menu/game/20.png", NULL);
    int minutor = 0;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(sprit, textur, sfTrue);
    sfSprite_setPosition(sprit, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfTime elapsed = sfClock_getElapsedTime(clock);
        float seconds = elapsed.microseconds / 1000000.0;
        if (seconds > 1) {
            minutor++;
            sfClock_restart(clock);
        }
        if (minutor == 4)
            break;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprit, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprit);
    sfTexture_destroy(textur);
}