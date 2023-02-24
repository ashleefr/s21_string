#include "../../headers/s21_string_tests.h"

START_TEST(test_to_lower_1) {
  char *p_buffer1 = NULL;
  char test1[256] = "1234_abcdABCD!?.,|\\\n\"\0";
  char reference1[256] = "1234_abcdabcd!?.,|\\\n\"\0";

  p_buffer1 = s21_to_lower(test1);
  ck_assert_pstr_eq(p_buffer1, reference1);
  free(p_buffer1);
}
END_TEST

START_TEST(test_to_lower_2) {
  char *p_buffer2 = NULL;
  char * test2 = NULL;

  p_buffer2 = s21_to_lower(test2);
  ck_assert_ptr_null(p_buffer2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char *p_buffer3 = NULL;
  char * test3 = "";

  p_buffer3 = s21_to_lower(test3);
  ck_assert_pstr_eq(p_buffer3, test3);
  free(p_buffer3);
}
END_TEST

Suite* s21_to_lower_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_to_lower");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_to_lower_1);
  tcase_add_test(tc_core, test_to_lower_2);
  tcase_add_test(tc_core, test_to_lower_3);
  suite_add_tcase(s, tc_core);
  return s;
}

