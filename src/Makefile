CC=gcc
CFLAGS= -Wall -Werror -Wextra -c -g -std=c11
LDFLAGS := -lcheck $(shell pkg-config --cflags --libs check) -fprofile-arcs
GCOVFLAGS := --coverage
20_FUNC := functions/20_func/s21*
VOID := functions/void/*.c
20_FUNC_TESTS := tests/20_func/
VOID_TESTS := tests/void/
ADDEDSOURC := functions/20_func/s21_strlen.c
VOID_OBJECTS := $(VOID:.c=.o)
ADDEDOBJECTS := s21_strlen.o


VOID_O := $(VOID_C:.c=.o)
TEST := $(VOID_C:.c=)


all: clean 20_func_test

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
## gcovr
	rm -rf *.gcda *.gcno
## helping file in sscanf and printf
	rm -rf log.txt
## OBJ files
	rm -rf *.o

push: clean
	rm -rf *.o

sscanf: clean
	$(CC) $(20_FUNC) ./functions/sscanf/s21_sscanf.c -o work
	./work
	rm work

## for endless running program
sscanf_in_file: clean
	$(CC) $(20_FUNC) ./functions/sscanf/s21_sscanf.c -o work
	./work >> log.txt
	rm work

## for running with SegFault
sscanf_fsanitize: clean
	$(CC) $(20_FUNC) ./functions/sscanf/s21_sscanf.c -g -fsanitize=address -o work
	./work
	rm work

sprintf: clean
	$(CC) $(20_FUNC) ./functions/sprintf/*.c -o work
	./work
	rm work

## for endless running program
sprintf_in_file: clean
	$(CC) $(20_FUNC) ./functions/sprintf/sprintf_work.c -o work
	./work >> log.txt
	rm work