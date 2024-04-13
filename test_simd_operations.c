#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "simd_operations.h"

Test(simd_operations, add_floats_test) {
    float a[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float b[8] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    float result[8] = {0};
    float expected[8] = {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

    add_floats(a, b, result, 8);

    for (int i = 0; i < 8; i++) {
        cr_expect_float_eq(result[i], expected[i], 0.001,
                           "Array element %d is %f, expected %f", i, result[i], expected[i]);
    }
}

Test(simd_operations, subtract_floats_test) {
    float a[8] = {5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0};
    float b[8] = {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    float result[8] = {0};
    float expected[8] = {3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    subtract_floats(a, b, result, 8);

    for (int i = 0; i < 8; i++) {
        cr_expect_float_eq(result[i], expected[i], 0.001,
                           "Array element %d is %f, expected %f", i, result[i], expected[i]);
    }
}

Test(simd_operations, multiply_floats_test) {
    float a[8] = {2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    float b[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float result[8] = {0};
    float expected[8] = {2.0, 6.0, 12.0, 20.0, 30.0, 42.0, 56.0, 72.0};

    multiply_floats(a, b, result, 8);

    for (int i = 0; i < 8; i++) {
        cr_expect_float_eq(result[i], expected[i], 0.001,
                           "Array element %d is %f, expected %f", i, result[i], expected[i]);
    }
}

Test(simd_operations, divide_floats_test) {
    float a[8] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0};
    float b[8] = {2.0, 4.0, 5.0, 8.0, 10.0, 12.0, 14.0, 16.0};
    float result[8] = {0};
    float expected[8] = {5.0, 5.0, 6.0, 5.0, 5.0, 5.0, 5.0, 5.0};

    divide_floats(a, b, result, 8);

    for (int i = 0; i < 8; i++) {
        cr_expect_float_eq(result[i], expected[i], 0.001,
                           "Array element %d is %f, expected %f", i, result[i], expected[i]);
    }
}

/*
Test(simd_operations, matrix_multiply_test) {
    const size_t N = 4;
    float A[N][N] = {{1.0, 2.0, 3.0, 4.0},
                     {5.0, 6.0, 7.0, 8.0},
                     {9.0, 10.0, 11.0, 12.0},
                     {13.0, 14.0, 15.0, 16.0}};
    float B[N][N] = {{1.0, 0.0, 0.0, 0.0},
                     {0.0, 1.0, 0.0, 0.0},
                     {0.0, 0.0, 1.0, 0.0},
                     {0.0, 0.0, 0.0, 1.0}};
    float result[N][N] = {0};
    float expected[N][N] = {{1.0, 2.0, 3.0, 4.0},
                            {5.0, 6.0, 7.0, 8.0},
                            {9.0, 10.0, 11.0, 12.0},
                            {13.0, 14.0, 15.0, 16.0}};

    matrix_multiply((float *)A, (float *)B, (float *)result, N);

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cr_expect_float_eq(result[i][j], expected[i][j], 0.001,
                               "Element at row %zu, column %zu is %f, expected %f", i, j, result[i][j], expected[i][j]);
        }
    }
}
*/
