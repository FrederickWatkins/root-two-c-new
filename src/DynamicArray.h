#pragma once
#include <stdlib.h>

typedef struct DynamicArray {
	size_t capacity;
	size_t size;
	u_int64_t *ptr;
} DynamicArray;

// Initialize arr to length 0
void DynamicArray_init(DynamicArray *arr);

// Free all memory allocated to arr
void DynamicArray_free(DynamicArray *arr);

// Resize dynamic array to size newSize
void DynamicArray_resize(DynamicArray *arr, size_t newSize);

// Append value to arr
void DynamicArray_append(DynamicArray *arr, u_int64_t value);

// Remove the element at the highest address
void DynamicArray_pop(DynamicArray *arr);