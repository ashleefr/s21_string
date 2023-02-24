////  HEADER ////

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
//#include <string.h>
#include "../../headers/s21_string.h"
#define SPECIFIERS "cdieEfgGosuxXpn%"

typedef struct type_length_and_other {
    int short_type;
    int long_int_type;
    int long_double_type;
    int skip_word;
} helpers;

int s21_sscanf(char* buffer, char* format, ...);

void parse_length(char arg, helpers* flags_length);
void parse_specs(char* buffer, char arg, va_list factor, helpers* flags_length);

void scanf_char(char* buffer, va_list factor, helpers* flags_length);
void scanf_string(char* buffer, va_list factor, helpers* flags_length);
void scanf_pointer(char* buffer, va_list factor, helpers* flags_length);
void scanf_n(char* buffer, va_list factor, helpers* flags_length);

void scanf_integer(char* buffer, va_list factor, helpers* flags_length);
void scanf_unsigned_integer(char* buffer, va_list factor, helpers* flags_length);
void scanf_i_flag(char* buffer, va_list factor, helpers* flags_length);
void scanf_hexa_integer(char* buffer, va_list factor, helpers* flags_length);
void scanf_octa_integer(char* buffer, va_list factor, helpers* flags_length);

void scanf_double(char* buffer, va_list factor, helpers* flags_length);

long int str_to_hexa(char* buffer);
long int str_to_int(char* buffer);
long int str_to_octa(char* buffer);

long double str_to_double(char* buffer);

void move_arr(char* buf, int size);
void erase_spaces(char* buf);

////  REALIZATION  ////

int global_read_counter = 0;

void parse_length(char arg, helpers* flags_length) {
    switch (arg) {
        case 'h':
            flags_length->short_type = 1;
            break;
        case 'l':
            flags_length->long_int_type = 1;
            break;
        case 'L':
            flags_length->long_double_type = 1;
            break;
        default:
            break;
    }
}

void parse_specs(char* buffer, char arg, va_list factor, helpers* flags_length) {
    switch (arg) {
        case 'c':  // Символ
            scanf_char(buffer, factor, flags_length);
            break;
        case 'd':  // Знаковое десятичное целое число
            scanf_integer(buffer, factor, flags_length);
            break;
        case 'i':  // Знаковое целое число (может быть десятичным, восьмеричным или шестнадцатеричным)
            scanf_i_flag(buffer, factor, flags_length);
//            printf("scanf_integer DONE\n");
            break;
        case 'o':  // Беззнаковое восьмеричное число
            scanf_octa_integer(buffer, factor, flags_length);
            break;
        case 'u':  // Беззнаковое десятичное целое число
            scanf_unsigned_integer(buffer, factor, flags_length);
            break;
        case 'x':  // Беззнаковое шестнадцатеричное целое число (любые буквы)
            scanf_hexa_integer(buffer, factor, flags_length);
            break;
        case 'X':  // Беззнаковое шестнадцатеричное целое число (любые буквы)
            scanf_hexa_integer(buffer, factor, flags_length);
            break;
        case 's':
            scanf_string(buffer, factor, flags_length);
            break;
        case 'p':
            scanf_pointer(buffer, factor, flags_length);
            break;
        case 'n':
//            printf("[DEBUG] N ROUTE\n");
            scanf_n(buffer, factor, flags_length);
            break;
        default:
            if (s21_strchr("eEfgG", arg)) {
                scanf_double(buffer, factor, flags_length);
            }
            break;
    }
}

void scanf_char(char* buffer, va_list factor, helpers* flags_length) {
    if (flags_length->skip_word == 0)
        *(char*)va_arg(factor, void*) = buffer[0];
    flags_length->skip_word = 0;
    move_arr(buffer, 1);
    global_read_counter++;

//    printf("[DEBUG] result buffer: %s\n", buffer);
}

