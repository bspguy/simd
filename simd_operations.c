#include "simd_operations.h"

#ifdef __ARM_NEON
#include <arm_neon.h>
#else
#include <emmintrin.h> // SSE2
#endif

void add_floats(float* a, float* b, float* result, int n) {
#ifdef __ARM_NEON
    for (int i = 0; i < n; i += 4) {
        float32x4_t a_vec = vld1q_f32(&a[i]);
        float32x4_t b_vec = vld1q_f32(&b[i]);
        float32x4_t result_vec = vaddq_f32(a_vec, b_vec);
        vst1q_f32(&result[i], result_vec);
    }
#else
    for (int i = 0; i < n; i += 4) {
        __m128 a_chunk = _mm_loadu_ps(&a[i]);
        __m128 b_chunk = _mm_loadu_ps(&b[i]);
        __m128 result_chunk = _mm_add_ps(a_chunk, b_chunk);
        _mm_storeu_ps(&result[i], result_chunk);
    }
#endif
}
