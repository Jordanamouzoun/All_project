/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** radar.h
*/
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <dirent.h>
#include <stddef.h>
#ifndef PAINT_H
    #define PAINT_H
enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};
typedef struct help {
    sfRenderWindow *win;
    sfEvent event;
    sfVideoMode mod;
} help_t;
typedef struct lis {
    sfRectangleShape *rect;
    sfText *text;
    char *str;
    struct lis *next;
} lis_t;
typedef struct menu {
    sfRenderWindow *win;
    sfEvent event;
    sfVideoMode mod;
    sfVector2i pos_mouse;
} menu_t;
typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
    enum e_gui_state state;
}button_s_t;
typedef struct tab_button {
    button_s_t *button;
    sfVector2f *position;
    float size_bord;
    sfColor *cont;
} tab_button_t;
typedef struct win {
    sfRenderWindow *win;
    sfEvent event;
    sfVideoMode mod;
    sfVector2i pos_mouse;
    sfCircleShape **cercle;
    sfText **text;
    sfFont *font;
    sfCircleShape *point;
    sfSprite *file;
    sfSprite *pen;
    sfSprite *actu_tool;
    tab_button_t new_file;
    sfSprite *gum;
    sfSprite *paint;
    sfSprite *pinceau;
    sfSprite *tools;
    sfSprite *square;
    sfCircleShape *points[500000];
    sfColor font_color;
    sfSprite *circle;
    int nbPoints;
    sfSprite *create_circle;
    sfSprite *size;
    sfSprite *formes;
    sfSprite *save;
    sfSprite *modify;
    sfCircleShape *forme_circle;
    sfRectangleShape *forme_rec;
    sfTexture *texture;
    sfSprite *image_spt;
    sfTexture *image_txt;
    char *src;
    int verif;
    int check1;
    int check2;
    int verif2;
    int verif3;
    int i;
    sfSprite *help_spt;
    sfTexture *help_txt;
    sfRectangleShape *help_rect;
    char *helpos;
    sfText *test;
    sfImage *image;
    sfTexture *txt;
} win_t;
typedef struct spri {
    sfSprite **sprite;
    sfVector2f *pos;
    sfVector2f *size;
}spri_t;
int helping(win_t *win);
int help_scan(menu_t *win, lis_t *list, win_t *wins);
int size_pen(win_t *win);
void crt_window(int argc, char **argv);
int help_crt_window(win_t *win);
int help_paint(win_t *win, tab_button_t *tab);
sfCircleShape *create_circle2(sfVector2f position, double radius, win_t *win);
int create_helping(win_t *pt);
sfRectangleShape *create_rectangle(sfVector2f position);
int new_file(win_t *win);
int forme_circle(win_t *win);
int actu_tool(win_t *win);
int draw_image(win_t *win);
sfBool verif_hovering(sfRectangleShape *rect, float x, float y);
int verif_image(char *str);
int my_strlen(char *str);
int circle_create(win_t *win);
sfBool verif_color(sfCircleShape *circle, win_t *win);
int dessin(win_t *win, sfCircleShape *point);
int outils(win_t *win);
int formes(win_t *win);
int setting_text(win_t *win);
int draw_cercle(win_t *win);
int circle(win_t *win);
int gum(win_t *win);
int help_events2(win_t *win);
int size(win_t *win);
int pinceau(win_t *win);
int paintint(win_t *win);
int create_button(win_t *win, tab_button_t *tab);
sfBool verif_hover(struct button_s *button, float x, float y);
void even(win_t *evt, tab_button_t *button);
sfColor creat_color(sfUint8 a, sfUint8 b, sfUint8 g, sfUint8 r);
sfBool verif_click(struct button_s *button, float x, float y, int l);
void destroy(win_t *win, tab_button_t *button);
void call(win_t *win, tab_button_t *button);
void display(win_t *win, tab_button_t *tab,
    sfCircleShape **points, int nbPoints);
void crt_window(int argc, char **argv);
int help_events(win_t *win, sfColor *Colors);
int events(win_t *win);
int modify(win_t *win);
int destroy_points(sfCircleShape **points, int nbPoints);
void even(win_t *evt, tab_button_t *tab);
button_s_t *init_button(tab_button_t tab);
sfVector2f *setting_size(float xp, float yp, float xs, float ys);
sfColor *setting_color(sfColor outline, sfColor fill);
int call2(win_t *win, tab_button_t *tab);
int verif_button(win_t *win, tab_button_t *tab);
int create_button(win_t *win, tab_button_t *tab);
int create_ep(win_t *win);
int drawing_circle(win_t *win);
int drawing_search(win_t *win, tab_button_t *tab);
void display1(win_t *win, tab_button_t *tab);
char *scan(win_t *win);
int setting_text(win_t *win);
sfCircleShape *create_circle(sfVector2f position, double radius);
char *my_strdup(char *str);
int setting_file(lis_t **list, menu_t *win, win_t *wins);
int add_fin(void *data, char *str);
int show2(lis_t **list);
void display2(win_t *win, tab_button_t *tab);
#endif
