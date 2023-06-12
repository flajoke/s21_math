#include "s21_math.h"

long double s21_acos(long double x) {
  // NOTE(pottluci):
  //
  //
  return S21_PI / 2 - s21_asin(x);
}
