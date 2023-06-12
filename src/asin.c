#include "s21_math.h"

long double s21_asin(long double x) {
  long double result = 0;
  int replace = false;
  double sign = 1;

  if (x < 0) {
    sign = -1;
  }

  if (s21_fabs(x) > 1) {
    result = S21_NAN;
  } else {
    if (s21_fabs(x) > 0.8) {
      x = s21_sqrt(1 - x * x);
      replace = true;
    }

    result = x;
    long double numerator = x;
    long double denumerator = 1.0;

    for (int i = 1; i < 100; i += 2) {
      numerator *= x * x * i;
      denumerator *= (i + 1) * (i + 2);
      denumerator /= i;
      result += numerator / denumerator;
    }

    if (replace == true) {
      result = sign * (S21_PI / 2 - result);
    }
  }

  return result;
}
