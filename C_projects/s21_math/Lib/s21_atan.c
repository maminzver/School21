#include <math.h>

#include "../s21_math.h"

long double s21_atan(double x) {
  long double res = 0.;

  if (x != x)
    res = S21_NAN;
  else if (x == 1)
    res = S21_PI / 4;
  else if (x == -1)
    res = -S21_PI / 4;
  else {
    long double nominator = 0.;
    long double denominator = 0.;
    long double sign = 1.;
    long double multi = (long double)x;
    if (s21_fabs(x) < 1.) {
      for (long double i = 1.; i < 500.; i++) {
        nominator = sign * multi;
        denominator = 2 * i - 1;

        res += nominator / denominator;
        sign *= -1;
        multi *= x * x;
      }
    } else if (s21_fabs(x) > 1.) {
      long double add_value = 0.0;
      long double sign = 1.;
      long double multi = (long double)x;

      for (long double i = 0.; i < 300.; i++) {
        nominator = sign / multi;
        denominator = 1. + (2. * i);

        add_value += (nominator / denominator);
        sign *= -1;
        multi *= x * x;
      }

      res = (S21_PI * s21_sqrt(x * x) / (2 * x)) - add_value;
    }
  }

  return res;
}