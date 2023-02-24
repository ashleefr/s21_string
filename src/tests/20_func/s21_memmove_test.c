#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_memmove_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "LUGANO THE BEST!";
  char b11[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memmove(b1, b1 + 5, n1), s21_memmove(b11, b1 + 5, n1));
}
END_TEST

START_TEST(test_s21_memmove_2) {
  s21_size_t n2 = 4;
  char b2[1024] = "777 9999999";
  char b22[1024] = "777 9999999";
  ck_assert_pstr_eq(memmove(b2, b2, n2), s21_memmove(b22, b2, n2));
}
END_TEST

START_TEST(test_s21_memmove_3) {
  s21_size_t n3 = 4;
  char b3[1024] = "777 LUGANO!";
  char b33[1024] = "777 LUGANO!";
  ck_assert_pstr_eq(memmove(b3, b3, n3), s21_memmove(b33, b33, n3));
}
END_TEST

START_TEST(test_s21_memmove_4) {
  s21_size_t n4 = 4;
  char b4[1024] = "777 LUGANO!";
  char b44[1024] = "777 LUGANO!";
  ck_assert_pstr_eq(memmove(b4, b4, n4), s21_memmove(b44, b44, n4));
}
END_TEST

Suite* s21_memmove_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_memmove_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_memmove_1);
    tcase_add_test(tc_core, test_s21_memmove_2);
    tcase_add_test(tc_core, test_s21_memmove_3);
    tcase_add_test(tc_core, test_s21_memmove_4);
    suite_add_tcase(s, tc_core);
    return s;
}