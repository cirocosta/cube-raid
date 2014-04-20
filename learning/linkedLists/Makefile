all:linkedlist
	gcc src/main.c linkedlist.o -o main

linkedlist:
	gcc -c src/linkedlist.c

test:linkedlist
	gcc test/tests.c linkedlist.o -o tests
	./tests

clean:
	rm tests main *.o

