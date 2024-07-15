/*
** EPITECH PROJECT, 2024
** outils
** File description:
** outils
*/
#include "paint.h"
int file(win_t *win)
{
    sfTexture *texture = sfTexture_createFromFile("./sp/fichier.png", NULL);
    sfVector2f position = {15, 15};
    sfVector2f scale = {0.15, 0.15};

    win->new_file.position = setting_size(310, 230, 700, 400);
    win->new_file.cont = setting_color(sfBlack, sfWhite);
    win->new_file.size_bord = 0.5;
    win->new_file.button = init_button(win->new_file);
    win->file = sfSprite_create();
    sfSprite_setTexture(win->file, texture, sfTrue);
    sfSprite_setScale(win->file, scale);
    sfSprite_setPosition(win->file, position);
}

int modify(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/save.jpg", NULL);
    sfVector2f position = {110, 20};
    sfVector2f scale = {0.15, 0.15};

    win->modify = sfSprite_create();
    sfSprite_setTexture(win->modify, texture, sfTrue);
    sfSprite_setScale(win->modify, scale);
    sfSprite_setPosition(win->modify, position);
}

int save(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/save.png", NULL);
    sfVector2f position = {210, 18};
    sfVector2f scale = {0.15, 0.15};

    win->save = sfSprite_create();
    sfSprite_setTexture(win->save, texture, sfTrue);
    sfSprite_setScale(win->save, scale);
    sfSprite_setPosition(win->save, position);
}

int tools(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/crayon.png", NULL);
    sfVector2f position = {310, 10};
    sfVector2f scale = {0.15, 0.15};

    win->tools = sfSprite_create();
    sfSprite_setTexture(win->tools, texture, sfTrue);
    sfSprite_setScale(win->tools, scale);
    sfSprite_setPosition(win->tools, position);
}

int outils(win_t *win)
{
    win->texture = sfTexture_createFromFile("./sp/crayon.png", NULL);
    win->point = sfCircleShape_create();
    sfCircleShape_setRadius(win->point, 2.0);
    sfCircleShape_setFillColor(win->point, sfBlack);
    paintint(win);
    circle(win);
    gum(win);
    pinceau(win);
    file(win);
    modify(win);
    save(win);
    tools(win);
    size(win);
    formes(win);
}
