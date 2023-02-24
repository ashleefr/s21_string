#include "../../headers/s21_string_tests.h"

START_TEST(test_to_upper_1) {
  char *p_buffer1 = NULL;
  char reference1[256] = "1234_ABCDABCD!?.,|\\\"\n\0";
  char test1[256] = "1234_abcdABCD!?.,|\\\"\n\0";

  p_buffer1 = s21_to_upper(test1);
  ck_assert_pstr_eq(p_buffer1, reference1);
  free(p_buffer1);
}
END_TEST

START_TEST(test_to_upper_2) {
  char *p_buffer2 = NULL;
  char * test2 = NULL;

  p_buffer2 = s21_to_upper(test2);
  ck_assert_ptr_null(p_buffer2);

  char *p_buffer3 = NULL;
  char * test3 = "";

  p_buffer3 = s21_to_upper(test3);
  ck_assert_pstr_eq(p_buffer3, test3);
  free(p_buffer3);
}
END_TEST

START_TEST(test_to_upper_3) {
  char *p_buffer3 = NULL;
  char * test3 = "";

  p_buffer3 = s21_to_upper(test3);
  ck_assert_pstr_eq(p_buffer3, test3);
  free(p_buffer3);
}
END_TEST

Suite* s21_to_upper_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_to_upper");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_to_upper_1);
  tcase_add_test(tc_core, test_to_upper_2);
  tcase_add_test(tc_core, test_to_upper_3);
  suite_add_tcase(s, tc_core);
  return s;
}
