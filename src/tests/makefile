CC=gcc
CFLAGS= -Wall -Werror -Wextra -c -g -std=c11
LDFLAGS := -lcheck $(shell pkg-config --cflags --libs check) -fprofile-arcs
GCOVFLAGS := --coverage
20_FUNC := ../functions/20_func/s21*
VOID := ../functions/void/*.c
20_FUNC_TESTS := 20_func/
VOID_TESTS := void/
ADDEDSOURC := ../functions/20_func/s21_strlen.c
VOID_OBJECTS := $(VOID:.c=.o)
ADDEDOBJECTS := s21_strlen.o


VOID_O := $(VOID_C:.c=.o)
TEST := $(VOID_C:.c=)


all: clean test

20_func_test: clean
	$(CC) $(CFLAGS) $(20_FUNC) 
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(LDFLAGS) $(20_FUNC_TESTS)*.c
	$(CC) $(LDFLAGS) *.o -o $@
	./$@
	rm -rf $@


void_test: clean
	$(CC) $(CFLAGS) $(VOID) $(ADDEDSOURC)
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(LDFLAGS) $(VOID_TESTS)*.c
	$(CC) $(LDFLAGS) *.o -o $@
	./$@
	rm -rf $@

gcov_report: test
	gcovr --html-details report.html


clean:
	rm -rf 
	rm -rf *.gcda
	rm -rf *.gcno

push: clean
	rm -rf *.o