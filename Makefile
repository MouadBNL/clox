NAME=clox
CC=clang
CFLAGS= -Wall -g
LDFLAGS=

OBJS=main.o chunk.o memory.o debug.o
all: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o build/clox


main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o clox
