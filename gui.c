#include "gui.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

#define REPORT_ERROR(x) do {fprintf(stderr, "%s | on line: %d | in file: %s\n", x, __LINE__, __FILE__);} while (0)
#define VERIFY(x, y) do {if (x) {REPORT_ERROR("ERROR"); return (y);}} while (0)
#define VERIFY_VOID(x) do {if (x) {REPORT_ERROR("ERROR"); return;}} while (0)

typedef struct Slider {
    float* value;
    float min;
    float max;
    int x;
    int y;
    int width;
    int height;
    bool update;
} Slider;

typedef struct Toggle {
    bool* value;
    int x;
    int y;
    int width;
    int height;
} Toggle;

typedef struct Button {
    bool* value;
    int x;
    int y;
    int width;
    int height;
} Button;

/****************************************************************/
// Button
/****************************************************************/

Button* gummygui_button_create(bool* Value, const int X, const int Y, const int Width, const int Height)
{
    VERIFY(Value == NULL, NULL);
    Button* button = malloc(sizeof (Toggle));
    VERIFY(button == NULL, NULL);

    button->value = Value;
    button->x = X;
    button->y = Y;
    button->width = Width;
    button->height = Height;

    return button;
}

void gummygui_button_destroy(Button** button)
{
    free(*button);
    *button = NULL;
}

void gummygui_button_update(Button* button)
{
    VERIFY_VOID(button == NULL);
    const int mouse_x = GetMouseX();
    const int mouse_y = GetMouseY();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !(mouse_x < button->x || mouse_x > button->x + button->width || mouse_y < button->y || mouse_y > button->y + button->height))
        *button->value = !(*button->value);
}

void gummygui_button_draw(const Button* button, const Color base)
{
    VERIFY_VOID(button == NULL);
    DrawRectangle(button->x, button->y, button->width, button->height, base);
}

/****************************************************************/

bool gummygui_button_get_value(const Button* button)
{
    VERIFY(button == NULL, false);
    return *button->value;
}

bool* gummygui_button_get_value_addr(const Button* button)
{
    VERIFY(button == NULL, NULL);
    return button->value;
}

int gummygui_button_get_x(const Button* button)
{
    VERIFY(button == NULL, 0);
    return button->x;
}

int gummygui_button_get_y(const Button* button)
{
    VERIFY(button == NULL, 0);
    return button->y;
}

int gummygui_button_get_width(const Button* button)
{
    VERIFY(button == NULL, 0);
    return button->width;
}

int gummygui_button_get_height(const Button* button)
{
    VERIFY(button == NULL, 0);
    return button->height;
}

/****************************************************************/

void gummygui_button_set_value(Button* button, const bool new_val)
{
    VERIFY_VOID(button == NULL);
    *button->value = new_val;
}

void gummygui_button_set_value_addr(Button* button, bool* new_addr)
{
    VERIFY_VOID(button == NULL || new_addr == NULL);
    button->value = new_addr;
}

void gummygui_button_set_x(Button* button, const int new_x)
{
    VERIFY_VOID(button == NULL);
    button->x = new_x;
}

void gummygui_button_set_y(Button* button, const int new_y)
{
    VERIFY_VOID(button == NULL);
    button->y = new_y;
}

void gummygui_button_set_width(Button* button, const int new_width)
{
    VERIFY_VOID(button == NULL);
    button->width = new_width;
}

void gummygui_button_set_height(Button* button, const int new_height)
{
    VERIFY_VOID(button == NULL);
    button->height = new_height;
}


/****************************************************************/
// TOGGLE
/****************************************************************/

Toggle* gummygui_toggle_create(bool* Value, const int X, const int Y, const int Width)
{
    VERIFY(Value == NULL, NULL);
    Toggle* toggle = malloc(sizeof (Toggle));
    VERIFY(toggle == NULL, NULL);

    toggle->value = Value;
    toggle->x = X;
    toggle->y = Y;
    toggle->width = Width;
    toggle->height = (int)(Width * 0.5);

    return toggle;
}

void gummygui_toggle_destroy(Toggle** toggle)
{
    free(*toggle);
    *toggle = NULL;
}

