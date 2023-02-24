#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strerror_1) {
  for (int i = -123; i < 0; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  for (int i = 0; i <= 106; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  for (int i = 107; i <= 234; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}

END_TEST

Suite* s21_strerror_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strerror_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strerror_1);
    suite_add_tcase(s, tc_core);
    return s;
}