#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_insert_1) {
  char *p_buffer1 = NULL;
  char src1[256] = "Hello, My name is ILYA\n";
  char str1[256] = "World! ";
  size_t start_index = 7;
  char reference1[256] = "Hello, World! My name is ILYA\n";

  p_buffer1 = s21_insert(src1, str1, start_index);
  ck_assert_pstr_eq(p_buffer1, reference1);
  free(p_buffer1);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char *p_buffer2 = NULL;
  char src2[256] = "Hello. I like school 21\n";
  char str2[256] = ", World! My name is ILYA";
  size_t start_index2 = 5;
  char reference2[256] = "Hello, World! My name is ILYA. I like school 21\n";

  p_buffer2 = s21_insert(src2, str2, start_index2);
  ck_assert_pstr_eq(p_buffer2, reference2);
  free(p_buffer2);
}
END_TEST

START_TEST(test_s21_insert_3) {
  char *p_buffer3 = NULL;
  char src3[7] = "Hello ";
  char str3[256] = ", World! My name is ILYA";
  size_t start_index3 = 10;

  p_buffer3 = s21_insert(src3, str3, start_index3);
  ck_assert_ptr_null(p_buffer3);
  free(p_buffer3);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char* buff = "0123456789";
  char* buff2 = "9999";

  char* buff3 = s21_insert(buff, buff2, 0);
  ck_assert_str_eq("99990123456789", buff3);
  free(buff3);
}
END_TEST

START_TEST(test_s21_insert_5) {
  char* buff = "0123456789";
  char* buff2 = "9999";

  char* buff3 = s21_insert(buff, buff2, 2);
  ck_assert_str_eq("01999923456789", buff3);
  free(buff3);
}
END_TEST

START_TEST(test_s21_insert_6) {
  char* buff = "0123456789";
  char* buff2 = "9999";

  char* buff3 = s21_insert(buff, buff2, 25);
  ck_assert_ptr_null(buff3);
}
END_TEST

Suite* s21_insert_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_insert");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_insert_1);
  tcase_add_test(tc_core, test_s21_insert_2);
  tcase_add_test(tc_core, test_s21_insert_3);
  tcase_add_test(tc_core, test_s21_insert_4);
  tcase_add_test(tc_core, test_s21_insert_5);
  tcase_add_test(tc_core, test_s21_insert_6);
  suite_add_tcase(s, tc_core);
  return s;
}

