#include "../s21_math.h"

long double s21_asin(double x) {
  if (x == 1.0) {
    return S21_PI / 2;
  } else if (x == -1.0) {
    return -S21_PI / 2;
  } else if (s21_fabs(x) <= 1.0) {
    long double number = x / s21_sqrt(1 - x * x);
    return s21_atan(number);
  } else {
    return S21_NAN;
  }
}