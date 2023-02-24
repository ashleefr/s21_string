#ifndef __SRC_HEADERS_S21_STRING_TESTS_H__
#define __SRC_HEADERS_S21_STRING_TESTS_H__

#include <check.h>
#include <stdlib.h>
#include "s21_string.h"

////
Suite* s21_memchr_test(void);
Suite* s21_memcmp_test(void);
Suite* s21_memcpy_test(void);
Suite* s21_memmove_test(void);
Suite* s21_memset_test(void);
Suite* s21_strcat_test(void);
Suite* s21_strchr_test(void);
Suite* s21_strcmp_test(void);
Suite* s21_strcpy_test(void);
Suite* s21_strcspn_test(void);
Suite* s21_strerror_test(void);
Suite* s21_strlen_test(void);
Suite* s21_strncat_test(void);
Suite* s21_strncmp_test(void);
Suite* s21_strncpy_test(void);
Suite* s21_strpbrk_test(void);
Suite* s21_strrchr_test(void);
Suite* s21_strspn_test(void);
Suite* s21_strstr_test(void);
Suite* s21_strtok_test(void);


//// VOID TESTS FUNCTIONS ////
Suite* s21_insert_test(void);
Suite* s21_to_lower_test(void);
Suite* s21_to_upper_test(void);
Suite* s21_trim_test(void);


#endif //  __SRC_HEADERS_S21_STRING_TESTS_H__