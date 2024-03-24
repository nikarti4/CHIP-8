#include "gui.h"

// screen configs
// (x, y) - center coordinates
// w x h - size
// flags - some flags, read SDL wiki for more
void gui_screen_configs(gui_t* screen, int x, int y, int w, int h,
                        unsigned int flags) {
  screen->x = x;
  screen->y = y;
  screen->w = w;
  screen->h = h;
  screen->flags = flags;
}

// init SDL
// 0 - OK
// 1 - FAIL
int gui_init(gui_t* screen) {
  // return 0 if success
  int flag = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

  if (flag != 0) {
    SDL_Log("SDL_Init FAIL due to: %s \n", SDL_GetError());
    flag = 1;
  } else {
    // wnd will be NULL on failure
    screen->wnd = SDL_CreateWindow("CHIP-8", screen->x, screen->y,
                                   screen->w * SIZE_OF_SCREEN,
                                   screen->h * SIZE_OF_SCREEN, screen->flags);
    if (!screen->wnd) {
      SDL_Log("SDL_CreateWindow FAIL due to: %s \n", SDL_GetError());
      flag = 1;
    } else {
      // rdr will be NULL on failure
      screen->rdr =
          SDL_CreateRenderer(screen->wnd, -1, SDL_RENDERER_ACCELERATED);

      if (!screen->rdr) {
        SDL_Log("SDL_CreateRenderer FAIL due to: %s \n", SDL_GetError());
        flag = 1;
      }
    }
  }

  return flag;
}

// Finish SDL
void gui_end(gui_t* screen) {
  SDL_DestroyRenderer(screen->rdr);
  SDL_DestroyWindow(screen->wnd);
  SDL_Quit();
}

// Clear screen with color from define (background color)
void gui_clear_screen(gui_t* screen, unsigned char color) {
  unsigned char r = ((color & RED) >> 2) * 255;
  unsigned char g = ((color & GREEN) >> 1) * 255;
  unsigned char b = (color & BLUE) * 255;

  SDL_SetRenderDrawColor(screen->rdr, r, g, b, 255);
  SDL_RenderClear(screen->rdr);
}

// Swap buffers
void gui_update_screen(gui_t* screen) { SDL_RenderPresent(screen->rdr); }

// Handle user's input from keyboard
void gui_user_input(emu_state_t* state) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        *state = QUIT;
        break;

      case SDL_KEYDOWN:

        switch (event.key.keysym.sym) {
          case SDLK_ESCAPE:
            *state = QUIT;
            break;

          case SDLK_p:
            printf("p key\n");
            *state = RUN ? PAUSE : RUN;
            break;

          default:
            break;
        }

        break;

      case SDL_KEYUP:
        break;

      default:
        break;
    }
  }
}

// FPS rate
void gui_fps_rate(unsigned int rate) {
  unsigned int ms = 17;  // 60fps on default
  if (rate != 0) {
    ms = 1000 / rate;
  }

  SDL_Delay(ms);
}