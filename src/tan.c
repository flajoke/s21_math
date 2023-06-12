#include "s21_math.h"

long double s21_atan(long double x) {
  long double result;
  int sign;

  if (x >= 0) {
    sign = 1;
  } else {
    x *= -1;
    sign = -1;
  }

  if (is_nan(x)) {
    result = x;
  } else {
    if (is_inf(x) && x > 1e7) {
      result = S21_PI / 2 * sign;
    } else {
      result = s21_asin(x / s21_pow(1 + x * x, 0.5)) * sign;
    }
  }

  return result;
}
