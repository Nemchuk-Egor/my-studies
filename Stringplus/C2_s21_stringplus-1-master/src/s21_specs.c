#include "s21_sprintf.h"

const char *set_specs(Spec *specs, const char *format, va_list *arguments) {
  format = get_specs(format, specs);
  format = get_width(format, &specs->width, arguments);
  format = get_precision(format, specs, arguments);
  format = get_length(format, specs);
  if (specs->width < 0) {
    specs->width = -specs->width;
    specs->minus = 1;
  }
  return format;
}

const char *get_specs(const char *format, Spec *specs) {
  while (*format) {
    if (*format == '+') {
      specs->plus = 1;
    } else if (*format == '-') {
      specs->minus = 1;
    } else if (*format == '0') {
      specs->zero = 1;
    } else if (*format == ' ') {
      specs->space = 1;
    } else if (*format == '#') {
      specs->hash = 1;
    } else {
      break;
    }
    format++;
  }

  if (specs->plus) specs->space = 0;
  if (specs->minus) specs->zero = 0;

  return format;
}

const char *get_width(const char *format, int *width, va_list *arguments) {
  *width = 0;
  if (*format == '*') {
    *width = va_arg(*arguments, int);
    format++;
  } else {
    while ('0' <= *format && *format <= '9') {
      *width = *width * 10 + (*format - '0');
      format++;
    }
  }

  return format;
}

const char *get_precision(const char *format, Spec *specs, va_list *arguments) {
  if (*format == '.') {
    specs->dot = 1;
    specs->zero = (!specs->minus && specs->zero) ? -1 : 0;
    format++;
    format = get_width(format, &specs->accuracy, arguments);
    if (specs->accuracy == 0) {
      specs->precision_zero = 1;
    }
  }

  return format;
}

const char *get_length(const char *format, Spec *specs) {
  if (*format == 'L' || *format == 'l' || *format == 'h') {
    specs->length = *format;
    format++;
  }
  return format;
}