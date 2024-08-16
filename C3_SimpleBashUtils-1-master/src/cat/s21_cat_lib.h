#ifndef S21_CAT_LIB_H
#define S21_CAT_LIB_H

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int b, n, s, E, T, v;
} Flag;

void scan_flag(int argc, char **argv, Flag *flags);
void print_error(const char *filename, int error_code);
void print_file(const char *filename, Flag *flags);
void print_v(char c);

#endif