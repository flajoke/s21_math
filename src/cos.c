#include "s21_math.h"

long double s21_cos(long double x) {
  // NOTE(pottluci):
  //
  //
  return s21_sin(x + S21_PI / 2);
}
