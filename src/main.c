#include <stdio.h>

#include "chip8.h"
#include "gui.h"

int main(int argc, char* argv[]) {
  printf("\n ===== CHIP-8 emulator logs ===== \n");

  if (argc != 2) {
    printf("Hint: ../build/CHIP-8 <rom_path>\n");
  }

  gui_t screen = {0};
  chip8_t chip8 = {0};
  chip8.state = RUN;

  // Set screen configs
  gui_screen_configs(&screen, 100, 100, 64, 32, 0);

  // Init SDL and draw screen
  if (gui_init(&screen) != 0 || chip8_init(&chip8, argv[1]) != 0) {
    printf("Something went wrong..\n");
  } else {
    // Set background color
    gui_clear_screen(&screen, FUCHSIA);

    // Main loop !!!
    while (chip8.state != QUIT) {
      gui_user_input(&chip8.state);

      gui_fps_rate(60);

      gui_update_screen(&screen);
    }

    // Destroy all SDL things that was created in init
    gui_end(&screen);
  }

  return 0;
}