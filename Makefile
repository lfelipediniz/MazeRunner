CC = gcc
CFLAGS = -std=c99 -Wall

all: labirinto

labirinto: labirinto.o main.o pilha.o
	$(CC) labirinto.o main.o pilha.o -o labirinto $(CFLAGS)

labirinto.o: labirinto.c labirinto.h
	$(CC) -c labirinto.c -o labirinto.o $(CFLAGS)

main.o: main.c labirinto.h
	$(CC) -c main.c -o main.o $(CFLAGS)

pilha.o: pilha.c pilha.h
	$(CC) -c pilha.c -o pilha.o $(CFLAGS)

clean:
	rm -f *.o labirinto

run:
	./labirinto