void scanf_string(char* buffer, va_list factor, helpers* flags_length) {
    erase_spaces(buffer);
    char sub_buffer[1000];
    int count = 0;
    if (flags_length->skip_word == 0) {
        while (buffer[count] != ' ' && buffer[count] != '\n' && buffer[count] != '\0') {
            sub_buffer[count] = buffer[count];
            count++;
        }
        sub_buffer[count] = '\0';
//        printf("[DEBUG] string: [%s]\n", sub_buffer);
        s21_memmove((char*) va_arg(factor, void*), sub_buffer, count + 1);
    }
    flags_length->skip_word = 0;
    move_arr(buffer, count);
    global_read_counter += count;
}

void scanf_pointer(char* buffer, va_list factor, helpers* flags_length) {

}

void scanf_n(char* buffer, va_list factor, helpers* flags_length) {
//    printf("[DEBUG] global_read_counter = %d\n", global_read_counter);
    *(int*) va_arg(factor, void*) = global_read_counter;
}

void scanf_integer(char* buffer, va_list factor, helpers* flags_length) {
    if (flags_length->skip_word == 0) {
        if (flags_length->short_type) {
            *(short int*)va_arg(factor, void*) = (short int) str_to_int(buffer);
        } else if (flags_length->long_int_type) {
            *(long int*)va_arg(factor, void*) = (long int) str_to_int(buffer);
        } else {
            *(int*)va_arg(factor, void*) =(int) str_to_int(buffer);
        }
    } else {
        str_to_int(buffer);
        flags_length->skip_word = 0;
    }
//    printf("[DEBUG] result buffer: %s\n", buffer);
}

void scanf_unsigned_integer(char* buffer, va_list factor, helpers* flags_length) {
    if (flags_length->skip_word == 0) {
        if (flags_length->short_type) {
            *(unsigned short int *)va_arg(factor, void*) = (unsigned short int) str_to_int(buffer);
        } else if (flags_length->long_int_type) {
            *(unsigned long *)va_arg(factor, void*) = (unsigned long) str_to_int(buffer);
        } else {
            unsigned int check = str_to_int(buffer);
//            printf("[DEBUG] Unsigned int = %u\n", check);
            *(unsigned int *)va_arg(factor, void*) = check;
        }
    } else {
        str_to_int(buffer);
        flags_length->skip_word = 0;
    }
}

void scanf_i_flag(char* buffer, va_list factor, helpers* flags_length) {
    erase_spaces(buffer);
    if (buffer[0] == '0') {
        buffer[1] >= '0' && buffer[1] <= '9' ? scanf_octa_integer(buffer, factor, flags_length) : 0;
        if (buffer[1] == 'x' || buffer[1] == 'X') {
            move_arr(buffer, 2);
            global_read_counter += 2;
//            printf("[DEBUG] buffer_i = [%s]\n", buffer);
            scanf_hexa_integer(buffer, factor, flags_length);
        }
    } else {
        scanf_integer(buffer, factor, flags_length);
    }
} // WORKING

void scanf_hexa_integer(char* buffer, va_list factor, helpers* flags_length) {
    erase_spaces(buffer);
    if (buffer[0] == '0' && (buffer[1] == 'x' || buffer[1] == 'X')) {
        move_arr(buffer, 2);
        global_read_counter += 2;
    }
    if (flags_length->skip_word == 0) {
        if (flags_length->short_type) {
            *(short int*)va_arg(factor, void*) = (short int) str_to_hexa(buffer);
        } else if (flags_length->long_int_type) {
            *(long int*)va_arg(factor, void*) = (long int) str_to_hexa(buffer);
        } else {
            *(int*)va_arg(factor, void*) =(int) str_to_hexa(buffer);
        }
    } else {
        str_to_hexa(buffer);
        flags_length->skip_word = 0;
    }
}

