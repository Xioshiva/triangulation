#ifndef I_EDGE_H
#define I_EDGE_H

#include <stdio.h>

typedef struct {
	int p1, p2;
} i_edge;

i_edge i_edge_create(int p1, int p2);
i_edge i_edge_print(i_edge *e);

#endif