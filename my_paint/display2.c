/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** display2.c
*/

#include "paint.h"

void display2(win_t *win, tab_button_t *tab)
{
    if (verif_click(tab[2].button, win->pos_mouse.x, win->pos_mouse.y, 0)
    == sfTrue) {
        sfTexture_updateFromRenderWindow(win->txt, win->win, 0, 0);
        win->image = sfTexture_copyToImage(win->txt);
        sfImage_saveToFile(win->image, "my_paint.jpg");
    }
    sfRenderWindow_drawRectangleShape(win->win, win->help_rect, NULL);
    sfRenderWindow_drawSprite(win->win, win->help_spt, NULL);
    sfRenderWindow_drawText(win->win, win->text[6], NULL);
    if (verif_hovering(win->help_rect, win->pos_mouse.x, win->pos_mouse.y)
    == sfTrue) {
        sfRectangleShape_setFillColor(win->help_rect,
        creat_color(255, 128, 128, 128));
        if (sfMouse_isButtonPressed(sfMouseLeft))
            create_helping(win);
    } else
        sfRectangleShape_setFillColor(win->help_rect, sfWhite);
}