void scanf_octa_integer(char* buffer, va_list factor, helpers* flags_length) {
    if (flags_length->skip_word == 0) {
        if (flags_length->short_type) {
            *(short int*)va_arg(factor, void*) = (short int) str_to_octa(buffer);
        } else if (flags_length->long_int_type) {
            *(long int*)va_arg(factor, void*) = (long int) str_to_octa(buffer);
        } else {
            *(int*)va_arg(factor, void*) =(int) str_to_octa(buffer);
        }
    } else {
        str_to_octa(buffer);
        flags_length->skip_word = 0;
    }
}

void scanf_double(char* buffer, va_list factor, helpers* flags_length) {
    if (flags_length->skip_word == 0) {
        if (flags_length->long_double_type) {
            *(long double*)va_arg(factor, void*) = (long double) str_to_double(buffer);
        } else {
            *(double*)va_arg(factor, void*) =(double) str_to_double(buffer);
        }
    } else {
        str_to_double(buffer);
        flags_length->skip_word = 0;
    }
}

long int str_to_int(char* buffer) {
    erase_spaces(buffer);
    int i = 0; int buf; int result = 0;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        buf = (int) (buffer[i] - '0');
        result = result * 10 + buf;
        i++;
    }

//    printf("[DEBUG] size = %d, buffer = [%s]\n", i, buffer);

    move_arr(buffer, i);
    global_read_counter += i;

//    printf("[DEBUG] After buffer = [%s]\n", buffer);
//    printf("[DEBUG] result = %d\n", result);

    return result;
}

long int str_to_octa(char* buffer) {
    erase_spaces(buffer);
    int i = 0; int buf; int result = 0;
    while (buffer[i] >= '0' && buffer[i] <= '7') {
        buf = (int) (buffer[i] - '0');
        result = result * 8 + buf;
        i++;
    }

//    printf("[DEBUG] size = %d, buffer = [%s]\n", i, buffer);

    move_arr(buffer, i);
    global_read_counter += i;

//    printf("[DEBUG] After buffer = [%s]\n", buffer);
//    printf("[DEBUG] result = %d\n", result);

    return result;
}

long int str_to_hexa(char* buffer) {
    erase_spaces(buffer);
    int i = 0; int buf; int result = 0;
    while ((buffer[i] >= '0' && buffer[i] <= '9') || (buffer[i] >= 'a' && buffer[i] <= 'f') || (buffer[i] >= 'A' && buffer[i] <= 'F')) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            buf = (int) (buffer[i] - '0');
            result = result * 16 + buf;
            i++;
        } else {
            buf = (buffer[i] >= 'a' && buffer[i] <= 'f') ? (int) (buffer[i] - 87) : (buffer[i] - 55);
            result = result * 16 + buf;
            i++;
        }
    }

//    printf("[DEBUG] size = %d, buffer = [%s]\n", i, buffer);

    move_arr(buffer, i);
    global_read_counter += i;

//    printf("[DEBUG] After buffer = [%s]\n", buffer);
//    printf("[DEBUG] result = %d\n", result);

    return result;
}

