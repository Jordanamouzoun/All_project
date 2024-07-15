/*
** EPITECH PROJECT, 2023
** B-MUL-200-COT-2-1-mypaint-deschanel.mondote
** File description:
** open.c
*/

#include "paint.h"

int my_strlen(char *str)
{
    int a = 0;

    for (a; str[a] != '\0'; a++);
    return a;
}

char *my_strdup(char *str)
{
    char *src = malloc((my_strlen(str) + 1) * sizeof(char));
    int a;

    for (a = 0; str[a] != '\0'; a++) {
        src[a] = str[a];
    }
    src[a] = '\0';
    return src;
}

int setting_file(lis_t **list, menu_t *win, win_t *wins)
{
    lis_t *temp = *list;

    for (int a = 1; temp != NULL; temp = temp->next) {
        temp->rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(temp->rect, (sfVector2f){0, 50 * a});
        sfRectangleShape_setOutlineColor(temp->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(temp->rect, 1.5);
        sfRectangleShape_setFillColor(temp->rect, sfTransparent);
        sfRectangleShape_setSize(temp->rect, (sfVector2f){1200, 50});
        temp->text = sfText_create();
        sfText_setFont(temp->text, wins->font);
        sfText_setFillColor(temp->text, sfBlack);
        sfText_setScale(temp->text, (sfVector2f){0.5, 0.5});
        sfText_setString(temp->text, temp->str);
        sfText_setPosition(temp->text, (sfVector2f){20, 50 * a + 20});
        a++;
    }
}

int add_fin(void *data, char *str)
{
    lis_t **students = (lis_t **)data;
    lis_t *student = malloc(sizeof(lis_t));
    lis_t *temp;

    student->str = my_strdup(str);
    student->next = NULL;
    if ((*students) == NULL)
        (*students) = student;
    else {
        temp = (*students);
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = student;
    }
}

int show2(lis_t **list)
{
    struct dirent *enter;
    DIR *rep;

    rep = opendir(".");
    enter = readdir(rep);
    while (enter != NULL) {
        if (verif_image(enter->d_name) == 1)
            add_fin(list, enter->d_name);
        enter = readdir(rep);
    }
    closedir(rep);
}
