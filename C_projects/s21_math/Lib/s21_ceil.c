#include "../s21_math.h"

long double s21_ceil(double x) {
  long double res;
  if (s21_fabs(x) == S21_DBL_MAX || S21_IS_INF(x) || S21_IS_NAN(x)) {
    res = x;
  } else {
    res = (long long int)x;
    if (x != res) {
      if (x > 0) {
        res++;
      }
    }
  }
  return res;
}