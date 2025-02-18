#include "../s21_decimal.h"

big_decimal bd_bin_add(big_decimal d1, big_decimal d2) {
  big_decimal res = d1;
  big_decimal tmp = d2;
  while (!is_null(tmp.decimals[0]) || !is_null(tmp.decimals[1])) {
    big_decimal of;
    of.decimals[0] = decimal_logic(res.decimals[0], tmp.decimals[0], _and);
    of.decimals[1] = decimal_logic(res.decimals[1], tmp.decimals[1], _and);
    of = bdshift(of, LEFT, 1);
    res.decimals[0] = decimal_logic(res.decimals[0], tmp.decimals[0], _xor);
    res.decimals[1] = decimal_logic(res.decimals[1], tmp.decimals[1], _xor);
    tmp = of;
  }
  return res;
}