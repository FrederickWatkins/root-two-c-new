#pragma once

#include "DynamicArray.h"

typedef struct ArbPreInt {
	DynamicArray arr;
} ArbPreInt;

// Initialize x
void ArbPreInt_init(ArbPreInt* x);

// Free all memory allocated to x
void ArbPreInt_free(ArbPreInt* x);

// Return x < y
bool ArbPreInt_lessThan(ArbPreInt x, ArbPreInt y);

// Return x > y
bool ArbPreInt_moreThan(ArbPreInt x, ArbPreInt y);

// Return x + y
ArbPreInt ArbPreInt_add(ArbPreInt x, ArbPreInt y);

// Return x - y
ArbPreInt ArbPreInt_sub(ArbPreInt x, ArbPreInt y);

// Return x * y
ArbPreInt ArbPreInt_mul(ArbPreInt x, ArbPreInt y);

// Reutrn x / y
ArbPreInt ArbPreInt_div(ArbPreInt x, ArbPreInt y);