#include "s21_math.h"

long double s21_floor(double x) {
  long double result = 0;

  if (is_nan(x) || x == inf || x == ninf) {
    result = x;
  } else {
    if (x == (int)x) {
      result = (int)x;
    } else if (x < 0) {
      result = (int)x - 1;
    } else {
      result = (int)x;
    }
  }

  return result;
}