void gummygui_toggle_update(Toggle* toggle)
{
    VERIFY_VOID(toggle == NULL);
    const int mouse_x = GetMouseX();
    const int mouse_y = GetMouseY();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !(mouse_x < toggle->x || mouse_x > toggle->x + toggle->width || mouse_y < toggle->y || mouse_y > toggle->y + toggle->height))
        *toggle->value = !(*toggle->value);
}

void gummygui_toggle_draw(const Toggle* toggle, const Color base, const Color outline)
{
    VERIFY_VOID(toggle == NULL);
    const int knob_x = (int)Remap(
        *toggle->value,
        0,
        1,
        (float)toggle->x,
        (float)(toggle->x + toggle->width - toggle->height)
    );

    // base
    DrawRectangle(toggle->x, toggle->y, toggle->width, toggle->height, base);

    // outline
    DrawRectangleLinesEx(
        (Rectangle){
            (float)toggle->x - GUMMYGUI_PADDING,
            (float)toggle->y - GUMMYGUI_PADDING,
            (float)toggle->width + GUMMYGUI_PADDING * 2,
            (float)toggle->height + GUMMYGUI_PADDING * 2},
            GUMMYGUI_PADDING,
            outline
    );

    // knob
    DrawRectangle(
        knob_x + GUMMYGUI_PADDING,
        toggle->y + GUMMYGUI_PADDING,
        toggle->height - GUMMYGUI_PADDING * 2,
        toggle->height - GUMMYGUI_PADDING * 2,
        outline
    );
}

/****************************************************************/

bool gummygui_toggle_get_value(const Toggle* toggle)
{
    VERIFY(toggle == NULL, false);
    return *toggle->value;
}

bool* gummygui_toggle_get_value_addr(const Toggle* toggle)
{
    VERIFY(toggle == NULL, NULL);
    return toggle->value;
}

int gummygui_toggle_get_x(const Toggle* toggle)
{
    VERIFY(toggle == NULL, 0);
    return toggle->x;
}

int gummygui_toggle_get_y(const Toggle* toggle)
{
    VERIFY(toggle == NULL, 0);
    return toggle->y;
}

int gummygui_toggle_get_width(const Toggle* toggle)
{
    VERIFY(toggle == NULL, 0);
    return toggle->width;
}

int gummygui_toggle_get_height(const Toggle* toggle)
{
    VERIFY(toggle == NULL, 0);
    return toggle->height;
}

/****************************************************************/

void gummygui_toggle_set_value(Toggle* toggle, const bool new_val)
{
    VERIFY_VOID(toggle == NULL);
    *toggle->value = new_val;
}

void gummygui_toggle_set_value_addr(Toggle* toggle, bool* new_addr)
{
    VERIFY_VOID(toggle == NULL || new_addr == NULL);
    toggle->value = new_addr;
}

void gummygui_toggle_set_x(Toggle* toggle, const int new_x)
{
    VERIFY_VOID(toggle == NULL);
    toggle->x = new_x;
}

void gummygui_toggle_set_y(Toggle* toggle, const int new_y)
{
    VERIFY_VOID(toggle == NULL);
    toggle->y = new_y;
}

void gummygui_toggle_set_width(Toggle* toggle, const int new_width)
{
    VERIFY_VOID(toggle == NULL);
    toggle->width = new_width;
}

void gummygui_toggle_set_height(Toggle* toggle, const int new_height)
{
    VERIFY_VOID(toggle == NULL);
    toggle->height = new_height;
}



/****************************************************************/
// SLIDER
/****************************************************************/

Slider* gummygui_slider_create(float* Value, const float Min, const float Max, const int X, const int Y, const int Width)
{
    VERIFY(Value == NULL, NULL);
    Slider* slider = malloc(sizeof(Slider));
    VERIFY(slider == NULL, NULL);

    slider->value = Value;
    slider->min = Min;
    slider->max = Max;

    slider->x = X;
    slider->y = Y;
    slider->width = Width;
    slider->height = (int)(Width * 0.08);

    slider->update = false;

    return slider;
}

void gummygui_slider_destroy(Slider** slider)
{
    free(*slider);
    *slider = NULL;
}

