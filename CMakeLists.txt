cmake_minimum_required(VERSION 3.14)

project(Sorting VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files in src/ recursively
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(sorting_lib STATIC ${SRC_FILES})
target_include_directories(sorting_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(sorting ${SRC_FILES})
target_include_directories(sorting PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(sorting PRIVATE sorting_lib)

# --- GoogleTest ---
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_sort tests/test_sort.cpp)
target_link_libraries(test_sort PRIVATE sorting_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_sort)
