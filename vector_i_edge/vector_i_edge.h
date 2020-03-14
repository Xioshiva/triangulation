#ifndef VECTOR_I_EDGE_H
#define VECTOR_I_EDGE_H

#include "../error/error.h"
#include "../i_edge/i_edge.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


#define VECTOR_INIT_CAPACITY 4

typedef i_edge type_i_e;

typedef struct vector_i_edge {
    type_i_e *content; // actual content of the vector
    int capacity; // capacity allocated
    int length; // actual length
} vector_i_edge;

error_code vector_i_edge_init(vector_i_edge *v); // initializes an empty vector_i_edge of site VECTOR_INIT_CAPACITY size
error_code vector_i_edge_length(vector_i_edge *v, int *length); // stores the length of v in length
error_code vector_i_edge_push(vector_i_edge *v, type_i_e element); // push an element
error_code vector_i_edge_pop(vector_i_edge *v, type_i_e *element); // pop the last element
error_code vector_i_edge_set(vector_i_edge *v, int index, type_i_e element); // set index-th element
error_code vector_i_edge_get(vector_i_edge *v, int index, type_i_e *element); // stores index-th element in *element
error_code vector_i_edge_remove(vector_i_edge *v, int index); // remove index-th element
error_code vector_i_edge_insert(vector_i_edge *v, type_i_e element, int index); // insert element at position index
error_code vector_i_edge_empty(vector_i_edge *v);
error_code vector_i_edge_free(vector_i_edge *v);
void vector_i_edge_print_int(vector_i_edge *v);

#endif
