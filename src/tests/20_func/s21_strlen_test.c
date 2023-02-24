#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strlen_1) {
    char src1[256] = "Hello, World! My name is Kostya\0";
    ck_assert_int_eq(s21_strlen(src1), strlen(src1));
}
END_TEST

START_TEST(test_s21_strlen_2) {
    char src1[256] = "Hello, World! My name is \0Kostya";
    ck_assert_int_eq(s21_strlen(src1), strlen(src1));
}
END_TEST

START_TEST(test_s21_strlen_3) {
    char src1[256] = "\0";
    ck_assert_int_eq(s21_strlen(src1), strlen(src1));
}
END_TEST

START_TEST(test_s21_strlen_4) {
  char src[] = "";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_5) {
  char src[] = "abosal";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_6) {
  char src[] = "987623456124678";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_7) {
  char src[] =
      "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_8) {
  char src[] = "abosal\0no_dal";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_9) {
  char src[] = "dai_mne_pen(321321)...123...123";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_10) {
  char src[] = "Floppy_disk";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_11) {
  char src[] = "Russky_kot_Shlepa";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_12) {
  char src[] = "kot Vasily";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_s21_strlen_13) {
  char src[] = "floppa";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

Suite* s21_strlen_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strlen_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strlen_1);
    tcase_add_test(tc_core, test_s21_strlen_2);
    tcase_add_test(tc_core, test_s21_strlen_3);
    tcase_add_test(tc_core, test_s21_strlen_4);
    tcase_add_test(tc_core, test_s21_strlen_5);
    tcase_add_test(tc_core, test_s21_strlen_6);
    tcase_add_test(tc_core, test_s21_strlen_7);
    tcase_add_test(tc_core, test_s21_strlen_8);
    tcase_add_test(tc_core, test_s21_strlen_9);
    tcase_add_test(tc_core, test_s21_strlen_10);
    tcase_add_test(tc_core, test_s21_strlen_11);
    tcase_add_test(tc_core, test_s21_strlen_12);
    tcase_add_test(tc_core, test_s21_strlen_13);
    suite_add_tcase(s, tc_core);
    return s;
}

