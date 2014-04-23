CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result
CC = gcc
################################################
LIB_DIR = src/lib
MODEL_DIR = src/models

all:models
	$(CC) $(CFLAGS) -o main src/main.c $(LIB_DIR)/lib.a 

lib:
	$(CC) $(CFLAGS) -c -o $(LIB_DIR)/position.o $(LIB_DIR)/position.c
	$(CC) $(CFLAGS) -c -o $(LIB_DIR)/circularbuffer.o $(LIB_DIR)/circularbuffer.c
	ar rvs $(LIB_DIR)/lib.a $(LIB_DIR)/position.o $(LIB_DIR)/circularbuffer.o

models: lib
	$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/cenario.o $(MODEL_DIR)/cenario.c $(LIB_DIR)/lib.a 
	$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/nave.o $(MODEL_DIR)/nave.c $(LIB_DIR)/lib.a
	$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/defesa.o $(MODEL_DIR)/defesa.c $(LIB_DIR)/lib.a
	$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/tiro.o $(MODEL_DIR)/tiro.c $(LIB_DIR)/lib.a

TEST_DIR = test
test: lib
	$(CC) $(CFLAGS) -o $(TEST_DIR)/test_circularbuffer $(TEST_DIR)/test_circularbuffer.c $(LIB_DIR)/lib.a

clean:
	rm main
	find . -name \*.o -delete
