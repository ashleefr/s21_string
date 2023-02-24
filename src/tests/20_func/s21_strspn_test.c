#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strspn_1) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_2) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_3) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_4) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_5) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_6) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_7) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_8) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_9) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_10) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_11) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_12) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_13) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_14) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_15) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strspn_16) {
  char str[] = "12-years";
  ck_assert_int_eq(strspn(str, "1234567890"), s21_strspn(str, "1234567890"));
}
END_TEST

START_TEST(test_s21_strspn_17) {
  char str2[] = "this is a test";
  ck_assert_int_eq(strspn(str2, "shit "), s21_strspn(str2, "shit "));
}
END_TEST

START_TEST(test_s21_strspn_18) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's'};
  ck_assert_int_eq(strspn(str3, "01234"), s21_strspn(str3, "01234"));
}
END_TEST

Suite* s21_strspn_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strstr_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strspn_1);
    tcase_add_test(tc_core, test_s21_strspn_2);
    tcase_add_test(tc_core, test_s21_strspn_3);
    tcase_add_test(tc_core, test_s21_strspn_4);
    tcase_add_test(tc_core, test_s21_strspn_5);
    tcase_add_test(tc_core, test_s21_strspn_6);
    tcase_add_test(tc_core, test_s21_strspn_7);
    tcase_add_test(tc_core, test_s21_strspn_8);
    tcase_add_test(tc_core, test_s21_strspn_9);
    tcase_add_test(tc_core, test_s21_strspn_10);
    tcase_add_test(tc_core, test_s21_strspn_11);
    tcase_add_test(tc_core, test_s21_strspn_12);
    tcase_add_test(tc_core, test_s21_strspn_13);
    tcase_add_test(tc_core, test_s21_strspn_14);
    tcase_add_test(tc_core, test_s21_strspn_15);
    tcase_add_test(tc_core, test_s21_strspn_16);
    tcase_add_test(tc_core, test_s21_strspn_17);
    tcase_add_test(tc_core, test_s21_strspn_18);
    suite_add_tcase(s, tc_core);
    return s;
}