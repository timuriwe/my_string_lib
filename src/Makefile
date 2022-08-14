CC=gcc
FLAGS=-Wall -Werror -Wextra

all: test

clean: 
	rm *.o *.a *.css *.html *.gcno *.gcda *.gcov tests my_string_test.c

my_string.a: my_string.o my_sprintf.o
	ar rc my_string.a my_string.o my_sprintf.o

my_string.o: my_string.c
	$(CC) -std=c11 -c my_string.c
	
my_sprintf.o: my_sprintf.c
	$(CC) -std=c11 -c my_sprintf.c

my_sprintf_tests.o:
	$(CC) -c my_sprintf_tests.c

my_string_tests.o:
	$(CC) -c my_string_tests.c

sprintf_test: my_string.a my_sprintf_tests.o 
	$(CC) $(FLAGS) my_sprintf_tests.o my_string.a -o sprintf_tests -lcheck -fprofile-arcs -lrt -lsubunit -lm 
	./sprintf_tests

string_test: my_string.a my_string_tests.o 
	$(CC) $(FLAGS) my_string_tests.o my_string.a -o string_tests -lcheck -fprofile-arcs -lrt -lsubunit -lm
	./string_tests

gcov_report: my_string_test.o
	$(CC) -c -fprofile-arcs -ftest-coverage my_sprintf.c my_string.c
	$(CC) -Wall -fprofile-arcs my_string_test.o my_string.o my_sprintf.o -o tests -lcheck
	./tests
	gcov -f my_string.gcda
	gcov -f my_sprintf.gcda
	gcovr -r . --html --html-details -o coverage_report.html
	rm my_sprintf.o my_string.o
