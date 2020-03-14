#include "vector_3d.h"


bool vector_3d_is_null(vector_3d v){
    return (v.length == -1 || v.capacity  == -1 || v.content == NULL);
}

error_code vector_3d_init(vector_3d *v) {
    v->content = malloc(VECTOR_INIT_CAPACITY * sizeof(type3d));
    v->length = 0;
    v->capacity = VECTOR_INIT_CAPACITY;
    return ok;
}

error_code vector_3d_length(vector_3d *v, int *length) {
    if(vector_3d_is_null(*v))
        return uninitialized;
    *length = v->length;
    return ok;
}

error_code vector_3d_push(vector_3d *v, type3d element) {
    if(vector_3d_is_null(*v))
        return uninitialized;
    if(v->length == v->capacity)
    {
        v->capacity = v->capacity * 2;
        v->content = realloc(v->content, v->capacity * sizeof(type3d));
        v->content[v->length] = element;
    }
    else
        v->content[v->length] = element;
    v->length++;
    return ok;
}

error_code vector_3d_pop(vector_3d *v, type3d *element) {
    if(vector_3d_is_null(*v))
        return uninitialized;
    if (v->length == 0)
        return out_of_bounds;
    *element = v->content[v->length];
    v->length--;
    if(v->length < v->capacity / 4){
        v->capacity = v->capacity / 2;
        v->content = realloc(v->content, v->capacity * sizeof(type3d));
    }
    return ok;
}

error_code vector_3d_set(vector_3d *v, int index, type3d element) {
    if(vector_3d_is_null(*v))
        return uninitialized;
    if(index >= v->length || index < 0)
        return out_of_bounds;
    v->content[index] = element;
    return ok;
}

error_code vector_3d_get(vector_3d *v, int index, type3d *element) {
    if(vector_3d_is_null(*v))
        return uninitialized;
    if(index >= v->length || index < 0)
        return out_of_bounds;
    *element = v->content[index];
    return ok;
}

error_code vector_3d_remove(vector_3d *v, int index) {
    if(vector_3d_is_null(*v))
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

error_code vector_3d_insert(vector_3d *v, type3d element, int index) {
    if(vector_3d_is_null(*v))
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

error_code vector_3d_empty(vector_3d *v) {
    if(vector_3d_is_null(*v))
        return uninitialized;
    type3d element;
    for (int i = v->length; i > -1; i--)
    {
        vector_3d_pop(v, &element);
    }
    return ok;
}

error_code vector_3d_free(vector_3d *v) {
    if(vector_3d_is_null(*v))
        return uninitialized;
    free(v->content);
    v->content = NULL;
    v->length = 0;
    v->capacity = 0;
    return ok;
}

void vector_3d_print(vector_3d *v) {
    for (int i = 0; i < v->length; ++i)
    {
        point_3d_print(&v->content[i]);
    };
}