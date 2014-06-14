LDLIBS = -lglut -lGLEW -lGL -lGLU -lm
CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result -D _BSD_SOURCE
CC = gcc

D_LIBS = ./libs
D_SRC = ./src


main: $(D_SRC)/main.c $(D_LIBS)/camera.o $(D_LIBS)/builder.o $(D_LIBS)/text-drawer.o
	@echo Building $@
	@$(CC) $(CFLAGS) -o $@.out $^ $(LDLIBS)
	./$@.out

$(D_LIBS)/camera.o: $(D_LIBS)/camera.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo $@ DONE!

$(D_LIBS)/builder.o: $(D_LIBS)/builder.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo $@ DONE!

$(D_LIBS)/text-drawer.o: $(D_LIBS)/text-drawer.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo $@ DONE!

check-sanity.out: $(D_SRC)/check-sanity.c
	@echo Building $@
	@$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@
	@echo $@ DONE!

clean:
	find . -name "*.out" -delete
	find . -name "*.o" -delete
