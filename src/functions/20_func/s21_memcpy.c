#include "../../headers/s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *work_src = (char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    ((char *)dest)[i] = work_src[i];
  }
  ((char *)dest)[n] = '\0';
  return dest;
}