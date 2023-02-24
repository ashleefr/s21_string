#include "../../headers/s21_string.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#define SPECIFIERS "cdieEfgGosuxXpn"
#define SHORT_INT 32767
#define INT 2147483647
#define LONG_INT 9223372036854775807

typedef struct parametrs {
    int width;
    int width_star;
    int precision_star;
    int precision;
    int precision_check;
    int length_h;
    int length_l;
    int length_L;
    int flag_minus;
    int flag_plus;
    int flag_null;
    int flag_space;
    int flag_lattice;
    int check_point;
} params;

int parse_variables( char* work_simbol, int *shift, params *variables);
void specifiers_cases(char *work_simbol, char *str, int *size_str, va_list factor, params *variables);
void insert_idu(char *work_simbol, char *str, int *size_str, va_list factor, params *variables);
void reader_for_int(char* buffer, int *size_buffer, int number);
void insert_cs(char *work_simbol, char *str, int *size_str, va_list factor, params *variables);
void insert_eEfgG(char *work_simbol, char *str, int *size_str, va_list factor, params *variables);
void reader_for_double(char* buffer, int *size_buffer,  long double number, params *variables, char* work_simbol);
void reader_for_science(char* buffer, int *size_buffer, long double number, params *variables, char *work_simbol);

int s21_sprintf(char *str, const char *format, ... ) {
    va_list factor;
    int size_str = 0;
    char *work_simbol = S21_NULL; 
    va_start(factor, format);
    int check_simbol_for_variables = 0;
    for (work_simbol = (char*) format; *work_simbol; work_simbol++) {
        if (*work_simbol != '%') {
            str[size_str] = *work_simbol;
            size_str +=1;
            continue;
        } else {
            //разбор параметра
            params variables = {0};
            int shift = 0;
            check_simbol_for_variables = parse_variables(work_simbol, &shift, &variables);
            work_simbol += shift;
            // printf("DEBUG check_simbol_for_variables = %i",check_simbol_for_variables);
            if (!check_simbol_for_variables) {
                 //функция кейсов на спецификаторы
                specifiers_cases(work_simbol, str, &size_str, factor, &variables);
            } else {
                str[size_str] = *work_simbol;
                size_str +=1;
            }
        }

    }
    str[size_str] = *work_simbol;
}

 //функция кейсов на спецификаторы
