#ifndef POINT2D_H
#define POINT2D_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h> 

typedef struct {
	double x, y;
} point_2d;


point_2d point_2d_create(double x, double y);
void point_2d_add_inplace(point_2d *p1, point_2d *p2);
void point_2d_sub_inplace(point_2d *p1, point_2d *p2);
void point_2d_scale_inplace(point_2d *p1, double a);
point_2d point_2d_add(point_2d *p1, point_2d *p2);
point_2d point_2d_sub(point_2d *p1, point_2d *p2);
point_2d point_2d_scale(point_2d *p1, double a);
double point_2d_compute_norm(point_2d *p);
double point_2d_compute_distance(point_2d *p1, point_2d *p2);
void point_2d_print(point_2d *p);
void point_2d_normalize_inplace(point_2d *p);
point_2d point_2d_normalize(point_2d *p);

#endif
