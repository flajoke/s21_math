#include "s21_math.h"

// long double s21_log(long double x) {
//   long double result = 0;
//   int exp_pow = 0;

//   if (x > 0) {
//     if (is_inf(x) || is_nan(x)) {
//       result = x;
//     } else {
//       while (x >= S21_EXP) {
//         x /= S21_EXP;
//         exp_pow++;
//       }
//       for (int i = 0; i < 200; i++) {
//         long double element = result;
//         result = element + 2 * (x - s21_exp(element)) / (x +
//         s21_exp(element));
//       }
//     }
//   } else if (x == 0) {
//     result = ninf;
//   } else {
//     result = S21_NAN;
//   }

//   return (result + exp_pow);
// }

long double s21_log(long double x) {
  if (x == inf) return x;
  if (x == 0) return -inf;
  if (x < 0) return S21_NAN;
  long double result = 0, compare = 0;
  int e_repeat = 0;
  for (; x >= S21_EXP; e_repeat++) x /= S21_EXP;
  for (int i = 0; i < 100; i++) {
    compare = result;
    result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
  }
  result += e_repeat;
  return result;
}