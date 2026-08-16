/*
gcc -O2 -Wall -Wextra -Wpedantic *.c -o main $(pkg-config --cflags --libs raylib) -lm
*/

#include <stdio.h>
#include <stdbool.h>

#include "gui.h"
#include "raylib.h"

int main(void)
{
    InitWindow(800, 800, "GUI Test");
    SetTargetFPS(60);

    float slider_val = 0;
    bool toggle_val = false;
    bool button_val = false;

    Slider* slider = gummygui_slider_create(&slider_val, 0, 255, 50, 50, 400);
    Toggle* toggle = gummygui_toggle_create(&toggle_val, 50, 100, 50);
    Button* button = gummygui_button_create(&button_val, 50, 150, 30, 60);

    if (slider == NULL || toggle ==  NULL) goto CLEANUP;

    while (!WindowShouldClose()) {
        gummygui_slider_update(slider);
        gummygui_toggle_update(toggle);
        gummygui_button_update(button);

        Color slider_color = {255 * toggle_val, slider_val, 200, 255};

        BeginDrawing();
        ClearBackground(slider_color);

        gummygui_slider_draw(slider, slider_color, BLACK);
        gummygui_toggle_draw(toggle, slider_color, BLACK);
        gummygui_button_draw(button, (Color){255 * button_val, 255 * button_val, 255 * button_val, 255});

        EndDrawing();
    }

CLEANUP:
    gummygui_slider_destroy(&slider);
    gummygui_toggle_destroy(&toggle);
    gummygui_button_destroy(&button);
    CloseWindow();
    return 0;
}




/*
 gcc -std=c11 \
 -Wall -Wextra -Wpedantic \
 -Wshadow -Wconversion -Wsign-conversion \
 -Wdouble-promotion -Wformat=2 -Wnull-dereference \
 -Wcast-align -Wcast-qual -Wundef -Wpointer-arith \
 -Wunused -Wuninitialized  \
 -Wredundant-decls -Wmisleading-indentation \
 -Wduplicated-cond -Wduplicated-branches -Wlogical-op \
 -g -O0 \
 -fsanitize=address,undefined \
 -fno-omit-frame-pointer \
 -fno-sanitize-recover=all \
 -o main *.c $(pkg-config --cflags --libs raylib) -lm
*/

