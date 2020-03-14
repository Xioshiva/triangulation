#include "i_triangle.h"


i_triangle i_triangle_create(int p1, int p2, int p3){
	i_triangle t;
	
	t.p1 = p1;
	t.p2 = p2;
	t.p3 = p3;

	return t;
}

void i_triangle_print(i_triangle *t){
	printf("p1 = %d p2 = %d p3 = %d \n" , t->p1, t->p2, t->p3);
}

bool find_edge_in_triangle(i_edge i_e, i_triangle i_t){
	if (i_e.p1 == i_t.p1 || i_e.p1 == i_t.p2 || i_e.p1 == i_t.p3)
		if(i_e.p2 == i_t.p1 || i_e.p2 == i_t.p2 || i_e.p2 == i_t.p3)
			return true;
	return false;
}

bool i_triangle_are_equal(i_triangle i_t1, i_triangle i_t2){
	if (i_t1.p1 == i_t2.p1 || i_t1.p1 == i_t2.p2 || i_t1.p1 == i_t2.p3)
		if (i_t1.p2 == i_t2.p1 || i_t1.p2 == i_t2.p2 || i_t1.p2 == i_t2.p3)
			if (i_t1.p3 == i_t2.p1 || i_t1.p3 == i_t2.p2 || i_t1.p3 == i_t2.p3)
				return true;
	return false;
}

i_triangle form_i_triangle_from_edge_and_point(i_edge i_e, int i){
	i_triangle t = i_triangle_create(i_e.p1, i_e.p2, i);
	return t;
}

bool i_triangle_in_i_triangle(i_triangle t1, i_triangle t2)
{
	if (t1.p1 == t2.p1 || t1.p1 == t2.p2 || t1.p1 == t2.p3 ||
		t1.p2 == t2.p1 || t1.p2 == t2.p2 || t1.p2 == t2.p3 ||
		t1.p3 == t2.p1 || t1.p3 == t2.p2 || t1.p3 == t2.p3)
		return true;
	return false;
}