#include "vector_2d.h"


bool vector_2d_is_null(vector_2d v){
    return (v.length == -1 || v.capacity  == -1 || v.content == NULL);
}

error_code vector_2d_init(vector_2d *v) {
    v->content = malloc(VECTOR_INIT_CAPACITY * sizeof(type2d));
    v->length = 0;
    v->capacity = VECTOR_INIT_CAPACITY;
    return ok;
}

error_code vector_2d_length(vector_2d *v, int *length) {
    if(vector_2d_is_null(*v))
        return uninitialized;
    *length = v->length;
    return ok;
}

error_code vector_2d_push(vector_2d *v, type2d element) {
    if(vector_2d_is_null(*v))
        return uninitialized;
    if(v->length == v->capacity)
    {
        v->capacity = v->capacity * 2;
        v->content = realloc(v->content, v->capacity * sizeof(type2d));
        v->content[v->length] = element;
    }
    else
        v->content[v->length] = element;
    v->length++;
    return ok;
}

error_code vector_2d_pop(vector_2d *v, type2d *element) {
    if(vector_2d_is_null(*v))
        return uninitialized;
    if (v->length == 0)
        return out_of_bounds;
    *element = v->content[v->length];
    v->length--;
    if(v->length < v->capacity / 4){
        v->capacity = v->capacity / 2;
        v->content = realloc(v->content, v->capacity * sizeof(type2d));
    }
    return ok;
}

error_code vector_2d_set(vector_2d *v, int index, type2d element) {
    if(vector_2d_is_null(*v))
        return uninitialized;
    if(index >= v->length || index < 0)
        return out_of_bounds;
    v->content[index] = element;
    return ok;
}

error_code vector_2d_get(vector_2d *v, int index, type2d *element) {
    if(vector_2d_is_null(*v))
        return uninitialized;
    if(index >= v->length || index < 0)
        return out_of_bounds;
    *element = v->content[index];
    return ok;
}

error_code vector_2d_remove(vector_2d *v, int index) {
    if(vector_2d_is_null(*v))
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

error_code vector_2d_insert(vector_2d *v, type2d element, int index) {
    if(vector_2d_is_null(*v))
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

error_code vector_2d_empty(vector_2d *v) {
    if(vector_2d_is_null(*v))
        return uninitialized;
    type2d element;
    for (int i = v->length; i > -1; i--)
    {
        vector_2d_pop(v, &element);
    }
    return ok;
}

error_code vector_2d_free(vector_2d *v) {
    if(vector_2d_is_null(*v))
        return uninitialized;
    free(v->content);
    v->content = NULL;
    v->length = 0;
    v->capacity = 0;
    return ok;
}

void vector_2d_print(vector_2d *v) {
    for (int i = 0; i < v->length; ++i)
    {
        point_2d_print(&v->content[i]);
    };
}
