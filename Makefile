# Makefile for SIMD

CC ?= gcc # set gcc as the default compiler but allows it to be overridden i.e <CC=clang make> or <make CC=clang>
CFLAGS=-O2
BUILD_DIR=./build
TARGET=$(BUILD_DIR)/simd

# Detect the architecture (ARM or x86_64)
UNAME_P := $(shell uname -m)
ifeq ($(UNAME_P),aarch64)
    CFLAGS += -D__ARM_NEON
else
    CFLAGS += -msse2
endif

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): simd.c
	$(CC) $(CFLAGS) $^ -o $@

# test target using criterion
test: $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/test_simd test_simd_operations.c simd_operations.c -lcriterion

clean:
	rm -f $(BUILD_DIR)

