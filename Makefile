CC=clang

CFLAGS=-I/usr/local/include
CFLAGS+=-I/opt/homebrew/include
CFLAGS+=-O3 -Wall -Wextra -Werror

LUAFLAGS=-shared -undefined dynamic_lookup -fpic

all: mu.so munch

munch: munch.o
	$(CC) -o $@ $^

mu.so: mu.o
	$(CC) $(LUAFLAGS) -o $@ $^


.PHONY: clean
clean:
	rm -f *.o munch mu.so
