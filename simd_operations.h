#ifndef SIMD_OPERATIONS_H
#define SIMD_OPERATIONS_H

#include <sys/types.h>

void add_floats(float* a, float* b, float* result, ssize_t n);
void subtract_floats(float* a, float* b, float* result, ssize_t n);
void multiply_floats(float* a, float* b, float* result, ssize_t n); 
void divide_floats(float* a, float* b, float* result, ssize_t n);

#endif // SIMD_OPERATIONS_H