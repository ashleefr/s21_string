#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strcpy_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcpy(b1, str_1_2), s21_strcpy(b11, str_1_2));
}
END_TEST

START_TEST(test_s21_strcpy_2) {
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_pstr_eq(strcpy(b2, str_2_2), s21_strcpy(b22, str_2_2));
}
END_TEST

START_TEST(test_s21_strcpy_3) {
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "LUGANO!";
  ck_assert_pstr_eq(strcpy(b3, str_3_2), s21_strcpy(b33, str_3_2));
}
END_TEST


Suite* s21_strcpy_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strcpy_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strcpy_1);
    tcase_add_test(tc_core, test_s21_strcpy_2);
    tcase_add_test(tc_core, test_s21_strcpy_3);
    suite_add_tcase(s, tc_core);
    return s;
}