void specifiers_cases(char *work_simbol, char *str, int *size_str, va_list factor, params *variables) {
    switch (*work_simbol) 
    {
        case 'd': ;
        case 'i': ;
        case 'u': insert_idu(work_simbol, str, size_str, factor, variables); break;
        case 'e': ;
        case 'E': ;
        case 'f': ;
        case 'g': ;
        case 'G': insert_eEfgG(work_simbol, str, size_str,factor,variables);break;
        // case 'o': insert_o(); break;
        // case 'x': ;
        // case 'X': insert_xX(); break;
        // case 'p': insert_p(); break;
        // case 'n': insert_n(); break;
        case '%': str[*size_str] = *work_simbol; *size_str += 1; break;
        case 'c': ;
        case 's': insert_cs(work_simbol, str, size_str, factor, variables); break;
    }
}
//обработка символов
void insert_cs(char *work_simbol, char *str, int *size_str, va_list factor, params *variables){
       if (variables->width_star) {
       variables->width = va_arg(factor, int);
    }
    if (variables->precision_star) {
        variables->precision = va_arg(factor, int);
    }
    char buffer[512];
    if (*work_simbol == 's') {
        char* buffer_string = va_arg(factor, char*);
        if (variables->precision_check) {
            for (int i = 0; i < variables->precision; i ++ )
            buffer[i] = buffer_string[i];
        buffer[variables->precision] = '\0';
        } else {
            for (int i = 0; i < s21_strlen(buffer_string); i ++ )
                buffer[i] = buffer_string[i];
            buffer[s21_strlen(buffer_string)] = '\0';
        }

        if (variables->width > s21_strlen(buffer)) {
        int diff = variables->width - s21_strlen(buffer);
        if (!variables->flag_minus) {
            for (int i = s21_strlen(buffer); i >= 0 ; i--)
                buffer[i + diff] = buffer[i];
            for (int i = 0; i < diff; i ++)
                buffer[i] =  ' ';
        } else {
            for (int i = s21_strlen(buffer); i < variables->width ; i ++)
                buffer[i] = ' ';
        }
        buffer[variables->width] = '\0';
        }
    } else {
        char buffer_char = va_arg(factor, int);
        buffer[0] = buffer_char;
        if (!variables->flag_minus) {
                buffer[variables->width - 1] = buffer[0];
                buffer[variables->width] = '\0';
            for (int i = 0; i < variables->width - 1; i ++)
                buffer[i] =  ' ';
        } else {
            for (int i = 1; i < variables->width ; i ++)
                buffer[i] = ' ';
        }
    }
    for (int i = 0; i < s21_strlen(buffer); i ++) {
        str[*size_str] = buffer[i];
        *size_str += 1;
    }
}
//обработка цифр с плавающей запятой
void insert_eEfgG(char *work_simbol, char *str, int *size_str, va_list factor, params *variables) {
    if (variables->width_star) {
       variables->width = va_arg(factor, int);
    }
    if (variables->precision_star) {
        variables->precision = va_arg(factor, int);
    }
    char buffer_dec[512], buffer_science[512];
    int size_buffer_dec = 0, size_buffer_science = 0;
    long double number;
    if (variables->length_L) {
        number = va_arg(factor, long double);
    } else {
        number = va_arg(factor, double);
    }
    reader_for_double(buffer_dec, &size_buffer_dec, number, variables, work_simbol);
    printf("DEBUG buffer_dec = [%s], size_buffer_dec = %i, number = %Lf\n", buffer_dec, size_buffer_dec, number);
    reader_for_science(buffer_science, &size_buffer_science, number, variables, work_simbol);
    printf("DEBUG buffer_science = [%s], size_buffer_science = %i\n", buffer_science, size_buffer_science);
    if (!variables->flag_plus && buffer[0] == '+') buffer[0] = ' ';
    char *buffer;
    int size_buffer;
    size_buffer = (size_buffer_dec <= size_buffer_science - 4) ? size_buffer_dec : size_buffer_science;
    // printf("DEBUG %i buffer = [%s] size_buffer = %d\n", variables->precision,buffer, size_buffer);
    if (size_buffer<= variables->precision) {
        int diff = variables->precision - size_buffer;
        buffer[0] = (buffer[0] = ' ' && diff == 0)? '0' : 0;
        for (int i = size_buffer; i > 0 ; i--)
            buffer[i + diff] = buffer[i];
        for (int i = 1; i <= diff; i ++)
            buffer[i] = '0';
            size_buffer = variables->precision;
    }
        if ((variables->flag_space) || (!variables->flag_space && buffer[0] == ' '))
    {
        for (int i = 0; i < s21_strlen(buffer) - 1; i++) {
            buffer[i] = buffer[i + 1];
        }
            
        buffer[s21_strlen(buffer)- 1] = '\0';
        size_buffer = s21_strlen(buffer); 
        printf("DEBUG buffer = [%s] size_buffer = %d\n",buffer, size_buffer);
    }
    if (variables->width > s21_strlen(buffer)) {
        int diff = variables->width - s21_strlen(buffer);
        if (!variables->flag_minus) {
            for (int i = s21_strlen(buffer); i >= 0 ; i--)
                buffer[i + diff] = buffer[i];
            for (int i = 0; i < diff; i ++)
                buffer[i] =  (variables->flag_null) ? '0' :' ';
        } else {
            for (int i = size_buffer; i < size_buffer + diff ; i ++)
                buffer[i] = ' ';
        }
        buffer[size_buffer + diff] = '\0';
        size_buffer = s21_strlen(buffer);
    }
    for (int i = 0; i < s21_strlen(buffer); i ++) {
        str[*size_str] = buffer[i];
        *size_str += 1;
    }

}

