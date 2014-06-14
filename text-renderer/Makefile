LDLIBS = -lglut -lGLEW -lGL -lGLU -lm
CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result -D _BSD_SOURCE
CC = gcc

main.out: main.c
	@echo Building $@
	@$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

glutfonts.out: glutfonts.o
	@echo Building $@
	@$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)
	./$@

glutfonts.o: glutfonts.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ -c -o $@

clean:
	find . -name "*.out" -delete
	find . -name "*.o" -delete
