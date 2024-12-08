#include "s21_string.h"

char *s21_strncpy(char *destination, const char *source, size_t n) {
  int k = 0;
  size_t len_source = 0;
  int check0 = 0;
  while (source[k] != '\0') {
    len_source += 1;
    k += 1;
  }
  for (size_t i = 0; i < n; i++) {
    if (len_source >= n) {
      destination[i] = source[i];
    } else {
      if (source[i] == '\0') {
        check0 = 1;
      }
      if (check0 == 0) {
        destination[i] = source[i];
      } else
        (destination[i] = '\0');
    }
  }
  return destination;
}
