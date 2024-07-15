/*
** EPITECH PROJECT, 2024
** zcasino_graph
** File description:
** test.c
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846

void drawSlice(sfRenderWindow *window, sfVector2f center, float radius, float startAngle, float endAngle, sfColor color, char *str)
{
    sfVertexArray *triangle = sfVertexArray_create();
    sfVertex vertex;
    sfFont *font = sfFont_createFromFile("font.TTF");
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 25);
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
    sfVector2f center = {960, 540};
    float angleIncrement = PI / (l / 2);
    sfColor colors[2] = {sfRed, sfBlack};
    char *arr[50] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25"
    , "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50"};
    int bin = 0;

    for (int i = 0; i < l; ++i) {
        bin = i % 2;
        drawSlice(window, center, radius, (i * angleIncrement + rotationAngle), ((i + 1) * angleIncrement + rotationAngle), colors[bin], arr[i]);
    }
}

int main() {
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    window = sfRenderWindow_create(mode, "Cercle avec des quartiers de gâteau", sfResize | sfClose, NULL);
    float rotationAngle = 0.0f;
    sfClock *clock = sfClock_create();
    float minutor = 0.5;
    int chrono = 0;

    if (!window)
        return 1;
    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfTime elapsed = sfClock_getElapsedTime(clock);
        float seconds = elapsed.microseconds / 1000000.0;
        if (seconds > 0.1) {
            if (sfKeyboard_isKeyPressed(sfKeySpace))
                minutor = 0;
            sfClock_restart(clock);
        }
        rotationAngle += minutor;
        sfRenderWindow_clear(window, sfBlue);

        drawRoue(window, 50, 400, (rotationAngle));

        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}
