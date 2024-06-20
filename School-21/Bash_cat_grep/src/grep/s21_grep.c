#include "s21_grep_lib.h"

int main(int argc, char **argv) {
  Flags Flag = scan_flag(argc, argv);
  output(argc, argv, Flag);
  free_flags(&Flag);
  return 0;
}