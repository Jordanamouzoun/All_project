/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** file_button.c
*/

#include "paint.h"

sfBool verif_hovering(sfRectangleShape *rect, float x, float y)
{
    sfFloatRect bound = sfRectangleShape_getGlobalBounds(rect);

    if (sfFloatRect_contains(&bound, x, y))
        return sfTrue;
    return sfFalse;
}
