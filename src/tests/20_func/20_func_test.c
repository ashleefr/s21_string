#include "../../headers/s21_string_tests.h"


int main(void) {
     
  Suite* suite[] = {s21_memchr_test(), s21_memcmp_test(), s21_memcpy_test(), s21_memmove_test(), s21_memset_test(), s21_strcat_test(), 
  s21_strchr_test(), s21_strcmp_test(), s21_strcpy_test(), s21_strcspn_test(), s21_strerror_test(), s21_strlen_test(), s21_strncat_test(), 
  s21_strncmp_test(), s21_strncpy_test(), s21_strpbrk_test(), s21_strrchr_test(), s21_strspn_test(), s21_strstr_test(), s21_strtok_test(), NULL};
  int failed_count = 0;
  int flag = EXIT_SUCCESS;

  for (int i = 0; suite[i]; ++i) {
    SRunner *suite_runner = srunner_create(suite[i]); 
    srunner_run_all(suite_runner, CK_NORMAL);
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
  }
  
  if (failed_count != 0) {
      flag = EXIT_FAILURE;
  }

  return flag;
}