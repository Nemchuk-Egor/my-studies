#include "s21_grep_lib.h"

#include <errno.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pattern_add(Flags *flag, char *pattern) {
  if (flag->pattern != NULL) {
    size_t len = strlen(flag->pattern) + strlen(pattern) + 3;
    char *new_pattern = malloc(len);
    if (new_pattern == NULL) {
      perror("malloc");
      exit(1);
    }
    snprintf(new_pattern, len, "%s|%s", flag->pattern, pattern);
    free(flag->pattern);
    flag->pattern = new_pattern;
  } else {
    flag->pattern = strdup(pattern);
  }
}

void print_file_error(const char *filename, int error_code) {
  fprintf(stderr, "%s: %s\n", filename, strerror(error_code));
}

void add_reg_from_file(Flags *flag, char *filename) {
  FILE *file = (filename != NULL) ? fopen(filename, "r") : stdin;
  if (file == NULL) {
    if (!flag->s) print_file_error(filename, errno);
    exit(1);
  }
  char *line = NULL;
  size_t memlen = 0;
  ssize_t read = getline(&line, &memlen, file);
  while (read != -1) {
    if (line[read - 1] == '\n') line[read - 1] = '\0';
    pattern_add(flag, line);
    read = getline(&line, &memlen, file);
  }
  free(line);
  fclose(file);
}

Flags scan_flag(int argc, char **argv) {
  Flags Flags = {0};
  int opt = 0;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        Flags.e = 1;
        pattern_add(&Flags, optarg);
        break;
      case 'i':
        Flags.i = REG_ICASE;
        break;
      case 'v':
        Flags.v = 1;
        break;
      case 'c':
        Flags.c = 1;
        break;
      case 'l':
        Flags.l = 1;
        break;
      case 'n':
        Flags.n = 1;
        break;
      case 'h':
        Flags.h = 1;
        break;
      case 's':
        Flags.s = 1;
        break;
      case 'f':
        Flags.f = 1;
        add_reg_from_file(&Flags, optarg);
        break;
      case 'o':
        Flags.o = 1;
        break;
    }
  }
  if (Flags.pattern == NULL && optind < argc) {
    Flags.pattern = strdup(argv[optind++]);
  }
  if (argc - optind == 1) {
    Flags.h = 1;
  }
  return Flags;
}

void output_line(char *line, int n) {
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
  if (line[n - 1] != '\n') putchar('\n');
}

void print_match(regex_t *reg, char *line) {
  regmatch_t match;
  int offset = 0;
  while (regexec(reg, line + offset, 1, &match, 0) == 0) {
    int start = match.rm_so + offset;
    int end = match.rm_eo + offset;
    for (int i = start; i < end; i++) {
      putchar(line[i]);
    }
    putchar('\n');
    offset = end;
  }
}

void processFile(Flags flag, char *filename, regex_t *reg) {
  FILE *file = (filename != NULL) ? fopen(filename, "r") : stdin;
  if (file == NULL) {
    if (!flag.s) print_file_error(filename, errno);
    exit(1);
  }
  char *line = NULL;
  int line_count = 1;
  int c = 0;
  size_t memlen = 0;
  ssize_t read = getline(&line, &memlen, file);
  while (read != -1) {
    int match = regexec(reg, line, 0, NULL, 0);
    if ((match == 0 && !flag.v) || (match != 0 && flag.v)) {
      if (!flag.c && !flag.l) {
        if (!flag.h && filename != NULL) {
          printf("%s:", filename);
        }
        if (flag.n) printf("%d:", line_count);
        if (flag.o) {
          print_match(reg, line);
        } else {
          output_line(line, read);
        }
      }
      c++;
    }
    read = getline(&line, &memlen, file);
    line_count++;
  }
  free(line);
  if (flag.c && !flag.l) {
    if (!flag.h) printf("%s:", filename);
    printf("%d\n", c);
  }
  if (flag.l && c > 0) {
    if (!flag.h) {
      printf("%s\n", filename);
    } else {
      printf("%s\n", filename);
    }
  }
  fclose(file);
}

void output(int argc, char **argv, Flags flag) {
  if (flag.pattern == NULL) {
    fprintf(stderr, "Error: No pattern provided.\n");
    exit(1);
  }

  regex_t reg;
  int error = regcomp(&reg, flag.pattern, REG_EXTENDED | flag.i);
  if (error) {
    char errbuf[1024];
    regerror(error, &reg, errbuf, sizeof(errbuf));
    fprintf(stderr, "Regex error: %s\n", errbuf);
    exit(1);
  }
  for (int i = optind; i < argc; i++) {
    processFile(flag, argv[i], &reg);
  }
  regfree(&reg);
}

void free_flags(Flags *flag) {
  if (flag->pattern != NULL) {
    free(flag->pattern);
    flag->pattern = NULL;
  }
}
