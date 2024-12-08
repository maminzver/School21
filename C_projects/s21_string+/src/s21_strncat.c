#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *dest_end = dest;

  while (*dest_end != '\0') {
    dest_end++;
  }
  // Копировать до n символов из src в dest
  size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest_end[i] = src[i];
  }
  dest_end[i] = '\0';
  return dest;
}
