#include <stdio.h>

#include "draw.h"

int main(int argc, char* argv[]) {
  printf("%d %s\n", argc, argv[argc - 1]);

  printf("%d", draw_init());

  draw_end();

  return 0;
}