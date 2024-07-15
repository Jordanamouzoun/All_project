/*
** EPITECH PROJECT, 2024
** help outils
** File description:
** help outils
*/

#include "paint.h"
int formes(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/square.png", NULL);
    sfVector2f position = {600, 25};
    sfVector2f scale = {0.1, 0.1};

    win->formes = sfSprite_create();
    sfSprite_setTexture(win->formes, texture, sfTrue);
    sfSprite_setScale(win->formes, scale);
    sfSprite_setPosition(win->formes, position);
}

int circle(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/dry-clean.png", NULL);
    sfVector2f position = {700, 25};
    sfVector2f scale = {0.1, 0.1};

    win->circle = sfSprite_create();
    sfSprite_setTexture(win->circle, texture, sfTrue);
    sfSprite_setScale(win->circle, scale);
    sfSprite_setPosition(win->circle, position);
}

int gum(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/gomme.png", NULL);
    sfVector2f position = {370, 7};
    sfVector2f scale = {0.06, 0.06};

    win->gum = sfSprite_create();
    sfSprite_setTexture(win->gum, texture, sfTrue);
    sfSprite_setScale(win->gum, scale);
    sfSprite_setPosition(win->gum, position);
}

int paintint(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/paint.png", NULL);
    sfVector2f position = {310, 60};
    sfVector2f scale = {0.06, 0.06};

    win->paint = sfSprite_create();
    sfSprite_setTexture(win->paint, texture, sfTrue);
    sfSprite_setScale(win->paint, scale);
    sfSprite_setPosition(win->paint, position);
}

int pinceau(win_t *win)
{
    sfTexture * texture = sfTexture_createFromFile("./sp/brush.png", NULL);
    sfVector2f position = {380, 60};
    sfVector2f scale = {0.06, 0.06};

    win->pinceau = sfSprite_create();
    sfSprite_setTexture(win->pinceau, texture, sfTrue);
    sfSprite_setScale(win->pinceau, scale);
    sfSprite_setPosition(win->pinceau, position);
}
