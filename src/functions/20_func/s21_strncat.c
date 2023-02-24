#include "../../headers/s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t lenght_src = s21_strlen(src) < n ? s21_strlen(src) : n;
  s21_size_t lenght_dest = s21_strlen(dest);
  for (s21_size_t i = 0; i < lenght_src; i++) {
    dest[i + lenght_dest] = src[i];
  }
  return dest;
}