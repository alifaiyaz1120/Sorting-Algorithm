// Homework 4
// Testing Sorting Algorithms
// Ali Faiyaz
// In this file, I have to implement the following functions: ComputeDuration, GenerateRandomVector, and VerifyOrder. 
// I implemented testSortingWrapper, where it reads inputs entered and sorts the vector using HeapSort, MergeSort,  QuickSort, and ShellSort.
// Also, verifies if the vector is sorted after and the run time of each sorting algorithm.

#include "Sort.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

// Computes duration given a start time and a stop time in nano seconds.
// Keep it in.
// changed long long to auto 
auto ComputeDuration(chrono::high_resolution_clock::time_point start_time, 
			  chrono::high_resolution_clock::time_point end_time) {
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  // Use rand() to generate random integer
  vector<int> random_vector(size_of_vector); // created a vector of size size_of_vector
  for (int i = 0; i < size_of_vector; ++i) {
    random_vector[i] = rand(); // assign random number to each element of the vector
  }
  return random_vector;
}

// Generates and returns sorted vector of size @size_of_vector.
// If @smaller_to_larger is true, returns vector sorted from small to large.
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {

  vector<int> sorted_vector(size_of_vector); // created a vector of size size_of_vector
  if (smaller_to_larger) {
    for (int i = 0; i < size_of_vector; ++i) {
      sorted_vector[i] = i; // sorted vector from small to large
    }
  } else {
    for (int i = 0; i < size_of_vector; ++i) {
      sorted_vector[i] = size_of_vector - i; // sorted vector from large to small 
    }
  }
  return sorted_vector;
  
}

// Verifies that a vector is sorted given a comparator.
// I.e. it applies less_than() for consecutive pair of elements and returns true
// iff less_than() is true for all pairs.
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  
  // checks where the vector is sorted from smaller to larger 
  for (size_t i = 0; i < input.size() - 1; ++i) {
    if (less_than(input[i+1], input[i])) { // if the next element is smaller than the previous element
      return false;
    }
  }
  return true;

  /*
  // checks where the vector is sorted from larger to smaller 
  for (size_t i = 0; i < input.size() - 1; ++i) {
    if (less_than(input[i], input[i+1])) {
      return false;
    }
  }
  return true;
  */

}

