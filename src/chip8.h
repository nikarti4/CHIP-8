// chip8.h

#ifndef CHIP8_H
#define CHIP8_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL.h>

typedef enum { QUIT, RUN, PAUSE } emu_state_t;

typedef struct {
    emu_state_t state;
    int PC;
    int memory[4096];
    int pixel[64*32];
    int stack[12];
    int V[16];
    int I;
    int delay;
    int sound;
    int key[16];
    char* rom_path;
} chip8_t;

// Init CHIP-8
void chip8_init(chip8_t* chip8);


#endif