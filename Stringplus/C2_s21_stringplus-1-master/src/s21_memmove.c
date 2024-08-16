#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (dest == s21_NULL || src == s21_NULL) {
    return s21_NULL;
  }

  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  if (d < s) {
    while (n--) {
      *d++ = *s++;
    }
  } else {
    d += n;
    s += n;
    while (n--) {
      *(--d) = *(--s);
    }
  }
  return dest;
}
