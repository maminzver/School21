#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;
  if (y == 0 || S21_IS_NAN(x) || S21_IS_NAN(y) || S21_IS_INF(x)) {
    res = S21_NAN;
  } else if (x != 0.0 && S21_IS_INF(y)) {
    res = (long double)x;
  } else {
    long long int mod = 0;
    mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;

  // long double res;
  // if (y == 0.) {
  //   res = 0.0 / 0.0;
  // }
  // else if ((x >= 0. && y > 0.) || (x <= 0 && y < 0.))

  //   res = x - y * floor(x / y);
  // else
  // res =  x - y * ceil(x / y);
  // return res;
}