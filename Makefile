all:models
	gcc -o main src/main.c src/lib/position.o src/models/cenario.o

models:lib
	gcc -c src/models/cenario.c -o src/models/cenario.o
	gcc -c src/models/nave.c -o src/models/nave.o
	gcc -c src/models/defesa.c -o src/models/defesa.o
	gcc -c src/models/tiro.c -o src/models/tiro.o

lib:
	gcc -c src/lib/position.c -o src/lib/position.o

clean:
	rm main
	find . -name \*.o -delete
