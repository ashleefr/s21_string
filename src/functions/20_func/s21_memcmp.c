#include "../../headers/s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *strr1 = (char *)str1;
  char *strr2 = (char *)str2;
  s21_size_t str1_size = s21_strlen(strr1);
  s21_size_t str2_size = s21_strlen(strr2);
  int rez = 0;
  for (s21_size_t i = 0; i < n && i < str1_size && i < str2_size; i++) {
    rez = strr1[i] - strr2[i];
    if (strr1[i] != strr2[i]) break;
  }
  return rez;
}