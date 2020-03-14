#include "i_edge.h"


i_edge i_edge_create(int p1, int p2)
{
	i_edge e;

	e.p1 = p1;
	e.p2 = p2;

	return e;
}

i_edge i_edge_print(i_edge *e){
	printf("p1 = %d p2 = %d\n", e->p1, e->p2);
}