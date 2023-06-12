#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

#define tolerance 1e-6

#define TESTS_COUNT 15

START_TEST(ABS) {
  const int max = __INT_MAX__;

  ck_assert_int_eq(abs(max), s21_abs(max));
  ck_assert_int_eq(abs(-1), s21_abs(-1));
}
END_TEST

START_TEST(ACOS) {
  for (double i = -1; i <= 1; i += 0.01) {
    ck_assert_ldouble_eq_tol(acos(i), s21_acos(i), tolerance);
  }

  // x is 1
  ck_assert_ldouble_eq(acos(1), s21_acos(1));

  ck_assert_ldouble_nan(s21_acos(3));
  ck_assert_ldouble_nan(s21_acos(-3));
  ck_assert_ldouble_nan(s21_acos(NAN));
}
END_TEST

START_TEST(ASIN) {
  for (double i = -1; i <= 1; i += 0.01) {
    ck_assert_ldouble_eq_tol(asin(i), s21_asin(i), tolerance);
  }

  // nan
  ck_assert_ldouble_nan(s21_asin(3));
  ck_assert_ldouble_nan(s21_asin(-3));
  ck_assert_ldouble_nan(s21_asin(NAN));
}
END_TEST

START_TEST(ATAN) {
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(atan(i), s21_atan(i), tolerance);
  }
  // inf
  ck_assert_ldouble_eq_tol(atan(inf), s21_atan(inf), tolerance);
  ck_assert_ldouble_eq_tol(atan(ninf), s21_atan(ninf), tolerance);
  // nan
  ck_assert_ldouble_nan(s21_atan(NAN));
}
END_TEST

START_TEST(CEIL) {
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(ceil(i), s21_ceil(i), tolerance);
  }
  // nan
  ck_assert_ldouble_nan(s21_ceil(NAN));

  // integer
  ck_assert_ldouble_eq(ceil(1), s21_ceil(1));

  // infinity
  ck_assert_ldouble_eq(ceil(inf), s21_ceil(inf));
  ck_assert_ldouble_eq(ceil(ninf), s21_ceil(ninf));
}
END_TEST

START_TEST(COS) {
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(cos(i), s21_cos(i), tolerance);
  }

  // inf
  ck_assert_ldouble_nan(s21_cos(inf));
  ck_assert_ldouble_nan(s21_cos(ninf));

  // nan
  ck_assert_ldouble_nan(s21_cos(NAN));
}
END_TEST

START_TEST(EXP) {
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(exp(i), s21_exp(i), tolerance);
  }

  // inf
  ck_assert_ldouble_infinite(s21_exp(inf));
  ck_assert_ldouble_eq_tol(exp(ninf), s21_exp(ninf), tolerance);

  // nan
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_double_eq(s21_exp(25048.369), exp(25048.369));

  ck_assert_double_eq_tol(s21_exp(-14.96), exp(-14.96), 0.000001);

  ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY));

  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));

  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));

  ck_assert_double_eq_tol(s21_exp(0), exp(0), 0.000001);

  ck_assert_double_eq_tol(s21_exp(1), exp(1), 0.000001);
  ck_assert_double_eq_tol(s21_exp(-1), exp(-1), 0.000001);

  // ck_assert_ldouble_eq_tol(s21_exp(arrexp[_i]), exp(arrexp[_i]), S21_EPS);

  double x = 999999999999;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));

  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(exp(NAN));

  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(exp(INFINITY));
}
END_TEST

START_TEST(FABS) {
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(fabsl(i), s21_fabs(i), tolerance);
  }
  // inf
  ck_assert_ldouble_infinite(s21_fabs(inf));
  ck_assert_ldouble_infinite(s21_fabs(ninf));
  // nan
  ck_assert_ldouble_nan(s21_fabs(NAN));
}
END_TEST

