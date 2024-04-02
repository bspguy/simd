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
        cr_expect_float_eq(result[i], expected[i], 0.001, "Array element %d is %f, expected %f", i, result[i], expected[i]);
    }
}
