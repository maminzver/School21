#include "../s21_math.h"

long double s21_exp(double x) {
  long double res = 1.0;
  if (S21_IS_INF(x) || S21_IS_NAN(x)) {
    res = (x == S21_INF_NEG) ? 0 : x;
    // } else if (x < -18) {
    //   res = 0;
  } else if ((x == S21_INF)) {
    res = S21_INF;
  } else {
    long double term = 1.0;
    int i = 1;
    while (i < 1000) {  // Увеличиваем количество для большей точности
      if (x > -19) {
        term *= x / i;
        res += term;
      } else if (x < -18) {  // После -18 точность теряется
        res = 0.0;
      }
      i++;
    }
  }
  return res;
}
