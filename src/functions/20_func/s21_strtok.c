#include "../../headers/s21_string.h"
#include <stdio.h>

static char *old_string;

char *s21_strtok(char *s, const char *delim) {
    char *result;
    if (s == S21_NULL) {
        if (old_string == NULL)
            return NULL;
        s = old_string;
    }

    s += s21_strspn (s, delim);
//    printf("[DEBUG] str = %s\n", s);
    if (*s == '\0') {
        old_string = s;
        return S21_NULL;
    }
    result = s;
    s = s21_strpbrk (result, delim);
    if (s == S21_NULL) {
        old_string = s21_strchr(result, '\0');
        return result;
    } else {
        *s = '\0';
        old_string = s + 1;
    }
//    printf ("[DEBUG] result = %s\n", result - 1);
    return result - 1;
}