void gummygui_slider_update(Slider* slider)
{
    VERIFY_VOID(slider == NULL);
    const int mouse_x = GetMouseX();
    const int mouse_y = GetMouseY();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (!(mouse_x < slider->x || mouse_x > slider->x + slider->width || mouse_y < slider->y || mouse_y > slider->y + slider->height)) {
            slider->update = true;
        } else {
            slider->update = false;
        }
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && (slider->update)) {
        *slider->value = Remap((float)mouse_x, (float)slider->x, (float)(slider->x + slider->width), slider->min, slider->max);
        *slider->value = Clamp(*slider->value, slider->min, slider->max);
    }
}

void gummygui_slider_draw(const Slider* slider, const Color base, const Color outline)
{
    VERIFY_VOID(slider == NULL);
    // const char* const text = TextFormat(slider->prec, (double)*slider->value);
    const int knob_x = (int)Remap(
        *slider->value,
        slider->min,
        slider->max,
        (float)slider->x,
        (float)(slider->x + slider->width - slider->height)
    );

    // base
    DrawRectangle(slider->x, slider->y, slider->width, slider->height, base);
    // outline
    DrawRectangleLinesEx(
        (Rectangle){
        (float)slider->x - GUMMYGUI_PADDING,
        (float)slider->y - GUMMYGUI_PADDING,
        (float)slider->width + GUMMYGUI_PADDING * 2,
        (float)slider->height + GUMMYGUI_PADDING * 2},
        GUMMYGUI_PADDING,
        outline
    );

    // knob
    DrawRectangle(
        knob_x + GUMMYGUI_PADDING,
        slider->y + GUMMYGUI_PADDING,
        slider->height - GUMMYGUI_PADDING * 2,
        slider->height - GUMMYGUI_PADDING * 2,
        outline
    );
}

/****************************************************************/

float gummygui_slider_get_value(const Slider* slider)
{
    VERIFY(slider == NULL, 0);
    return *slider->value;
}

float* gummygui_slider_get_value_addr(const Slider* slider)
{
    VERIFY(slider == NULL, NULL);
    return slider->value;
}

float gummygui_slider_get_max(const Slider* slider)
{
    VERIFY(slider == NULL, 0);
    return slider->max;
}

float gummygui_slider_get_min(const Slider* slider)
{
    VERIFY(slider == NULL, 0);
    return slider->min;
}

int gummygui_slider_get_x(const Slider* slider)
{
    VERIFY(slider == NULL, 0);
    return slider->x;
}

int gummygui_slider_get_y(const Slider* slider)
{
    VERIFY(slider == NULL, 0);
    return slider->y;
}

int gummygui_slider_get_width(const Slider* slider)
{
    VERIFY(slider == NULL, 0);
    return slider->width;
}

int gummygui_slider_get_height(const Slider* slider)
{
    VERIFY(slider == NULL, 0);
    return slider->height;
}

/****************************************************************/

void gummygui_slider_set_value(Slider* slider, const float new_value)
{
    VERIFY_VOID(slider == NULL);
    *slider->value = new_value;
}

void gummygui_slider_set_value_addr(Slider* slider, float* new_addr)
{
    VERIFY_VOID(slider == NULL || new_addr == NULL);
    slider->value = new_addr;
}

void gummygui_slider_set_max(Slider* slider, const float new_max)
{
    VERIFY_VOID(slider == NULL);
    slider->max = new_max;
}

void gummygui_slider_set_min(Slider* slider, const float new_min)
{
    VERIFY_VOID(slider == NULL);
    slider->min = new_min;
}

void gummygui_slider_set_x(Slider* slider, const int new_x)
{
    VERIFY_VOID(slider == NULL);
    slider->x = new_x;
}

void gummygui_slider_set_y(Slider* slider, const int new_y)
{
    VERIFY_VOID(slider == NULL);
    slider->y = new_y;
}

void gummygui_slider_set_width(Slider* slider, const int new_width)
{
    VERIFY_VOID(slider == NULL);
    slider->width = new_width;
}

void gummygui_slider_set_height(Slider* slider, const int new_height)
{
    VERIFY_VOID(slider == NULL);
    slider->height = new_height;
}



