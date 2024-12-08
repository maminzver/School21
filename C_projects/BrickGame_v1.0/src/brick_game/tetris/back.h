#ifndef S21_back
#define S21_back

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CELLS_IN_TETROMINO 4

#define HEIGHT 20
#define WIDTH 10

#define TETROMINO_HEIGHT 2
#define TETROMINO_WIDTH 4

#define HIGH_SCORE_FILE "high_score.txt"

typedef enum { I = 0, J, L, O, S, T, Z } TetroName_t;

typedef struct {
  int x;
  int y;
} Cell_t;

typedef struct {
  Cell_t cells[CELLS_IN_TETROMINO];
  TetroName_t name;
  TetroName_t name_next;
} Tetromino_t;

typedef enum {
  START = 0,
  GAMEOVER,
  SPAWN,
  MOVING,
  SHIFTING,
  ATTACHING,
} GameState_t;

typedef enum {
  Start = 0,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef struct {
  GameInfo_t info;
  Tetromino_t tetromino;
  GameState_t state;
} GameParams_t;

typedef void (*ActionT)(GameParams_t *prms);

GameInfo_t updateCurrentState();

GameParams_t *updateParams(GameParams_t *prms);

void initializeParams(GameParams_t *prms);

void startGame(GameParams_t *prms);

void pauseGame(GameParams_t *prms);

void terminateGame(GameParams_t *prms);

void spawn(GameParams_t *prms);

void moveDown(GameParams_t *prms);

void moveRight(GameParams_t *prms);

void moveLeft(GameParams_t *prms);

void attach(GameParams_t *prms);

void shift(GameParams_t *prms);

void rotate(GameParams_t *prms);

bool isCollide(GameParams_t *prms);

bool isAttach(GameParams_t *prms);

int linesDisappeared(int **field);

bool canSpawn(GameParams_t *prms);

int **newArray2D(int n, int m);

void deleteArray2D(int **this, int n);

int readHighScore(void);

void writeHighScore(int high_score);

#endif