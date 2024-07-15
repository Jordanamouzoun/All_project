/*
** EPITECH PROJECT, 2024
** rectangle
** File description:
** rectangle
*/
#include "paint.h"
sfRectangleShape *create_rectangle(sfVector2f position)
{
    sfVector2f size = {125, 125};
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setOutlineColor(rectangle, sfBlack);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangle, 3);
    sfRectangleShape_setSize(rectangle, size);
    return rectangle;
}
