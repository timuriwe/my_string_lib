CC=gcc
FLAGS=-Wall -Werror -Wextra

all: string_report sprintf_report

clean: 
	rm -f *.o *.a *.css *.html *.gcno *.gcda *.gcov tests string_tests sprintf_tests

my_string.a: my_string.o my_sprintf.o
	ar rc libmy_string.a my_string.o my_sprintf.o

my_string.o: my_string.c
	$(CC) $(FLAGS) -std=c11 -c my_string.c
	
my_sprintf.o: my_sprintf.c
	$(CC) $(FLAGS) -std=c11 -c my_sprintf.c

my_sprintf_tests.o:
	$(CC) -c my_sprintf_tests.c

my_string_tests.o:
	$(CC) -c my_string_tests.c

sprintf_test: my_string.a my_sprintf_tests.o 
	$(CC) my_sprintf_tests.o libmy_string.a -o sprintf_tests -lcheck -fprofile-arcs -lrt -lsubunit -lm 
	./sprintf_tests

string_test: my_string.a my_string_tests.o 
	$(CC) my_string_tests.o libmy_string.a -o string_tests -lcheck -fprofile-arcs -lrt -lsubunit -lm
	./string_tests

string_report: string_test my_string_tests.o
	$(CC) -c -fprofile-arcs -ftest-coverage my_string.c
	$(CC) my_string_tests.o my_string.o -o string_tests -lcheck -fprofile-arcs -lrt -lsubunit -lm
	./string_tests
	gcov -f my_string.gcda
	gcovr -r . --html --html-details -o string_coverage_report.html

sprintf_report: sprintf_test my_sprintf_tests.o
	$(CC) -c -fprofile-arcs -ftest-coverage my_sprintf.c
	$(CC) my_sprintf_tests.o my_string.o my_sprintf.o -o sprintf_tests -lcheck -fprofile-arcs -lrt -lsubunit -lm
	./sprintf_tests
	gcov -f my_sprintf.gcda
	gcovr -r . --html --html-details -o sprintf_coverage_report.html
