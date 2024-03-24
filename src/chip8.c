#include "chip8.h"

// Init CHIP-8
// 0 - OK
// 1 - FAIL
int chip8_init(chip8_t* chip8, char* rom_path) {
  int flag = 0;

  int font[] = {
      0xF0, 0x90, 0x90, 0x90, 0xF0,  // 0
      0x20, 0x60, 0x20, 0x20, 0x70,  // 1
      0xF0, 0x10, 0xF0, 0x80, 0xF0,  // 2
      0xF0, 0x10, 0x90, 0x10, 0xF0,  // 3
      0x90, 0x90, 0xF0, 0x10, 0x10,  // 4
      0xF0, 0x80, 0xF0, 0x10, 0xF0,  // 5
      0xF0, 0x80, 0xF0, 0x90, 0xF0,  // 6
      0xF0, 0x10, 0x20, 0x40, 0x40,  // 7
      0xF0, 0x90, 0xF0, 0x90, 0xF0,  // 8
      0xF0, 0x90, 0xF0, 0x10, 0xF0,  // 9
      0xF0, 0x90, 0xF0, 0x90, 0x90,  // A
      0xE0, 0x90, 0xE0, 0x90, 0xE0,  // B
      0xF0, 0x80, 0x80, 0x80, 0xF0,  // C
      0xE0, 0x90, 0x90, 0x90, 0xE0,  // D
      0xF0, 0x80, 0xF0, 0x80, 0xF0,  // E
      0xF0, 0x80, 0x90, 0x80, 0x80,  // F
  };

  // Load font in memory
  memcpy(&chip8->memory[0], font, sizeof(font));

  // Open ROM
  FILE* f = fopen(rom_path, "rb");

  if (!f) {
    SDL_Log("chip8_init FAIL: %s - no such file or directory\n", rom_path);
    flag = 1;
  } else {
    // Get ROM size
    fseek(f, 0, SEEK_END);         // point at the end of f
    long int rom_size = ftell(f);  // size of file
    rewind(f);

    printf("ROM File: %s, size: %ld bytes\n", rom_path, rom_size);

    // Load ROM
    if (fread(&chip8->memory[0x200], rom_size, 1, f) != 1) {
      printf("fread ROM FAIL\n");
      flag = 1;
    }

    fclose(f);

    if (flag == 0) {
      // CHIP-8 Inintial conditions
      chip8->state = RUN;
      chip8->PC = 0x200;
      chip8->stack_ptr = 0;
      chip8->rom_path = rom_path;
    }
  }

  return flag;
}

// Emulate instructions
// all instructions (or opcodes) looks like
// 0000, each number are 4-bits long (0..F)
// so >> 12 means that we get left one etc.
void chip8_instructions(chip8_t* chip8) {
  int instr = (chip8->memory[chip8->PC] << 8) | chip8->memory[chip8->PC + 1];
  chip8->PC += 2;

  switch ((instr >> 12) & 0x0F) {
    case 0x00:
      if ((instr & 0x00FF) == 0x00E0) {
        // Clear screen
      } else if ((instr & 0x00FF) == 0x00EE) {
        // Returns from subroutine
      }
      break;

    case 0x01:
      // Jumps to adress NNN
      break;

    case 0x02:
      // Calls subroutine at NNN
      break;

    case 0x03:
      // Skips the next instruction if VX = NN
      break;

    case 0x04:
      // Skips the next instruction if VX != NN
      break;

    case 0x05:
      // Skips the next instruction if VX == VY
      break;

    case 0x06:
      // Sets VX to NN
      break;

    case 0x07:
      // Adds NN to VX
      break;

    case 0x08:
      break;

    case 0x09:
      break;

    case 0x0A:
      break;

    case 0x0B:
      break;

    case 0x0C:
      break;

    case 0x0D:
      break;

    case 0x0E:
      break;

    case 0x0F:
      break;

    default:
      break;
  }
}