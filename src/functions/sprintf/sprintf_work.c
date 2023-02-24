#include "../../headers/s21_string.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int main(void) {
    char format[512] = "stroka = [%+.5g]";
    char str[512], str1[512];
    int w = 2, p = 3;
    double c = 45345.232323;
    s21_sprintf(str, format, c);
    sprintf(str1, format, c);
    printf("str = [%s]\nst1 = [%s]\n", str, str1);

    return 0;
}