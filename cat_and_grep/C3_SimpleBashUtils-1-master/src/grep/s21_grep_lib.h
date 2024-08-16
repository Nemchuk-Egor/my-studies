#ifndef S21_GREP_LIB_H
#define S21_GREP_LIB_H

#define _POSIX_C_SOURCE 201709L

#include <regex.h>
#include <stdio.h>

typedef struct Flags {
  int e, i, v, c, l, n, h, s, f, o;
  char *pattern;
} Flags;

void free_flags(Flags *flag);
void pattern_add(Flags *flag, char *pattern);
void print_file_error(const char *filename, int error_code);
void add_reg_from_file(Flags *flag, char *filename);
Flags scan_flag(int argc, char **argv);
void output_line(char *line, int n);
void print_match(regex_t *reg, char *line);
void processFile(Flags flag, char *filename, regex_t *reg);
void output(int argc, char **argv, Flags flag);

#endif