/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** fist graphical program
*/
#include "my.h"

void even(hun_t *evt)
{
    while (sfRenderWindow_pollEvent(evt->window, &(evt->event))) {
        if (evt->event.type == sfEvtClosed) {
            sfRenderWindow_close(evt->window);
        }
    }
}

void call1(hun_t *win)
{
    call2(win);
    win->scl_bird1.x = 2.2;
    win->scl_bird1.y = 2.2;
    win->clock = sfClock_create();
    win->txt_ground = sfTexture_createFromFile("je3.png", NULL);
    win->txt_bird = sfTexture_createFromFile("je1.png", NULL);
    win->txt_bird1 = sfTexture_createFromFile("im.png", NULL);
    win->spt_ground = sfSprite_create();
    win->spt_bird = sfSprite_create();
    win->spt_bird1 = sfSprite_create();
    sfSprite_setScale(win->spt_bird, win->scl_bird);
    sfSprite_setScale(win->spt_bird1, win->scl_bird1);
    sfSprite_setTexture(win->spt_ground, win->txt_ground, sfTrue);
    sfSprite_setTexture(win->spt_bird, win->txt_bird, sfTrue);
    sfSprite_setTexture(win->spt_bird1, win->txt_bird1, sfTrue);
    sfSprite_setTextureRect(win->spt_ground, win->rect_grd);
    sfSprite_setTextureRect(win->spt_bird, win->rect_bird);
    sfSprite_setTextureRect(win->spt_bird1, win->rect_bird1);
    win->window = sfRenderWindow_create(win->video_mode, "Window",
    sfClose | sfResize, NULL);
}

void call(hun_t *win)
{
    win->pos_bird.x = 0;
    win->pos_bird.y = 0;
    win->scl_bird.x = 0.75;
    win->scl_bird.y = 0.75;
    win->video_mode.width = 800;
    win->video_mode.height = 600;
    win->video_mode.bitsPerPixel = 32;
    win->rect_grd.left = 0;
    win->rect_grd.top = 0;
    win->rect_grd.width = 800;
    win->rect_grd.height = 600;
    win->rect_bird.left = 0;
    win->rect_bird.top = 0;
    win->rect_bird.width = 110;
    win->rect_bird.height = 110;
    win->rect_bird1.left = 0;
    win->rect_bird1.top = 0;
    win->rect_bird1.width = 60;
    win->rect_bird1.height = 30;
    call1(win);
}

void display(hun_t *win)
{
    sfText_setFont(win->score, win->record);
    win->str = main1(win->goal);
    sfText_setString(win->score, win->str);
    sfMusic_setLoop(win->mario, sfTrue);
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    win->pos_mouse = sfMouse_getPositionRenderWindow(win->window);
    win->pos_cursor.x = win->pos_mouse.x;
    win->pos_cursor.y = win->pos_mouse.y;
    sfSprite_setPosition(win->spt_cursor, win->pos_cursor);
    clock1(win);
    sfRenderWindow_clear(win->window, sfBlue);
    sfRenderWindow_drawSprite(win->window, win->spt_ground, NULL);
    sfRenderWindow_drawSprite(win->window, win->spt_bird, NULL);
    sfRenderWindow_drawSprite(win->window, win->spt_cursor, NULL);
    sfRenderWindow_drawSprite(win->window, win->spt_bird1, NULL);
    sfRenderWindow_drawSprite(win->window, win->spt_kill, NULL);
    sfRenderWindow_drawText(win->window, win->score, NULL);
    sfRenderWindow_display(win->window);
}

int main(int argc, char **argv)
{
    hun_t *win = malloc(sizeof(hun_t));

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        describ();
        return 0;
    }
    call(win);
    while (sfRenderWindow_isOpen(win->window)) {
        even(win);
        display(win);
    }
    destroy(win);
}
