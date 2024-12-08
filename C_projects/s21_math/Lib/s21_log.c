#include "../s21_math.h"

long double s21_log(double x) {
  double res = 0.;

  double prev_res = 0.;
  int exp_pow = 0;

  if (x < 0 || S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x))
    res = S21_INF;
  else if (x == 0)
    res = S21_INF_NEG;
  else {
    for (register long long int i = 0; i < 1000; i++) {
      prev_res = res;
      res = prev_res + 2 * (x - s21_exp(prev_res)) / (x + s21_exp(prev_res));
    }

    res += exp_pow;
  }

  return res;
}
