#ifndef VECTOR_H
#define VECTOR_H

#include "../error/error.h"
#include "../i_triangle/i_triangle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


#define VECTOR_INIT_CAPACITY 4

typedef i_triangle type_i_t;

typedef struct vector_i_triangle {
    type_i_t *content; // actual content of the vector
    int capacity; // capacity allocated
    int length; // actual length
} vector_i_triangle;

error_code vector_i_triangle_init(vector_i_triangle *v); // initializes an empty vector_i_triangle of site VECTOR_INIT_CAPACITY size
error_code vector_i_triangle_length(vector_i_triangle *v, int *length); // stores the length of v in length
error_code vector_i_triangle_push(vector_i_triangle *v, type_i_t element); // push an element
error_code vector_i_triangle_pop(vector_i_triangle *v, type_i_t *element); // pop the last element
error_code vector_i_triangle_set(vector_i_triangle *v, int index, type_i_t element); // set index-th element
error_code vector_i_triangle_get(vector_i_triangle *v, int index, type_i_t *element); // stores index-th element in *element
error_code vector_i_triangle_remove(vector_i_triangle *v, int index); // remove index-th element
error_code vector_i_triangle_insert(vector_i_triangle *v, type_i_t element, int index); // insert element at position index
error_code vector_i_triangle_empty(vector_i_triangle *v);
error_code vector_i_triangle_free(vector_i_triangle *v);
void vector_i_triangle_print_int(vector_i_triangle *v);

#endif
