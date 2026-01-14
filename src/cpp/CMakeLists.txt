cmake_minimum_required(VERSION 3.14)
project(Grind75CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add test executable for each problem
add_executable(
  110-balanced-binary-tree_test
  110-balanced-binary-tree.cpp
  110-balanced-binary-tree.test.cpp
)

target_link_libraries(
  110-balanced-binary-tree_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(110-balanced-binary-tree_test)
