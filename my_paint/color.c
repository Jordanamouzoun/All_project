/*
** EPITECH PROJECT, 2023
** bspaint
** File description:
** color.c
*/

#include "paint.h"

sfColor creat_color(sfUint8 a, sfUint8 b, sfUint8 g, sfUint8 r)
{
    sfColor couleur;

    couleur.a = a;
    couleur.b = b;
    couleur.g = g;
    couleur.r = r;
    return couleur;
}

int verif_image(char *str)
{
    int a = my_strlen(str) - 1;

    if (str[a] == 'g' && str[a - 1] == 'n' && str[a - 2] == 'p' &&
    str[a - 3] == '.')
        return 1;
    if (str[a] == 'g' && str[a - 1] == 'p' && str[a - 2] == 'j' &&
    str[a - 3] == '.')
        return 1;
    return 0;
}

int draw_image(win_t *win)
{
    sfVector2u size;

    if (win->src != NULL) {
        win->image_spt = sfSprite_create();
        win->image_txt = sfTexture_createFromFile(win->src, NULL);
        sfSprite_setTexture(win->image_spt, win->image_txt, sfTrue);
        size = sfTexture_getSize(win->image_txt);
        sfSprite_setScale(win->image_spt, (sfVector2f){1300 / size.x, 600 /
        size.y});
        sfSprite_setPosition(win->image_spt, (sfVector2f){310, 230});
        win->verif3++;
    }
}

sfBool verif_color(sfCircleShape *circle, win_t *win)
{
    sfVector2f position = sfCircleShape_getPosition(circle);
    sfVector2f size = sfCircleShape_getScale(circle);

    if (win->pos_mouse.x >= position.x &&
        win->pos_mouse.x <= (position.x + 30) &&
        win->pos_mouse.y >= position.y &&
        win->pos_mouse.y <= (position.y + 30))
            return sfTrue;
    return sfFalse;
}
