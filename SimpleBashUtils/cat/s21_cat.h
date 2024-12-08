#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>

#define N 10000

struct FLAGS {
  int pN;
  int pB;
  int pS;
  int pV;
  int pE;
  int pT;
};

void GetInputFlags(int argc, char *argv[], struct FLAGS *myFlags);

void compareChar(int *nearestLine, char buf);
void printChars(char *arr, int i, struct FLAGS *myFlags, int flag);
void output(FILE *fileNAME, struct FLAGS myFlags);
int GetOptions(int argc, char **argv);

#endif