long double str_to_double(char* buffer) {
    erase_spaces(buffer);
    long double result = 0;
    int sub_result = 0;
    int count = 0; int dot_flag = 0; int ten_power = 10; int power = 0;
//    printf("[DEBUG] buffer = [%s]\n", buffer);

    char* useless_buffer = calloc(s21_strlen(buffer), sizeof(buffer));
    s21_strcpy(useless_buffer, buffer);
    s21_strtok(useless_buffer, " ");
//    printf("[DEBUG] useless buffer = [%s]\n", useless_buffer);
    if (s21_strpbrk(useless_buffer, "eE")) {
//        printf("[DEBUG] ROUTE WITH E\n");
        while (useless_buffer[count] != 'e' && useless_buffer[count] != 'E') {
//            printf("[DEBUG] useless_buffer[%i] = %c\n", count, useless_buffer[count]);
            if (useless_buffer[count] == '.') {
                dot_flag = 1;
                count++;
                continue;
            }
            sub_result = (int) (useless_buffer[count] - '0');
//            printf("[DEBUG] sub_result = %d\n", sub_result);
            result = dot_flag == 0 ? result * 10 + sub_result : result + (long double) sub_result / (long double) ten_power;
//            printf("[DEBUG] result = %Lf\n", result);

            dot_flag ? ten_power = ten_power * 10 : 0;

            count++;
        }
        count++;
        while (useless_buffer[count] >= '0' && useless_buffer[count] <= '9') {
            sub_result = (int) (useless_buffer[count] - '0');
//            printf("[DEBUG] sub_result_after_exp = %d\n", sub_result);
            power = power * 10 + sub_result;

            count++;
        }
//        printf("[DEBUG] power = %d\n", power);
        for (int i = 0; i < power; i++)
            result *= 10;
//        printf("[DEBUG] result_power = %Lf\n", result);
    } else {
//        printf("[DEBUG] ROUTE WITHOUT E\n");
        while (useless_buffer[count] >= '0' && useless_buffer[count] <= '9' || useless_buffer[count] == '.') {
            if (useless_buffer[count] == '.') {
                dot_flag = 1;
                count++;
                continue;
            }
            sub_result = (int) (useless_buffer[count] - '0');
//            printf("[DEBUG] sub_result = %d\n", sub_result);
            result = dot_flag == 0 ? result * 10 + sub_result : result + (long double) sub_result / (long double) ten_power;
            dot_flag ? ten_power = ten_power * 10 : 0;

            count++;
        }
    }

    move_arr(buffer, s21_strlen(useless_buffer));
    global_read_counter += s21_strlen(useless_buffer);
//    printf("[DEBUG] result = %Lf\n", result);
    return result;
}

void move_arr(char* buf, int size) {
//    printf("strlen in move_arr\n");
    s21_size_t full_size = s21_strlen(buf);
//    printf("OK strlen in move_arr\n");
    for (s21_size_t i = 0; i <= (full_size - size); i++)
        buf[i] = buf[i + size];
    buf[full_size - size] = '\0';
}

void erase_spaces(char* buf) {
    while (buf[0] == ' ') {
        move_arr(buf, 1);
        global_read_counter++;
    }
//    printf("[DEBUG] erase_spaces buffer = [%s]\n", buf);
}

int s21_sscanf(char* buffer, char* format, ...) {
    global_read_counter = 0;
    helpers flags_length = {0};
    int i = 0;
//    printf("strlen in clone_buffer\n");
    char* clone_buffer = calloc(s21_strlen(buffer) + 1, sizeof(char*));
//    printf("OK strlen in clone_buffer\n");
    s21_strcpy(clone_buffer, buffer);
    clone_buffer[s21_strlen(clone_buffer)] = '\0';
//    printf("[DEBUG] s21_sscanf work_buffer = [%s]\n", clone_buffer);

    va_list factor;
    va_start(factor, format);

    while (i < s21_strlen(format)) {
//        printf("OK strlen in cycle with i = %d\n", i);
        if (format[i] == '%') {
            i++;
            if (format[i] == '*') {
                flags_length.skip_word = 1;
                i++;
            }
            if (s21_strchr("hlL", format[i])) {
                parse_length(format[i], &flags_length);
                i++;
            }
            if (s21_strchr(SPECIFIERS, format[i])) {
                parse_specs(clone_buffer, format[i], factor, &flags_length);
            }
        }
        i++;
    }
    free(clone_buffer);
    va_end(factor);
    global_read_counter = 0;
    return 1;
}

