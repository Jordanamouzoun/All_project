/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** menu.c
*/

#include "../include/casino.h"

void create_sprite(sfSprite **sprite, sfTexture **texture, char *str)
{
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, (sfVector2f){0, 0});
}

sfBool check_colliMouse(sfVector2f pos, sfVector2f size, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= pos.x && pos_mouse.x <= pos.x + size.x && pos_mouse.y >= pos.y && pos_mouse.y <= pos.y + size.y)
        return sfTrue;
    else
        return sfFalse;
}

int menu()
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    window = sfRenderWindow_create(mode, "CasinoLand", sfResize | sfClose, NULL);
    float rotationAngle = 0.0f;
    sfClock *clock = sfClock_create();
    float minutor = 0.5;
    int chrono = 0;
    sfEvent event;
    sfSprite *sprite[11];
    sfTexture *texture[11];
    char *arr[11] = {"Casino_menu/1.png", "Casino_menu/2.png", "Casino_menu/3.png", "Casino_menu/4.png", "Casino_menu/5.png",
    "Casino_menu/6.png", "Casino_menu/7.png", "Casino_menu/8.png", "Casino_menu/9.png", "Casino_menu/10.png", "Casino_menu/11.png"};
    sfVector2f pos[5] = {{758.5, 475.6}, {758.5, 659.7}, {758.5, 844.3}, {86, 71.2}, {239.6, 65.8}};
    sfVector2f size[5] = {{403.1, 151.2}, {403.1, 151.2}, {403.1, 151.2}, {86.3, 86.3}, {97.2, 97.2}};
    sfVector2i pos_mouse;
    sfMusic *music = sfMusic_createFromFile("son/spin.ogg");
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile("son/click.ogg");
    float volume = 50;
    int somme = 1000;
    char name[120];
    int num = 0;
    int mises = 0;
    float num_ale = 0;
    int lolo = 0;
    int fd = 0;
    record_t *record = NULL;
    record_t *temp = NULL;

    load(&record);
    name[0] = 0;
    for (int a = 0; a < 11; a++)
        create_sprite(&sprite[a], &texture[a], arr[a]);
    sfMusic_setVolume(music, volume);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buffer);
    if (!window)
        return 1;
    while (sfRenderWindow_isOpen(window)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft && check_colliMouse(pos[2], size[2], pos_mouse) == sfTrue))
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft) {
                if (check_colliMouse(pos[4], size[4], pos_mouse) == sfTrue)
                    menu_about(window, event);
                if (check_colliMouse(pos[3], size[3], pos_mouse) == sfTrue)
                    menu_setting(window, event, music, sound, &volume);
                if (check_colliMouse(pos[1], size[1], pos_mouse) == sfTrue)
                    records(window, event, record, sound);
                if (check_colliMouse(pos[0], size[0], pos_mouse) == sfTrue) {
                    loading(window, event);
                    if (login(window, event, sound, name) == 1) {
                        while (sfRenderWindow_isOpen(window)) {
                            lolo = mise(window, event, name, somme, sound, &num, &mises);
                            if (lolo == 0) {
                                adder(name, somme, &record);
                                break;
                            }
                            if (lolo == 1) {
                                num_ale = roue(window, event, num, mises, name, somme, sound);
                                if (answers(window, event, name, &somme, sound, (int)num_ale, num, mises, music, volume) == 0) {
                                    adder(name, somme, &record);
                                    break;
                                }
                            }
                        }
                    }
                    
                }
            }
        }
        sfRenderWindow_clear(window, sfBlue);
        if (check_colliMouse(pos[0], size[0], pos_mouse) == sfTrue) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfRenderWindow_drawSprite(window, sprite[2], NULL);
                sfSound_play(sound);
            } else
                sfRenderWindow_drawSprite(window, sprite[1], NULL);
        } else if(check_colliMouse(pos[1], size[1], pos_mouse) == sfTrue) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfRenderWindow_drawSprite(window, sprite[4], NULL);
                sfSound_play(sound);
            } else
                sfRenderWindow_drawSprite(window, sprite[3], NULL);
        } else if(check_colliMouse(pos[2], size[2], pos_mouse) == sfTrue) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfSound_play(sound);
                sfRenderWindow_drawSprite(window, sprite[6], NULL);
            } else
                sfRenderWindow_drawSprite(window, sprite[5], NULL);
        } else if(check_colliMouse(pos[3], size[3], pos_mouse) == sfTrue) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfRenderWindow_drawSprite(window, sprite[8], NULL);
                sfSound_play(sound);
            } else
                sfRenderWindow_drawSprite(window, sprite[7], NULL);
        } else if(check_colliMouse(pos[4], size[4], pos_mouse) == sfTrue) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                sfRenderWindow_drawSprite(window, sprite[10], NULL);
                sfSound_play(sound);
            } else
                sfRenderWindow_drawSprite(window, sprite[9], NULL);
        } else
            sfRenderWindow_drawSprite(window, sprite[0], NULL);
        sfRenderWindow_display(window);
    }
    for (int a = 0; a < 11; a++){
        sfSprite_destroy(sprite[a]);
        sfTexture_destroy(texture[a]);
    }
    if (record != NULL)
        save(record);
    sfMusic_destroy(music);
    sfSound_destroy(sound);
    sfSoundBuffer_destroy(buffer);
    sfRenderWindow_destroy(window);
    return 0;
}