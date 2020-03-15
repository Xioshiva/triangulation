#ifndef LST_VECTOR_H
#define LST_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "error.c"
//nothing here works pls ignore
typedef int type;

typedef struct_element {
	type data;
	struct _element* next;
} element;

typedef element* lst_vector;

bool lst_vector_is_null(lst_vector v);
error_code lst_vector_init(lst_vector *v);
error_code lst_vector_length(lst_vector *v, int *length);
error_code lst_vector_push(lst_vector *v, type element);
error_code lst_vector_pop(lst_vector *v, type *element);
error_code lst_vector_set(lst_vector *v, int index, type element);
error_code lst_vector_get(lst_vector *v, int index, type *element);
error_code lst_vector_remove(lst_vector *v, int index);
error_code lst_vector_insert(lst_vector *v, type element, int index);
error_code lst_vector_empty(lst_vector *v);
error_code lst_vector_map(lst_vector *v, type (*f)(type), lst_vector *rhs);
error_code lst_vector_filter(lst_vector *v, bool (*f)(type), lst_vector *rhs);

#endif