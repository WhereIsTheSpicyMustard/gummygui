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

    float val = 0;
    bool val2 = 0;


    Slider* slider = gummygui_slider_create("Slider", &val, 0, 15, 50, 50, 400, 20, "%.3f");
    Toggle* toggle = gummygui_toggle_create(&val2, 50, 100, 50);


    while (!WindowShouldClose()) {
        gummygui_slider_update(slider);
        gummygui_toggle_update(toggle);


        BeginDrawing();
        ClearBackground(BEIGE);

        gummygui_slider_draw(slider, BEIGE, BLACK);
        gummygui_toggle_draw(toggle, BEIGE, BLACK);

        EndDrawing();
    }

    gummygui_slider_destroy(&slider);
    gummygui_toggle_destroy(&toggle);
    CloseWindow();
    return 0;
}
