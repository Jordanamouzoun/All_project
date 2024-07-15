/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** answers.c
*/

#include "../include/casino.h"

int answers(sfRenderWindow *window, sfEvent event, char *name, int *somme, sfSound *sound, int num_ale, int num, int mises, sfMusic *music, int volume)
{
    sfVector2i pos_mouse;
    sfSprite *spt[5];
    sfTexture *txt[5];
    char *str[5] = {"Casino_menu/game/22.png", "Casino_menu/game/23.png", "Casino_menu/game/24.png", "Casino_menu/game/25.png", "Casino_menu/game/26.png"};
    sfText *texte[5];
    char buf[2][14];
    sfMusic *mus[2];
    sfFont* font = sfFont_createFromFile("Casino_menu/Casino Bar.otf");
    sfVector2f pos[3] = {{206.6, 874.3}, {1220, 874.3}, {751.4, 864.1}};
    sfVector2f size = {417.2, 124.8};
    sfVector2f pos_txt[5] = {{399.5, 55.1}, {399.5, 180.6}, {658.8, 560}, {1585.3, 560}, {1107.2, 692.6}};
    int open = 0;
    int v = 0;
    int somme_win = 0;

    sfMusic_pause(music);
    mus[0] = sfMusic_createFromFile("son/win.ogg");
    mus[1] = sfMusic_createFromFile("son/lose.ogg");
    for (int a = 0; a < 5; a++) {
        if (a < 2) {
            sfMusic_setVolume(mus[a], volume);
            sfMusic_setLoop(mus[a], sfTrue);
        }
        spt[a] = sfSprite_create();
        txt[a] = sfTexture_createFromFile(str[a], NULL);
        sfSprite_setTexture(spt[a], txt[a], sfTrue);
        sfSprite_setPosition(spt[a], (sfVector2f){0, 0});
        texte[a] = sfText_create();
        sfText_setFont(texte[a], font);
        if (a == 2 || a == 3)
            sfText_setColor(texte[a], sfWhite);
        else
            sfText_setColor(texte[a], sfBlack);
        sfText_setCharacterSize(texte[a], 40);
        sfText_setPosition(texte[a], pos_txt[a]);
    }
    sfText_setString(texte[0], name);
    sprintf(buf[0], "%d", num);
    sfText_setString(texte[2], buf[0]);
    sprintf(buf[0], "%d", num_ale);
    sfText_setString(texte[3], buf[0]);
    buf[1][0] = 0;
    if (num == num_ale) {
        v = 1;
        somme_win = mises * 3;
    } else if (num % 2 == 0 && num_ale % 2 == 0) {
        somme_win = ceil(mises / 2);
        v = 2;
    } else if (num % 2 != 0 && num_ale % 2 != 0) {
        v = 3;
        somme_win = ceil(mises / 2);
    } else {
        somme_win = -1 * mises;
        if ((*somme) + somme_win == 0)
            v = 4;
        else
            v = 5;
    }
    if (v == 1 || v == 2 || v == 3)
        sfMusic_play(mus[0]);
    if (v == 4 || v == 5)
        sfMusic_play(mus[1]);
    (*somme) += somme_win;
    sprintf(buf[0], "%d", (*somme));
    sfText_setString(texte[1], buf[0]);
    sprintf(buf[1], "%d", somme_win);
    sfText_setString(texte[4], buf[1]);
    while (sfRenderWindow_isOpen(window)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft) {
                if (v != 4) {
                    if (check_colliMouse(pos[0], size, pos_mouse) == sfTrue) {
                        open = 1;
                        sfSound_play(sound);
                    }
                    if (check_colliMouse(pos[1], size, pos_mouse) == sfTrue) {
                        open = 2;
                    }
                } else {
                    if (check_colliMouse(pos[2], size, pos_mouse) == sfTrue) {
                        open = 1;
                        sfSound_play(sound);
                    }
                }
            }
        }
        if (open != 0)
            break;
        sfRenderWindow_clear(window, sfBlack);
        if (v == 1) {
            sfRenderWindow_drawSprite(window, spt[3], NULL);
            sfRenderWindow_drawText(window, texte[4], NULL);
        } else if (v == 2) {
            sfRenderWindow_drawSprite(window, spt[1], NULL);
            sfRenderWindow_drawText(window, texte[2], NULL);
            sfRenderWindow_drawText(window, texte[3], NULL);
            sfRenderWindow_drawText(window, texte[4], NULL);
        } else if (v == 3) {
            sfRenderWindow_drawSprite(window, spt[0], NULL);
            sfRenderWindow_drawText(window, texte[2], NULL);
            sfRenderWindow_drawText(window, texte[3], NULL);
            sfRenderWindow_drawText(window, texte[4], NULL);
        } else if (v == 4) {
            sfRenderWindow_drawSprite(window, spt[4], NULL);
        } else if (v == 5) {
            sfRenderWindow_drawSprite(window, spt[2], NULL);
        }
        for (int a = 0; a < 2; a++) {
            sfRenderWindow_drawText(window, texte[a], NULL);
        }
        sfRenderWindow_display(window);
    }
    for (int a = 0; a < 5; a++) {
        if (a < 2)
            sfMusic_destroy(mus[a]);
        sfSprite_destroy(spt[a]);
        sfTexture_destroy(txt[a]);
        sfText_destroy(texte[a]);
    }
    sfMusic_play(music);
    sfFont_destroy(font);
    if (open == 2)
        return 1;
    return 0;
}