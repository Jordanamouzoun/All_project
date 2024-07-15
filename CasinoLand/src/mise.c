/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** mise.c
*/

#include "../include/casino.h"

int mise(sfRenderWindow *window, sfEvent event, char *name, int somme, sfSound *sound, int *num, int *mises)
{
    sfVector2i pos_mouse;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("Casino_menu/game/18.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfTexture *textures = sfTexture_createFromFile("Casino_menu/game/19.png", NULL);
    sfVector2f pos[4] = {{1171.6, 407.7}, {1171.6, 627.1}, {758.1, 823.5}, {110.2, 848.3}};
    sfVector2f size[3] = {{454.5, 95.1}, {309.1, 127.6}, {102.7, 102.7}};
    sfFont* font = sfFont_createFromFile("Casino_menu/Casino Bar.otf");
    sfText* text = sfText_create();
    sfText* texte = sfText_create();
    char buffer[128];
    char str[128];
    char buffers[128];
    char strs[128];
    int len = 0;
    int lengh = 0;
    sfBool bin = sfTrue;
    char buf[2][128];
    sfText *t[2];
    int v = 0;

    for (int a = 0; a < 2; a++) {
        t[a] = sfText_create();
        buf[a][0] = 0;
        sfText_setFont(t[a], font);
        sfText_setCharacterSize(t[a], 40);
        sfText_setColor(t[a], sfBlack);
    }
    sprintf(buf[0], "%s", name);
    sfText_setString(t[0], buf[0]);
    sprintf(buf[1], "%d", somme);
    sfText_setString(t[1], buf[1]);
    sfText_setFont(text, font);
    sfText_setFont(texte, font);
    sfText_setColor(text, sfBlack);
    sfText_setColor(texte, sfBlack);
    str[0] = 0;
    buffer[0] = 0;
    strs[0] = 0;
    buffers[0] = 0;
    sfText_setPosition(t[1], (sfVector2f){409.6, 182.4});
    sfText_setPosition(t[0], (sfVector2f){409.6, 57.4});
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, (sfVector2f){1181.6, 417.7});
    sfText_setCharacterSize(texte, 40);
    sfText_setPosition(texte, (sfVector2f){1181.6, 637.1});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(sprites, textures, sfTrue);
    sfSprite_setPosition(sprites, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(window)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft) {
                if (check_colliMouse(pos[0], size[0], pos_mouse) == sfTrue) {
                    bin = sfTrue;
                    sfSound_play(sound);
                }
                if (check_colliMouse(pos[1], size[0], pos_mouse) == sfTrue) {
                    bin = sfFalse;
                    sfSound_play(sound);
                }
                if (check_colliMouse(pos[3], size[2], pos_mouse) == sfTrue) {
                    v = 1;
                    sfSound_play(sound);
                }
                if (check_colliMouse(pos[2], size[1], pos_mouse) == sfTrue) {
                    sfSound_play(sound);
                    *mises = atoi(strs);
                    *num = atoi(str);

                    if (!((*num) <= 50 && (*num) >= 1) || (*mises) > somme || (*mises) <= 0)
                        error(window, event);
                    else
                        v = 2;
                }
            }
            if (event.type == sfEvtKeyPressed) {
                len = strlen(str);
                lengh = strlen(strs);
                if (bin == sfTrue) {
                    if (event.key.code >= sfKeyNumpad0 && event.key.code <= sfKeyNumpad9 && len < 2) {
                        str[len] = event.key.code - 27;
                        str[len + 1] = 0;
                    }
                    if (event.key.code >= sfKeyNum0 && event.key.code <= sfKeyNum9 && len < 2) {
                        str[len] = event.key.code + 22;
                        str[len + 1] = 0;
                    }
                    if (event.key.code == sfKeyBackspace) {
                        if (len != 0)
                            str[len - 1] = 0;
                        else
                            str[len] = 0;
                    }
                } else {
                    if (event.key.code >= sfKeyNumpad0 && event.key.code <= sfKeyNumpad9 && lengh < 20) {
                        strs[lengh] = event.key.code - 27;
                        strs[lengh + 1] = 0;
                    }
                    if (event.key.code >= sfKeyNum0 && event.key.code <= sfKeyNum9 && lengh < 20) {
                        strs[lengh] = event.key.code + 22;
                        strs[lengh + 1] = 0;
                    }
                    if (event.key.code == sfKeyBackspace) {
                        if (lengh != 0)
                            strs[lengh - 1] = 0;
                        else
                            strs[lengh] = 0;
                    }
                }
            }
        }
        sprintf(buffer, "%s", str);
        sprintf(buffers, "%s", strs);
        sfText_setString(text, buffer);
        sfText_setString(texte, buffers);
        sfRenderWindow_clear(window, sfBlack);
        if (bin == sfTrue)
            sfRenderWindow_drawSprite(window, sprite, NULL);
        else
            sfRenderWindow_drawSprite(window, sprites, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_drawText(window, texte, NULL);
        for (int a = 0; a < 2; a++) {
            sfRenderWindow_drawText(window, t[a], NULL);
        }
        sfRenderWindow_display(window);
        if (v == 1 || v == 2)
            break;
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfText_destroy(text);
    sfText_destroy(t[0]);
    sfText_destroy(t[1]);
    sfFont_destroy(font);
    sfSprite_destroy(sprites);
    sfTexture_destroy(textures);
    sfText_destroy(texte);
    if (v == 2)
        return 1;
    return 0;
}