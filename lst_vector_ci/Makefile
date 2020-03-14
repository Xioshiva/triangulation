CC=gcc
CFLAGS=-Wall -Wextra -pedantic -g -std=c11 -O3
CFLAGS_ASAN=-fsanitize=address -fno-omit-frame-pointer
LDFLAGS=-lm
LDFLAGS_ASAN=-fsanitize=address -fno-omit-frame-pointer

all: main

main: main.o stl_vector.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDFLAGS_ASAN)

stl_vector.o: stl_vector.c stl_vector.h
	$(CC) -c $< $(CFLAGS) $(CFLAGS_ASAN)

error.o : error.c error.h
	$(CC) -c $< $(CFLAGS) $(CFLAGS_ASAN)

main.o: main.c
	$(CC) -c $< $(CFLAGS) $(CFLAGS_ASAN)

re: clean main

test: 
	./main

clean:
	rm -f *.o main test/test