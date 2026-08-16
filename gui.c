#include "gui.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

typedef struct Toggle {
    bool* value;
    int x;
    int y;
    int width;
    int height;
} Toggle;

typedef struct Slider {
    const char* name;
    float* value;
    float min;
    float max;
    int x;
    int y;
    int width;
    int height;
    const char* prec;
    bool update;
} Slider;


/****************************************************************/
// TOGGLE
/****************************************************************/

Toggle* gummygui_toggle_create(bool* Value, const int X, const int Y, const int Width)
{
    Toggle* toggle = malloc(sizeof (Toggle));
    if (toggle == NULL) return NULL;

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
    const int mouse_x = GetMouseX();
    const int mouse_y = GetMouseY();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !(mouse_x < toggle->x || mouse_x > toggle->x + toggle->width || mouse_y < toggle->y || mouse_y > toggle->y + toggle->height))
        *toggle->value = !(*toggle->value);
}

void gummygui_toggle_draw(const Toggle* toggle, const Color base, const Color outline)
{
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

bool gummygui_toggle_get_value(const Toggle* toggle) {
    return *toggle->value;
}

bool* gummygui_toggle_get_value_addr(const Toggle* toggle) {
    return toggle->value;
}

int gummygui_toggle_get_x(const Toggle* toggle) {
    return toggle->x;
}

int gummygui_toggle_get_y(const Toggle* toggle) {
    return toggle->y;
}

int gummygui_toggle_get_width(const Toggle* toggle) {
    return toggle->width;
}

int gummygui_toggle_get_height(const Toggle* toggle) {
    return toggle->height;
}

/****************************************************************/

void gummygui_toggle_set_value(Toggle* toggle, const bool new_val) {
    *toggle->value = new_val;
}

void gummygui_toggle_set_value_addr(Toggle* toggle, bool* new_addr) {
    toggle->value = new_addr;
}

void gummygui_toggle_set_x(Toggle* toggle, const int new_x) {
    toggle->x = new_x;
}

void gummygui_toggle_set_y(Toggle* toggle, const int new_y) {
    toggle->y = new_y;
}

void gummygui_toggle_set_width(Toggle* toggle, const int new_width) {
    toggle->width = new_width;
}

void gummygui_toggle_set_height(Toggle* toggle, const int new_height) {
    toggle->height = new_height;
}



/****************************************************************/
// SLIDER
/****************************************************************/

Slider* gummygui_slider_create(
    const char* Name,
    float* Value, const float Min, const float Max,
    const int X, const int Y, const int Width, const int Height,
    const char* Prec)
{
    Slider* slider = malloc(sizeof(Slider));
    if (slider == NULL) return NULL;

    slider->name = Name; // assumes n is a string literal

    slider->value = Value;
    slider->min = Min;
    slider->max = Max;

    slider->x = X;
    slider->y = Y;
    slider->width = Width;
    slider->height = Height;

    slider->prec = Prec; // assumes p is a string literal

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
    const char* const text = TextFormat(slider->prec, (double)*slider->value);
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

    // name
    DrawText(
        slider->name, slider->x,
        slider->y - slider->height - GUMMYGUI_PADDING,
        slider->height, outline
    );

    // value
    DrawText(
        text, slider->x + slider->width - MeasureText(text, slider->height),
        slider->y - slider->height - GUMMYGUI_PADDING,
        slider->height, outline
    );
}

/****************************************************************/

float gummygui_slider_get_value(const Slider* slider) {
    return *slider->value;
}

float* gummygui_slider_get_value_addr(const Slider* slider) {
    return slider->value;
}

float gummygui_slider_get_max(const Slider* slider) {
    return slider->max;
}

float gummygui_slider_get_min(const Slider* slider) {
    return slider->min;
}

int gummygui_slider_get_x(const Slider* slider) {
    return slider->x;
}

int gummygui_slider_get_y(const Slider* slider) {
    return slider->y;
}

int gummygui_slider_get_width(const Slider* slider) {
    return slider->width;
}

int gummygui_slider_get_height(const Slider* slider) {
    return slider->height;
}

/****************************************************************/

void gummygui_slider_set_name(Slider* slider, const char* new_name) {
    slider->name = new_name;
}

void gummygui_slider_set_prec(Slider* slider, const char* new_prec) {
    slider->prec = new_prec;
}

void gummygui_slider_set_value(Slider* slider, const float new_value) {
    *slider->value = new_value;
}

void gummygui_slider_set_value_addr(Slider* slider, float* new_addr) {
    slider->value = new_addr;
}

void gummygui_slider_set_max(Slider* slider, const float new_max) {
    slider->max = new_max;
}

void gummygui_slider_set_min(Slider* slider, const float new_min) {
    slider->min = new_min;
}

void gummygui_slider_set_x(Slider* slider, const int new_x) {
    slider->x = new_x;
}

void gummygui_slider_set_y(Slider* slider, const int new_y) {
    slider->y = new_y;
}

void gummygui_slider_set_width(Slider* slider, const int new_width) {
    slider->width = new_width;
}

void gummygui_slider_set_height(Slider* slider, const int new_height) {
    slider->height = new_height;
}



