#include "../s21_math.h"

long double s21_sin(double x) {
  long double res = 0;
  if (x == 0.0)
    res = x;
  else if (x == S21_INF)
    res = S21_NAN;
  else {
    while (x > 2 * S21_PI) x -= 2 * S21_PI;
    while (x < -2 * S21_PI) x += 2 * S21_PI;
    for (int i = 1, j = 0; i < 20; i += 2, j++)
      res += s21_pow(-1, j) * s21_pow(x, i) / s21_factorial(i);
  }
  return res;
}

long double s21_factorial(double x) {
  long double res = 0;
  if (x == 1 || x == 0)
    res = 1;
  else if (x < 0)
    res = S21_INF;
  else
    res = x * s21_factorial(x - 1);
  return res;
}
