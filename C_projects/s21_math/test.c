#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_fabs) {
  ck_assert_ldouble_eq_tol(s21_fabs(0.001), fabsl(0.001), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.001332132121643),
                           fabsl(-0.001332132121643), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(-159.056784), fabsl(-159.056784), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(3567964238463158.3),
                           fabsl(3567964238463158.3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(-13567964238463158.3),
                           fabsl(-13567964238463158.3), S21_EPS);

  ck_assert_ldouble_eq_tol(s21_fabs(S21_DBL_MAX), fabsl(S21_DBL_MAX), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fabs(-S21_DBL_MAX), fabsl(-S21_DBL_MAX),
                           S21_EPS);

  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_ne(s21_fabs(S21_NAN), fabsl(S21_NAN));

  ck_assert_ldouble_infinite(s21_fabs(S21_INF));
  ck_assert_ldouble_eq(s21_fabs(S21_INF), fabsl(S21_INF));
  ck_assert_ldouble_infinite(s21_fabs(S21_INF_NEG));
  ck_assert_ldouble_eq(s21_fabs(S21_INF_NEG), fabsl(S21_INF_NEG));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_ldouble_eq_tol(s21_ceil(100.539), ceill(100.539), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(23657.0000009), ceill(23657.0000009),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(116633354.000001), ceill(116633354.000001),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(1656.0), ceill(1656.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-165566.015), ceill(-165566.015), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-6565387.000001), ceill(-6565387.000001),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-15.0), ceill(-15.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-5633237.000000567),
                           ceill(-5633237.000000567), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(100.0000001), ceill(100.0000001), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceill(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(0.0000001), ceill(0.0000001), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(3567964238463158.1),
                           ceill(3567964238463158.1), S21_EPS);

  ck_assert_ldouble_eq_tol(s21_ceil(S21_DBL_MAX), ceill(S21_DBL_MAX), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_ceil(-S21_DBL_MAX), ceill(-S21_DBL_MAX),
                           S21_EPS);

  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_ne(s21_ceil(S21_NAN), ceill(S21_NAN));

  ck_assert_ldouble_infinite(s21_ceil(S21_INF));
  ck_assert_ldouble_eq(s21_ceil(S21_INF), ceill(S21_INF));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF_NEG));
  ck_assert_ldouble_eq(s21_ceil(S21_INF_NEG), ceill(S21_INF_NEG));
}
END_TEST

START_TEST(test_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(0.0), cosl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(2.045), cosl(2.045), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-13.45), cosl(-13.45), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(40.45), cosl(40.45), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(40500), cosl(40500), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-50680), cosl(-50680), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(120000), cosl(120000), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-520000), cosl(-520000), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(36879647), cosl(36879647), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cosl(S21_PI), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(2 * S21_PI), cosl(2 * S21_PI), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI / 2), cosl(S21_PI / 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(3 * S21_PI / 2), cosl(3 * S21_PI / 2),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(30), cosl(30), S21_EPS);

  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_ne(s21_cos(S21_NAN), cosl(S21_NAN));

  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_ne(s21_cos(S21_INF), cosl(S21_INF));
  ck_assert_ldouble_nan(s21_cos(S21_INF_NEG));
  ck_assert_ldouble_ne(s21_cos(S21_INF_NEG), cosl(S21_INF_NEG));
}
END_TEST

START_TEST(test_exp) {
  ck_assert_ldouble_eq_tol(s21_exp(0.0), expl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(0.001), expl(0.001), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-0.001332132121643),
                           expl(-0.001332132121643), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(21), expl(21), 1e-06);
  ck_assert_ldouble_eq_tol(s21_exp(-30.561), expl(-30.561), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-159.056784), expl(-159.056784), S21_EPS);
  ck_assert_ldouble_eq(s21_exp(S21_INF), expl(S21_INF));

  ck_assert_ldouble_infinite(s21_exp(S21_DBL_MAX));
  ck_assert_ldouble_eq(s21_exp(S21_DBL_MAX), expl(S21_DBL_MAX));
  ck_assert_ldouble_eq_tol(s21_exp(-S21_DBL_MAX), expl(-S21_DBL_MAX), S21_EPS);

  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_ne(s21_exp(S21_NAN), expl(S21_NAN));

  ck_assert_ldouble_infinite(s21_exp(S21_INF));
  ck_assert_ldouble_eq(s21_exp(S21_INF), expl(S21_INF));
  ck_assert_ldouble_eq_tol(s21_exp(S21_INF_NEG), expl(S21_INF_NEG), S21_EPS);
}
END_TEST

