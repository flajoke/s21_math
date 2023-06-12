#include "s21_math.h"

long double s21_sqrt(long double x) {
  if (x < 0) {
    x = S21_NAN;
  }

  return s21_pow(x, 1. / 2);
}
