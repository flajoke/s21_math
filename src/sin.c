#include "s21_math.h"

long double s21_sin(long double x) {
  x = s21_fmod(x, 2 * S21_PI);

  if (x > S21_PI) {
    x = -1 * s21_fmod(x, S21_PI);
  }

  long double numerator = x;
  long double denominator = 1.;
  long double result = x;

  long double x_squared = x * x;
  int sign = 1;

  for (int i = 1; i < 37; i += 2) {
    sign *= -1;

    denominator *= (i + 1) * (i + 2);
    numerator *= x_squared;
    result += sign * numerator / denominator;
  }
  return result;
}
