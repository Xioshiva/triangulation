#include "point3d.h"

point_3d point_3d_create(double x, double y, double z){
	point_3d p;
	p.x = x;
	p.y = y;
	p.z = z;
	return p;
}

void point_3d_add_inplace(point_3d *p1, point_3d *p2){
	p1->x += p2->x;
	p1->y += p2->y;
	p1->z += p2->z;
}

void point_3d_sub_inplace(point_3d *p1, point_3d *p2){
	p1->x -= p2->x;
	p1->y -= p2->y;
	p1->z -= p2->z;
}

void point_3d_scale_inplace(point_3d *p1, double a){
	p1->x *= a;
	p1->y *= a;
	p1->z *= a;
}

point_3d point_3d_add(point_3d *p1, point_3d *p2){
	point_3d Res;
	Res.x = p1->x + p2->x;
	Res.y = p1->y + p2->y;
	Res.z = p1->z + p2->z;
	return Res;
}

point_3d point_3d_sub(point_3d *p1, point_3d *p2){
	point_3d Res;
	Res.x = p1->x - p2->x;
	Res.y = p1->y - p2->y;
	Res.z = p1->z - p2->z;
	return Res;
}

point_3d point_3d_scale(point_3d *p1, double a){
	point_3d Res;
	Res.x = p1->x * a;
	Res.y = p1->y * a;
	Res.z = p1->z * a;
	return Res;
}

double point_3d_compute_norm(point_3d *p){
	double Res = sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
	return Res;
}

double point_3d_compute_distance(point_3d *p1, point_3d *p2){
	double Res = point_3d_compute_norm(p1) - point_3d_compute_norm(p2);
	if(Res < 0)
		Res *= -1;
	return Res;
}

void point_3d_print(point_3d *p){
	printf("x = %f y = %f z = %f \n", p->x, p->y, p->z);
}

void point_3d_normalize_inplace(point_3d *p){
	double norme = point_3d_compute_norm(p);
	p->x /= norme;
	p->y /= norme;
	p->z /= norme;
}

point_3d point_3d_normalize(point_3d *p){
	point_3d Res;
	double norme = point_3d_compute_norm(p);
	Res.x = p->x / norme;
	Res.y = p->y / norme;
	Res.z = p->z / norme;
	return Res;
}

point_3d point_3d_vector_product(point_3d *p1, point_3d *p2){
	point_3d Res;
	Res.x = p1->y * p2->z - p1->z * p2->y;
	Res.y = p1->z * p2->x - p1->x * p2->z;
	Res.z = p1->x * p2->y - p1->y * p2->x;
	return Res;
}

point_3d point_3d_from_point_2d(point_2d p2d)
{
	point_3d Res = point_3d_create(p2d.x, p2d.y, 0.0);
	return Res;
}