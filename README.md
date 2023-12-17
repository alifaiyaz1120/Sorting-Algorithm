[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9439613&assignment_repo_type=AssignmentRepo)
# Assignment-4-Code


I was successfully about to complete Assignment 4. The main purpose of this project was to understand how sorting works and the difference between all of them.

For Question 1, I created a VerifyOrder function that verifies if a vector is sorted using the Comparable less than. 
- bool VerifyOrder(const vector<Comparable> &input, Comparator less_than)

Then, I created two functions that generate a random vector and another with a sorted vector. The sorted vector generates a vector increasing or decreasing based on bool smaller_to_larger. The way I did to generate the random vector was by using the rand() function and assigning it to a vector. For the sorted vector, I used a for loop to sort the vector from smaller to larger or larger to smaller.
- vector<int> GenerateRandomVector(size_t size_of_vector) 
- vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger)

Next, I modified the function, ComputeDuration, which computes the duration given a start time and stop time in nanoseconds. The only thing I changed for this function was instead of long long, I used auto to follow the function signature given to us for this assignment. So far , from this part of the assigment, everything was straight forward and easy to do.
- auto ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time)


Step 2: 
For this part of the assignment, I was supposed to modify functions HeapSort, MergeSort, and QuickSort. The only thing I modified for these functions was making each function take a Comparator with their input, less_than. So for HeapSort, MergeSort, and QuickSort, I added the Comparator less_than to the function parameters. Also, I added the Comparator in the template and inside the function, too, so it can read the Comparator less_than. This allows the vectors to be sorted from least to greatest or greatest to least. I also changed functions like perDown, merge, median3, and insertionSort to take the Comparator less_than because they were being called in the functions HeapSort, MergeSort, and QuickSort. In addition, I did the same thing to the driver functions, where I added the Comparator less_than to the function parameters. For this assignment, the drivers function for HeapSort, MergeSort, and QuickSort were all given to us, so all I did I copied and pasted the functions to the driver functions that are being tested into it. This was straight forward and I really found this interesting because I was able to see how sorting works and how it is implemented.

- Like: void merge( vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd, Comparator less_than )
- void insertionSort( vector<Comparable> & a, int left, int right, Comparator less_than )
- void percDown( vector<Comparable> & a, int i, int n, Comparator less_than )


Step 3:

The next part of the assignment was creating a test driver to test different inputs entered. For example, having the <input type> as random, sorted_small_to_large_ or sorted_large_to_small. Also, <input size> as being either less or greater. So what I did first was 
make an if statement checking if it's random, then call GenerateRandomVector; if its sorted_small_to_large, then call GenerateSortedVector with smaller_to_larger as true, and if its sorted_large_to_small, then call GenerateSortedVector with smaller_to_larger as false. 

Next, I made an if statement for comparision_type = less_than, then calls the function VerifyOrder with less_than as the Comparator. If comparision_type = greater_than, then call the function VerifyOrder with greater_than as the Comparator. 

Then, I made an if statement for comparison_type = "less" when called. Inside is where I print out the type of sorts used and its runtime and verify if it's sorted or not.
For example, for HeapSort, I called HeapSort(input_vector, less<int>{}); input_vector is the vector created. I printed out "HeapSort" and its runtime, where I used const auto begin_time = chrono::high_resolution_clock::now() to start and const auto end_time = chrono::high_resolution_clock::now() to end the time. And then called ComputeDuration to get the duration. After that, I called VerifyOrder to verify whether it was sorted. I did all of this same for MergeSort, QuickSort, ShellSort, QuickSort2, and QuickSort3 but using a new vector input for each sort. At first, I was confused on how to do this, especially for the runtime. But after looking at the example given to us for finding the runtime, I was able to figure it out.

- To test the sorts I used the following inputs:
    ./test_sorting_algorithms <input_type> <input_size> <comparison_type>
    <input_type> can be random, sorted_small_to_large, or sorted_large_to_small
    <input_size> any positive integer
    <comparison_type> can be less or greater

