#include "s21_string.h"

char* s21_strchr(const char* str, int c) {
  int check = 0;  // счетчик поиска
  char* p = (char*)str;
  while (*p != '\0') {
    if (*p == (char)c) {
      check += 1;
      break;
    }
    p += 1;
  }
  if (*p == c) {
    check = 1;
  }
  if (check == 0) {
    p = NULL;
  }
  return p;
}
