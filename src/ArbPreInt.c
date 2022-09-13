#include "ArbPreInt.h"

void ArbPreInt_init(ArbPreInt *x)
{
	DynamicArray_init(&x->arr);
}

void ArbPreInt_free(ArbPreInt *x)
{
	DynamicArray_free(&x->arr);
}

void ArbPreInt_clear(ArbPreInt *x)
{
	DynamicArray_clear(&x->arr);
}

void ArbPreInt_prune(ArbPreInt *x)
{
	for (size_t i = x->arr.size - 1;; i--) {
		if (DynamicArray_at(&x->arr, i) == 0) {
			DynamicArray_pop(&x->arr);
		} else {
			return;
		}
		if (i == 0) {
			return;
		}
	}
}

bool ArbPreInt_lessThan(ArbPreInt x, ArbPreInt y)
{
	if (x.arr.size > y.arr.size) {
		return false;
	}
	if (x.arr.size < y.arr.size) {
		return true;
	}
	for (size_t i = x.arr.size - 1;; i--) {
		if (DynamicArray_at(&x.arr, i) < DynamicArray_at(&y.arr, i)) {
			return true;
		}
		if (DynamicArray_at(&x.arr, i) > DynamicArray_at(&y.arr, i)) {
			return false;
		}
		if (i == 0) {
			return false;
		}
	}
}

bool ArbPreInt_moreThan(ArbPreInt x, ArbPreInt y)
{
	if (x.arr.size < y.arr.size) {
		return false;
	}
	if (x.arr.size > y.arr.size) {
		return true;
	}
	for (size_t i = x.arr.size - 1;; i--) {
		if (DynamicArray_at(&x.arr, i) > DynamicArray_at(&y.arr, i)) {
			return true;
		}
		if (DynamicArray_at(&x.arr, i) < DynamicArray_at(&y.arr, i)) {
			return false;
		}
		if (i == 0) {
			return false;
		}
	}
}

ArbPreInt ArbPreInt_add(ArbPreInt x, ArbPreInt y)
{
	ArbPreInt out;
	ArbPreInt_init(&out);
	size_t i = 0;
	bool carry = 0;
	if (x.arr.size < y.arr.size) {
		return ArbPreInt_add(y, x);
	}
	for (; i < y.arr.size; i++) {
		if (DynamicArray_at(&y.arr, i) == __UINT32_MAX__ && carry) {
			DynamicArray_append(&out.arr,
					    DynamicArray_at(&x.arr, i));
		} else if (DynamicArray_at(&x.arr, i) >
			   (__UINT32_MAX__ - DynamicArray_at(&y.arr, i)) -
				   carry) {
			DynamicArray_append(&out.arr,
					    DynamicArray_at(&x.arr, i) +
						    DynamicArray_at(&x.arr, i) +
						    carry);
			carry = true;
		} else {
			DynamicArray_append(&out.arr,
					    DynamicArray_at(&x.arr, i) +
						    DynamicArray_at(&y.arr, i) +
						    carry);
			carry = false;
		}
	}
	for (; i < x.arr.size; i++) {
		DynamicArray_append(&out.arr,
				    DynamicArray_at(&x.arr, i) + carry);
		carry = 0;
	}
	DynamicArray_append(&out.arr, carry);
	ArbPreInt_prune(&out);
	return out;
}

ArbPreInt ArbPreInt_sub(ArbPreInt x, ArbPreInt y)
{
	ArbPreInt out;
	ArbPreInt_init(&out);
	size_t i = 0;
	bool carry = 0;
	if (y.arr.size > x.arr.size) {
		printf("Invalid subtraction: length\n");
		exit(EXIT_FAILURE);
	}
	for (; i < y.arr.size; i++) {
		if (DynamicArray_at(&y.arr, i) == __UINT32_MAX__ && carry) {
			DynamicArray_append(&out.arr,
					    DynamicArray_at(&x.arr, i));
		} else if (DynamicArray_at(&x.arr, i) <
			   DynamicArray_at(&y.arr, i) + carry) {
			DynamicArray_append(
				&out.arr,
				DynamicArray_at(&x.arr, i) -
					(DynamicArray_at(&y.arr, i) + carry));
			carry = 1;
		} else {
			DynamicArray_append(
				&out.arr,
				DynamicArray_at(&x.arr, i) -
					(DynamicArray_at(&y.arr, i) + carry));
			carry = 0;
		}
	}
	for (; i < x.arr.size; i++) {
		DynamicArray_append(&out.arr,
				    DynamicArray_at(&x.arr, i) - carry);
		carry = 0;
	}
	if (carry == 1) {
		printf("Invalid subtraction: carry\n");
		exit(EXIT_FAILURE);
	}
	ArbPreInt_prune(&out);
	return out;
}

ArbPreInt ArbPreInt_mul(ArbPreInt x, ArbPreInt y);

ArbPreInt ArbPreInt_div(ArbPreInt x, ArbPreInt y);