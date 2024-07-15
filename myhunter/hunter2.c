/*
** EPITECH PROJECT, 2023
** hunter
** File description:
** second files
*/
#include "my.h"

void call2(hun_t *win)
{
    win->mario = sfMusic_createFromFile("mario.ogg");
    sfMusic_play(win->mario);
    win->txt_cursor = sfTexture_createFromFile("psn.png", NULL);
    win->txt_kill = sfTexture_createFromFile("titi.png", NULL);
    win->spt_cursor = sfSprite_create();
    win->spt_kill = sfSprite_create();
    sfSprite_setTexture(win->spt_cursor, win->txt_cursor, sfTrue);
    sfSprite_setTexture(win->spt_kill, win->txt_kill, sfTrue);
    win->scl_cursor.x = 0.10;
    win->scl_cursor.y = 0.10;
    sfSprite_setScale(win->spt_cursor, win->scl_cursor);
    win->rect_kill.left = 0;
    win->rect_kill.top = 0;
    win->rect_kill.width = 56;
    win->rect_kill.height = 30;
    sfSprite_setTextureRect(win->spt_kill, win->rect_kill);
    win->scl_kill.x = 2;
    win->scl_kill.y = 2;
    sfSprite_setScale(win->spt_kill, win->scl_kill);
    call3(win);
}

void mv_bird1(hun_t *win)
{
    if (win->pos_bird1.y > -65)
        win->pos_bird1.y -= 20;
    else {
        win->pos_bird1.y = 442;
        win->pos_bird1.x = (rand() % (800 - 5 + 1)) + 5;
    }
    sfSprite_setPosition(win->spt_bird1, win->pos_bird1);
    if (win->rect_bird1.left == 130)
        win->rect_bird1.left = 0;
    else
        win->rect_bird1.left += 65;
    sfSprite_setTextureRect(win->spt_bird1, win->rect_bird1);
}

void mv_bird(hun_t *win)
{
    if (win->pos_bird.x < 800)
        win->pos_bird.x += 20;
    else {
        win->pos_bird.x = -110;
        win->pos_bird.y = (rand() % (400 - 5 + 1)) + 5;
    }
    sfSprite_setPosition(win->spt_bird, win->pos_bird);
    if (win->rect_bird.left == 220)
        win->rect_bird.left = 0;
    else
        win->rect_bird.left += 110;
    sfSprite_setTextureRect(win->spt_bird, win->rect_bird);
}

void clock1(hun_t *win)
{
    win->times = sfClock_getElapsedTime(win->clock);
    win->seconds = win->times.microseconds / 100000.0;
    if (win->seconds > 1.0) {
        hunt_bird(win);
        hunt_bird1(win);
        mv_bird(win);
        mv_bird1(win);
        sfClock_restart(win->clock);
    }
}
