/*
gcc -O2 -Wall -Wextra -Wpedantic *.c -o main $(pkg-config --cflags --libs raylib) -lm
*/

#include <stdio.h>
#include <stdbool.h>

#include "gui.h"
#include "raylib.h"

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 800;

int main(void)
{


    InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT, "GUI Test");

    float val1 = 0;
    bool val2 = 0;

    Slider* slider = gummygui_slider_create(&val1, 0, 255, 50, 50, 400);
    Toggle* toggle = gummygui_toggle_create(&val2, 50, 100, 50);

    if (slider == NULL || toggle ==  NULL) goto CLEANUP;

    while (!WindowShouldClose()) {
        gummygui_slider_update(slider);
        gummygui_toggle_update(toggle);

        Color slider_color = {255 * val2, val1, 200, 255};

        BeginDrawing();
        ClearBackground(slider_color);

        gummygui_slider_draw(slider, slider_color, BLACK);
        gummygui_toggle_draw(toggle, slider_color, BLACK);

        EndDrawing();
    }

CLEANUP:
    gummygui_slider_destroy(&slider);
    gummygui_toggle_destroy(&toggle);
    CloseWindow();
    return 0;
}
