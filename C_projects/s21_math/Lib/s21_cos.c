#include "../s21_math.h"

long double s21_cos(double x) {
  long double res;
  if (S21_IS_INF(x) || S21_IS_NAN(x)) {
    res = S21_NAN;
  } else {
    res = 1;
    long double term = 1;
    x = s21_fmod(x, 2 * S21_PI);
    for (long double i = 1; term >= S21_EPS || term <= -S21_EPS; i++) {
      term *= ((-1) * x * x) / ((2 * i - 1) * (2 * i));
      res += term;
    }
  }
  return res;
}