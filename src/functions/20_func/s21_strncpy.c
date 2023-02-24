#include "../../headers/s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t lenght = sizeof src > n ? n : sizeof src;
  for (s21_size_t i = 0; i < lenght; i++) {
    dest[i] = src[i];
  }
  return dest;
}