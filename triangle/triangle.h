#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../point3d/point3d.h"
#include "../vector_3d/vector_3d.h"
#include "../i_triangle/i_triangle.h"
#include "../vector_i_triangle/vector_i_triangle.h"

typedef struct {
	point_3d v1, v2, v3;
} triangle;

triangle triangle_create(point_3d v1, point_3d v2, point_3d v3);
point_3d triangle_compute_normal(triangle *t);
double triangle_compute_area(triangle *t);
triangle *triangle_from_i_triangle(vector_3d *p, vector_i_triangle i_t);
void triangle_print(triangle *t);


#endif