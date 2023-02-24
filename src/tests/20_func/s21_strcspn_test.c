#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strcspn_1) {
  char str1[] = "this is a test";
  ck_assert_int_eq(strcspn(str1, "ab"), s21_strcspn(str1, "ab"));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char str2[] = "LOST: 4-8-15-16-23-42";
  ck_assert_int_eq(strcspn(str2, "1234567890"),
                   s21_strcspn(str2, "1234567890"));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_int_eq(strcspn(str3, "zx"), s21_strcspn(str3, "zx"));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  char str[] = "12-years";
  ck_assert_int_eq(strspn(str, "1234567890"), s21_strspn(str, "1234567890"));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  char str2[] = "this is a test";
  ck_assert_int_eq(strspn(str2, "shit "), s21_strspn(str2, "shit "));
}
END_TEST

START_TEST(test_s21_strcspn_6) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's'};
  ck_assert_int_eq(strspn(str3, "01234"), s21_strspn(str3, "01234"));
}
END_TEST

START_TEST(test_s21_strcspn_7) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_8) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_9) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_10) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_11) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_12) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_13) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_14) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_15) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_16) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_17) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_18) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_19) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_20) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(test_s21_strcspn_21) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}

Suite* s21_strcspn_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strcspn_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strcspn_1);
    tcase_add_test(tc_core, test_s21_strcspn_2);
    tcase_add_test(tc_core, test_s21_strcspn_3);
    tcase_add_test(tc_core, test_s21_strcspn_4);
    tcase_add_test(tc_core, test_s21_strcspn_5);
    tcase_add_test(tc_core, test_s21_strcspn_6);
    tcase_add_test(tc_core, test_s21_strcspn_7);
    tcase_add_test(tc_core, test_s21_strcspn_8);
    tcase_add_test(tc_core, test_s21_strcspn_9);
    tcase_add_test(tc_core, test_s21_strcspn_10);
    tcase_add_test(tc_core, test_s21_strcspn_11);
    tcase_add_test(tc_core, test_s21_strcspn_12);
    tcase_add_test(tc_core, test_s21_strcspn_13);
    tcase_add_test(tc_core, test_s21_strcspn_14);
    tcase_add_test(tc_core, test_s21_strcspn_15);
    tcase_add_test(tc_core, test_s21_strcspn_16);
    tcase_add_test(tc_core, test_s21_strcspn_17);
    tcase_add_test(tc_core, test_s21_strcspn_18);
    tcase_add_test(tc_core, test_s21_strcspn_19);
    tcase_add_test(tc_core, test_s21_strcspn_20);
    tcase_add_test(tc_core, test_s21_strcspn_21);
    suite_add_tcase(s, tc_core);
    return s;
}