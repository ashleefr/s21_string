#include "../../headers/s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *str_str = (char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    str_str[i] = (char)c;
  }

  return str;
}