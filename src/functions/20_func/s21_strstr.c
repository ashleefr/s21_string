#include "../../headers/s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    char *first_temp_string, *second_temp_string;

    if (*needle == 0)
        return (char*) haystack;
    second_temp_string = (char*) needle;

    for ( ; *haystack != 0; haystack += 1) {
        if (*haystack != *second_temp_string)
            continue;

        first_temp_string = (char*) haystack;
        while (1) {
            if (*second_temp_string == 0)
                return (char*) haystack;
            if (*first_temp_string++ != *second_temp_string++)
                break;
        }
        second_temp_string = (char*) needle;
    }
    return S21_NULL;
}