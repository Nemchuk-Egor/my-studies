#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  int result = 1;
  s21_decimal tmp1 = remove_trailing_zeros(value1);
  s21_decimal tmp2 = remove_trailing_zeros(value2);
  if (tmp1.bits[0] == 0 && tmp1.bits[1] == 0 && tmp1.bits[2] == 0 &&
      tmp2.bits[0] == 0 && tmp2.bits[1] == 0 && tmp2.bits[2] == 0) {
    result = 1;
  } else {
    result = tmp1.bits[0] == tmp2.bits[0] && tmp1.bits[1] == tmp2.bits[1] &&
             tmp1.bits[2] == tmp2.bits[2] && tmp1.bits[3] == tmp2.bits[3];
  }

  return result;
}