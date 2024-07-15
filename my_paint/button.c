/*
** EPITECH PROJECT, 2023
** bspaint
** File description:
** button.c
*/

#include "paint.h"

button_s_t *init_button(tab_button_t tab)
{
    button_s_t *button = malloc(sizeof(button_s_t *));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, tab.position[0]);
    sfRectangleShape_setOutlineColor(button->rect, tab.cont[0]);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setFillColor(button->rect, tab.cont[1]);
    sfRectangleShape_setSize(button->rect, tab.position[1]);
    return button;
}

sfBool verif_click(struct button_s *button, float x, float y, int l)
{
    sfVector2f position = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (x >= position.x && x <= (position.x + size.x) &&
        y >= position.y && y <= (position.y + size.y))
            return sfTrue;
    }
    return sfFalse;
}

sfBool verif_hover(struct button_s *button, float x, float y)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&bound, x, y))
        return sfTrue;
    return sfFalse;
}

sfVector2f *setting_size(float xp, float yp, float xs, float ys)
{
    sfVector2f *posi = malloc(2 * sizeof(sfVector2f));

    posi[0].x = xp;
    posi[0].y = yp;
    posi[1].x = xs;
    posi[1].y = ys;
    return posi;
}

sfColor *setting_color(sfColor outline, sfColor fill)
{
    sfColor *color = malloc(2 * sizeof(sfColor));

    color[0] = outline;
    color[1] = fill;
    return color;
}
