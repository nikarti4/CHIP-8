#include "draw.h"

#include <SDL.h>

// init SDL
// 0 - success
int draw_init() {
  return SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
}

// finish SDL
void draw_end() { SDL_Quit(); }
