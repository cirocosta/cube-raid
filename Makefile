CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result -D _BSD_SOURCE
LDLIBS = -lglut -lGLEW -lGL -lGLU -lm
CC = gcc

# --- DIR ----

LIB_DIR = src/lib
MODEL_DIR = src/models
MAP_DIR = src/maps
TEST_UNIT_DIR = test/unit

# --- MAIN ---

all: models lib
	@$(CC) $(CFLAGS) -o main.out src/main.c $(MODEL_DIR)/models.a $(LIB_DIR)/lib.a -lm
	@echo [BUILD] Building main.out [OK]

src/main.out: src/main.c
	@$(CC) $^ $(CFLAGS) $(LDLIBS) -o $@

lib:
	@$(CC) $(CFLAGS) -c -o $(LIB_DIR)/circularbuffer.o $(LIB_DIR)/circularbuffer.c
	@$(CC) $(CFLAGS) -c -o $(LIB_DIR)/queue.o $(LIB_DIR)/queue.c
	@$(CC) $(CFLAGS) -c -o $(LIB_DIR)/position.o $(LIB_DIR)/position.c
	@$(CC) $(CFLAGS) -c -o $(LIB_DIR)/keyboard.o $(LIB_DIR)/keyboard.c
	@echo [BUILD] Building libs
	@ar rvs $(LIB_DIR)/lib.a $(LIB_DIR)/circularbuffer.o $(LIB_DIR)/queue.o $(LIB_DIR)/position.o $(LIB_DIR)/keyboard.o > /dev/null
	@echo [BUILD] Creating lib.a

models: lib
	@$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/cenario.o $(MODEL_DIR)/cenario.c
	@$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/nave.o $(MODEL_DIR)/nave.c
	@$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/defesa.o $(MODEL_DIR)/defesa.c
	@$(CC) $(CFLAGS) -c -o $(MODEL_DIR)/tiro.o $(MODEL_DIR)/tiro.c
	@echo [BUILD] Building models
	@ar rvs $(MODEL_DIR)/models.a $(MODEL_DIR)/cenario.o $(MODEL_DIR)/nave.o $(MODEL_DIR)/defesa.o $(MODEL_DIR)/tiro.o > /dev/null
	@echo [BUILD] Creating models.a

test: lib models maps
	@echo [TEST] Building tests
	@$(CC) $(CFLAGS) -o $(TEST_UNIT_DIR)/test_cenario.out $(TEST_UNIT_DIR)/test_cenario.c $(MODEL_DIR)/models.a $(LIB_DIR)/lib.a -lm
	@$(CC) $(CFLAGS) -o $(TEST_UNIT_DIR)/test_circularbuffer.out $(TEST_UNIT_DIR)/test_circularbuffer.c $(LIB_DIR)/lib.a
	@$(CC) $(CFLAGS) -o $(TEST_UNIT_DIR)/test_queue.out $(TEST_UNIT_DIR)/test_queue.c $(LIB_DIR)/lib.a
	@$(CC) $(CFLAGS) -o $(TEST_UNIT_DIR)/test_position.out $(TEST_UNIT_DIR)/test_position.c $(LIB_DIR)/lib.a
	@$(CC) $(CFLAGS) -o $(TEST_UNIT_DIR)/test_nave.out $(TEST_UNIT_DIR)/test_nave.c $(LIB_DIR)/lib.a $(MODEL_DIR)/models.a
	@$(CC) $(CFLAGS) -o $(TEST_UNIT_DIR)/test_defesa.out $(TEST_UNIT_DIR)/test_defesa.c $(LIB_DIR)/lib.a $(MODEL_DIR)/models.a
	@$(CC) $(CFLAGS) -o $(TEST_UNIT_DIR)/test_tiro.out $(TEST_UNIT_DIR)/test_tiro.c $(LIB_DIR)/lib.a $(MODEL_DIR)/models.a
	@$(CC) $(CFLAGS) -o $(TEST_UNIT_DIR)/test_keyboard.out $(TEST_UNIT_DIR)/test_keyboard.c $(LIB_DIR)/lib.a
	@echo [TEST] Running tests
	@./$(TEST_UNIT_DIR)/test_circularbuffer.out
	@echo [TEST-LIB] CircularBuffer [OK]
	@./$(TEST_UNIT_DIR)/test_queue.out
	@echo [TEST-LIB] Queues [OK]
	@./$(TEST_UNIT_DIR)/test_position.out
	@echo [TEST-LIB] Position [OK]
	@./$(TEST_UNIT_DIR)/test_cenario.out
	@echo [TEST-MODEL] Cenario [OK]
	@./$(TEST_UNIT_DIR)/test_nave.out
	@echo [TEST-MODEL] Nave [OK]
	@./$(TEST_UNIT_DIR)/test_defesa.out
	@echo [TEST-MODEL] Defesa [OK]
	@./$(TEST_UNIT_DIR)/test_tiro.out
	@echo [TEST-MODEL] Tiro [OK]
	@./$(TEST_UNIT_DIR)/test_keyboard.out
	@echo [TEST-MODEL] Keyboard [OK]

clean:
	find . -name \*.o -delete
	find . -name \*.a -delete
	find . -name \*.out -delete
