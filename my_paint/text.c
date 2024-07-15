/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** text.c
*/

#include "paint.h"

int help_setting_text(win_t *win)
{
    sfText_setPosition(win->text[4], (sfVector2f){475, 100});
    sfText_setString(win->text[4], "Size");
    sfText_setPosition(win->text[5], (sfVector2f){660, 100});
    sfText_setString(win->text[5], "Forms");
    sfText_setPosition(win->text[6], (sfVector2f){1840, 100});
    sfText_setString(win->text[6], "Help");
}

int setting_text(win_t *win)
{
    win->font = sfFont_createFromFile("fonts.otf");
    win->text = malloc(7 * sizeof(sfText *));
    for (int a = 0; a < 7; a++) {
        win->text[a] = sfText_create();
        sfText_setFont(win->text[a], win->font);
        sfText_setFillColor(win->text[a], sfBlack);
        sfText_setScale(win->text[a], (sfVector2f){0.5, 0.5});
    }
    sfText_setPosition(win->text[0], (sfVector2f){35, 100});
    sfText_setString(win->text[0], "File");
    sfText_setPosition(win->text[1], (sfVector2f){125, 100});
    sfText_setString(win->text[1], "Modify");
    sfText_setPosition(win->text[2], (sfVector2f){235, 100});
    sfText_setString(win->text[2], "Save");
    sfText_setPosition(win->text[3], (sfVector2f){350, 100});
    sfText_setString(win->text[3], "Tools");
    help_setting_text(win);
}
