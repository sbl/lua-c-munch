CC=clang
CFLAGS=-I/usr/local/include -O3 -Wall -Wextra -Werror

all: mu.so munch

munch: munch.o
	$(CC) -o $@ $^

mu.so: mu.o
	$(CC) -shared -undefined dynamic_lookup -llua -fpic -o $@ $^


.PHONY: clean
clean:
	rm -f *.o munch mu.so
