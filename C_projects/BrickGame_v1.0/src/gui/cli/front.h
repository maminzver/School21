#ifndef S21_front
#define S21_front

#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../../brick_game/tetris/back.h"

#define COLOR_ORANGE 8

#define MVPRINTW(y, x, ...) \
  mvprintw(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), __VA_ARGS__)
#define MVADDCH(y, x, c) mvaddch(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), c)

#define ESCAPE_KEY 27
#define ENTER_KEY 10
#define PAUSE_KEY 112
#define ACTION_KEY 32

#define INTRO_MESSAGE "Press ENTER to start"
#define INTRO_MESSAGE_LEN 21

#define BOARDS_BEGIN 2

#define BOARD_N HEIGHT
#define BOARD_M 2 * WIDTH

#define HUD_WIDTH 16

#define Y_NEXT 2
#define Y_SCORE 9
#define Y_HIGH_SCORE 14
#define Y_LEVEL 19

void myWinInit();
void gameLoop();
void userInput(UserAction_t action, bool hold);
UserAction_t getAction(int user_input);
void drawGui();
void drawRectangle(int top_y, int bottom_y, int left_x, int right_x);
void drawInfo(GameInfo_t *info, int type_next);
void drawGameOver();
void drawPause();
void drawTetromino(Tetromino_t *tetromino);
void drawField(int **field, int **colors);
void drawCell(int i, int j, bool isCell, int color);

#endif