LDLIBS= -lglut -lGLEW -lGL -lGLU -lm
CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result -D _BSD_SOURCE
CC = gcc


main: main.c camera.o mouse.o
	@echo Building $@
	@$(CC) $(CFLAGS) -o $@.out $^ $(LDLIBS)
	./$@.out

camera.o: camera.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ -c

check-sanity.out: check-sanity.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@
	@echo $@ DONE!

clean:
	find . -name "*.out" -delete
	find . -name "*.o" -delete
