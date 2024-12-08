#include "s21_string.h"

void *s21_memcpy(void *destination, const void *source, size_t n) {
  char *castdestination = (char *)destination;
  char *castsource = (char *)source;
  for (size_t i = 0; i < n; i++) {
    castdestination[i] = castsource[i];
  }
  return destination;
}
