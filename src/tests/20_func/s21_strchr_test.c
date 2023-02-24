#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strrchr_1) {
  char str[] = "0163456769";
  ck_assert_pstr_eq(strrchr(str, '6'), s21_strrchr(str, '6'));
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str2, 'o'), s21_strrchr(str2, 'o'));
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str3, 'h'), s21_strrchr(str3, 'h'));
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char str4[] = "";
  ck_assert_pstr_eq(strrchr(str4, 'd'), s21_strrchr(str4, 'd'));
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char str5[] = {""};
  ck_assert_pstr_eq(strrchr(str5, 'z'), s21_strrchr(str5, 'z'));
}
END_TEST

START_TEST(test_s21_strrchr_6) {
  char str1[] = "";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(test_s21_strrchr_7) {
  char str1[] = "floppy";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(test_s21_strrchr_8) {
  char str1[] = "";
  char str2 = 'f';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(test_s21_strrchr_9) {
  char str1[] = "poki doki";
  char str2 = 'o';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(test_s21_strrchr_10) {
  char str1[] = "poki doki";
  char str2 = 'i';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(test_s21_strrchr_11) {
  char str1[] = "poki p dokip";
  char str2 = 'p';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(test_s21_strrchr_12) {
  char str1[] = "ppPpppppppppP";
  char str2 = 'P';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(test_s21_strrchr_13) {
  char str1[] = "123456789";
  char str2 = '0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST


Suite* s21_strchr_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strchr_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strrchr_1);
    tcase_add_test(tc_core, test_s21_strrchr_2);
    tcase_add_test(tc_core, test_s21_strrchr_3);
    tcase_add_test(tc_core, test_s21_strrchr_4);
    tcase_add_test(tc_core, test_s21_strrchr_5);
    tcase_add_test(tc_core, test_s21_strrchr_6);
    tcase_add_test(tc_core, test_s21_strrchr_7);
    tcase_add_test(tc_core, test_s21_strrchr_8);
    tcase_add_test(tc_core, test_s21_strrchr_9);
    tcase_add_test(tc_core, test_s21_strrchr_10);
    tcase_add_test(tc_core, test_s21_strrchr_11);
    tcase_add_test(tc_core, test_s21_strrchr_12);
    tcase_add_test(tc_core, test_s21_strrchr_13);
    suite_add_tcase(s, tc_core);
    return s;
}