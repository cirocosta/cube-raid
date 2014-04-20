all:compile
	gcc src/main.c linkedlist.o -o main

compile:
	gcc -c src/linkedlist.c

test:compile
	gcc test/tests.c linkedlist.o -o tests
	./tests

clean:
	rm tests main *.o
