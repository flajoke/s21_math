#include "s21_math.h"

long double s21_exp(long double x) {
  int attention = false;
  long double res = 1;
  if (x == inf) {
    res = x;
    attention = true;
  }
  if (x == -inf) {
    res = 0;
    attention = true;
  }
  if (attention == false) {
    int minus = false;
    if (x < 0) {
      x = -x;
      minus = true;
    }
    long double value = 1;
    long double i = 1;
    while (s21_fabs(value) > S21_EPS) {
      if (res > __DBL_MAX__) {
        res = inf;
        break;
      }
      value = value * (x / i);
      i++;
      res = res + value;
    }
    if (minus == true) {
      res = 1.0 / res;
    }
  }
  return res;
}