CC=gcc
CFLAGS=-Wall -Wextra -pedantic -g -std=c11 -O3
CFLAGS_ASAN=-fsanitize=address -fno-omit-frame-pointer
LDFLAGS=-lm
LDFLAGS_ASAN=-fsanitize=address -fno-omit-frame-pointer

all: triangulation.exe

triangulation.exe:  main.o error/error.o functions/filter_functions.o functions/map_functions.o i_edge/i_edge.o i_triangle/i_triangle.o point2d/point2d.o point3d/point3d.o read_lidar/read_lidar.o stl_file/stl_file.o triangle/triangle.o triangulation/triangulation.o vector/vector.o vector_2d/vector_2d.o vector_3d/vector_3d.o vector_i_edge/vector_i_edge.o vector_i_triangle/vector_i_triangle.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDFLAGS_ASAN)

%.o : %.c
	$(CC) $(COMPILE_OPTS) $(OPTIM_OPTS) $(SANITIZERS) -c $^ -o $@

test: 
	./triangulation.exe

clean:
	rm -f */*.o *.o triangulation.exe

.PHONY: clean test
