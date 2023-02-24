#include "../../headers/s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  s21_size_t lenght_str1 = s21_strlen(str1);
  s21_size_t lenght_str2 = s21_strlen(str2);
  int result = 0;

  s21_size_t i = 0;
  while (i < lenght_str1 && i < lenght_str2 && result == 0) {
    result = str1[i] != str2[i] ? (int)str1[i] - (int)str2[i] : 0;
    i++;
  }

  if (lenght_str1 != lenght_str2 && result == 0) {
    result = lenght_str1 > lenght_str2 ? (int)str1[lenght_str2]
                                       : -(int)str2[lenght_str1];
  }

  return result;
}