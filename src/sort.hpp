#ifndef SORT_HPP
#define SORT_HPP

#include <vector>

// ========== CONFIGURATION ==========
// Required sorts: BUBBLE, QUICK (always enabled)

// Choose at least 1 of selection or insertion by uncommenting:
// #define ENABLE_SELECTION_SORT
// #define ENABLE_INSERTION_SORT

// Choose at least 1 additional sort from the options below by uncommenting:

// Optional sort selections (choose 2):
// #define ENABLE_MERGE_SORT
// #define ENABLE_BUCKET_SORT
// #define ENABLE_COUNTING_SORT
// #define ENABLE_RADIX_SORT

// ===================================

// Bubble Sort - compares adjacent elements and swaps if needed
template <typename T>
void bubbleSort(std::vector<T> &arr);

#ifdef ENABLE_SELECTION_SORT
// Selection Sort - finds minimum element and places it in sorted position
template <typename T>
void selectionSort(std::vector<T> &arr);
#endif

// Insertion Sort - builds sorted array one item at a time
#ifdef ENABLE_INSERTION_SORT
template <typename T>
void insertionSort(std::vector<T> &arr);
#endif

// Quick Sort - divide and conquer using pivot
template <typename T>
void quickSort(std::vector<T> &arr);

// Merge Sort - divide and conquer by merging sorted subarrays
#ifdef ENABLE_MERGE_SORT
template <typename T>
void mergeSort(std::vector<T> &arr);
#endif

// Bucket Sort - distributes elements into buckets then sorts
#ifdef ENABLE_BUCKET_SORT
template <typename T>
void bucketSort(std::vector<T> &arr);
#endif

// Counting Sort - counts occurrences of each value
#ifdef ENABLE_COUNTING_SORT
template <typename T>
void countingSort(std::vector<T> &arr);
#endif

// Radix Sort - sorts by individual digits or characters
#ifdef ENABLE_RADIX_SORT
template <typename T>
void radixSort(std::vector<T> &arr);
#endif

#endif // SORT_HPP
