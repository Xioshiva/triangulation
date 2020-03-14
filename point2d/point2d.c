#include "point2d.h"

point_2d point_2d_create(double x, double y){
	point_2d p;
	p.x = x;
	p.y = y;
	return p;
}

void point_2d_add_inplace(point_2d *p1, point_2d *p2){
	p1->x += p2->x;
	p1->y += p2->y;
}

void point_2d_sub_inplace(point_2d *p1, point_2d *p2){
	p1->x -= p2->x;
	p1->y -= p2->y;
}

void point_2d_scale_inplace(point_2d *p1, double a){
	p1->x *= a;
	p1->y *= a;
}

point_2d point_2d_add(point_2d *p1, point_2d *p2){
	point_2d Res;
	Res.x = p1->x + p2->x;
	Res.y = p1->y + p2->y;
	return Res;
}

point_2d point_2d_sub(point_2d *p1, point_2d *p2){
	point_2d Res;
	Res.x = p1->x - p2->x;
	Res.y = p1->y - p2->y;
	return Res;
}

point_2d point_2d_scale(point_2d *p1, double a){
	point_2d Res;
	Res.x = p1->x * a;
	Res.y = p1->y * a;
	return Res;
}

double point_2d_compute_norm(point_2d *p){
	double Res = sqrt(p->x * p->x + p->y * p->y);
	return Res;
}

double point_2d_compute_distance(point_2d *p1, point_2d *p2){
	double Res = point_2d_compute_norm(p1) - point_2d_compute_norm(p2);
	if(Res < 0)
		Res *= -1;
	return Res;
}

void point_2d_print(point_2d *p){
	printf("x = %f y = %f\n", p->x, p->y);
}

void point_2d_normalize_inplace(point_2d *p){
	double norme = point_2d_compute_norm(p);
	p->x /= norme;
	p->y /= norme;
}

point_2d point_2d_normalize(point_2d *p){
	point_2d Res;
	double norme = point_2d_compute_norm(p);
	Res.x = p->x / norme;
	Res.y = p->y / norme;
	return Res;
}