START_TEST(FLOOR) {
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(floor(i), s21_floor(i), tolerance);
  }

  // inf
  ck_assert_ldouble_infinite(s21_floor(inf));
  ck_assert_ldouble_infinite(s21_floor(ninf));
  // nan
  ck_assert_ldouble_nan(s21_floor(NAN));
}
END_TEST

START_TEST(FMOD) {
  for (double i = -10; i <= 10; i += 1) {
    for (double j = 0; j < 10; j++) {
      if (j == 0) j++;
      ck_assert_ldouble_eq_tol(fmod(i, j), s21_fmod(i, j), tolerance);
    }
  }
  // inf
  ck_assert_ldouble_nan(s21_fmod((inf), 15));
  ck_assert_ldouble_nan(s21_fmod((ninf), 15));
  // NOTE(pottluci): y wasn't tested for infinity
  ck_assert_ldouble_eq(fmod(1.1, inf), s21_fmod(1.1, inf));
  ck_assert_ldouble_eq(fmod(1.1, ninf), s21_fmod(1.1, ninf));
  // nan
  ck_assert_ldouble_nan(s21_fmod(NAN, 15));
  ck_assert_ldouble_nan(s21_fmod(32, 0));
}
END_TEST

START_TEST(LOG) {
  for (double i = tolerance; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(logl(i), s21_log(i), tolerance);
  }
  ck_assert_ldouble_eq(logl(0), s21_log(0));
  ck_assert_ldouble_eq(logl(1), s21_log(1));
  // // inf
  ck_assert_ldouble_infinite(s21_log(inf));
  // nan
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_nan(s21_log(ninf));
}
END_TEST

START_TEST(POW) {
  for (double i = -10; i <= 10; i += 1) {
    for (double j = -10; j <= 10; j += 1) {
      if (i == 0) i += 1;
      ck_assert_ldouble_eq_tol(pow(i, 2), s21_pow(i, 2), tolerance);
    }
  }
  // inf
  for (double i = 10; i <= 10; i += 0.1) {
    if (i == 0) i += 1;

    ck_assert_ldouble_infinite(s21_pow(i, (inf)));
    ck_assert_ldouble_eq_tol(pow(i, (ninf)), s21_pow(i, (ninf)), tolerance);
    ck_assert_ldouble_infinite(s21_pow((inf), i));
    ck_assert_ldouble_infinite(s21_pow((ninf), i));
  }
  ck_assert_ldouble_eq_tol(pow((inf), (ninf)), s21_pow((inf), (ninf)),
                           tolerance);

  ck_assert_ldouble_eq_tol(pow((ninf), (ninf)), s21_pow((ninf), (ninf)),
                           tolerance);
  // nan
  ck_assert_ldouble_nan(s21_pow(NAN, 3));
  ck_assert_ldouble_nan(s21_pow(NAN, (inf)));
  ck_assert_ldouble_nan(s21_pow(NAN, (ninf)));

  ck_assert_double_eq_tol(s21_pow(20, 0.4), pow(20, 0.4), 0.000001);

  ck_assert_double_nan(s21_pow(-20, 0.4));
  ck_assert_double_nan(pow(-20, 0.4));

  ck_assert_double_eq(s21_pow(INFINITY, INFINITY), pow(INFINITY, INFINITY));

  ck_assert_double_eq(s21_pow(-INFINITY, -INFINITY), pow(-INFINITY, -INFINITY));

  ck_assert_double_nan(s21_pow(NAN, NAN));
  ck_assert_double_nan(pow(NAN, NAN));

  ck_assert_double_nan(s21_pow(INFINITY, NAN));
  ck_assert_double_nan(pow(INFINITY, NAN));

  ck_assert_double_nan(s21_pow(NAN, INFINITY));
  ck_assert_double_nan(pow(NAN, INFINITY));

  ck_assert_double_nan(s21_pow(-INFINITY, NAN));
  ck_assert_double_nan(pow(-INFINITY, NAN));

  ck_assert_double_nan(s21_pow(NAN, -INFINITY));
  ck_assert_double_nan(pow(NAN, -INFINITY));

  ck_assert_double_eq(s21_pow(-INFINITY, INFINITY), pow(-INFINITY, INFINITY));

  ck_assert_double_eq(s21_pow(INFINITY, -INFINITY), pow(INFINITY, -INFINITY));

  ck_assert_double_eq_tol(s21_pow(12.69, 0), pow(12.69, 0), 0.000001);

  ck_assert_double_eq_tol(s21_pow(-20.63, 3), pow(-20.63, 3), 0.00001);

  ck_assert_double_eq_tol(s21_pow(-20.63, 6), pow(-20.63, 6), 0.00001);

  ck_assert_double_eq_tol(s21_pow(-INFINITY, 0), pow(-INFINITY, 0), 0.000001);

  ck_assert_double_eq_tol(s21_pow(INFINITY, 0), pow(INFINITY, 0), 0.000001);

  ck_assert_double_eq_tol(s21_pow(NAN, 0), pow(NAN, 0), 0.000001);

  ck_assert_double_eq(s21_pow(0, -INFINITY), pow(0, -INFINITY));

  ck_assert_double_eq_tol(s21_pow(0, INFINITY), pow(0, INFINITY), 0.000001);

  ck_assert_double_nan(s21_pow(0, NAN));
  ck_assert_double_nan(pow(0, NAN));

  ck_assert_double_eq(s21_pow(16894.2629, 1545), pow(16894.2629, 1545));

  ck_assert_ldouble_eq(s21_pow(16894.2629, -1545), pow(16894.2629, -1545));

  ck_assert_double_eq(s21_pow(-16894.2629, 1545), pow(-16894.2629, 1545));

  ck_assert_double_eq(s21_pow(-16894.2629, -1545), pow(-16894.2629, -1545));
}
END_TEST

