all:
	gcc -o main main.c func.c

func:
	gcc -c func.c

clean:
	rm -f *.o main test

test: func
	gcc -o test func.o test.c

run:
	./main

run_test: test
	./test