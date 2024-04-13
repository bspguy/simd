#include "simd_operations.h"

#ifdef __ARM_NEON
#include <arm_neon.h>
#else
#include <emmintrin.h> // SSE2
#endif

void add_floats(float* a, float* b, float* result, ssize_t n) {
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

void subtract_floats(float* a, float* b, float* result, ssize_t n) {
#ifdef __ARM_NEON
    for (int i = 0; i < n; i += 4) {
        float32x4_t a_vec = vld1q_f32(&a[i]);
        float32x4_t b_vec = vld1q_f32(&b[i]);
        float32x4_t result_vec = vsubq_f32(a_vec, b_vec);
        vst1q_f32(&result[i], result_vec);
    }
#else
    for (int i = 0; i < n; i += 4) {
        __m128 a_chunk = _mm_loadu_ps(&a[i]);
        __m128 b_chunk = _mm_loadu_ps(&b[i]);
        __m128 result_chunk = _mm_sub_ps(a_chunk, b_chunk);
        _mm_storeu_ps(&result[i], result_chunk);
    }
#endif
}

void multiply_floats(float* a, float* b, float* result, ssize_t n) {
#ifdef __ARM_NEON
    for (int i = 0; i < n; i += 4) {
        float32x4_t a_vec = vld1q_f32(&a[i]);
        float32x4_t b_vec = vld1q_f32(&b[i]);
        float32x4_t result_vec = vmulq_f32(a_vec, b_vec);
        vst1q_f32(&result[i], result_vec);
    }
#else
    for (int i = 0; i < n; i += 4) {
        __m128 a_chunk = _mm_loadu_ps(&a[i]);
        __m128 b_chunk = _mm_loadu_ps(&b[i]);
        __m128 result_chunk = _mm_mul_ps(a_chunk, b_chunk);
        _mm_storeu_ps(&result[i], result_chunk);
    }
#endif
}

void divide_floats(float* a, float* b, float* result, ssize_t n) {
#ifdef __ARM_NEON
    for (int i = 0; i < n; i += 4) {
        float32x4_t a_vec = vld1q_f32(&a[i]);
        float32x4_t b_vec = vld1q_f32(&b[i]);
        float32x4_t result_vec = vdivq_f32(a_vec, b_vec);
        vst1q_f32(&result[i], result_vec);
    }
#else
    for (int i = 0; i < n; i += 4) {
        __m128 a_chunk = _mm_loadu_ps(&a[i]);
        __m128 b_chunk = _mm_loadu_ps(&b[i]);
        __m128 result_chunk = _mm_div_ps(a_chunk, b_chunk);
        _mm_storeu_ps(&result[i], result_chunk);
    }
#endif
}

// Matrix multiplication using SIMD
// This implementation assumes that both matrices are square 
// and their dimensions are multiples of the SIMD vector size (e.g., 4 for SSE/NEON).
void matrix_multiply(float* A, float* B, float* C, ssize_t N) {
#ifdef __ARM_NEON
    for (ssize_t i = 0; i < N; ++i) {
        for (ssize_t j = 0; j < N; ++j) {
            float32x4_t sum_vec = vdupq_n_f32(0.0f);
            for (ssize_t k = 0; k < N; k += 4) {
                float32x4_t a_vec = vld1q_f32(&A[i * N + k]);
                float32x4_t b_vec = vld1q_f32(&B[k * N + j]);
                sum_vec = vmlaq_f32(sum_vec, a_vec, b_vec);
            }
            float32x2_t sum_vec_lo = vget_low_f32(sum_vec);
            float32x2_t sum_vec_hi = vget_high_f32(sum_vec);
            float32x2_t sum_vec_lo_hi = vpadd_f32(sum_vec_lo, sum_vec_hi);
            float32_t sum = vget_lane_f32(sum_vec_lo_hi, 0) + vget_lane_f32(sum_vec_lo_hi, 1);
            C[i * N + j] = sum;
        }
    }
#else
    for (ssize_t i = 0; i < N; ++i) {
        for (ssize_t j = 0; j < N; ++j) {
            __m128 sum_vec = _mm_setzero_ps();
            for (ssize_t k = 0; k < N; ++k) {
                __m128 a_vec = _mm_load_ps(&A[i * N + k]);
                __m128 b_vec = _mm_load_ps(&B[k * N + j]);
                sum_vec = _mm_add_ps(sum_vec, _mm_mul_ps(a_vec, b_vec));
            }
            C[i * N + j] = _mm_cvtss_f32(sum_vec);
        }
    }
#endif
}