void reader_for_science(char* buffer, int *size_buffer, long double number, params *variables,char *work_simbol) {
    int check_minus = (number >= 0) ? 1 : -1;
    number = fabs(number);
    int degree_counter = 0;
    while (number >= 10.0) {
        number /= 10;
        degree_counter ++;
    }
    while (number < 0) {
        number *= 10;
        degree_counter --;
    }
    number *= check_minus;

    // printf("number = %Lf\n",number);
    reader_for_double(buffer, size_buffer, number,variables,work_simbol);
    *size_buffer += 4;
    buffer[*size_buffer - 4] = (*work_simbol == 'e' || *work_simbol == 'g') ? 'e' : 'E';
    buffer[*size_buffer - 3] = (degree_counter >= 0) ? '+' : '-';
    degree_counter = (int) fabs(degree_counter);
    buffer[*size_buffer - 1] = '0' + degree_counter % 10; degree_counter /= 10;
    buffer[*size_buffer - 2] = '0' + degree_counter % 10;
    buffer[*size_buffer] = '\0';
}

void reader_for_double(char* buffer, int *size_buffer, long double number, params *variables, char* work_simbol) {
    buffer[0] = (number >= 0) ? '+' : '-';
    number =  fabs((double) number);
    if (variables->precision_check && *work_simbol != 'g') {
        number = round(number * pow(10, variables->precision)) / pow(10, variables->precision);
    } else {
        number = round(number * pow(10, 6)) / pow(10, 6);
    }
    long double number_after_point = (long double) fmod((double) number, 1);
    // printf("DEBUG number = %Lf number_after_point = %Lf\n",number, number_after_point);
    long int size_after_point = 0 ,buf_int;
    printf("DEBUG number = %Lf number_after_point = %Lf\n",number, number_after_point);
    if (variables->precision_check) {
        for (int i = 0; i < variables->precision; i ++) {
            number_after_point *= 10;
        }      
        size_after_point = (variables->precision == 0) ? -1 : variables->precision;
    } else {
        if (*work_simbol != 'g') {    
            for (int i = 0; i < 6; i ++) {
                number_after_point *= 10;
            }
            size_after_point = 6;   
         } else {
            int buf = ((int) number_after_point);
            for (int i = 0; i < 5; i ++) {
                number_after_point *= 10;
            }
            size_after_point = 5;
        }
    }
    buf_int = (int) number;
    // printf("DEBUG buf_int = %i\n",buf_int);
    while (buf_int / 10 > 0) {
        *size_buffer += 1;
        buf_int /= 10;
    } 
    *size_buffer = (variables->precision == 0 && variables->precision_check)? *size_buffer + 2  : *size_buffer + 3 + size_after_point;
    // printf("DEBUG size_buffer = %i\n",*size_buffer);
    buf_int = (int) round((double)number_after_point);
    // printf("DEBUG number_after_point = %Lf buf_int = %i\n",number_after_point,buf_int);
    for (int i = 1; i <= size_after_point; i ++) {
        buffer[*size_buffer - i] = '0' + buf_int % 10;
        buf_int /= 10;
    }
    buffer[*size_buffer - size_after_point - 1] = (variables->precision == 0 && variables->precision_check) ? '\0' : '.';
    number = (variables->precision == 0 && variables->precision_check) ? number + number_after_point : number;
    buf_int  = (int)number;
    // printf("DEBUG buf_int = %d number = %Lf\n",buf_int,number);
    for (int i = size_after_point + 2; i < *size_buffer ; i ++) {
        buffer[*size_buffer - i] = '0' + buf_int % 10;
        buf_int /= 10;
    }
    buffer[*size_buffer] = '\0';
    //         printf("buffer = %s\n",buffer);
    // for (int i = 0; i < *size_buffer; i ++)
    //     printf("%c",buffer[i]);
    // printf("|\n");
}
//функция для обработки целых чисел
void insert_idu(char *work_simbol, char *str, int *size_str, va_list factor, params *variables) {
    if (variables->width_star) {
       variables->width = va_arg(factor, int);
    }
    if (variables->precision_star) {
        variables->precision = va_arg(factor, int);
    }
    char buffer[512];
    int size_buffer = 1;
    long int number;
    // дописать ограничения по размеру типа
    if (variables->length_h) {
        number = va_arg(factor, int);
        number = (short int)number;
    } else if (variables->length_l) {
        number = va_arg(factor, long int);
    } else {
        number = va_arg(factor, int);
    }
    reader_for_int(buffer, &size_buffer, number);
    if (*work_simbol == 'u') buffer[0] = ' ';
    if (!variables->flag_plus && buffer[0] == '+') buffer[0] = ' ';
    printf("DEBUG %i buffer = [%s] size_buffer = %d\n", variables->precision,buffer, size_buffer);
    if (size_buffer <= variables->precision) {
        int diff = variables->precision - size_buffer;
        buffer[0] = (buffer[0] = ' ' && diff == 0)? '0' : 0;
        for (int i = size_buffer; i > 0 ; i--)
            buffer[i + diff] = buffer[i];
        for (int i = 1; i <= diff; i ++)
            buffer[i] = '0';
            size_buffer = variables->precision;
    }

        if ((variables->flag_space && *work_simbol == 'u') || (!variables->flag_space && buffer[0] == ' '))
    {
        for (int i = 0; i < s21_strlen(buffer) - 1; i++) {
            buffer[i] = buffer[i + 1];
        }
            
        buffer[s21_strlen(buffer)- 1] = '\0';
        size_buffer = s21_strlen(buffer); 
        printf("DEBUG buffer = [%s] size_buffer = %d\n",buffer, size_buffer);
    }
    if (variables->width > s21_strlen(buffer)) {
        int diff = variables->width - s21_strlen(buffer);
        if (!variables->flag_minus) {
            for (int i = s21_strlen(buffer); i >= 0 ; i--)
                buffer[i + diff] = buffer[i];
            for (int i = 0; i < diff; i ++)
                buffer[i] =  (variables->flag_null) ? '0' :' ';
        } else {
            for (int i = size_buffer; i < size_buffer + diff ; i ++)
                buffer[i] = ' ';
        }
        buffer[size_buffer + diff] = '\0';
        size_buffer = s21_strlen(buffer);
    }
    for (int i = 0; i < s21_strlen(buffer); i ++) {
        str[*size_str] = buffer[i];
        *size_str += 1;
    }
}

