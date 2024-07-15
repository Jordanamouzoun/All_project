/*
** EPITECH PROJECT, 2024
** zcasino_graph
** File description:
** rotate_letter.c
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

int main() {
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    window = sfRenderWindow_create(mode, "Rotation d'une lettre avec CSFML", sfResize | sfClose, NULL);

    if (!window)
        return 1;

    // Charger la police de caractères
    sfFont *font = sfFont_createFromFile("font.TTF");
    if (!font) {
        printf("Impossible de charger la police\n");
        return 1;
    }

    // Créer un objet texte
    char *c[2] = {"1", NULL};
    sfText *text = sfText_create();
    sfText_setString(text, c[0]);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50); // Taille du texte
    sfText_setFillColor(text, sfWhite); // Couleur du texte

    // Positionner le texte au centre de la fenêtre
    sfFloatRect textRect = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){textRect.width / 2, textRect.height / 2});

    float radius = 100.0f; // Rayon de rotation
    float angle = 0.0f; // Angle initial

    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfTime elapsed = sfClock_getElapsedTime(clock);
        float deltaTime = sfTime_asSeconds(elapsed);
        sfClock_restart(clock);

        // Mettre à jour l'angle de rotation
        angle += deltaTime;

        // Calculer la nouvelle position de la lettre
        float x = 400 + radius * cos(angle);
        float y = 300 + radius * sin(angle);
        sfText_setPosition(text, (sfVector2f){x, y});
        
        // Optionnel : mettre à jour la rotation du texte lui-même
        sfText_setRotation(text, angle * 180 / PI);

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }

    // Nettoyage des ressources
    sfText_destroy(text);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
    sfClock_destroy(clock);
    return 0;
}