START_TEST(test_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(0.1), tanl(0.1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(-0.001332132121643),
                           tanl(-0.001332132121643), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(90), tanl(90), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(179), tanl(179), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(0), tanl(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tanl(S21_PI), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI * (2)), tanl(S21_PI * (2)), S21_EPS);
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(tanl(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_double_nan(tanl(S21_INF));
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
  ck_assert_double_nan(tanl(-S21_INF));
  double x = 1 + 1e-6;
  ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), 1e-6);

  x = -1 - 1e-6;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 1e-6);
  x = -0.4;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 1e-6);
}
END_TEST

START_TEST(test_arcsin) {
  ck_assert_double_eq_tol(s21_asin(0.001), asin(0.001), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(-0.001332132121643),
                           asin(-0.001332132121643), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.2), asin(0.2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.3), asin(0.3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.312345), asin(0.312345), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), S21_EPS);
  double x = S21_INF;
  ck_assert_ldouble_nan(s21_asin(x));
  x = -S21_INF;
  ck_assert_ldouble_nan(s21_asin(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_asin(x));
  x = S21_PI;
  ck_assert_ldouble_nan(asin(x));
  x = S21_EPS;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
  x = 100000000000;
  ck_assert_ldouble_nan(asin(x));
  x = 0.123123213323;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
  x = 0.4;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
  x = -0.4;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS);
}

END_TEST

START_TEST(test_fmod) {
  ck_assert_ldouble_eq_tol(s21_fmod(120, 2.1), fmod(120, 2.1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(1234, 0.001332132121643),
                           fmod(1234, 0.001332132121643), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(1234.3, -159.056784),
                           fmod(1234.3, -159.056784), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(64238463158.3, -159.056784),
                           fmod(64238463158.3, -159.056784), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(7964238463158.3, -13567964238463158.3),
                           fmod(7964238463158.3, -13567964238463158.3),
                           S21_EPS);
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(s21_fmod(2, 0));
  ck_assert_double_eq_tol(s21_fmod(0, 2), fmod(0, 2), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(2, 5), fmod(2, 5), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(2, -5), fmod(2, -5), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(-2, 5), fmod(-2, 5), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(-2, -5), fmod(-2, -5), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(2, 5.23), fmod(2, 5.23), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(2, -5.23), fmod(2, -5.23), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(S21_EXP, 5), fmod(S21_EXP, 5), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(S21_EXP, -5), fmod(S21_EXP, -5), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(S21_EXP, 5.23), fmod(S21_EXP, 5.23),
                          S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(S21_EXP, -5.23), fmod(S21_EXP, -5.23),
                          S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(-S21_EXP, 5), fmod(-S21_EXP, 5), S21_EPS);
  ck_assert_double_eq_tol(s21_fmod(-S21_EXP, -5), fmod(-S21_EXP, -5), S21_EPS);
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 5.23));
  ck_assert_ldouble_nan(s21_fmod(5.23, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod((S21_INF), 5.23));
  ck_assert_double_eq_tol(s21_fmod(-S21_EXP, S21_INF), fmod(-S21_EXP, S21_INF),
                          S21_EPS);

  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, S21_INF));
  ck_assert_double_eq_tol(s21_fmod(-S21_EXP, -S21_INF),
                          fmod(-S21_EXP, -S21_INF), S21_EPS);
}
END_TEST

