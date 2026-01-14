#!/bin/bash

# Script to build and run C++ LeetCode tests
# Usage: ./run_test.sh [test_name]
# Example: ./run_test.sh balanced_binary_tree_test

set -e

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

# Configure and build
cmake ..
make

# Run specific test if provided, otherwise run all tests
if [ $# -eq 0 ]; then
    echo "Running all tests..."
    ctest --output-on-failure
else
    echo "Running $1..."
    ./$1
fi
