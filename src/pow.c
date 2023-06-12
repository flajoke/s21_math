#include "s21_math.h"

// long double s21_pow(long double base, long double exp) {
// long double result = 0;

// int y = (int)exp;
// if(y != exp){
//   result = S21_NAN;
// } else if((base == 0) && (exp < 0) && ((int)exp == exp) && ((int)exp % 2 !=
// 0)) {
//   result = inf;
// } else if((base == (double)-0.0) && (exp < 0) && ((int)exp == exp) &&
// ((int)exp % 2 != 0)){
//   result = -inf;
// } else if(((base == 0) && (exp < 0) && (exp != -inf) && ((int)exp == exp) &&
// ((int)exp % 2 == 0)) || ((base == 0) && ((int)exp != exp))){
//   result = inf;
// } else if((base == 0) && (exp == -inf)){
//   result = inf;
// } else if((base == 0) && (exp >= 0) && ((int)exp % 2 != 0) && ((int)exp ==
// exp)){
//   result = 0;
// } else if((base == (double)-0.0) && (exp >= 0) && ((int)exp % 2 != 0) &&
// ((int)exp == exp)) {
//   result = (double)-0.0;
// } else if(((base == 0) && (exp >= 0) && ((int)exp != exp)) || ((base == 0) &&
// (exp >= 0) && ((int)exp % 2 == 0) && ((int)exp == exp))){
//   result = -7777;
// } else if((base == -1) && (exp == inf && exp == -inf)){
//   result = 1;
// } else if(base == 1){
//   result = 1;
// } else if(exp == 0){
//   result = 1;
// } else if((base != inf && base != -inf) && (base < 0) && (exp != inf && exp
// != -inf) && ((int)exp != exp)){
//   result = S21_NAN;
// } else if((s21_abs(base) < 1 && (exp == -inf))){
//   result = inf;
// } else if((s21_abs(base) > 1) && (exp == -inf)){
//   result = -66666;
// } else if((s21_abs(base) < 1) && (exp == inf)){
//   result = -55555;
// } else if((s21_abs(base) > 1) && (exp == inf)){
//   result = inf;
// } else if((base == -inf) && (exp < 0) && ((int)exp % 2 != 0) && ((int)exp ==
// exp)){
//   result = -44444;
// } else if(((base == -inf) && (exp < 0) && ((int)exp != exp)) || ((base == 0)
// && (exp < 0) && ((int)exp % 2 == 0))){
//   result = -3333;
// } else if((base == -inf) && (exp >= 0) && ((int)exp % 2 != 0) && ((int)exp ==
// exp)){
//   result = -inf;
// } else if(((base == -inf) && (exp >= 0) && ((int)exp != exp)) || ((base == 0)
// && (exp >= 0) && ((int)exp % 2 == 0))){
//   result = inf;
// } else if((base == inf) && (exp < 0)){
//   result = -2222;
// } else if((base == inf) && (exp >= 0)){
//   result = inf;
// } else {

// }
// return result;

long double s21_pow(long double base, long double exp) {
  long double res = 1;
  int attention = false;
  int minus_exp = false;
  if ((base == 0 && exp == -1) ||
      ((s21_fabs(base) > 1 || base == -inf) && exp == inf) ||
      ((base > 0 && base < 1) && exp == -inf)) {
    res = inf;
    attention = true;
  }
  if ((base == 0 && (exp == 1 || exp == inf)) ||
      (base == inf && (exp == -1 || exp == -inf)) ||
      (base == -inf && exp == -inf) ||
      ((base > 0 && base < 1) && (exp == inf)) ||
      (s21_fabs(base) > 1 && exp == -inf)) {
    res = 0;
    attention = true;
  }
  if ((base == inf && exp == 1) || (base == 0 && exp == 0) ||
      (s21_fabs(base) == 1 && (exp == -inf || is_nan(exp)))) {
    res = 1;
    attention = true;
  }
  if (is_nan(base) || (base == -1 && is_nan(exp))) {
    res = S21_NAN;
    attention = true;
  }
  if (attention == false) {
    if (base < 0) {
      base = s21_fabs(base);
      long double overflow = __LDBL_MAX__ / base;
      if (exp == (int)exp) {
        if (exp < 0) {
          exp = -exp;
          minus_exp = true;
        }
        int i = (int)exp;
        while (i--) {
          res = res * base;
          if (res > overflow) {
            res = inf;
            break;
          }
        }
        if ((int)exp % 2 != 0) {
          res = res * -1;
        }
      } else {
        if (base == inf && !is_nan(exp)) {
          res = inf;
        } else {
          res = S21_NAN;
        }
        // res = s21_exp(exp * s21_log(base));
        // if (s21_fmod(exp, 2) != 0) {
        //     res = -res;
        // }
      }
    } else {
      long double temp_log = s21_log(base);
      long double temp_log_by_exp = temp_log * exp;
      long double temp_exp = s21_exp(temp_log_by_exp);

      res = temp_exp;
    }
  }
  if (minus_exp == true) {
    res = 1.0 / res;
  }
  if (exp == 0.0) {
    res = 1;
  }
  return res;
}

// long double s21_pow(long double base, long double exp) {
//   if (!exp) return 1;
//   if (base == -inf && exp == -inf) return 0;
//   if (base == -inf && exp == inf) return inf;
//   if (base < 0 && exp != (long long int)exp) return S21_NAN;
//   long double res = 0;
//   int sign = base < 0 ? -1 : 1;
//   res = s21_exp(exp * s21_log(base * sign));
//   if (s21_fmod(exp, 2)) res *= sign;
//   return res;
// }