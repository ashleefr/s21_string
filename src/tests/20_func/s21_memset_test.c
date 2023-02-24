#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_memset_1) {
  s21_size_t n1 = 6;
  int c1 = '7';
  char b1[1024] = "LUGANO THE BEST!";
  char b11[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memset(b1, c1, n1), s21_memset(b11, c1, n1));
}
END_TEST

START_TEST(test_s21_memset_2) {
  s21_size_t n2 = 4;
  int c2 = '4';
  char b2[1024] = " BEST!!";
  char b22[1024] = " BEST!!";
  ck_assert_pstr_eq(memset(b2, c2, n2), s21_memset(b22, c2, n2));
}
END_TEST

START_TEST(test_s21_memset_3) {
  s21_size_t n3 = 6;
  int c3 = '3';
  char b3[1024] = " LUGANO!";
  char b33[1024] = " LUGANO!";
  ck_assert_pstr_eq(memset(b3, c3, n3), s21_memset(b33, c3, n3));
}
END_TEST

Suite* s21_memset_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_memset_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_memset_1);
    tcase_add_test(tc_core, test_s21_memset_2);
    tcase_add_test(tc_core, test_s21_memset_3);
    suite_add_tcase(s, tc_core);
    return s;
}