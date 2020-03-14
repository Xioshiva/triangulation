#ifndef STL_FILE_H
#define STL_FILE_H


#include "../triangle/triangle.h"
#include "../point3d/point3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	FILE *file;
} stl_file;

stl_file stl_file_create(char *filename, char *name);
void stl_file_close(stl_file *s);
void stl_file_write_triangle(stl_file *s, triangle *t);
void stl_file_create_and_write(char *filename, char *name,triangle *t, int num_triangles);

#endif