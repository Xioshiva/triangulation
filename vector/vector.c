#include "vector.h"


bool vector_is_null(vector v){
    return (v.length == -1 || v.capacity  == -1 || v.content == NULL);
}

error_code vector_init(vector *v) {
    v->content = malloc(VECTOR_INIT_CAPACITY * sizeof(type));
    v->length = 0;
    v->capacity = VECTOR_INIT_CAPACITY;
    return ok;
}

bool vector_is_equal(vector *v1, vector *v2){
    if(vector_is_null(*v1) || vector_is_null(*v2))
        return false;
    if (v1->length != v2->length)
        return false;
    for (int i = 0; i < v1->length; i++)
    {
        if (v1->content[i] != v2->content[i])
        {
            return false;
        }
    }
    return true;
}

error_code vector_length(vector *v, int *length) {
    if(vector_is_null(*v))
        return uninitialized;
    *length = v->length;
    return ok;
}

error_code vector_push(vector *v, type element) {
    if(vector_is_null(*v))
        return uninitialized;
    if(v->length == v->capacity)
    {
        v->capacity = v->capacity * 2;
        v->content = realloc(v->content, v->capacity * sizeof(type));
        v->content[v->length] = element;
    }
    else
        v->content[v->length] = element;
    v->length++;
    return ok;
}

error_code vector_pop(vector *v, type *element) {
    if(vector_is_null(*v))
        return uninitialized;
    if (v->length == 0)
        return out_of_bounds;
    *element = v->length;
    v->length--;
    v->content[v->length] = 0;
    if(v->length < v->capacity / 4){
        v->capacity = v->capacity / 2;
        v->content = realloc(v->content, v->capacity * sizeof(type));
    }
    return ok;
}

error_code vector_set(vector *v, int index, type element) {
    if(vector_is_null(*v))
        return uninitialized;
    if(index >= v->length || index < 0)
        return out_of_bounds;
    v->content[index] = element;
    return ok;
}

error_code vector_get(vector *v, int index, type *element) {
    if(vector_is_null(*v))
        return uninitialized;
    if(index >= v->length || index < 0)
        return out_of_bounds;
    *element = v->content[index];
    return ok;
}

error_code vector_remove(vector *v, int index) {
    if(vector_is_null(*v))
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

error_code vector_insert(vector *v, type element, int index) {
    if(vector_is_null(*v))
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

error_code vector_empty(vector *v) {
    if(vector_is_null(*v))
        return uninitialized;
    type element;
    for (int i = v->length; i > -1; i--)
    {
        vector_pop(v, &element);
    }
    return ok;
}

error_code vector_free(vector *v) {
    if(vector_is_null(*v))
        return uninitialized;
    free(v->content);
    v->content = NULL;
    v->length = 0;
    v->capacity = 0;
    return ok;
}

void vector_print_int(vector *v) {
    for (int i = 0; i < v->length; ++i)
    {
        printf("%d\n",  v->content[i]);;
    };
}

error_code vector_map(vector *v, type  (*f)(type), vector *rhs) {
    if(vector_is_null(*v))
        return uninitialized;
    vector_init(rhs);
    for (int i = 0 ; i < v->length ; i++ ) {
        vector_push(rhs, (*f)(v->content[i]));
    }
    return ok;
}

error_code vector_filter(vector *v, bool  (*f)(type), vector *rhs) {
    if(vector_is_null(*v))
        return uninitialized;
    vector_init(rhs);
    for (int i = 0 ; i < v->length ; i++ ) {
        if ((*f)(v->content[i]))
            vector_push(rhs, v->content[i]);
    }
    return ok;
}
