/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my.h
*/
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#ifndef MY_H
    #define MY_H
typedef struct hun {
    sfClock *clock;
    int goal;
    sfTime times;
    float seconds;
    sfRenderWindow *window;
    sfWindow *win;
    sfVideoMode video_mode;
    sfEvent event;
    sfText *score;
    char *str;
    sfFont *record;
    sfIntRect rect_grd;
    sfIntRect rect_bird;
    sfIntRect rect_bird1;
    sfIntRect rect_kill;
    sfVector2i pos_mouse;
    sfVector2f pst;
    sfMouseButtonEvent evening;
    sfSound *jump;
    sfSoundBuffer *jomp;
    sfMusic *mario;
    sfTexture *txt_ground;
    sfTexture *txt_bird;
    sfTexture *txt_bird1;
    sfTexture *txt_cursor;
    sfTexture *txt_kill;
    sfTexture *txt_start;
    sfSprite *spt_ground;
    sfSprite *spt_bird;
    sfSprite *spt_bird1;
    sfSprite *spt_cursor;
    sfSprite *spt_kill;
    sfSprite *spt_start;
    sfVector2f pos_bird;
    sfVector2f scl_bird;
    sfVector2f pos_bird1;
    sfVector2f scl_bird1;
    sfVector2f pos_cursor;
    sfVector2f scl_cursor;
    sfVector2f pos_kill;
    sfVector2f scl_kill;
    sfVector2f scl_start;
    sfVector2f pos_start;
    sfVector2f posi_mouse;
} hun_t;

void even(hun_t *evt);
void call(hun_t *win);
void call2(hun_t *win);
void call3(hun_t *win);
void menu(hun_t *win);
void display(hun_t *win);
void hunt_bird(hun_t *win);
void hunt_bird1(hun_t *win);
char *main1(int nb);
int my_putstr(char *str);
void describ(void);
void destroy(hun_t *win);
void mv_rect(hun_t *win);
void clock1(hun_t *win);
#endif
