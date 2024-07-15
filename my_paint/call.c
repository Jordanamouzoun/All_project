/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** call.c
*/

#include "paint.h"

int call2(win_t *win, tab_button_t *tab)
{
    for (int a = 0; a < 3; a++)
        tab[a].position = setting_size(a * 100, 0, 100, 140);
    tab[3].position = setting_size(300, 0, 140, 140);
    tab[4].position = setting_size(440, 0, 100, 140);
    tab[5].position = setting_size(540, 0, 300, 140);
    tab[6].position = setting_size(840, 0, 940, 140);
    tab[7].position = setting_size(310, 230, 1300, 660);
    tab[8].position = setting_size(440, 140, 100, 100);
    tab[9].position = setting_size(440, 240, 100, 100);
    tab[10].position = setting_size(440, 340, 100, 100);
    tab[11].position = setting_size(50, 140, 200, 60);
    for (int a = 0; a < 12; a++) {
        tab[a].cont = setting_color(sfBlack, sfWhite);
        tab[a].size_bord = 0.5;
        tab[a].button = init_button(tab[a]);
    }
    tab[7].cont = &win->font_color;
    circle_create(win);
    create_ep(win);
}
