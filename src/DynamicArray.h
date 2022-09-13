#pragma once
#include <stdlib.h>

typedef struct DynamicArray{
    size_t capacity;
    size_t size;
    u_int64_t* ptr;
};

//Initializes arr to length 0
void DynamicArray_init(DynamicArray* arr);