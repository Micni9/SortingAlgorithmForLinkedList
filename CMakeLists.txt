# This file is used to build the project using cmake
cmake_minimum_required(VERSION 3.10)

# Project name
project(SortingLinkedList)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory to the project
include_directories(include)

# Create a list of source files
set(ALGORITHMS
    src/algorithms
)

set(UTILS
    src/utils
)

set(SOURCES
    ${ALGORITHMS}/insertion_sort.cpp
    ${ALGORITHMS}/merge_sort.cpp
    ${ALGORITHMS}/quick_sort.cpp
    ${ALGORITHMS}/selection_sort.cpp
    ${ALGORITHMS}/bubble_sort.cpp
)

set(LIST_UTILS
    ${UTILS}/list_utils.cpp
)

# Add the source files to the project
add_executable(SortingLinkedList src/main.cpp ${SOURCES} ${LIST_UTILS})