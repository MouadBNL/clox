NAME=clox
CC=clang
CFLAGS= -Wall -g
LDFLAGS=

all: main.o
	$(CC) $(LDFLAGS) main.o -o build/clox


main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

clean:
	rm -rf *.o clox
