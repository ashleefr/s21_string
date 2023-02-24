#ifndef __SRC_HEADERS_S21_STRING_H__
#define __SRC_HEADERS_S21_STRING_H__

//// TYPEDEFS OF STR ////

typedef unsigned long int s21_size_t;

//// MACROS ////

#define S21_NULL 0

//// STRING.H FUNCTIONS ////

void *s21_memchr(const void *str, int c, s21_size_t n); /* Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str. */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n); /* Сравнивает первые n байтов str1 и str2. */
void *s21_memcpy(void *dest, const void *src, s21_size_t n); /* Копирует n символов из src в dest. */
void *s21_memmove(void *dest, const void *src, s21_size_t n); /* Еще одна функция для копирования n символов из src в dest. */
void *s21_memset(void *str, int c, s21_size_t n); /* Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str. */
char *s21_strcat(char *dest, const char *src); /* Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest. */
char *s21_strncat(char *dest, const char *src, s21_size_t n); /* Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов. */
char *s21_strchr(const char *str, int c); /* Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str. */
int s21_strcmp(const char *str1, const char *str2); /* Сравнивает строку, на которую указывает str1, со строкой, на которую указывает str2. */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n); /* Сравнивает не более первых n байтов str1 и str2. */
char *s21_strcpy(char *dest, const char *src); /* Копирует строку, на которую указывает src, в dest. */
char *s21_strncpy(char *dest, const char *src, s21_size_t n); /* Копирует до n символов из строки, на которую указывает src, в dest. */
s21_size_t s21_strcspn(const char *str1, const char *str2); /* Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2. */

/*WORK*/
char *s21_strerror(int errnum); /* Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие
 * массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив. */

s21_size_t s21_strlen(const char *str); /* Вычисляет длину строки str, не включая завершающий нулевой символ. */
char *s21_strpbrk(const char *str1, const char *str2); /* Находит первый символ в строке str1, который соответствует любому символу, указанному в str2. */
char *s21_strrchr(const char *str, int c); /* Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str. */
s21_size_t s21_strspn(const char *str1, const char *str2); /* Вычисляет длину начального сегмента str1, который полностью состоит из символов str2. */
char *s21_strstr(const char *haystack, const char *needle); /* Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack. */
char *s21_strtok(char *str, const char *delim); /* Разбивает строку str на ряд токенов, разделенных delim. */

//// VOID FUNCTIONS ////

// additional function
void trim_before_after(const char *src, const char *trim_chars, s21_size_t* count, s21_size_t* recount); /*Считает кол-во удаляемых символов до и после печатаемого блока */
/*DONE*/

// main functions
void *s21_to_upper(const char *str); //Переводит все буквы в верхний регистр*/
/*DONE*/
void *s21_to_lower(const char *str); /*Переводит все буквы в нижний регистр*/
/*DONE*/
void *s21_insert(const char *src, const char *str, s21_size_t start_index); /*Вставляет строку str в позицию start_index в строке src */
/*DONE*/
void *s21_trim(const char *src, const char *trim_chars); /*удаляем из строки src набор символов из строки trim_chars до первого печаемого символа слева и справа*/
/*DONE*/
//// SSCANF AND SPRINTF ////

int s21_sprintf(char *str, const char *format, ...); /*Отправляет форматированный вывод в строку, на которую указывает str. */
//int sscanf(const char *str, const char *format, ...);

#endif //  __SRC_HEADERS_S21_STRING_H__