// Wrapper function to test different sorting algorithms. See homework's PDF for details.
void testSortingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return;
  }

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  cout << endl;

  vector<int> input_vector; // created a vector of type int

  if (input_type == "random") {
    // Generate random vector @input_vector.
    input_vector = GenerateRandomVector(input_size); // generate random vectors calling GenerateRandomVector 
  } 
  else if (input_type == "sorted_small_to_large")
  {
    // Generate sorted vector @input_vector from small to large.
    input_vector = GenerateSortedVector(input_size, true); // generate sorted vectors calling GenerateSortedVector 
  } 
  else if (input_type == "sorted_large_to_small")
  {
    // Generate sorted vector @input_vector from large to small.
    input_vector = GenerateSortedVector(input_size, false); // generate sorted vectors calling GenerateSortedVector 
  } 
  else
  {
    input_vector = GenerateSortedVector(input_size, true); // generate sorted vectors calling GenerateSortedVector
  }

  // all these vectors are new vectors equal to the input vector
  vector<int>input_vector2 = input_vector; 
  vector<int>input_vector3 = input_vector;
  vector<int>input_vector4 = input_vector;
  vector<int>input_vector5 = input_vector;
  vector<int>input_vector6 = input_vector;
  vector<int>input_vector7 = input_vector;

  if (comparison_type == "less")
  {
    // HeapSort
    const auto begin_time = chrono::high_resolution_clock::now(); // used to generate the start time
    HeapSort(input_vector, less<int>{}); // 
    const auto end_time = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "HeapSort" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl; // check if the vector is sorted from smaller to larger after heapsort
    cout << endl;

    // MergeSort
    const auto begin_time2 = chrono::high_resolution_clock::now(); // used to generate the start time
    MergeSort(input_vector2, less<int>{}); // call MergeSort
    const auto end_time2 = chrono::high_resolution_clock::now();  // used to generate the end time
    cout << "MergeSort" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time2, end_time2) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector2, less<int>{}) << endl; // check if the vector is sorted from smaller to larger after using MergeSort
    cout << endl;

   
    // QuickSort
    
    const auto begin_time3 = chrono::high_resolution_clock::now(); // used to generate the start time
    QuickSort(input_vector3, less<int>{}); // call QuickSort
    const auto end_time3 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "QuickSort" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time3, end_time3) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector3, less<int>{}) << endl; // check if the vector is sorted from smaller to larger after using QuickSort
    cout << endl;

   
    //ShellSort (Extra Credit)
    const auto begin_time7 = chrono::high_resolution_clock::now(); // used to generate the start time
    ShellSort(input_vector7, less<int>{}); // call ShellSort
    const auto end_time7 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "ShellSort" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time7, end_time7) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector7, less<int>{}) << endl; // check if the vector is sorted from smaller to larger after using ShellSort
    cout << endl;

   
    cout << "Testing Quicksort Pivot Implementations" << endl;
    cout << endl;

    // Median of Three
    const auto begin_time4 = chrono::high_resolution_clock::now(); // used to generate the start time
    QuickSort(input_vector4, less<int>{}); // call QuickSort
    const auto end_time4 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "Median of Three" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time4, end_time4) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector4, less<int>{}) << endl; // check if the vector is sorted from smaller to larger after using QuickSort
    cout << endl;

    // Middle 
    const auto begin_time5 = chrono::high_resolution_clock::now(); // used to generate the start time
    QuickSort2(input_vector5, less<int>{}); // call QuickSort2
    const auto end_time5 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "Middle" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time5, end_time5) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector5, less<int>{}) << endl; // check if the vector is sorted from smaller to larger after using QuickSort2
    cout << endl;

    // First
    const auto begin_time6 = chrono::high_resolution_clock::now(); // used to generate the start time
    QuickSort3(input_vector6, less<int>{}); // call QuickSort3
    const auto end_time6 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "First" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time6, end_time6) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector6, less<int>{}) << endl; // check if the vector is sorted from smaller to larger after using QuickSort3
    cout << endl;

  }
  // this else statment is for comparison_type for "greater"
  // simliar to "less" 
  else{

    // HeapSort
    const auto begin_time = chrono::high_resolution_clock::now(); // used to generate the start time
    HeapSort(input_vector, greater<int>{}); // call HeapSort
    const auto end_time = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "HeapSort" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl; // check if the vector is sorted from larger to smaller after using HeapSort
    cout << endl;

    // MergeSort
    const auto begin_time2 = chrono::high_resolution_clock::now(); // used to generate the start time
    MergeSort(input_vector2, greater<int>{}); // call MergeSort
    const auto end_time2 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "MergeSort" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time2, end_time2) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector2, greater<int>{}) << endl; // check if the vector is sorted from larger to smaller after using MergeSort
    cout << endl;

    // QuickSort
    const auto begin_time3 = chrono::high_resolution_clock::now(); // used to generate the start time
    QuickSort(input_vector3, greater<int>{}); // call QuickSort
    const auto end_time3 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "QuickSort" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time3, end_time3) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector3, greater<int>{}) << endl; // check if the vector is sorted from larger to smaller after using QuickSort
    cout << endl;

    //ShellSort (Extra Credit)
    const auto begin_time7 = chrono::high_resolution_clock::now(); // used to generate the start time
    ShellSort(input_vector7, greater<int>{}); // call ShellSort
    const auto end_time7 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "ShellSort" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time7, end_time7) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector7, greater<int>{}) << endl; // check if the vector is sorted from larger to smaller after using ShellSort
    cout << endl;

    cout << "Testing Quicksort Pivot Implementations" << endl;
    cout << endl;

    // Median of Three
    const auto begin_time4 = chrono::high_resolution_clock::now(); // used to generate the start time
    QuickSort(input_vector4, greater<int>{}); // call QuickSort
    const auto end_time4 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "Median of Three" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time4, end_time4) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector4, greater<int>{}) << endl; // check if the vector is sorted from larger to smaller after using QuickSort
    cout << endl;

    // Middle 
    const auto begin_time5 = chrono::high_resolution_clock::now(); // used to generate the start time
    QuickSort2(input_vector5, greater<int>{}); // call QuickSort2
    const auto end_time5 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "Middle" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time5, end_time5) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector5, greater<int>{}) << endl; // check if the vector is sorted from larger to smaller after using QuickSort2
    cout << endl;

    // First
    const auto begin_time6 = chrono::high_resolution_clock::now(); // used to generate the start time
    QuickSort3(input_vector6, greater<int>{}); // call QuickSort3
    const auto end_time6 = chrono::high_resolution_clock::now(); // used to generate the end time
    cout << "First" << endl;
    cout << "Runtime: " << ComputeDuration(begin_time6, end_time6) << " ns" << endl; // used ComputeDuration to calculate the duration
    cout << "Verified: " << VerifyOrder(input_vector6, greater<int>{}) << endl; // check if the vector is sorted from larger to smaller after using QuickSort3
    cout << endl;
    
  }

} 

int main(int argc, char **argv) {
  // DO NOT CHANGE or ADD ANY CODE in this function.
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  testSortingWrapper(argc, argv);

  return 0;
}
