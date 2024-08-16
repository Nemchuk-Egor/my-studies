#include "s21_cat_lib.h"

int main(int argc, char **argv) {
  Flag flag = {0};
  scan_flag(argc, argv, &flag);
  return 0;
}