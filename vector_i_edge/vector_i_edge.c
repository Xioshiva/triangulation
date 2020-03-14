#include "vector_i_edge.h"


bool vector_i_edge_is_null(vector_i_edge v){
    return (v.length == -1 || v.capacity  == -1 || v.content == NULL);
}

error_code vector_i_edge_init(vector_i_edge *v) {
    v->content = malloc(VECTOR_INIT_CAPACITY * sizeof(type_i_e));
    v->length = 0;
    v->capacity = VECTOR_INIT_CAPACITY;
    return ok;
}

error_code vector_i_edge_length(vector_i_edge *v, int *length) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    *length = v->length;
    return ok;
}

error_code vector_i_edge_push(vector_i_edge *v, type_i_e element) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    if(v->length == v->capacity)
    {
        v->capacity = v->capacity * 2;
        v->content = realloc(v->content, v->capacity * sizeof(type_i_e));
        v->content[v->length] = element;
    }
    else
        v->content[v->length] = element;
    v->length++;
    return ok;
}

error_code vector_i_edge_pop(vector_i_edge *v, type_i_e *element) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    if (v->length == 0)
        return out_of_bounds;
    *element = v->content[v->length];
    v->length--;
    if(v->length < v->capacity / 4){
        v->capacity = v->capacity / 2;
        v->content = realloc(v->content, v->capacity * sizeof(type_i_e));
    }
    return ok;
}

error_code vector_i_edge_set(vector_i_edge *v, int index, type_i_e element) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    if(index >= v->length || index < 0)
        return out_of_bounds;
    v->content[index] = element;
    return ok;
}

error_code vector_i_edge_get(vector_i_edge *v, int index, type_i_e *element) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    if(index >= v->length || index < 0)
        return out_of_bounds;
    *element = v->content[index];
    return ok;
}

error_code vector_i_edge_remove(vector_i_edge *v, int index) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    if(index > v->length || index < 0)
        return out_of_bounds;
    v->length -= 1;
    for (int i = 0; i <= v->length - index; i++)
    {
        v->content[index + i] = v->content[index + i + 1];
    }
    return ok;
}

error_code vector_i_edge_insert(vector_i_edge *v, type_i_e element, int index) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    if(index > v->length || index < 0)
        return out_of_bounds;
    for (int i = 0; i < v->length - index; ++i)
    {
        v->content[v->length - i] = v->content[v->length - i - 1];
    }
    v->content[index] = element;
    v->length += 1;
    return ok;
}

error_code vector_i_edge_empty(vector_i_edge *v) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    v->length = 0;
    return ok;
}

error_code vector_i_edge_free(vector_i_edge *v) {
    if(vector_i_edge_is_null(*v))
        return uninitialized;
    free(v->content);
    v->content = NULL;
    v->length = 0;
    v->capacity = 0;
    return ok;
}

void vector_i_edge_print_int(vector_i_edge *v) {
    for (int i = 0; i < v->length; ++i)
    {
        i_edge_print(&v->content[i]);
    };
}

// error_code vector_map(vector *v, type_i_e  (*f)(type_i_e), vector *rhs) {
//     if(vector_is_null(*v))
//         return uninitialized;
//     vector_init(rhs);
//     for (int i = 0 ; i < v->length ; i++ ) {
//         vector_push(rhs, (*f)(v->content[i]));
//     }
//     return ok;
// }

// error_code vector_filter(vector *v, bool  (*f)(type_i_e), vector *rhs) {
//     if(vector_is_null(*v))
//         return uninitialized;
//     vector_init(rhs);
//     for (int i = 0 ; i < v->length ; i++ ) {
//         if ((*f)(v->content[i]))
//             vector_push(rhs, v->content[i]);
//     }
//     return ok;
// }
