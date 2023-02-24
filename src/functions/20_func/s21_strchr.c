#include "../../headers/s21_string.h"

char *s21_strchr(const char *str, int c) {
  int flag = 0;
  s21_size_t i = 0;
  while (i < s21_strlen(str) && !flag) {
    flag = str[i] == (char)c ? 1 : 0;
    i++;
  }

  return flag ? (char *)(str + i - 1) : S21_NULL;
}