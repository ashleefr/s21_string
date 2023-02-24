#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strstr_1) {
    char str[] = "";
    ck_assert_pstr_eq(strstr(str, ""), s21_strstr(str, ""));
}
END_TEST

START_TEST(test_s21_strstr_2) {
    char str2[] = "john.smith@mic\0rosoft.com";
    ck_assert_pstr_eq(strstr(str2, "sm"), s21_strstr(str2, "sm"));
}
END_TEST

START_TEST(test_s21_strstr_3) {
    char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
    ck_assert_pstr_eq(strstr(str3, "woo"), s21_strstr(str3, "woo"));
}
END_TEST

START_TEST(test_s21_strstr_4) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_5) {
  char haystack[] = "";
  char needle[] = "jho1faQsdkjnSa3aefwf8hiuJafeHioj";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_6) {
  char haystack[] = "safQhilufas7MaSef2345wknwefnkjHawe2fhilu";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_7) {
  char haystack[] = "You are toxic!";
  char needle[] = "toxic";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_8) {
  char haystack[] = "There is no right word in this test!";
  char needle[] = "NOT";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_9) {
  char haystack[] = "AbOBosNyTSa";
  char needle[] = "aBoboSNYTsa";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_10) {
  char haystack[] = "AD AD AD";
  char needle[] = "AD";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_11) {
  char haystack[] = "22 321 123";
  char needle[] = "123";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_12) {
  char haystack[] = "1";
  char needle[] = "1";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_13) {
  char haystack[] =
      "13625523478437263475984675342345sdghyftrg freshtsyASFWEt wEafe";
  char needle[] = " ";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_14) {
  char haystack[] = "-";
  char needle[] = "1234567890qwertyuiopasdfghjk-";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite* s21_strstr_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strstr_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strstr_1);
    tcase_add_test(tc_core, test_s21_strstr_2);
    tcase_add_test(tc_core, test_s21_strstr_3);
    tcase_add_test(tc_core, test_s21_strstr_4);
    tcase_add_test(tc_core, test_s21_strstr_5);
    tcase_add_test(tc_core, test_s21_strstr_6);
    tcase_add_test(tc_core, test_s21_strstr_7);
    tcase_add_test(tc_core, test_s21_strstr_8);
    tcase_add_test(tc_core, test_s21_strstr_9);
    tcase_add_test(tc_core, test_s21_strstr_10);
    tcase_add_test(tc_core, test_s21_strstr_11);
    tcase_add_test(tc_core, test_s21_strstr_12);
    tcase_add_test(tc_core, test_s21_strstr_13);
    tcase_add_test(tc_core, test_s21_strstr_14);
    suite_add_tcase(s, tc_core);
    return s;
}