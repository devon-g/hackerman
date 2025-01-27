CC=zig cc
CFLAGS=-g -Wall -Werror

all: bin/dummy bin/hack

bin/dummy: src/dummy.c
	$(CC) $(CFLAGS) src/dummy.c -o ./bin/dummy

bin/hack: src/hack.c src/proc.c src/mem.c
	$(CC) $(CFLAGS) src/hack.c src/proc.c src/mem.c -o ./bin/hack

clean:
	rm -f ./bin/*
