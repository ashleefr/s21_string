#include "../../headers/s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t counter = 0;
  int flag = 0;
  //    getchar();
  while (counter < s21_strlen(str1)) {
    for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
      str1[counter] == str2[i] ? flag = 1 : 0;
    }
    if (flag) break;
    counter++;
  }

  return flag == 1 ? (char*) &str1[counter] : S21_NULL;
}