#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  char specificators[] = "duoxXcpsEenfigG%";
  char *src = str;
  va_list arguments;
  va_start(arguments, format);
  while (*format) {
    if (*format == '%') {
      format++;
      Spec specs = {0};
      specs.number_system = 10;
      format = set_specs(&specs, format, &arguments);
      while (!s21_strchr(specificators, *format)) format++;
      str = parser(str, src, format, specs, &arguments);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }
  *str = '\0';
  va_end(arguments);
  return (str - src);
}

char *parser(char *str, char *src, const char *format, Spec specs,
             va_list *arguments) {
  if (*format == 'd' || *format == 'i') {
    str = print_decimal(str, specs, arguments);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
             *format == 'X') {
    specs = set_number_system(specs, *format);
    str = print_u(str, specs, arguments);
  } else if (*format == 'f') {
    specs.e = 1;
    str = print_float(str, specs, arguments, format);
  } else if ((*format == 'e') || (*format == 'E')) {
    specs.e = 1;
    str = print_e(str, specs, arguments, format);
  } else if (*format == 'c') {
    str = print_c(str, specs, arguments);
  } else if (*format == 'p') {
    void *pointer = va_arg(*arguments, void *);
    str = print_p(str, pointer, specs);
  } else if (*format == 's') {
    str = print_s(str, specs, arguments);
  } else if (*format == 'n') {
    int *count = va_arg(*arguments, int *);
    *count = str - src;
  } else if (*format == '%') {
    *str = '%';
    str++;
  } else {
    str = s21_NULL;
  }
  if (!str) *src = '\0';
  return str;
}