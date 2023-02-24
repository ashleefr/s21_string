#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strpbrk_1) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char str1[] = "floppy";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char str1[] = "";
  char str2[] = "floppy";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  char str1[] = "poki doki";
  char str2[] = "o";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  char str1[] = "poki doki";
  char str2[] = "i";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_6) {
  char str1[] = "poki doki";
  char str2[] = "p";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_7) {
  char str1[] = "ppppppppppppP";
  char str2[] = "P";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_8) {
  char str1[] = "ppppppppppppP";
  char str2[] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_9) {
  char str[] = "this_is_a_";
  ck_assert_pstr_eq(strpbrk(str, "369"), s21_strpbrk(str, "369"));
}
END_TEST

START_TEST(test_s21_strpbrk_10) {
  char str2[] = "john.smith@mic\0rosoft.com";
  ck_assert_pstr_eq(strpbrk(str2, "fzx"), s21_strpbrk(str2, "fzx"));
}
END_TEST

START_TEST(test_s21_strpbrk_11) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strpbrk(str3, "saq"), s21_strpbrk(str3, "saq"));
}
END_TEST

Suite* s21_strpbrk_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strpbrk_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strpbrk_1);
    tcase_add_test(tc_core, test_s21_strpbrk_2);
    tcase_add_test(tc_core, test_s21_strpbrk_3);
    tcase_add_test(tc_core, test_s21_strpbrk_4);
    tcase_add_test(tc_core, test_s21_strpbrk_5);
    tcase_add_test(tc_core, test_s21_strpbrk_6);
    tcase_add_test(tc_core, test_s21_strpbrk_7);
    tcase_add_test(tc_core, test_s21_strpbrk_8);
    tcase_add_test(tc_core, test_s21_strpbrk_9);
    tcase_add_test(tc_core, test_s21_strpbrk_10);
    tcase_add_test(tc_core, test_s21_strpbrk_11);
    suite_add_tcase(s, tc_core);
    return s;
}