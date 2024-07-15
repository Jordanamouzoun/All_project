/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** help_button.c
*/

#include "paint.h"

int evening(win_t *pt, help_t *win)
{
    while (sfRenderWindow_pollEvent(win->win, &(win->event))) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->win);
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(pt->win);
    }
}

char *load_file_in_mem(char const *filepath)
{
    int fd;
    struct stat inf;
    char *s;
    char *src;
    int long size;

    stat(filepath, &inf);
    s = malloc((inf.st_size)* sizeof(char));
    fd = open(filepath, O_RDONLY);
    size = read(fd, s, inf.st_size);
    s[size] = '\0';
    close(fd);
    return s;
}

int create_helping(win_t *pt)
{
    help_t *win = malloc(sizeof(help_t));

    win->mod.width = 1920;
    win->mod.height = 1080;
    win->mod.bitsPerPixel = 32;
    win->win = sfRenderWindow_create(win->mod, "HELP",
    sfClose | sfResize, NULL);
    pt->helpos = load_file_in_mem("helping");
    sfText_setString(pt->test, pt->helpos);
    while (sfRenderWindow_isOpen(win->win)) {
        evening(pt, win);
        sfRenderWindow_clear(win->win, sfWhite);
        sfRenderWindow_drawText(win->win, pt->test, NULL);
        sfRenderWindow_display(win->win);
    }
    sfRenderWindow_destroy(win->win);
}

int helping(win_t *win)
{
    win->help_rect = sfRectangleShape_create();
    win->test = sfText_create();
    sfText_setFont(win->test, win->font);
    sfText_setFillColor(win->test, sfBlack);
    sfText_setScale(win->test, (sfVector2f){1, 1});
    sfText_setPosition(win->test, (sfVector2f){20, 20});
    sfRectangleShape_setPosition(win->help_rect, (sfVector2f){1780, 0});
    sfRectangleShape_setOutlineColor(win->help_rect, sfBlack);
    sfRectangleShape_setOutlineThickness(win->help_rect, 1);
    sfRectangleShape_setFillColor(win->help_rect, sfWhite);
    sfRectangleShape_setSize(win->help_rect, (sfVector2f){140, 140});
    win->help_spt = sfSprite_create();
    win->help_txt = sfTexture_createFromFile("sp/helping.png", NULL);
    sfSprite_setTexture(win->help_spt, win->help_txt, sfTrue);
    sfSprite_setPosition(win->help_spt, (sfVector2f){1790, 5});
    sfSprite_setScale(win->help_spt, (sfVector2f){0.5, 0.5});
}
