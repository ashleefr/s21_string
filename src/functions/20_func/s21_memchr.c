#include "../../headers/s21_string.h"

void* s21_memchr(const void* str, int c, s21_size_t n) {
  int flag = 0;
  char* work_str = (char*)str;
  char* ptr = (char*)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (work_str[i] == c) {
      ptr = &work_str[i];
      flag = 1;
    }
  }
  return flag ? ptr : 0;
}