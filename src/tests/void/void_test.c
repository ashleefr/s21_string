#include "../../headers/s21_string_tests.h"


int main(void) {
  
  Suite* suite[] = {s21_insert_test(), s21_to_lower_test(), s21_to_upper_test(), s21_trim_test(), NULL};
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