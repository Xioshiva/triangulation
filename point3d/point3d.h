#ifndef POINT3D_H
#define POINT3D_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h> 
#include "../point2d/point2d.h"

typedef struct {
	double x, y, z;
} point_3d;


point_3d point_3d_create(double x, double y, double z);
void point_3d_add_inplace(point_3d *p1, point_3d *p2);
void point_3d_sub_inplace(point_3d *p1, point_3d *p2);
void point_3d_scale_inplace(point_3d *p1, double a);
point_3d point_3d_add(point_3d *p1, point_3d *p2);
point_3d point_3d_sub(point_3d *p1, point_3d *p2);
point_3d point_3d_scale(point_3d *p1, double a);
double point_3d_compute_norm(point_3d *p);
double point_3d_compute_distance(point_3d *p1, point_3d *p2);
void point_3d_print(point_3d *p);
void point_3d_normalize_inplace(point_3d *p);
point_3d point_3d_normalize(point_3d *p);
point_3d point_3d_vector_product(point_3d *p1, point_3d *p2);
point_3d point_3d_from_point_2d(point_2d p2d);

#endif