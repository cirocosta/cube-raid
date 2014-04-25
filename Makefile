CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result
CC = gcc
################################################
LIB_DIR = src/lib
MODEL_DIR = src/models
MAP_DIR = src/maps
TEST_DIR = test

all: maps models lib
	@$(CC) $(CFLAGS) -o main.out src/main.c $(MAP_DIR)/map1.o $(MODEL_DIR)/models.a $(LIB_DIR)/lib.a
	@echo [BUILD] Building main.out [OK]

lib:
	@$(CC) $(CFLAGS) -c -o $(LIB_DIR)/circularbuffer.o $(LIB_DIR)/circularbuffer.c
	@$(CC) $(CFLAGS) -c -o $(LIB_DIR)/queue.o $(LIB_DIR)/queue.c
	@$(CC) $(CFLAGS) -c -o $(LIB_DIR)/position.o $(LIB_DIR)/position.c
	@echo [BUILD] Building libs
	@ar rvs $(LIB_DIR)/lib.a $(LIB_DIR)/circularbuffer.o $(LIB_DIR)/queue.o $(LIB_DIR)/position.o > /dev/null
	@echo [BUILD] Creating lib.a

models: lib
	@$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/cenario.o $(MODEL_DIR)/cenario.c
	@$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/nave.o $(MODEL_DIR)/nave.c
	@$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/defesa.o $(MODEL_DIR)/defesa.c
	@$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/tiro.o $(MODEL_DIR)/tiro.c
	@echo [BUILD] Building models
	@ar rvs $(MODEL_DIR)/models.a $(MODEL_DIR)/cenario.o $(MODEL_DIR)/nave.o $(MODEL_DIR)/defesa.o $(MODEL_DIR)/tiro.o > /dev/null
	@echo [BUILD] Creating models.a

maps: lib models
	@$(CC) $(CFLAGS) -c -o $(MAP_DIR)/map1.o $(MAP_DIR)/map1.c
	@echo [BUILD] Building maps

test: lib models maps
	@$(CC) $(CFLAGS) -o $(TEST_DIR)/test_circularbuffer.out $(TEST_DIR)/test_circularbuffer.c $(LIB_DIR)/lib.a
	@$(CC) $(CFLAGS) -o $(TEST_DIR)/test_queue.out $(TEST_DIR)/test_queue.c $(LIB_DIR)/lib.a
	@$(CC) $(CFLAGS) -o $(TEST_DIR)/test_position.out $(TEST_DIR)/test_position.c $(LIB_DIR)/lib.a
	@$(CC) $(CFLAGS) -o $(TEST_DIR)/test_nave.out $(TEST_DIR)/test_nave.c $(LIB_DIR)/lib.a $(MODEL_DIR)/models.a
	@echo [TEST] Building tests
	@./test/test_circularbuffer.out
	@echo [TEST-LIB] CircularBuffer [OK]
	@./test/test_queue.out
	@echo [TEST-LIB] Queues [OK]
	@./test/test_position.out
	@echo [TEST-LIB] Position [OK]
	@./test/test_nave.out
	@echo [TEST-MODEL] Nave [OK]

clean:
	find . -name \*.o -delete
	find . -name \*.a -delete
	find . -name \*.out -delete
