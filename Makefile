LDLIBS= -lglut -lGLEW -lGL -lGLU -lm
CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result -D _BSD_SOURCE
CC = gcc


main.out: main.c camera.o mouse.o
	@echo Building $@
	@$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)
	./$@

camera.o: camera.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ -c

mouse.o: mouse.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ -c

check-sanity.out: check-sanity.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@
	@echo check-sanity.out DONE!

clean:
	find . -name "*.out" -delete
	find . -name "*.o" -delete
