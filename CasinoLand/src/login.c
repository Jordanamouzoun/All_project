/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** login.c
*/

#include "../include/casino.h"

int login(sfRenderWindow *window, sfEvent event, sfSound *sound, char *name)
{
    sfVector2i pos_mouse;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("Casino_menu/login/login.png", NULL);
    sfVector2f pos[2] = {{164.5, 875.9}, {1481.4, 875.9}};
    sfVector2f size = {285, 117.6};
    sfFont* font = sfFont_createFromFile("Casino_menu/casino.ttf");
    sfText* text = sfText_create();
    char buffer[128];
    char str[128];
    int len = 0;
    int v = 0;

    sfText_setFont(text, font);
    str[0] = 0;
    buffer[0] = 0;
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, (sfVector2f){540.8, 511.8});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(window)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed) {
                len = strlen(str);
                if (event.key.code >= 0 && event.key.code <= 25 && len <= 37) {
                    str[len] = event.key.code + 'A';
                    str[len + 1] = 0;
                }
                if (event.key.code == sfKeyBackspace) {
                    str[len - 1] = 0;
                }
                if (event.key.code == sfKeySpace && len <= 37) {
                    str[len] = ' ';
                    str[len + 1] = 0;
                }
            }
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) && check_colliMouse(pos[0], size, pos_mouse) == sfTrue) {
            v = 1;
            sfSound_play(sound);
            break;
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) && check_colliMouse(pos[1], size, pos_mouse) == sfTrue && len != 0) {
            sfSound_play(sound);
            break;
        }
        sprintf(buffer, "%s", str);
        sfText_setString(text, buffer);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
    strcpy(name, str);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfText_destroy(text);
    sfFont_destroy(font);
    if (v == 0)
        return 1;
    return 0;
}