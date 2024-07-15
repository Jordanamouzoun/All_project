/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** hunter game
*/

#include "my.h"

char *main1(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 100000);
    char *src = malloc(sizeof(char) * 100000);
    int a;
    int j = 0;

    for (a = 0; nb != 0; a++) {
        i = nb % 10;
        nb = nb / 10;
        str[a] = '0' + i;
    }
    for (a -= 1; a >= 0; a--) {
        src[j] = str[a];
        j++;
    }
    return src;
    free(str);
    free(src);
}

void call3(hun_t *win)
{
    win->goal = 0;
    win->str = malloc(1000 * sizeof(char));
    win->score = sfText_create();
    win->record = sfFont_createFromFile("font.TTF");
    win->jump = sfSound_create();
    win->jomp = sfSoundBuffer_createFromFile("mario_jump.ogg");
    sfSound_setBuffer(win->jump, win->jomp);
    win->pos_kill.x = 1000;
    win->pos_kill.y = 1000;
    sfSprite_setPosition(win->spt_kill, win->pos_kill);
    win->txt_start = sfTexture_createFromFile("star.png", NULL);
    win->spt_start = sfSprite_create();
    sfSprite_setTexture(win->spt_start, win->txt_start, sfTrue);
    win->pos_start.x = 300;
    win->pos_start.y = 200;
    sfSprite_setPosition(win->spt_start, win->pos_start);
}

void hunt_bird(hun_t *win)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSound_play(win->jump);
        if ((win->pos_mouse.x >= win->pos_bird.x - 110 &&
        win->pos_mouse.x <= win->pos_bird.x + 110) &&
        (win->pos_mouse.y >= win->pos_bird.y -110 &&
        win->pos_mouse.y <= win->pos_bird.y + 110)) {
            win->pos_kill.x = win->pos_bird.x;
            win->pos_kill.y = win->pos_bird.y;
            sfSprite_setPosition(win->spt_kill, win->pos_kill);
            win->goal++;
            win->pos_bird.x = 900;
        }
    }
}

void hunt_bird1(hun_t *win)
{
    if ((win->pos_mouse.x >= win->pos_bird1.x - 60 &&
    win->pos_mouse.x <= win->pos_bird1.x + 60) &&
    (win->pos_mouse.y >= win->pos_bird1.y - 30 &&
    win->pos_mouse.y <= win->pos_bird1.y + 30)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            win->pos_kill.x = win->pos_bird1.x;
            win->pos_kill.y = win->pos_bird1.y;
            sfSprite_setPosition(win->spt_kill, win->pos_kill);
            win->goal++;
            win->pos_bird1.y = -65;
        }
    }
}

void destroy(hun_t *win)
{
    sfRenderWindow_destroy(win->window);
    sfSprite_destroy(win->spt_bird1);
    sfMusic_destroy(win->mario);
    sfSound_destroy(win->jump);
    sfSoundBuffer_destroy(win->jomp);
    sfTexture_destroy(win->txt_ground);
    sfTexture_destroy(win->txt_bird);
    sfTexture_destroy(win->txt_bird1);
    sfTexture_destroy(win->txt_cursor);
    sfTexture_destroy(win->txt_kill);
    sfTexture_destroy(win->txt_start);
    sfSprite_destroy(win->spt_bird);
    sfSprite_destroy(win->spt_ground);
    sfSprite_destroy(win->spt_cursor);
    sfSprite_destroy(win->spt_kill);
    sfClock_destroy(win->clock);
}
