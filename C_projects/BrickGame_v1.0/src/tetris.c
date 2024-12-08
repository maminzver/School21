#include <unistd.h>

//#include "gui/cli/front.h"
#include "tetris.h"

int main(void) {
  myWinInit();
  gameLoop();
  drawGameOver();
  // sleep(5);

  endwin();

  return 0;
}
