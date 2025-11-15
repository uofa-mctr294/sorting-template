# sorting

## Introduction

Almost all programming tasks can be described as 'reading', 'manipulating' and 'writing' data. One of the most basic manipulations of data is sorting. If you know your data is sorted then many manner of data operations become trivial. If you want the smallest or largest element in a set you can either get the first or last element. If you want to find a value in a large array, you can do a [binary search](https://en.wikipedia.org/wiki/Binary_search). For these reasons, sorting data is often the first step in many algorithms, and there are various algorithms with different performance characteristics.

As sorting is a common programming problem, solutions can easily be found online and AI assistants can easily provide implementations, but it is highly suggested that you give a good faith attempt to implement a solution yourself. You will very likely come across problems in the future where there are no reference implementations, especially when working with embedded systems and other mechatronic-adjacent fields, so it is worth practicing this process. But feel free to compare your final implementation with these resources.

## Requirements

Implement some sorting algorithms.

- Bubble Sort
- Selection or Insertion Sort
- Quick Sort
- 1 of the following
  - Merge Sort
  - Bucket Sort
  - Counting Sort
  - Radix Sort

In addition, benchmark the performance of your algorithms. Add a comparison with a sorting algorithm from the STL.

## Testing Requirements

- For the sake of testing we require that all your source files are placed in `src`.
- We also require that nothing in `tests/test_sort.cpp` and `src/sort.hpp` is removed. You may feel free to add to this file or add additional files to this directory, as long as testing continues to build and run. We expect that an entry point to your benchmark tool will exist inside `src`. Any additional changes may require you to changes to `CMakeLists.txt`

### Hints

- Descriptions of the above sorting algorithms can be found [here](https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms)
- The C++ standard template library (STL) provides sorting functions in their `<algorithm>` header. You can't use these directly in your implementation but they can be useful for reference. They can also serve as a reference implementation if you wish to evaluate the quality of your implementation.
- When benchmarking, the STL's `<chrono>` provides various utilities for timekeeping. Notably `std::chrono::high_resolution_clock` allows for the measurement of time intervals on the scale of nanoseconds
- When benchmarking, time measurements can have significant variance, easily on the scale of the measurements themselves. Additionally measurement tools can themselves affect what they are measuring. You will have to take measures to mitigate these issues.

## Building

```shell
cmake -S . -B build
cmake --build build --config Debug
build\Debug\sorting.exe
```

## Testing

[Build](#building)

```shell
ctest --test-dir build -C Debug
Add -V for verbose testing
```
