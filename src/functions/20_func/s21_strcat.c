#include "../../headers/s21_string.h"
//#include <stdio.h>
char *s21_strcat(char *dest, const char *src) {
  s21_size_t lenght = s21_strlen(dest);
  for (s21_size_t i = 0; i < lenght; i++) {
    //        printf("[DEBUG] BEFORE dest = %i, src = %i\n", (int) dest[i +
    //        lenght], (int) src[i]);
    dest[i + lenght] = src[i];
    //        printf("[DEBUG] AFTER dest = %i, src = %i\n", (int) dest[i +
    //        lenght], (int) src[i]);
  }
  return dest;
}