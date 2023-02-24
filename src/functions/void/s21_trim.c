#include <stdlib.h>
#include "../../headers/s21_string.h"


void trim_before_after(const char *src, const char *trim_chars, s21_size_t* count, s21_size_t* recount) {
  s21_size_t src_s = src ? s21_strlen(src) : 0;
  s21_size_t trim_s = trim_chars ? s21_strlen(trim_chars) : 0;
  int flag = (src_s && trim_s) ? 1 : 0;


  for (s21_size_t i = 0; i < src_s && flag == 1; i++) { //считаем кол-во удаляемых символов до печатуемого текста
    s21_size_t r = 0;
    for (s21_size_t j = 0; j < trim_s; j++) {
      if (src[i] == trim_chars[j]) {
          *count = *count + 1;
      } else {
        r++;
      }
    } 
    if (r == trim_s) {
      flag = 2;
    }
  }

  for (s21_size_t i = src_s - 1; (i > 0) && (flag > 0) && (*count < src_s); i--) { // считаем кол-во удаляемых символов после печатуемого текста
    s21_size_t r = 0;
    for (s21_size_t j = 0; j < trim_s; j++) {
      if (src[i] == trim_chars[j]) {
          *recount = *recount + 1;
      } else {
        r++;
      }
    } 
    if (r == trim_s) {
      flag = 0;
    }
  }
}

void *s21_trim(const char *src, const char *trim_chars) {
  char* new_str = S21_NULL;
  
  if ((src != S21_NULL) && (*src != '\0')) {
    s21_size_t src_s = s21_strlen(src); //длина  src
    if (src_s != 0) {
      
      s21_size_t count = 0; // кол-во удалаемых символов до печатаемого блока
      s21_size_t recount = 0; // кол-во удаляемых символов после печатаемого блока

      trim_before_after(src, trim_chars, &count, &recount);
      s21_size_t new_size = src_s - count - recount;
           
      new_str = malloc((new_size + 1) * sizeof(char)); 

      for(s21_size_t i = 0; (i < new_size) && (count != src_s); i++) {
        new_str[i] = src[count + i];
      }
      new_str[new_size] = '\0'; 
    } 
  } else if (src == S21_NULL) {
    ;
  } else {
       new_str = malloc(sizeof(char));
       new_str[0] = '\0'; 
    }
  return new_str;
}