START_TEST(test_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 2), pow(2, 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-1, -1), pow(-1, -1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, 1), pow(1, 1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(24, 0), pow(24, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(12.47, 0.5), pow(12.47, 0.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(2, 0), pow(2, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0, 2), pow(0, 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(2, 5), pow(2, 5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(2, -5), pow(2, -5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 5), pow(-2, 5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -5), pow(-2, -5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(2, 5.23), pow(2, 5.23), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(2, -5.23), pow(2, -5.23), S21_EPS);
}
END_TEST

START_TEST(test_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(0.0), sinl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(1.0), sinl(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(2), sinl(2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(4), sinl(4), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-4), sinl(-4), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(10), sinl(10), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(90), sinl(90), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-666666.3), sinl(-666666.3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(666666.3), sinl(666666.3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(91), sinl(91), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(359), sinl(359), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(360), sinl(360), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(361), sinl(361), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(179.96394497), sinl(179.96394497), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(271), sinl(271), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sinl(S21_PI), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(30), cosl(30), S21_EPS);
}
END_TEST

START_TEST(test_floor) {
  ck_assert_double_eq_tol(s21_floor(0.001), floorl(0.001), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(-0.001332132121643),
                           floorl(-0.001332132121643), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(-12.0564), floorl(-12.0564), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(456.456), floorl(456.456), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(0.0), floorl(0.0), S21_EPS);
}
END_TEST

START_TEST(test_log) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), logl(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_log(64238463158.5), logl(64238463158.5),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_log(2.5), logl(2.5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_log(0.2), logl(0.2), S21_EPS);
  ck_assert_ldouble_nan(s21_log(-159.056784));
  ck_assert_ldouble_nan(logl(-159.056784));
  ck_assert_ldouble_nan(s21_log(-135679642384));
  ck_assert_ldouble_nan(logl(-135679642384));
}

END_TEST

START_TEST(test_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(0.001), atanl(0.001), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atanl(-1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atanl(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atanl(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(12.47), atanl(12.47), S21_EPS);
}
END_TEST

START_TEST(test_abs) {
  int x;
  x = 5;
  ck_assert_int_eq(abs(x), s21_abs(x));
  x = -4;
  ck_assert_int_eq(abs(x), s21_abs(x));
  x = 0;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(test_sqrt) {
  double y;
  y = 9;
  ck_assert_double_eq(sqrt(y), s21_sqrt(y));
  y = 10;
  ck_assert_double_eq(sqrt(y), s21_sqrt(y));
  y = 10000;
  ck_assert_double_eq(sqrt(y), s21_sqrt(y));
  y = 1.69;
  ck_assert_double_eq(sqrt(y), s21_sqrt(y));
  y = 13.34;
  ck_assert_double_eq(sqrt(y), s21_sqrt(y));
}
END_TEST

START_TEST(test_acos) {
  for (double x = -1; x < 1; x += 0.05) {
    ck_assert_double_eq_tol(s21_acos(x), acos(x), S21_EXP);
  }
  ck_assert_double_nan(s21_acos(-2));
  ck_assert_double_nan(s21_acos(1.2));
}
END_TEST

Suite *math_suite(void) {
  Suite *s;
  TCase *tc_core_fabs;
  TCase *tc_core_ceil;
  TCase *tc_core_cos;
  TCase *tc_core_exp;
  TCase *tc_core_tan;
  TCase *tc_core_arcsin;
  TCase *tc_core_fmod;
  TCase *tc_core_pow;
  TCase *tc_core_sin;
  TCase *tc_core_floor;
  TCase *tc_core_log;
  TCase *tc_core_atan;
  TCase *tc_core_abs;
  TCase *tc_core_sqrt;
  TCase *tc_core_acos;

  s = suite_create("Math");
  tc_core_fabs = tcase_create("fabs_core");
  tc_core_ceil = tcase_create("ceil_core");
  tc_core_cos = tcase_create("cos_core");
  tc_core_exp = tcase_create("exp_core");
  tc_core_tan = tcase_create("tan_core");
  tc_core_arcsin = tcase_create("arcsin_core");
  tc_core_fmod = tcase_create("fmod_core");
  tc_core_pow = tcase_create("pow_core");
  tc_core_sin = tcase_create("sin_core");
  tc_core_floor = tcase_create("floor_core");
  tc_core_log = tcase_create("log_core");
  tc_core_atan = tcase_create("atan_core");
  tc_core_abs = tcase_create("abs_core");
  tc_core_sqrt = tcase_create("sqrt_core");
  tc_core_acos = tcase_create("acos_core");

  tcase_add_test(tc_core_fabs, test_fabs);
  suite_add_tcase(s, tc_core_fabs);

  tcase_add_test(tc_core_ceil, test_ceil);
  suite_add_tcase(s, tc_core_ceil);

  tcase_add_test(tc_core_cos, test_cos);
  suite_add_tcase(s, tc_core_cos);

  tcase_add_test(tc_core_exp, test_exp);
  suite_add_tcase(s, tc_core_exp);

  tcase_add_test(tc_core_tan, test_tan);
  suite_add_tcase(s, tc_core_tan);

  tcase_add_test(tc_core_arcsin, test_arcsin);
  suite_add_tcase(s, tc_core_arcsin);

  tcase_add_test(tc_core_fmod, test_fmod);
  suite_add_tcase(s, tc_core_fmod);

  tcase_add_test(tc_core_pow, test_pow);
  suite_add_tcase(s, tc_core_pow);

  tcase_add_test(tc_core_sin, test_sin);
  suite_add_tcase(s, tc_core_sin);

  tcase_add_test(tc_core_floor, test_floor);
  suite_add_tcase(s, tc_core_floor);

  tcase_add_test(tc_core_log, test_log);
  suite_add_tcase(s, tc_core_log);

  tcase_add_test(tc_core_atan, test_atan);
  suite_add_tcase(s, tc_core_atan);

  tcase_add_test(tc_core_abs, test_abs);
  suite_add_tcase(s, tc_core_abs);

  tcase_add_test(tc_core_sqrt, test_sqrt);
  suite_add_tcase(s, tc_core_sqrt);

  tcase_add_test(tc_core_acos, test_acos);
  suite_add_tcase(s, tc_core_acos);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (!number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}