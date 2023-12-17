# Sorting Algorithms Project

This project implements and tests modified sorting algorithms with additional features, including sorting with custom comparators and variations of the quicksort algorithm. The project is structured into multiple tasks, as outlined below
## Files

- **Sort.h**: This file contains the modified sorting algorithms, including heapsort, quicksort, and mergesort. 

- **test_sorting_algorithms.cc**: This file contains functions for testing the sorting algorithms, generating random and sorted vectors, computing durations, and a driver program for testing the algorithms with different inputs.

## Functions and Tasks

### Task 1: VerifyOrder Function and Vector Generation

- **VerifyOrder()**: Verifies if a given vector is in sorted order based on a provided comparator.

- **GenerateRandomVector(size_t size_of_vector)**: Generates a random vector of a specified size.

- **GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger)**: Generates a sorted vector in ascending or descending order based on the provided boolean.

- **ComputeDuration()**: Computes the duration between two time points in nanoseconds.

### Task 2: Sorting Algorithm Modifications

- **HeapSort()**: Modified heapsort that accepts a custom comparator.

- **QuickSort()**: Modified quicksort that accepts a custom comparator.

- **MergeSort()**: Modified mergesort that accepts a custom comparator.

### Task 3: Sorting Algorithm Testing

- **sortTestingWrapper()**: Driver program to test the modified sorting algorithms with different inputs.

### Task 4: Quicksort Variations

- **QuickSort2()**: Quicksort with middle pivot.

- **QuickSort3()**: Quicksort with first pivot.

### Driver Formatting

The driver program outputs the runtime and verification status for each sorting algorithm and quicksort pivot variation.

The full driver format should be as follows: (example shown with function call
`./test_sorting_algorithms random 20000 less`) Note: The number output next to
“Verified” is the boolean output of the function `VerifyOrder()`. If that value is 0, your sort did not
work as intended.

```bash
Running sorting algorithms: random 20000 less
Heapsort
Runtime: <X> ns
Verified: 1

MergeSort
Runtime: <X> ns
Verified: 1

QuickSort
Runtime: <X> ns
Verified: 1

Testing Quicksort Pivot Implementations
Median of Three
Runtime: <X> ns
Verified: 1

Middle
Runtime: <X> ns
Verified: 1

First
Runtime: <X> ns
Verified: 1
```
- Replace X with the actual runtime values. This format provides a clear and structured output for each sorting algorithm and quicksort pivot variation, including the runtime and verification status.

## How to Use

To test the sorting algorithms, compile the code and run the following command:

```bash
./test_sorting_algorithms <input_type> <input_size> <comparison_type>
```
- Replace <input_type>, <input_size>, and <comparison_type> with appropriate values.


