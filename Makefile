CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result
CC = gcc
################################################
LIB_DIR = src/lib
MODEL_DIR = src/models
MAP_DIR = src/maps
TEST_DIR = test

all: models
	$(CC) $(CFLAGS) -o main src/main.c $(LIB_DIR)/lib.a

lib: $(LIB_DIR)/circularbuffer.o $(LIB_DIR)/queue.o $(LIB_DIR)/tipos.h
	$(CC) $(CFLAGS) -c -o $(LIB_DIR)/circularbuffer.o $(LIB_DIR)/circularbuffer.c
	$(CC) $(CFLAGS) -c -o $(LIB_DIR)/queue.o $(LIB_DIR)/queue.c
	$(CC) $(CFLAGS) -c -o $(LIB_DIR)/position.o $(LIB_DIR)/position.c
	ar rvs $(LIB_DIR)/lib.a $(LIB_DIR)/circularbuffer.o $(LIB_DIR)/queue.o $(LIB_DIR)/position.o

models: lib
	$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/cenario.o $(MODEL_DIR)/cenario.c
	$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/nave.o $(MODEL_DIR)/nave.c
	$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/defesa.o $(MODEL_DIR)/defesa.c
	$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/tiro.o $(MODEL_DIR)/tiro.c

maps: lib
	$(CC) $(CFLAGS) -c -o $(MAP_DIR)/map1.o $(MAP_DIR)/map1.c

test: lib
	$(CC) $(CFLAGS) -o $(TEST_DIR)/test_circularbuffer $(TEST_DIR)/test_circularbuffer.c $(LIB_DIR)/lib.a
	$(CC) $(CFLAGS) -o $(TEST_DIR)/test_queue $(TEST_DIR)/test_queue.c $(LIB_DIR)/lib.a
	./test/test_circularbuffer
	./test/test_queue

clean:
	rm -f main
	find . -name \*.o -delete
	find . -name \*.a -delete
