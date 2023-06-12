#ifndef S21_MATH
#define S21_MATH

#define S21_NAN __builtin_nanf("0x7fc00000")
#define S21_PI ((long double)3.1415926535)
#define S21_EXP ((long double)2.7182818284)
#define S21_EPS 1e-17

#if !defined __cplusplus
#define true (0 == 0)
#define false (0 != 0)
#endif

#define inf (1. / 0.)
#define ninf (-1. / 0.)

#define is_nan(x) (x != x)
#define is_inf(value) (value == inf || value == ninf)

int s21_abs(int x);
long double s21_acos(long double x);
long double s21_asin(long double x);
long double s21_atan(long double x);
long double s21_ceil(double x);
long double s21_cos(long double x);
long double s21_exp(long double x);
long double s21_fabs(long double x);
long double s21_floor(double x);
long double s21_fmod(long double x, long double y);
long double s21_log(long double x);
long double s21_pow(long double base, long double exp);
long double s21_sin(long double x);
long double s21_sqrt(long double x);
long double s21_tan(long double x);

#endif  // S21_MATH
