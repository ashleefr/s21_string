#include "../../headers/s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int flag = 0;
  s21_size_t i = s21_strlen(str);
  while (i > 0 && !flag) {
    flag = str[i] == (char)c ? 1 : 0;
    i--;
  }

  return flag ? (char *)(str + i + 1) : S21_NULL;
}