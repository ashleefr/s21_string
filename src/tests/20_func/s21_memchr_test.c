#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_memchr_1) {
  char str[] = "Hello w\0orld\0";
  ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
}
END_TEST

START_TEST(test_s21_memchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(memchr(str2, 's', 6), s21_memchr(str2, 's', 6));
}
END_TEST

START_TEST(test_s21_memchr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
}
END_TEST

Suite* s21_memchr_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_memchr_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_memchr_1);
    tcase_add_test(tc_core, test_s21_memchr_2);
    tcase_add_test(tc_core, test_s21_memchr_3);
    suite_add_tcase(s, tc_core);
    return s;
}