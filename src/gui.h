// gui.h

#ifndef GUI_H
#define GUI_H

#include <SDL.h>

// Colors
//--------------0bRGB
#define BLACK 0b000
#define RED 0b100
#define YELLOW 0b110
#define GREEN 0b010
#define FUCHSIA 0b101
#define CYAN 0b011
#define BLUE 0b001
#define WHITE 0b111

typedef struct {
  SDL_Window* wnd;
  SDL_Renderer* rdr;
  int x;
  int y;
  int w;
  int h;
  unsigned int flags;
} draw_t;

typedef enum { QUIT, RUN, PAUSE } emu_state_t;

// init SDL
// 0 - OK
// 1 - FAIL
int gui_init(draw_t* screen);
// finish SDL
void gui_end(draw_t* screen);
// screen configs
// (x, y) - center coordinates
// w x h - size
// flags - some flags, read SDL wiki for more
void gui_screen_configs(draw_t* screen, int x, int y, int w, int h,
                        unsigned int flags);
// clear screen with color from define
void gui_clear_screen(draw_t* screen, unsigned char color);
// Swap buffers
void gui_update_screen(draw_t* screen);
// Handle user's input from keyboard
void gui_user_input(emu_state_t* state);
// FPS rate
void gui_fps_rate(unsigned int rate);

#endif