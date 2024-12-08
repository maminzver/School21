#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t len1 = s21_strlen(str1);
  size_t len2 = s21_strlen(str2);
  size_t i = 0;
  size_t j = 0;
  int flag = 0;
  while (i < len1) {
    while (j < len2) {
      if (str1[i] == str2[j]) {
        flag = 1;
        break;
      }
      j++;
    }
    j = 0;
    if (flag) break;
    i++;
  }
  return i;
}
