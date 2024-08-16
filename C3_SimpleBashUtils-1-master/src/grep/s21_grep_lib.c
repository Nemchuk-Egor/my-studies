#include "s21_grep_lib.h"

#include <errno.h>
#include <getopt.h>
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
  Flags flags = {0};
  int opt = 0;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        flags.e = 1;
        pattern_add(&flags, optarg);
        break;
      case 'i':
        flags.i = REG_ICASE;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 'c':
        flags.c = 1;
        break;
      case 'l':
        flags.l = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 'h':
        flags.h = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 'f':
        flags.f = 1;
        add_reg_from_file(&flags, optarg);
        break;
      case 'o':
        flags.o = 1;
        break;
    }
  }
  if (flags.pattern == NULL && optind < argc) {
    flags.pattern = strdup(argv[optind++]);
  }
  if (argc - optind == 1) {
    flags.h = 1;
  }
  return flags;
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

void processFile(Flags flags, char *filename, regex_t *reg) {
  FILE *file = (filename != NULL) ? fopen(filename, "r") : stdin;
  if (file == NULL) {
    if (!flags.s) print_file_error(filename, errno);
    exit(1);
  }
  char *line = NULL;
  int line_count = 1;
  int c = 0;
  size_t memlen = 0;
  ssize_t read = getline(&line, &memlen, file);
  while (read != -1) {
    int match = regexec(reg, line, 0, NULL, 0);
    if ((match == 0 && !flags.v) || (match != 0 && flags.v)) {
      if (!flags.c && !flags.l) {
        if (!flags.h && filename != NULL) {
          printf("%s:", filename);
        }
        if (flags.n) printf("%d:", line_count);
        if (flags.o) {
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
  if (flags.c && !flags.l) {
    if (!flags.h) printf("%s:", filename);
    printf("%d\n", c);
  }
  if (flags.l && c > 0) {
    if (!flags.h) {
      printf("%s\n", filename);
    } else {
      printf("%s\n", filename);
    }
  }
  fclose(file);
}

void output(int argc, char **argv, Flags flags) {
  if (flags.pattern == NULL) {
    fprintf(stderr, "Error: No pattern provided.\n");
    exit(1);
  }

  regex_t reg;
  int error = regcomp(&reg, flags.pattern, REG_EXTENDED | flags.i);
  if (error) {
    char errbuf[1024];
    regerror(error, &reg, errbuf, sizeof(errbuf));
    fprintf(stderr, "Regex error: %s\n", errbuf);
    exit(1);
  }
  for (int i = optind; i < argc; i++) {
    processFile(flags, argv[i], &reg);
  }
  regfree(&reg);
}

void free_flags(Flags *flags) {
  if (flags->pattern != NULL) {
    free(flags->pattern);
    flags->pattern = NULL;
  }
}