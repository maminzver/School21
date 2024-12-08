

#include "s21_cat.h"

int main(int argc, char *argv[]) {
  struct FLAGS myFlags = {0, 0, 0, 0, 0, 0};
  GetInputFlags(argc, argv, &myFlags);
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      FILE *fileNAME = fopen(argv[i], "rb");
      if (fileNAME != NULL) {
        output(fileNAME, myFlags);

        fclose(fileNAME);
      } else {
        fprintf(stderr, "cat: %s: No such file or directory", argv[i]);
      }
    }
  }
  return 0;
}

void compareChar(int *nearestLine, char buf) {
  if (buf == '\n') {
    (*nearestLine)++;
  } else {
    *nearestLine = 0;
  }
}

void printChars(char *arr, int i, struct FLAGS *myFlags, int flag) {
  if (!flag) {
    for (int j = 0; j <= i; j++) {
      if (myFlags->pV && arr[j] < 32 && arr[j] != 9 && arr[j] != 10) {
        printf("^%c", arr[j] ^ 0b01000000);
      } else if (arr[j] >= 127 && myFlags->pV) {
        printf("M-^%c", arr[j] ^ 0b11000000);
      } else if (myFlags->pE && arr[j] == '\n') {
        printf("$\n");
      } else if (myFlags->pT && arr[j] == '\t') {
        printf("^I");
      }

      else {
        printf("%c", arr[j]);
      }
    }
  } else {
    for (int j = 0; j <= i; j++) {
      if (myFlags->pV && arr[j] < 32 && arr[j] != 9 && arr[j] != 10) {
        printf("^%c", arr[j] ^ 0b01000000);
      } else if (arr[j] >= 127 && myFlags->pV) {
        printf("M-^%c", arr[j] ^ 0b11000000);
      } else if (myFlags->pE && arr[j] == '\n') {
        printf("$");
      } else if (myFlags->pT && arr[j] == '\t') {
        printf("^I");
      } else if (arr[j] == '\n') {
        printf("$");
      }

      else {
        printf("%c", arr[j]);
      }
    }
  }
}

void output(FILE *fileNAME, struct FLAGS myFlags) {
  char arr[N];
  int i = 0;
  int numOfString = 1;
  int flag = 0;
  char buf = '\n';
  int nearestLine = 0;
  while ((arr[i] = fgetc(fileNAME)) != EOF) {
    if (arr[i] == '\n') {
      if (myFlags.pS) {
        compareChar(&nearestLine, buf);
        if (nearestLine > 1) {
          continue;
        }
      }
      if (myFlags.pN || (myFlags.pB && buf != '\n')) {
        printf("%6d\t", numOfString++);
      }
      printChars(arr, i, &myFlags, flag);
      i = 0;
      buf = '\n';
    } else {
      buf = arr[i];
      i++;
    }
  }
  if (arr[0] > 31 && arr[i] < 126) {
    if (myFlags.pN) {
      printf("%6d\t", numOfString);
    } else if (myFlags.pB && buf != '\n') {
      printf("%6d\t", numOfString);
    }
    flag = 1;
  }
  printChars(arr, i - 1, &myFlags, flag);
}

int GetOptions(int argc, char **argv) {
  static struct option const longOptions[] = {
      {"number", 0, NULL, 'n'},
      {"number-nonblank", 0, NULL, 'b'},
      {"squeeze-blank", 0, NULL, 's'},
      {NULL, 0, NULL, 0},
  };
  return getopt_long(argc, argv, "ETbenstv", longOptions, NULL);
}

void GetInputFlags(int argc, char *argv[], struct FLAGS *myFlags) {
  int currentFlag;
  while ((currentFlag = GetOptions(argc, argv)) != -1) {
    switch (currentFlag) {
      case 'b':
        myFlags->pB = 1;
        break;
      case 'e':
        myFlags->pE = 1;
        myFlags->pV = 1;
        break;
      case 'v':
        myFlags->pV = 1;
        break;
      case 'E':
        myFlags->pE = 1;
        break;
      case 'n':
        myFlags->pN = 1;
        break;
      case 's':
        myFlags->pS = 1;
        break;
      case 't':
        myFlags->pT = 1;
        myFlags->pV = 1;
        break;
      case 'T':
        myFlags->pT = 1;
      default:
        break;
    }
  }
  if (myFlags->pB) {
    myFlags->pN = 0;
  }
}
