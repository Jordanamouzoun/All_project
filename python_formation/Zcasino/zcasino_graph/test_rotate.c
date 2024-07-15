#include <SFML/Graphics.h>
#include <math.h>

#define PI 3.14159265358979323846

void drawSlice(sfRenderWindow *window, sfVector2f center, float radius, float startAngle, float endAngle, sfColor color)
{
    sfVertexArray *triangle = sfVertexArray_create();
    sfVertex vertex;

    sfVertexArray_setPrimitiveType(triangle, sfTrianglesFan);
    vertex.color = color;
    vertex.position = center;
    sfVertexArray_append(triangle, vertex);
    for (float angle = startAngle; angle <= endAngle; angle += 0.01f) {
        vertex.position.x = center.x + radius * cos(angle);
        vertex.position.y = center.y + radius * sin(angle);
        sfVertexArray_append(triangle, vertex);
    }
    sfRenderWindow_drawVertexArray(window, triangle, NULL);
    sfVertexArray_destroy(triangle);
}

int main() {
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    window = sfRenderWindow_create(mode, "Cercle avec des quartiers de gâteau", sfResize | sfClose, NULL);

    if (!window)
        return 1;

    sfVector2f center = {400, 300};
    float radius = 200;
    float angleIncrement = PI / 4;
    sfColor colors[8] = {
        sfRed, sfGreen, sfBlue, sfYellow, sfCyan, sfMagenta, sfWhite, sfBlack
    };

    float rotationAngle = 0.0f;

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

        rotationAngle += deltaTime; // Incrémenter l'angle de rotation

        sfRenderWindow_clear(window, sfBlack);

        for (int i = 0; i < 8; ++i) {
            float startAngle = i * angleIncrement + rotationAngle;
            float endAngle = (i + 1) * angleIncrement + rotationAngle;
            drawSlice(window, center, radius, startAngle, endAngle, colors[i]);
        }

        sfRenderWindow_display(window);
    }

    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
