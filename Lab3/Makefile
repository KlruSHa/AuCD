all:
	gcc -o main main.c func.c -lm

func:
	gcc -c func.c

clean:
	rm -f *.o main test

test: func
	gcc -o test func.o test.c -lm

run:
	./main

run_test: test
	./test