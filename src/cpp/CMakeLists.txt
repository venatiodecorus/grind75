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

# Add test executable for 141-linked-list-cycle
add_executable(
  141-linked-list-cycle_test
  141-linked-list-cycle.cpp
  141-linked-list-cycle.test.cpp
)

target_link_libraries(
  141-linked-list-cycle_test
  GTest::gtest_main
)

gtest_discover_tests(141-linked-list-cycle_test)

# Add test executable for 232-implement-queue-using-stacks
add_executable(
  232-implement-queue-using-stacks_test
  232-implement-queue-using-stacks.cpp
  232-implement-queue-using-stacks.test.cpp
)

target_link_libraries(
  232-implement-queue-using-stacks_test
  GTest::gtest_main
)

gtest_discover_tests(232-implement-queue-using-stacks_test)

# Add test executable for 278-first-bad-version
add_executable(
  278-first-bad-version_test
  278-first-bad-version.cpp
  278-first-bad-version.test.cpp
)

target_link_libraries(
  278-first-bad-version_test
  GTest::gtest_main
)

gtest_discover_tests(278-first-bad-version_test)

# Add test executable for 383-ransom-note
add_executable(
  383-ransom-note_test
  383-ransom-note.cpp
  383-ransom-note.test.cpp
)

target_link_libraries(
  383-ransom-note_test
  GTest::gtest_main
)

gtest_discover_tests(383-ransom-note_test)

# Add test executable for 70-climbing-stairs
add_executable(
  70-climbing-stairs_test
  70-climbing-stairs.cpp
  70-climbing-stairs.test.cpp
)

target_link_libraries(
  70-climbing-stairs_test
  GTest::gtest_main
)

gtest_discover_tests(70-climbing-stairs_test)

# Add test executable for 409-longest-palindrome
add_executable(
  409-longest-palindrome_test
  409-longest-palindrome.cpp
  409-longest-palindrome.test.cpp
)

target_link_libraries(
  409-longest-palindrome_test
  GTest::gtest_main
)

gtest_discover_tests(409-longest-palindrome_test)