void reader_for_int(char* buffer, int *size_buffer, int number) {
    buffer[0] = (number >= 0) ? '+' : '-';
    number = fabs(number);
    int buf_num = number;
    while (buf_num / 10 > 0) {
        *size_buffer += 1;
        buf_num /= 10;
    }
    *size_buffer += 1;
    // printf("DEBUG size_buffer = %d\n",*size_buffer);
    buffer[*size_buffer] = '\0';
    for (int i = 1; i <= *size_buffer - 1; i ++) {
        buffer[*size_buffer - i] = '0' + number % 10;
        number /= 10;
    }
}


// Определяет какие заданы параметры или их отсутсвие после символа %
int parse_variables( char* work_simbol, int *shift, params *variables) {
    int check_simbol_for_variables = 0;
    *shift +=1;
    while (!check_simbol_for_variables) {
        work_simbol ++;
        if (*work_simbol == '-') {
            variables->flag_minus = 1;
        } else if (*work_simbol == '+') {
            variables->flag_plus = 1;
        } else if (*work_simbol == ' ') {
            variables->flag_space = 1;
        } else if (*work_simbol == '#') {
            variables->flag_lattice = 1;
        } else if (*work_simbol >= '0' && *work_simbol <= '9') {
            if (!variables->width && !variables->check_point && *work_simbol == '0') {
                variables->flag_null = 1;
            } else {
                if (!variables->check_point) {
                  variables->width = variables->width * 10 + *work_simbol - '0';  
                } else {
                  variables->precision = variables->precision * 10 + *work_simbol - '0';
                  variables->precision_check = 1;  
                }
            }
        } else if (*work_simbol == '*') {
            if (!variables->check_point) {
                variables->width_star = 1;
            } else {
                variables->precision_star = 1;
            }
        } else if (*work_simbol == '.') {
            variables->check_point = 1;
        } else if (*work_simbol == 'h') {
            variables->length_h = 1;
        } else if (*work_simbol == 'l') {
            variables->length_l = 1;
        } else if (*work_simbol == 'L') {
            variables->length_L = 1;
        } else if (*work_simbol == '%' ||
         s21_strchr(SPECIFIERS, (int) *work_simbol)) {
            break;
        }
        else {
            check_simbol_for_variables = 1;
        }
        *shift += 1;
    }
    return check_simbol_for_variables;
}

