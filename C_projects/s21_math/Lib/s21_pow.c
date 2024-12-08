#include "../s21_math.h"

long double s21_pow(double base, double expp) {
  long double res;
  long double copy = base;
  if (!expp) {
    res = 1.;
  } else if (copy < 0) {
    copy = -copy;
    res = s21_exp(expp * s21_log(copy));
    if (s21_fmod(expp, 2) != 0) {
      res = -res;
    }
    if ((expp > 0 && expp != s21_floor(expp)) ||
        (expp < 0 && expp != s21_ceil(expp)))
      res = S21_NAN;
  } else {
    res = s21_exp(expp * s21_log(base));
  }
  return res;
}
