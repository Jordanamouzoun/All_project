/*
** EPITECH PROJECT, 2024
** CasinoLand
** File description:
** casino.h
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifndef MY_CASINO
    #define MY_CASINO
typedef struct record {
    char name[120];
    int somme;
    struct record *next;
} record_t;

void create_sprite(sfSprite **sprite, sfTexture **texture, char *str);
sfBool check_colliMouse(sfVector2f pos, sfVector2f size, sfVector2i pos_mouse);
int menu();
int login(sfRenderWindow *window, sfEvent event, sfSound *sound, char *str);
int menu_about(sfRenderWindow *window, sfEvent event);
int menu_setting(sfRenderWindow *window, sfEvent event, sfMusic *music, sfSound *sound, float *volume);
int loading(sfRenderWindow *window, sfEvent event);
int mise(sfRenderWindow *window, sfEvent event, char *name, int somme, sfSound *sound, int *num, int *mise);
int error(sfRenderWindow *window, sfEvent event);
float roue(sfRenderWindow *window, sfEvent event, int num, int mise, char *str, int somme, sfSound *sound);
int answers(sfRenderWindow *window, sfEvent event, char *name, int *somme, sfSound *sound, int num_ale, int num, int mise, sfMusic *music, int volume);
int add_debut(void *data, char *name, int somme);
int link_destroy(record_t *record);
int delete_last(record_t **record);
int load(record_t **record);
int save(record_t *record);
int records(sfRenderWindow *window, sfEvent event, record_t *record, sfSound *sound);
int adder(char *name, int somme, record_t **record);
#endif
