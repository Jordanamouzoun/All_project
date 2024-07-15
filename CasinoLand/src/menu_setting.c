/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** menu_setting.c
*/

#include "../include/casino.h"

int menu_setting(sfRenderWindow *window, sfEvent event, sfMusic *music, sfSound *sound, float *volume)
{
    sfVector2i pos_mouse;
    sfRectangleShape *rect = sfRectangleShape_create();
    sfSprite *sprite[2];
    sfTexture *texture[2];
    char *arr[2] = {"Casino_menu/setting/14.png", "Casino_menu/setting/15.png"};
    sfVector2f pos_rect = {365.7, 519.2};
    sfVector2f size_rect = {527.5, 54.4};
    sfVector2f size_rects = {527.5, 54.4};
    sfVector2f pos[5] = {{110.9, 152.2}, {970.9, 477.9}, {970.9, 557.6}, {133.1, 718.1}, {548.4, 718.1}};
    sfVector2f size[5] = {{73.9, 73.9}, {73.2, 57.3}, {73.2, 57.3}, {162, 162}, {162, 162}};
    sfBool bin = sfTrue;

    for (int a = 0; a < 2; a++)
        create_sprite(&sprite[a], &texture[a], arr[a]);
    sfRectangleShape_setPosition(rect, pos_rect);
    sfRectangleShape_setFillColor(rect, sfRed);
    while (sfRenderWindow_isOpen(window)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft) {
                if (check_colliMouse(pos[3], size[3], pos_mouse) == sfTrue) {
                    sfSound_play(sound);
                    bin = sfTrue;
                    sfMusic_setVolume(music, (*volume));
                }
                if (check_colliMouse(pos[4], size[4], pos_mouse) == sfTrue) {
                    sfSound_play(sound);
                    bin = sfFalse;
                    sfMusic_setVolume(music, 0.0);
                }
                if (check_colliMouse(pos[1], size[1], pos_mouse) == sfTrue && (*volume) < 100 && bin == sfTrue) {
                    sfSound_play(sound);
                    (*volume) += 25;
                    sfMusic_setVolume(music, (*volume));
                }
                if (check_colliMouse(pos[2], size[2], pos_mouse) == sfTrue && (*volume) > 0 && bin == sfTrue) {
                    sfSound_play(sound);
                    (*volume) -= 25;
                    sfMusic_setVolume(music, (*volume));
                }
            }
        }
        size_rects.x = (size_rect.x * (*volume)) / 100.0;
        sfRectangleShape_setSize(rect, size_rects);
        if (check_colliMouse(pos[0], size[0], pos_mouse) == sfTrue && sfMouse_isButtonPressed(sfMouseLeft))
            break;
        sfRenderWindow_clear(window, sfBlack);
        if (bin == sfTrue)
            sfRenderWindow_drawSprite(window, sprite[0], NULL);
        else
            sfRenderWindow_drawSprite(window, sprite[1], NULL);
        if (bin == sfTrue)
            sfRenderWindow_drawRectangleShape(window, rect, NULL);
        sfRenderWindow_display(window);
    }
    sfRectangleShape_destroy(rect);
    for (int a = 0; a < 2; a++){
        sfSprite_destroy(sprite[a]);
        sfTexture_destroy(texture[a]);
    }
}