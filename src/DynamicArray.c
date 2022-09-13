#include "DynamicArray.h"

void DynamicArray_init(DynamicArray *arr)
{
	arr->size = 0;
	arr->capacity = 4;
	arr->ptr = malloc(arr->capacity * sizeof(u_int32_t));
	if (arr->ptr == NULL) {
		printf("malloc failed to allocate memory");
		exit(EXIT_FAILURE);
	}
}

void DynamicArray_free(DynamicArray *arr)
{
	if (arr->capacity == 0) {
		printf("memory already freed");
		return;
	}
	arr->capacity = 0;
	free(arr->ptr);
}

void DynamicArray_resize(DynamicArray *arr, size_t newCapacity)
{
	if (arr->capacity == 0) {
		arr->capacity = newCapacity;
		arr->ptr = malloc(newCapacity * sizeof(u_int32_t));
		return;
	}
	arr->capacity = newCapacity;
	arr->ptr = realloc(arr->ptr, newCapacity * sizeof(u_int32_t));
}

void DynamicArray_append(DynamicArray *arr, u_int32_t value)
{
	if (arr->size == arr->capacity) {
		DynamicArray_resize(arr, arr->capacity * 2);
	}
	arr->ptr[arr->size] = value;
	arr->size++;
}

void DynamicArray_pop(DynamicArray *arr)
{
	if (arr->size == 0) {
		printf("Attempted to pop empty array");
		exit(EXIT_FAILURE);
	}
	arr->size--;
	if (arr->size < arr->capacity / 2) {
		DynamicArray_resize(arr, arr->capacity / 2);
	}
}

void DynamicArray_clear(DynamicArray *arr)
{
	arr->size = 0;
	DynamicArray_resize(arr, 4);
}

u_int32_t DynamicArray_at(DynamicArray *arr, size_t i)
{
	if(i >= arr->size){
		printf("Attempted to access value at index higher than size of array");
		exit(EXIT_FAILURE);
	}
	return arr->ptr[i];
}