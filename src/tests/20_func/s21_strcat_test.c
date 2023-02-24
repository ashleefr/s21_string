#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strcat_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcat(b1, str_1_2), s21_strcat(b11, str_1_2));
}
END_TEST

START_TEST(test_s21_strcat_2) {
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strcat(b2, str_2_2), s21_strcat(b22, str_2_2));
}
END_TEST

START_TEST(test_s21_strcat_3) {
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strcat(b3, str_3_2), s21_strcat(b33, str_3_2));
}
END_TEST



Suite* s21_strcat_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strcat_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strcat_1);
    tcase_add_test(tc_core, test_s21_strcat_2);
    tcase_add_test(tc_core, test_s21_strcat_3);
    suite_add_tcase(s, tc_core);
    return s;
}