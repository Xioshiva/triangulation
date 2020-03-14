#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include "../error/error.h"
#include "../point2d/point2d.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


#define VECTOR_INIT_CAPACITY 4

typedef point_2d type2d;

typedef struct vector_2d {
    type2d *content; // actual content of the vector
    int capacity; // capacity allocated
    int length; // actual length
} vector_2d;

error_code vector_2d_init(vector_2d *v); // initializes an empty vector_2d of site VECTOR_INIT_CAPACITY size
error_code vector_2d_length(vector_2d *v, int *length); // stores the length of v in length
error_code vector_2d_push(vector_2d *v, type2d element); // push an element
error_code vector_2d_pop(vector_2d *v, type2d *element); // pop the last element
error_code vector_2d_set(vector_2d *v, int index, type2d element); // set index-th element
error_code vector_2d_get(vector_2d *v, int index, type2d *element); // stores index-th element in *element
error_code vector_2d_remove(vector_2d *v, int index); // remove index-th element
error_code vector_2d_insert(vector_2d *v, type2d element, int index); // insert element at position index
error_code vector_2d_empty(vector_2d *v);
error_code vector_2d_free(vector_2d *v);
void vector_2d_print(vector_2d *v);

#endif
