#include "../../headers/s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  while (result < s21_strlen(str1)) {
    int flag = 0;
    for (s21_size_t i = 0; i < s21_strlen(str2); i++)
      str1[result] == str2[i] ? flag = 1 : 0;
    if (flag == 1) break;
    result++;
  }

  return result;
}