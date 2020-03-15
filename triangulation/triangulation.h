#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "../point2d/point2d.h"
#include "../i_triangle/i_triangle.h"
#include "../vector_2d/vector_2d.h"
#include "../vector_i_triangle/vector_i_triangle.h"
#include "../vector_i_edge/vector_i_edge.h"
#include <stdbool.h> 

#include <string.h>

double findMaxMin(vector_2d *p, char *search);//find what you want in list depending on char * you give
void add_super_triangle(vector_2d *p, vector_i_triangle *t);//puts super triangle in vector2d
void bowyer_watson(vector_2d *p, vector_i_triangle *t);//makes the triangulation

#endif