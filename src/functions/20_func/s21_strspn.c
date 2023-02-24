#include "../../headers/s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t counter = 0;
  int flag = 0;
  //int add_flag = 1;
  while (counter < s21_strlen(str1)) {
    for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
      flag = str1[counter] == str2[i] ? 1 : 0;
      if (flag) {
        result++;
        break;
      }
    }
    if (flag == 0 && result > 0) break;
    counter++;
  }

  return result;
}