Part 2: 
For this part, I created two functions for quicksort that take a middle pivot that always selects the middle item in the array and the first pivot that always selects the first item in the array. These two sorts are very similar to the median of three, which was already implemented for us and used earlier in this assignment for the function QuickSort.
I first copied everything inside the function QuickSort and pasted it into QuickSort2 and QuickSort3. For QuickSort2, we needed to take in a middle pivot of the array. I made a helper function called 
void swapMiddle, which swaps the middle element with the right. Then, I called the function swapMiddle and passed in the vector, left, and right inside QuickSort2. Then create a pivot which is the right element, instead of making it equal to median3. I next changed right - 1 to the right and left to left -1 instead. So it starts at the left -1, where from the start it's compared, and j starts at the right, before the pivot is compared. Also, when restoring, the pivot is changed right -1 to right. 
All the changes I made in quicksort2 were the same for quicksort3, but its the first pivot instead of the middle pivot.
Just like quicksort2, I made a helper that swapped the left and right and called it void swapLeftRight. I called swapLeftRight and passed in the vector, left, and right inside QuickSort3 instead of swapMiddle. Everything else the changes are the same as quicksort2.
I created driver functions for Quicksort2 and Quicksort3 and called the functions quicksort2 and quicksort3 inside. I also added the Comparator less_than to the function parameters.
In addition, I did the same thing for quicksort2 and quicksort3, where I added the Comparator less_than to the function parameters. Overall, I believe this section,  creating quicksort2 and quicksort3, was more challenging for me than most parts because to make these function work, I need to play around with values and fully understand them correctly, like how to find the middle pivot and the first pivot.

- void swapMiddle( vector<Comparable> & a, int left, int right, Comparator less_than)
- void swapLeftRight( vector<Comparable> & a, int left, int right, Comparator less_than)
- void quicksort2( vector<Comparable> & a, int left, int right, Comparator less_than)
- void quicksort3( vector<Comparable> & a, int left, int right, Comparator less_than)
- void QuickSort2(vector<Comparable> & a, Comparator less_than)
- void QuickSort3(vector<Comparable> & a, Comparator less_than)


Extra Credit:
I created a function void ShellSort, where I just added the Comparator less_than to the function parameters and inside the function and made a driver calling shellSort similar to HeapSort, MergeSort, and QuickSort. Then, I called it in my test driver function.
- void ShellSort(vector<Comparable> &a, Comparator less_than) 

Deleted Functions 
- I deleted driver functions that were copied and not being used. Also, I deleted quickSelect because it wasn't needed for this assignment or used.

Q2: Heaps 
For this question, we are supposed to fill in the following answers in terms of N, and the last three answers in terms of Big O. The first one is a binary tree that has two extra levels (that is, it is slightly unbalanced). This is 4N because it has two additional levels making the size 4N. The first is N nodes, and the second has 2N nodes, so N+N+2N = 4N. The second one is a binary tree that has the deepest node at depth 2 logN, which is O(N^2) because the height of a binary tree is log(x) which is x nodes making the array size for this O(N2). The three one is a binary tree that has a deepest node at depth 4.1 log N which is O(N^4.1), similar to the last one but the height is 4.1. Last one is the worst-case binary tree which is O(2^N).


Errors:
- A problem I encountered was in my test driving, I was using the same input_vector for all the sorts being called. I realized that after HeapSort, for MergeSort, and QuickSort, the input_vector was printing out sorted without me implementing or modifying the functions for MergeSort and QuickSort during that time. Then, I realized that I was using the same input_vector for all the sorts. So, I created a new input_vector for each sort, and it was then fixed. 
- Another issue was when modifying and implementing the merge sort, I was getting errors, and my code wasn't compiling. I realized the error was my merge function was on the bottom of my mergesort function. I moved it to the top, and it was fixed.
