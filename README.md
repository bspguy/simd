# SIMD Operations Example with Criterion Testing

This project demonstrates the use of Single Instruction, Multiple Data (SIMD) operations for Intel/AMD (using SSE) and ARM (using NEON) architectures in C, along with unit testing using the Criterion testing framework.

## Project Structure

- `simd_operations.c` and `simd_operations.h`: Contain the implementation of SIMD operations.
- `test_simd_operations.c`: Contains the Criterion-based unit tests for the SIMD operations.
- `Makefile` (Optional): Can be used to automate compilation and testing.

## Installing Criterion

Criterion is a cross-platform C and C++ testing framework. Follow these steps to install Criterion:

### On Linux

1. **Using a Package Manager (Debian/Ubuntu):**
    ```bash
    sudo apt-get install libcriterion-dev
    ```

2. **From Source:**
    - Install the necessary dependencies.
    - Clone the Criterion repository:
        ```bash
        git clone --recursive https://github.com/Snaipe/Criterion.git
        ```
    - Build and install:
        ```bash
        mkdir Criterion/build && cd Criterion/build
        cmake ..
        make
        sudo make install
        ```

## Compiling the SIMD Operations

gcc -o test_simd test_simd_operations.c simd_operations.c -lcriterion

## Writing and Running Tests

1. **Write Tests:**
   - Place your tests in `test_simd_operations.c`. Use the Criterion API to define test cases.

2. **Compile the Tests:**
   - Ensure Criterion is installed and accessible to your compiler.
   - Compile the test file along with the SIMD operation sources and link against Criterion:
     ```bash
     gcc -o test_simd test_simd_operations.c simd_operations.c -lcriterion
     ```

3. **Run the Tests:**
   - Execute the compiled test binary:
     ```bash
     ./test_simd
     ```

## Note on SIMD Architectures

- This example includes code paths for both SSE (Intel/AMD) and NEON (ARM). Ensure your compiler supports the SIMD instructions for your target architecture.
- Use appropriate compiler flags if necessary, e.g., `-msse2` for SSE2 or `-march=armv8-a+simd` for ARM NEON.

For more detailed information about Criterion and its usage, refer to the [official Criterion documentation](https://criterion.readthedocs.io/).
