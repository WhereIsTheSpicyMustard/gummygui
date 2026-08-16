#ifndef GUMMYGUI_H
#define GUMMYGUI_H

#ifndef GUMMYGUI_PADDING
#define GUMMYGUI_PADDING 2
#endif

#include <stdbool.h>

typedef struct Color Color;
typedef struct Slider Slider;
typedef struct Toggle Toggle;
typedef struct Button Button;

/************************ Button ************************/

Button* gummygui_button_create(bool* Value, const int X, const int Y, const int Width, const int Height);
void    gummygui_button_destroy(Button** button);
void    gummygui_button_update(Button* button);
void    gummygui_button_draw(const Button* button, const Color base);

bool    gummygui_button_get_value(const Button* button);
bool*   gummygui_button_get_value_addr(const Button* button);
int     gummygui_button_get_x(const Button* button);
int     gummygui_button_get_y(const Button* button);
int     gummygui_button_get_width(const Button* button);
int     gummygui_button_get_height(const Button* button);

void    gummygui_button_set_value(Button* button, const bool new_val);
void    gummygui_button_set_value_addr(Button* button, bool* new_addr);
void    gummygui_button_set_x(Button* button, const int new_x);
void    gummygui_button_set_y(Button* button, const int new_y);
void    gummygui_button_set_width(Button* button, const int new_width);
void    gummygui_button_set_height(Button* button, const int new_height);

/************************ Toggle ************************/

Toggle* gummygui_toggle_create(bool* Value, const int X, const int Y, const int Width);
void    gummygui_toggle_destroy(Toggle** toggle);
void    gummygui_toggle_update(Toggle* toggle);
void    gummygui_toggle_draw(const Toggle* toggle, const Color base, const Color outline);

bool    gummygui_toggle_get_value(const Toggle* toggle);
bool*   gummygui_toggle_get_value_addr(const Toggle* toggle);
int     gummygui_toggle_get_x(const Toggle* toggle);
int     gummygui_toggle_get_y(const Toggle* toggle);
int     gummygui_toggle_get_width(const Toggle* toggle);
int     gummygui_toggle_get_height(const Toggle* toggle);

void    gummygui_toggle_set_value(Toggle* toggle, const bool new_val);
void    gummygui_toggle_set_value_addr(Toggle* toggle, bool* new_addr);
void    gummygui_toggle_set_x(Toggle* toggle, const int new_x);
void    gummygui_toggle_set_y(Toggle* toggle, const int new_y);
void    gummygui_toggle_set_width(Toggle* toggle, const int new_width);
void    gummygui_toggle_set_height(Toggle* toggle, const int new_height);


/************************ Slider ************************/

Slider* gummygui_slider_create(float* Value, const float Min, const float Max, const int X, const int Y, const int Width);
void    gummygui_slider_destroy(Slider** slider);
void    gummygui_slider_update(Slider* slider);
void    gummygui_slider_draw(const Slider* slider, const Color base, const Color outline);

float   gummygui_slider_get_value(const Slider* slider);
float*  gummygui_slider_get_value_addr(const Slider* slider);
float   gummygui_slider_get_max(const Slider* slider);
float   gummygui_slider_get_min(const Slider* slider);
int     gummygui_slider_get_x(const Slider* slider);
int     gummygui_slider_get_y(const Slider* slider);
int     gummygui_slider_get_width(const Slider* slider);
int     gummygui_slider_get_height(const Slider* slider);

void    gummygui_slider_set_value(Slider* slider, const float new_value);
void    gummygui_slider_set_value_addr(Slider* slider, float* new_addr);
void    gummygui_slider_set_max(Slider* slider, const float new_max);
void    gummygui_slider_set_min(Slider* slider, const float new_min);
void    gummygui_slider_set_x(Slider* slider, const int new_x);
void    gummygui_slider_set_y(Slider* slider, const int new_y);
void    gummygui_slider_set_width(Slider* slider, const int new_width);
void    gummygui_slider_set_height(Slider* slider, const int new_height);

#endif
