#ifndef VECTOR_H
#define VECTOR_H

#include "../error/error.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


#define VECTOR_INIT_CAPACITY 4

typedef int type;

typedef struct vector {
    type *content; // actual content of the vector
    int capacity; // capacity allocated
    int length; // actual length
} vector;

error_code vector_init(vector *v); // initializes an empty vector of site VECTOR_INIT_CAPACITY size
bool vector_is_equal(vector *v1, vector *v2);
error_code vector_length(vector *v, int *length); // stores the length of v in length
error_code vector_push(vector *v, type element); // push an element
error_code vector_pop(vector *v, type *element); // pop the last element
error_code vector_set(vector *v, int index, type element); // set index-th element
error_code vector_get(vector *v, int index, type *element); // stores index-th element in *element
error_code vector_remove(vector *v, int index); // remove index-th element
error_code vector_insert(vector *v, type element, int index); // insert element at position index
error_code vector_empty(vector *v);
error_code vector_free(vector *v);

error_code vector_map(vector *v, type (*f)(type), vector *rhs); // map function f on v and stores the result in rhs
error_code vector_filter(vector *v, bool (*f)(type), vector *rhs); // filter v with predicate f and stores the result in rhs

void vector_print_int(vector *v);

#endif
