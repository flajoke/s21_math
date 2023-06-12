#include "s21_math.h"

long double s21_tan(long double x) {
  // NOTE(pottluci):
  //
  //
  return s21_sin(x) / s21_sin(x + S21_PI / 2);
}
