#include "../s21_decimal.h"

int is_null(s21_decimal value) {
  return value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0 &&
         value.bits[3] == 0;
}