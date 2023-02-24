#include "../../headers/s21_string_tests.h"

START_TEST(test_s21_strtok_1) {
    char str4_1[] = "/testing/with/original/string.h/";
    char str4_2[] = "/testing/with/original/string.h/";
    char del4[3] = "/";
    char *nstr_1, *nstr_2;
    nstr_1 = strtok(str4_1, del4);
    nstr_2 = s21_strtok(str4_2, del4);
    while (nstr_1 != S21_NULL) {
        ck_assert_pstr_eq(nstr_1, nstr_2);
        nstr_1 = strtok(S21_NULL, del4);
        nstr_2 = s21_strtok(S21_NULL, del4);
    }
}
END_TEST

START_TEST(test_s21_strtok_2) {
    char str4_1[] = ". . testing with original string.h";
    char str4_2[] = ". . testing with original string.h";
    char del4[3] = ". ";
    char *nstr_1, *nstr_2;
    nstr_1 = strtok(str4_1, del4);
    nstr_2 = s21_strtok(str4_2, del4);
    while (nstr_1 != S21_NULL) {
        ck_assert_pstr_eq(nstr_1, nstr_2);
        nstr_1 = strtok(S21_NULL, del4);
        nstr_2 = s21_strtok(S21_NULL, del4);
    }
}
END_TEST

START_TEST(test_s21_strtok_3) {
    char str4_1[] = "testing with original string.h";
    char str4_2[] = "testing with original string.h";
    char del4[3] = ". ";
    char *nstr_1, *nstr_2;
    nstr_1 = strtok(str4_1, del4);
    nstr_2 = s21_strtok(str4_2, del4);
    while (nstr_1 != S21_NULL) {
        ck_assert_pstr_eq(nstr_1, nstr_2);
        nstr_1 = strtok(S21_NULL, del4);
        nstr_2 = s21_strtok(S21_NULL, del4);
    }
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
  char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_8) {
  char str1[] = "++++++++";
  char str2[] = "++++++++";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(test_s21_strtok_9) {
  char str1[] = "Aboba_Floppa_Roba";
  char str2[] = "Aboba_Floppa_Roba";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  int i = 5;
  while (i) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    i--;
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_10) {
  char str1[] = "Roba++++Kepa++A++++B__V";
  char str2[] = "Roba++++Kepa++A++++B__V";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_11) {
  char str1[] = "Aboba__+Floppa_  Roba";
  char str2[] = "Aboba__+Floppa_  Roba";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_12) {
  char str1[] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_13) {
  char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_14) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_15) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

Suite* s21_strtok_test(void) {
    Suite* s;
    TCase* tc_core;
    s = suite_create("s21_strtok_test");
    tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_s21_strtok_1);
    tcase_add_test(tc_core, test_s21_strtok_2);
    tcase_add_test(tc_core, test_s21_strtok_3);
    tcase_add_test(tc_core, test_s21_strtok_4);
    tcase_add_test(tc_core, test_s21_strtok_5);
    tcase_add_test(tc_core, test_s21_strtok_6);
    tcase_add_test(tc_core, test_s21_strtok_7);
    tcase_add_test(tc_core, test_s21_strtok_8);
    tcase_add_test(tc_core, test_s21_strtok_9);
    tcase_add_test(tc_core, test_s21_strtok_10);
    tcase_add_test(tc_core, test_s21_strtok_11);
    tcase_add_test(tc_core, test_s21_strtok_12);
    tcase_add_test(tc_core, test_s21_strtok_13);
    tcase_add_test(tc_core, test_s21_strtok_14);
    tcase_add_test(tc_core, test_s21_strtok_15);
    suite_add_tcase(s, tc_core);
    return s;
}