#include <stdio.h>

#include "gui.h"

int main(int argc, char* argv[]) {
  printf("%d %s\n", argc, argv[argc - 1]);

  draw_t screen;
  emu_state_t state = RUN;

  // Set screen configs
  gui_screen_configs(&screen, 100, 100, 200, 200, 0);

  // Init SDL and draw screen
  if (gui_init(&screen) != 0) {
    printf("Something went wrong..\n");
  } else {
    // Set background color
    gui_clear_screen(&screen, FUCHSIA);

    // Main loop !!!
    while (state != QUIT) {
      gui_user_input(&state);

      gui_fps_rate(60);

      gui_update_screen(&screen);
    }

    // Destroy all SDL things that was created in init
    gui_end(&screen);
  }

  return 0;
}