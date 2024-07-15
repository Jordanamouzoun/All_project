/*
** EPITECH PROJECT, 2024
** zcasino_graph
** File description:
** test.c
*/

#include "../include/casino.h"

#define PI 3.14159265358979323846

void drawSlice(sfRenderWindow *window, sfVector2f center, float radius, float startAngle, float endAngle, sfColor color, char *str)
{
    sfVertexArray *triangle = sfVertexArray_create();
    sfVertex vertex;
    sfFont *font = sfFont_createFromFile("Casino_menu/Casino Bar.otf");
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfWhite);
    sfVertexArray_setPrimitiveType(triangle, sfTrianglesFan);
    vertex.color = color;
    vertex.position = center;
    float angles = startAngle;//(startAngle + endAngle) / 2.0;
    float x = center.x + (radius - 40.0) * cos(angles);
    float y = center.y + (radius - 40.0) * sin(angles);
    sfText_setPosition(text, (sfVector2f){x, y});
    sfText_setRotation(text, angles * 180 / PI);
    sfVertexArray_append(triangle, vertex);
    for (float angle = startAngle; angle <= endAngle; angle += 0.001f) {
        vertex.position.x = center.x + radius * cos(angle);
        vertex.position.y = center.y + radius * sin(angle);
        sfVertexArray_append(triangle, vertex);
    }
    sfRenderWindow_drawVertexArray(window, triangle, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfVertexArray_destroy(triangle);
}

void drawRoue(sfRenderWindow *window, int l, float radius, float rotationAngle)
{
    sfVector2f center = {960, 450};
    float angleIncrement = PI / (l / 2);
    sfColor colors[2] = {sfRed, sfBlack};
    char *arr[50] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25"
    , "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50"};
    int bin = 0;

    for (int i = 0; i < l; ++i) {
        bin = i % 2;
        drawSlice(window, center, radius, (i * angleIncrement + rotationAngle), ((i + 1) * angleIncrement + rotationAngle), colors[bin], arr[49-i]);
    }
}

float roue(sfRenderWindow *window, sfEvent event, int num, int mise, char *name, int somme, sfSound *sound)
{
    float rotationAngle = 0.0f;
    sfClock *clock = sfClock_create();
    float minutor = -7.2;
    float chrono = 1;
    int num_ale = 1;
    int min = 0;
    sfSprite *sprite = sfSprite_create();
    sfSprite *spt_roue = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("Casino_menu/game/21.png", NULL);
    sfTexture *txt_roue = sfTexture_createFromFile("Casino_menu/game/roue.png", NULL);
    sfFont* font = sfFont_createFromFile("Casino_menu/Casino Bar.otf");
    sfText *text[2];
    sfVector2f pos[2] = {{297.4, 37.2}, {297.4, 123.5}};
    char buf[3][14];

    for (int a = 0; a < 2; a++){
        text[a] = sfText_create();
        sfText_setCharacterSize(text[a], 40);
        sfText_setColor(text[a], sfBlack);
        sfText_setPosition(text[a], pos[a]);
        sfText_setFont(text[a], font);
    }
    sprintf(buf[0], "%d", num);
    sfText_setString(text[0], buf[0]);
    sprintf(buf[1], "%d", mise);
    sfText_setString(text[1], buf[1]);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(spt_roue, txt_roue, sfTrue);
    sfSprite_setScale(spt_roue, (sfVector2f){1.2094, 1.209418838});
    sfVector2u size = sfTexture_getSize(txt_roue);
    sfVector2f origin = {(float)size.x / 2, (float)size.y / 2};
    sfSprite_setOrigin(spt_roue, origin);
    sfSprite_setPosition(spt_roue, (sfVector2f){660 + (float)size.x / 2 + 50, 175.3 + (float)size.y / 2 + 60});
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
                minutor = 0;
            }
        }
        if (minutor != 0) {
            sfTime elapsed = sfClock_getElapsedTime(clock);
            float seconds = elapsed.microseconds / 10000.0;
            if (seconds > 0.1) {
                sfSprite_rotate(spt_roue, minutor);
                chrono++;
                if (chrono == 51)
                    chrono = 1;
                sfClock_restart(clock);
            }
        } else {
            sfTime elapsed = sfClock_getElapsedTime(clock);
            float seconds = elapsed.microseconds / 1000000.0;
            if (seconds > 1) {
                min++;
                if (min == 3)
                    break;
                sfClock_restart(clock);
            }
        }
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, spt_roue, NULL);
        for (int a = 0; a < 2; a++) {
            sfRenderWindow_drawText(window, text[a], NULL);
        }
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfSprite_destroy(spt_roue);
    sfTexture_destroy(txt_roue);
    sfText_destroy(text[0]);
    sfText_destroy(text[1]);
    sfFont_destroy(font);
    return chrono;
}
