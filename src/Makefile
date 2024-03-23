
#sudo apt-get install libsdl2-2.0.0 libsdl2-dev

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 #-I/usr/include/SDL2 -D_REENTRANT -lSDL2
SDLFLAGS = -lSDL2 `sdl2-config --cflags --libs`
SOURCE_FILES = main.c gui.c
BUILD_PATH = ../build/


all: CHIP-8
	

CHIP-8:
	$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(BUILD_PATH)CHIP-8 $(SDLFLAGS)

rebuild: clean all


clean:
	rm -rf $(BUILD_PATH)CHIP-8