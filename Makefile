NAME=clox
CC=clang
CFLAGS= -Wall -g
LDFLAGS=

OBJS=main.o chunk.o memory.o debug.o value.o

all: $(OBJS)
	@mkdir -p build
	$(CC) $(LDFLAGS) $(OBJS) -o build/clox


main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf *.o clox

fclean: clean
	@rm -rf build
