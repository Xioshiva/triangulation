#include "triangle.h"


triangle triangle_create(point_3d v1, point_3d v2, point_3d v3){
	triangle t;
	t.v1.x = v1.x;
	t.v1.y = v1.y;
	t.v1.z = v1.z;

	t.v2.x = v2.x;
	t.v2.y = v2.y;
	t.v2.z = v2.z;

	t.v3.x = v3.x;
	t.v3.y = v3.y;
	t.v3.z = v3.z;

	return t;
}

point_3d triangle_compute_normal(triangle *t){
	point_3d arete1, arete2;
	arete1.x = t->v1.x - t->v2.x;
	arete1.y = t->v1.y - t->v2.y;
	arete1.z = t->v1.z - t->v2.z;

	arete2.x = t->v1.x - t->v3.x;
	arete2.y = t->v1.y - t->v3.y;
	arete2.z = t->v1.z - t->v3.z;

	return (point_3d_vector_product(&arete1, &arete2));
}

double triangle_compute_area(triangle *t){
	double Res;
	point_3d norme;
	norme = triangle_compute_normal(t);
	Res =  point_3d_compute_norm(&norme) / 2;
	return Res;
}

triangle *triangle_from_i_triangle(vector_3d *p, vector_i_triangle i_t){
	triangle *t = malloc(i_t.length * sizeof(triangle));
	for (int i = 0; i < i_t.length; i++)
	{
		t[i] = triangle_create(p->content[i_t.content[i].p1], 
		p->content[i_t.content[i].p2], p->content[i_t.content[i].p3]);
	}
	return t;
}

void triangle_print(triangle *t){
	point_3d_print(&t->v1);
	point_3d_print(&t->v2);
	point_3d_print(&t->v3);
}
