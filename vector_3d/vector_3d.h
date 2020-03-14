#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include "../error/error.h"
#include "../point3d/point3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


#define VECTOR_INIT_CAPACITY 4

typedef point_3d type3d;

typedef struct vector_3d {
    type3d *content; // actual content of the vector
    int capacity; // capacity allocated
    int length; // actual length
} vector_3d;

error_code vector_3d_init(vector_3d *v); // initializes an empty vector_3d of site VECTOR_INIT_CAPACITY size
error_code vector_3d_length(vector_3d *v, int *length); // stores the length of v in length
error_code vector_3d_push(vector_3d *v, type3d element); // push an element
error_code vector_3d_pop(vector_3d *v, type3d *element); // pop the last element
error_code vector_3d_set(vector_3d *v, int index, type3d element); // set index-th element
error_code vector_3d_get(vector_3d *v, int index, type3d *element); // stores index-th element in *element
error_code vector_3d_remove(vector_3d *v, int index); // remove index-th element
error_code vector_3d_insert(vector_3d *v, type3d element, int index); // insert element at position index
error_code vector_3d_empty(vector_3d *v);
error_code vector_3d_free(vector_3d *v);
void vector_3d_print(vector_3d *v);

#endif
