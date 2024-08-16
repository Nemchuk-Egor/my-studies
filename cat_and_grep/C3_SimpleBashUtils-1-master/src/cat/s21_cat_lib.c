#include "s21_cat_lib.h"

void scan_flag(int argc, char **argv, Flag *flags) {
  int opt = 0;
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {0, 0, 0, 0}};

  while ((opt = getopt_long(argc, argv, "bEensTtv", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        flags->b = 1;
        flags->n = 0;
        break;
      case 'E':
        flags->E = 1;
        break;
      case 'e':
        flags->E = 1;
        flags->v = 1;
        break;
      case 'n':
        if (!flags->b) {
          flags->n = 1;
        }
        break;
      case 's':
        flags->s = 1;
        break;
      case 'T':
        flags->T = 1;
        break;
      case 't':
        flags->T = 1;
        flags->v = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      default:
        print_error(argv[0], EINVAL);
        exit(EXIT_FAILURE);
    }
  }

  if (optind >= argc) {
    print_file(NULL, flags);
  } else {
    for (int i = optind; i < argc; i++) {
      print_file(argv[i], flags);
    }
  }
}

void print_error(const char *filename, int error_code) {
  fprintf(stderr, "%s: %s\n", filename, strerror(error_code));
}

void print_file(const char *filename, Flag *flags) {
  FILE *file = (filename != NULL) ? fopen(filename, "r") : stdin;
  if (file == NULL) {
    print_error(filename, errno);
    return;
  }

  char buf[4096];
  size_t nread;
  int line_number = 1;
  int empty_line_count = 0;
  int print_line_number = 1;

  while ((nread = fread(buf, 1, sizeof(buf), file)) > 0) {
    for (size_t i = 0; i < nread; i++) {
      char c = buf[i];

      if (flags->s && c == '\n') {
        empty_line_count++;
        if (empty_line_count > 2) {
          continue;
        }
      } else {
        empty_line_count = 0;
      }

      if ((flags->b && c != '\n' && print_line_number) ||
          (flags->n && print_line_number)) {
        printf("%6d\t", line_number++);
        print_line_number = 0;
      }

      if (c == '\n') {
        print_line_number = 1;
        if (flags->E) {
          putchar('$');
        }
        putchar(c);
      } else {
        if (flags->T && c == '\t') {
          printf("^I");
        } else if (flags->v) {
          print_v(c);
        } else {
          putchar(c);
        }
      }
    }
  }

  if (ferror(file)) {
    print_error(filename, errno);
  }

  if (file != stdin) {
    fclose(file);
  }
}

void print_v(char c) {
  unsigned char uc = (unsigned char)c;

  if (uc < 32 && c != '\n' && c != '\t') {
    putchar('^');
    putchar(c + 64);
  } else if (uc == 127) {
    putchar('^');
    putchar('?');
  } else if (uc > 127) {
    printf("M-");
    print_v(c - 128);
  } else {
    putchar(c);
  }
}