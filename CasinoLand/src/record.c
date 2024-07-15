/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** record.c
*/

#include "../include/casino.h"

int records(sfRenderWindow *window, sfEvent event, record_t *record, sfSound *sound)
{
    sfVector2i pos_mouse;
    record_t *temp = record;
    sfRectangleShape *rect[5];
    sfText *text[5];
    sfFont *font = sfFont_createFromFile("Casino_menu/Casino Bar.otf");
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("Casino_menu/record/27.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfTexture *textures = sfTexture_createFromFile("Casino_menu/record/28.png", NULL);
    sfVector2f pos = {108, 81};
    sfVector2f size = {67.7, 67.7};
    sfBool open = sfTrue;
    char buf[220];

    buf[0] = 0;
    for (int a = 0; a < 5; a++) {
        text[a] = sfText_create();
        rect[a] = sfRectangleShape_create();
        sfText_setFont(text[a], font);
        sfText_setColor(text[a], sfBlack);
        sfText_setCharacterSize(text[a], 60);
        sfText_setPosition(text[a], (sfVector2f){20, ((a + 1) * 160 + 25) + 100});
        sfRectangleShape_setFillColor(rect[a], sfTransparent);
        sfRectangleShape_setOutlineColor(rect[a], sfBlack);
        sfRectangleShape_setOutlineThickness(rect[a], 2);
        sfRectangleShape_setPosition(rect[a], (sfVector2f){0, ((a + 1) * 160) + 100});
        sfRectangleShape_setSize(rect[a], (sfVector2f){1920, 160});
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(sprites, textures, sfTrue);
    sfSprite_setPosition(sprites, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(window)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (check_colliMouse(pos, size, pos_mouse) == sfTrue && event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft) {
                sfSound_play(sound);
                open = sfFalse;
            }
        }
        if (open == sfFalse)
            break;
        sfRenderWindow_clear(window, sfBlack);
        if (record == NULL)
            sfRenderWindow_drawSprite(window, sprites, NULL);
        else
            sfRenderWindow_drawSprite(window, sprite, NULL);
        temp = record;
        for (int a = 0; temp != NULL; a++, temp = temp->next) {
            sfRenderWindow_drawRectangleShape(window, rect[a], NULL);
            sprintf(buf, "%s                                                       %d", temp->name, temp->somme);
            sfText_setString(text[a], buf);
            sfRenderWindow_drawText(window, text[a], NULL);
        }
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprites);
    sfTexture_destroy(textures);
    for (int a = 0; a < 5; a++) {
        sfText_destroy(text[a]);
        sfRectangleShape_destroy(rect[a]);
    }
    sfFont_destroy(font);
}