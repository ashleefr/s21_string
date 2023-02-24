#include <stdlib.h>
#include "../../headers/s21_string.h"


void *s21_to_lower(const char *str) {
  char* new_str = S21_NULL;
  
  if (str != S21_NULL && str[0] != '\0') { 
    s21_size_t src_s = s21_strlen(str); //длина  src
    if (src_s != 0) {
      new_str = malloc((src_s + 1) * sizeof(char));
      new_str[src_s] = '\0';
    }
    for (s21_size_t i = 0; i < src_s && new_str != S21_NULL; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        new_str[i] = str[i] + ('a' - 'A');
      } else {
        new_str[i] = str[i];
      }
    }
  } else if (str == S21_NULL) {
    ;
  } else {
    new_str = malloc(1 * sizeof(char));
    new_str[0] = '\0';
  }
  return new_str;
}
