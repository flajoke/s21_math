#include "s21_math.h"

long double s21_fmod(long double x, long double y) {
  long double result = 0;

  if (x == 0 && (y != 0 || y != S21_NAN)) {
    result = 0;
  } else if (is_inf(x) || y == 0) {
    result = S21_NAN;
  } else if (is_inf(y) && !is_inf(x)) {
    result = x;
  } else {
    int n = x / y;
    result = (long double)x - n * (long double)y;
  }

  return result;
}
