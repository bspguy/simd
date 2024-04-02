# SIMD Example

This project demonstrates how to perform SIMD (Single Instruction, Multiple Data) operations in C by using preprocessor directives to accommodate different architectures, specifically Intel/AMD (with SSE) and ARM (with NEON).

## Files

- `simd_example.c`: The main C source file that contains SIMD operations for both architectures.
- `Makefile`: A makefile for easy compilation on Linux systems, automatically detecting the target architecture.

## Compiling

To compile the project, simply run:

```bash
make
```

## Running

After compilation, run the program with:

```bash
./simd_example
```
