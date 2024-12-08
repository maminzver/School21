#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double S = x, a = 1, b = x;
  while (s21_fabs(a - b) > 1e-7) {
    a = (a + b) / 2;
    b = S / a;
  }
  return (a + b) / 2;
}
