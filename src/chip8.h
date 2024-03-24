// chip8.h

#ifndef CHIP8_H
#define CHIP8_H

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { QUIT, RUN, PAUSE } emu_state_t;

typedef struct {
  emu_state_t state;
  int PC;
  unsigned char memory[4096];
  int pixel[64 * 32];
  int stack[12];
  int stack_ptr;
  int V[16];
  int I;
  int delay;
  int sound;
  int key[16];
  char* rom_path;
} chip8_t;

// Init CHIP-8
// 0 - OK
// 1 - FAIL
int chip8_init(chip8_t* chip8, char* rom_path);
// Emulate instructions
void chip8_instructions(chip8_t* chip8);

#endif