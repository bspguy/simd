#ifndef SIMD_OPERATIONS_H
#define SIMD_OPERATIONS_H

#include <sys/types.h>

void add_floats(float* a, float* b, float* result, ssize_t n);
void subtract_floats(float* a, float* b, float* result, ssize_t n);
void multiply_floats(float* a, float* b, float* result, ssize_t n); 
void divide_floats(float* a, float* b, float* result, ssize_t n);
void matrix_multiply(float* A, float* B, float* C, ssize_t N);

#endif // SIMD_OPERATIONS_H