# Makefile for SIMD Example

CC=gcc
CFLAGS=-O2
TARGET=simd_example

# Detect the architecture (ARM or x86_64)
UNAME_P := $(shell uname -m)
ifeq ($(UNAME_P),aarch64)
    CFLAGS += -D__ARM_NEON
else
    CFLAGS += -msse2
endif

all: $(TARGET)

$(TARGET): simd_example.c
    $(CC) $(CFLAGS) $^ -o $@

clean:
    rm -f $(TARGET)
