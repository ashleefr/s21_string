#include "../../headers/s21_string_tests.h"

START_TEST(test_trim_1) {
  char *p_buffer1 = NULL;
  char src1[256] = "***////Hello, My name is D*ck.****////";
  char trim_chars1[256] = "*/";
  char reference1[256] = "Hello, My name is D*ck.";

  p_buffer1 = s21_trim(src1, trim_chars1);
  ck_assert_pstr_eq(p_buffer1, reference1);
  free(p_buffer1);
}
END_TEST

START_TEST(test_trim_2) {
  char *p_buffer2 = NULL;
  char src2[256] = "            ";
  char trim_chars2[256] = " ";
  char reference2[256] = "";

  p_buffer2 = s21_trim(src2, trim_chars2);
  ck_assert_pstr_eq(p_buffer2, reference2);
  free(p_buffer2);
}
END_TEST

START_TEST(test_trim_3) {
  char *p_buffer3 = NULL;
  char *src3 = NULL;
  char trim_chars3[256] = " ";

  p_buffer3 = s21_trim(src3, trim_chars3);
  ck_assert_ptr_null(p_buffer3);
  free(p_buffer3);
}
END_TEST

START_TEST(test_trim_4) {
  char* buff = "     '''''asdfADASSA5522 ASasdaspqp112212'''''    ";
  char* buff2 = " '2";
  char* reference = "asdfADASSA5522 ASasdaspqp11221";
  char* buff3 = s21_trim(buff, buff2);
  ck_assert_str_eq(reference, buff3);
  free(buff3);
}
END_TEST

START_TEST(test_trim_5) {
  char* buff = "                   ";
  char* buff2 = " ";
  char* buff3 = s21_trim(buff, buff2);
  ck_assert_str_eq("", buff3);
  free(buff3);
}
END_TEST

START_TEST(test_trim_6) {
  char* buff = NULL;
  char* buff2 = " ";
  char* buff3 = s21_trim(buff, buff2);
  ck_assert_ptr_null(buff3);
}
END_TEST

Suite* s21_trim_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_trim");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_trim_1);
  tcase_add_test(tc_core, test_trim_2);
  tcase_add_test(tc_core, test_trim_3);
  tcase_add_test(tc_core, test_trim_4);
  tcase_add_test(tc_core, test_trim_5);
  tcase_add_test(tc_core, test_trim_6);
  suite_add_tcase(s, tc_core);
  return s;
}
