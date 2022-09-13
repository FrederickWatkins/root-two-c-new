#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct DynamicArray {
	size_t capacity;
	size_t size;
	u_int32_t *ptr;
} DynamicArray;

// Initialize arr to size 0 and capacity 4
void DynamicArray_init(DynamicArray *arr);

// Free all memory allocated to arr
void DynamicArray_free(DynamicArray *arr);

// Resize dynamic array to size newSize
void DynamicArray_resize(DynamicArray *arr, size_t newSize);

// Append value to arr
void DynamicArray_append(DynamicArray *arr, u_int32_t value);

// Remove the element at the highest address
void DynamicArray_pop(DynamicArray *arr);

// Remove all array elements and set length to zero
void DynamicArray_clear(DynamicArray *arr);

// Return the value stored at index i
u_int32_t DynamicArray_at(DynamicArray *arr, size_t i);