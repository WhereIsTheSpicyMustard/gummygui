#ifndef GUMMYGUI_H
#define GUMMYGUI_H

#ifndef GUMMYGUI_PADDING
#define GUMMYGUI_PADDING 2
#endif

#include <stdbool.h>

typedef enum Alignment {
    ALIGN_TOP,
    ALIGN_BOTTOM,
    ALIGN_RIGHT,
    ALIGN_CENTER
} Alignment;

typedef struct Color Color;
typedef struct Slider Slider;
typedef struct Toggle Toggle;
typedef struct Button Button;
typedef struct Label Label;
typedef struct TextLabel TextLabel;

/************************ Text Label ************************/

TextLabel* gummygui_textlabel_create(char* Text, const int X, const int Y, const int Size);
TextLabel* gummygui_textlabel_button_create(char* Text, const Button* button, const Alignment a);
TextLabel* gummygui_textlabel_toggle_create(char* Text, const Toggle* toggle, const Alignment a);
TextLabel* gummygui_textlabel_slider_create(char* Text, const Slider* slider, const Alignment a);
void       gummygui_textlabel_destroy(TextLabel** label);
void       gummygui_textlabel_draw(const TextLabel* label, Color base);

char*      gummygui_textlabel_get_text(const TextLabel* label);
int        gummygui_textlabel_get_x(const TextLabel* label);
int        gummygui_textlabel_get_y(const TextLabel* label);
int        gummygui_textlabel_get_size(const TextLabel* label);

void       gummygui_textlabel_set_text(TextLabel* label, char* new_text);
void       gummygui_textlabel_set_x(TextLabel* label, const int new_x);
void       gummygui_textlabel_set_y(TextLabel* label, const int new_y);
void       gummygui_textlabel_set_size(TextLabel* label, const int new_size);

/************************ Label ************************/

Label*     gummygui_label_create(float* Data, const int X, const int Y, const int Size, const char Prec);
Label*     gummygui_label_slider_create(const Slider* slider, const Alignment a, const char Prec);
void       gummygui_label_destroy(Label** label);
void       gummygui_label_draw(const Label* label, Color base);

float*     gummygui_label_get_data(const Label* label);
int        gummygui_label_get_x(const Label* label);
int        gummygui_label_get_y(const Label* label);
int        gummygui_label_get_size(const Label* label);
char       gummygui_label_get_prec(const Label* label);

void       gummygui_label_set_data(Label* label, float* new_data);
void       gummygui_label_set_x(Label* label, const int new_x);
void       gummygui_label_set_y(Label* label, const int new_y);
void       gummygui_label_set_size(Label* label, const int new_size);
void       gummygui_label_set_prec(Label* label, const char new_prec);

/************************ Button ************************/

Button*    gummygui_button_create(bool* Value, const int X, const int Y, const int Width, const int Height);
void       gummygui_button_destroy(Button** button);
void       gummygui_button_update(Button* button);
void       gummygui_button_draw(const Button* button, const Color base);

bool*      gummygui_button_get_value(const Button* button);
int        gummygui_button_get_x(const Button* button);
int        gummygui_button_get_y(const Button* button);
int        gummygui_button_get_width(const Button* button);
int        gummygui_button_get_height(const Button* button);

void       gummygui_button_set_value(Button* button, bool* new_value);
void       gummygui_button_set_x(Button* button, const int new_x);
void       gummygui_button_set_y(Button* button, const int new_y);
void       gummygui_button_set_width(Button* button, const int new_width);
void       gummygui_button_set_height(Button* button, const int new_height);

/************************ Toggle ************************/

Toggle*    gummygui_toggle_create(bool* Value, const int X, const int Y, const int Width);
void       gummygui_toggle_destroy(Toggle** toggle);
void       gummygui_toggle_update(Toggle* toggle);
void       gummygui_toggle_draw(const Toggle* toggle, const Color base, const Color outline);

bool*      gummygui_toggle_get_value(const Toggle* toggle);
int        gummygui_toggle_get_x(const Toggle* toggle);
int        gummygui_toggle_get_y(const Toggle* toggle);
int        gummygui_toggle_get_width(const Toggle* toggle);
int        gummygui_toggle_get_height(const Toggle* toggle);

void       gummygui_toggle_set_value(Toggle* toggle, bool* new_value);
void       gummygui_toggle_set_x(Toggle* toggle, const int new_x);
void       gummygui_toggle_set_y(Toggle* toggle, const int new_y);
void       gummygui_toggle_set_width(Toggle* toggle, const int new_width);
void       gummygui_toggle_set_height(Toggle* toggle, const int new_height);


/************************ Slider ************************/

Slider*    gummygui_slider_create(float* Value, const float Min, const float Max, const int X, const int Y, const int Width);
void       gummygui_slider_destroy(Slider** slider);
void       gummygui_slider_update(Slider* slider);
void       gummygui_slider_draw(const Slider* slider, const Color base, const Color outline);

float*     gummygui_slider_get_value(const Slider* slider);
float      gummygui_slider_get_max(const Slider* slider);
float      gummygui_slider_get_min(const Slider* slider);
int        gummygui_slider_get_x(const Slider* slider);
int        gummygui_slider_get_y(const Slider* slider);
int        gummygui_slider_get_width(const Slider* slider);
int        gummygui_slider_get_height(const Slider* slider);

void       gummygui_slider_set_value(Slider* slider, float* new_value);
void       gummygui_slider_set_max(Slider* slider, const float new_max);
void       gummygui_slider_set_min(Slider* slider, const float new_min);
void       gummygui_slider_set_x(Slider* slider, const int new_x);
void       gummygui_slider_set_y(Slider* slider, const int new_y);
void       gummygui_slider_set_width(Slider* slider, const int new_width);
void       gummygui_slider_set_height(Slider* slider, const int new_height);

#endif
