#ifndef I_TRIANGLE_H
#define I_TRIANGLE_H

#include <stdio.h>
#include <stdbool.h> 
#include "../i_edge/i_edge.h"

typedef struct{
	int p1, p2, p3;
} i_triangle;

i_triangle i_triangle_create(int v1, int v2, int v3);
void i_triangle_print(i_triangle *t);
bool find_edge_in_triangle(i_edge i_e, i_triangle i_t);//returns true if edge is triangle, false if not
bool i_triangle_are_equal(i_triangle i_t1, i_triangle i_t2);
i_triangle form_i_triangle_from_edge_and_point(i_edge i_e, int i);//makes a triangle from an edge and a point
bool i_triangle_in_i_triangle(i_triangle t1, i_triangle t2);//returns true there is common point in this 2 triangles


#endif