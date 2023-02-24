#include "../../headers/s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *str_dest = (char *)dest;
  char *str_src = (char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    str_dest[i] = str_src[i];
  }
  return dest;
}