START_TEST(SIN) {
  for (double i = -10; i <= 10; i += 1) {
    ck_assert_ldouble_eq_tol(sin(i), s21_sin(i), tolerance);
  }
  // inf
  ck_assert_ldouble_nan(s21_sin(inf));
  ck_assert_ldouble_nan(s21_sin(ninf));
  // nan
  ck_assert_ldouble_nan(s21_sin(NAN));
}
END_TEST

START_TEST(SQRT) {
  for (double i = 0; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(sqrt(i), s21_sqrt(i), tolerance);
  }
  // // inf
  ck_assert_ldouble_infinite(s21_sqrt(inf));
  // nan
  ck_assert_ldouble_nan(s21_sqrt(NAN));
  ck_assert_ldouble_nan(s21_sqrt(ninf));
}
END_TEST

START_TEST(TAN) {
  for (double i = -10; i <= 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(tan(i), s21_tan(i), tolerance);
  }
  // nan
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(s21_tan(inf));
  ck_assert_ldouble_nan(s21_tan(ninf));
}
END_TEST

static const TTest **test[] = {
    &ABS,   &ACOS, &ASIN, &ATAN, &CEIL, &COS,  &EXP, &FABS,
    &FLOOR, &FMOD, &LOG,  &POW,  &SIN,  &SQRT, &TAN,
};

Suite *setup_suite(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("math");
  core = tcase_create("Core");

  for (int i = 0; i < TESTS_COUNT; ++i) {
    tcase_add_test(core, *test[i]);
  }

  suite_add_tcase(suite, core);

  return suite;
}

int main(void) {
  Suite *suite;
  SRunner *runner;

  suite = setup_suite();
  runner = srunner_create(suite);

  // NOTE(pottluci): generates TAP output
  // srunner_set_tap(runner, "-");

  srunner_run_all(runner, CK_VERBOSE);
  (void)srunner_ntests_failed(runner);

  srunner_free(runner);

  return 0;
}