int main(void) {
    ////  d ld hd c  ////
    long int a = 0; short int b = 0; int c = 0;
    long int need_a = 0; short int need_b = 0; int need_c = 0;
    char d = ' '; char ff = ' ';
    char need_d = ' '; char need_f = ' ';
    s21_sscanf("5 2 3fG ", "%*ld%hd%d%*c%c", &b, &c, &d, &ff);
    sscanf("5 2 3fG ", "%*ld%hd%d%*c%c", &need_b, &need_c, &need_d, &need_f);
    printf("  [TEST d ld hd] Our: %ld %hd %d\tNeed: %ld %hd %d\n", a, b, c, need_a, need_b, need_c);
    printf("  [TEST c] Our: [%c%c]\tNeed: [%c%c]\n", d, ff, need_d, need_f);

    ////  i o u x X  ////
    int i = 0; int check_i = 0;
    int o = 0; int check_o = 0;
    unsigned int u = 0; unsigned int check_u = 0;
    int x = 0; int check_x = 0;
    int x_x = 0; int check_x_x = 0;
    char* check_integer_buffer = "0x13 15 13 0xd 0xD";
    char* check_integer_format = "%i %o %u %x %X";
    s21_sscanf(check_integer_buffer, check_integer_format, &i, &o, &u, &x, &x_x);
    sscanf(check_integer_buffer, check_integer_format, &check_i, &check_o, &check_u, &check_x, &check_x_x);
    printf("  [TEST i o u x X] Our: %d %d %d %d %d\tNeed: %d %d %d %d %d\n", i, o, u, x, x_x, check_i, check_o, check_u, check_x, check_x_x);

    ////  e E f g G  ////
    double e = 0.0f; double check_e = 0.0f;
    double e_e = 0.0f; double check_e_e = 0.0f;
    double f = 0.0f; double check_f = 0.0f;
    double g = 0.0f; double check_g = 0.0f;
    double g_g = 0.0f; double check_g_g = 0.0f;
    char* check_double_buffer = "0.13e2 0.13E2 13.0 13.0 13.0";
    char* check_double_format = "%le %lE %lf %lg %lG";
    s21_sscanf(check_double_buffer, check_double_format, &e, &e_e, &f, &g, &g_g);
    sscanf(check_double_buffer, check_double_format, &check_e, &check_e_e, &check_f, &check_g, &check_g_g);
    printf("  [TEST e E f g G] Our: %.2f %.2f %.2f %.2f %.2f\tNeed: %.2f %.2f %.2f %.2f %.2f\n", e, e_e, f, g, g_g, check_e, check_e_e, check_f, check_g, check_g_g);

    ////  s  ////
    char s[100], s2[100];
    char check_s[100], check_s2[100];
    char* check_string_buffer = "Hellou YOBANAT  ";
    char* check_string_format = "%s %s";

    s21_sscanf(check_string_buffer, check_string_format, s, s2);
    sscanf(check_string_buffer, check_string_format, check_s, check_s2);
    printf("  [TEST s] Our: [%s] [%s]\tNeed: [%s] [%s]\n", s, s2, check_s, check_s2);

    ////  p  ////
//    void *p, *check_p;
//    printf("[DEBUG] WTF: [%p] [%d]", s, *((int*) s));
//    char* check_pointer_buffer = s;
//    char* check_pointer_format = "%p";
////    s21_sscanf(check_pointer_buffer, check_pointer_format, &p);
//    sscanf(check_pointer_buffer, check_pointer_format, &check_p);
//    sscanf(check_pointer_buffer, check_pointer_format, &p);
//    printf("  [TEST p] Our: [%p] [%d]\tNeed: [%p] [%d]\n", p, *((int*) p), check_p, *((int*) check_p));

    ////  n  ////
    int n, check_n;
    int a1, a2, a3, b1, b2, b3;
    char* check_n_buffer = "12 34 56";
    char* check_n_format = "%d %d %d %n";
    s21_sscanf(check_n_buffer, check_n_format, &a1, &a2, &a3, &n);
    sscanf(check_n_buffer, check_n_format, &b1, &b2, &b3, &check_n);
    printf("  [TEST n] Our: %d\tNeed:%d\n", n, check_n);
    return 0;
}
