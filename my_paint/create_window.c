/*
** EPITECH PROJECT, 2024
** create window
** File description:
** create window
*/
#include "paint.h"
void crt_window(int argc, char **argv)
{
    win_t *win = malloc(sizeof(win_t));
    tab_button_t *tab = malloc(12 * sizeof(tab_button_t));
    sfVector2f position1 = {650, 200};
    sfVector2f position = {750, 300};
    double radius = 0.2;

    win->check1 = 0;
    win->check2 = 0;
    win->forme_rec = create_rectangle(position1);
    help_paint(win, tab);
    win->txt = sfTexture_create(1920, 1080);
    while (sfRenderWindow_isOpen(win->win)) {
        actu_tool(win);
        even(win, tab);
        help_crt_window(win);
        help_events2(win);
        display(win, tab, win->points, win->nbPoints);
    }
    destroy_points(win->points, win->nbPoints);
    destroy(win, tab);
}
