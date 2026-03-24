all:
	gcc -o main main.c table.c

table:
	gcc -c table.c

clean:
	rm -f *.o main tests

tests: table
	gcc -o tests table.o tests.c

run:
	./main

run_file: all
	./main < data.txt

run_tests: tests
	./tests
