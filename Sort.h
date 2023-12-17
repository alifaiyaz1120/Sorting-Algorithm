// Current code is from the textbook
// Modified by: Ali Faiyaz
// In this file, I modified sorting functions such as heap sort, quick sort, and merge sort by adding a Comparator less_than.
// In addition, I add functions and drivers for quick sort, quicksort2, and quicksort3.

#ifndef SORT_H
#define SORT_H

/**
 * Several sorting routines.
 * Arrays are rearranged with smallest item first.
 */

#include <vector>
#include <functional>
using namespace std;

/**
 * Simple insertion sort.
 */

// for most of these sort functions, comparator was added as a parameter so the vector can be sorted from largest to smallest or smallest to largest
// added Comparator less_than to insertion sort
template <typename Comparable, typename Comparator>
void insertionSort(vector<Comparable> & a, Comparator less_than) {
  for (int p = 1; p < a.size(); ++p) {
    Comparable tmp = std::move(a[p]);
    int j;
    for (j = p; j > 0 && less_than(tmp, a[j - 1]); --j) // added less_than so it can use the comparator to sort 
      a[j] = std::move(a[j - 1]);
    a[j] = std::move(tmp);
  }
}
/**
 * Internal insertion sort routine for subarrays
 * that is used by quicksort.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
// added Comparator less_than to insertionSort
template <typename Comparable, typename Comparator>
void insertionSort(vector<Comparable> & a, int left, int right, Comparator less_than) {
  for (int p = left + 1; p <= right; ++p) {
    Comparable tmp = std::move(a[p]);
    int j;
    for (j = p; j > left && less_than(tmp, a[j - 1]); --j) // add less_than 
      a[j] = std::move(a[j - 1]);
    a[j] = std::move(tmp);
  }
}

/**
 * Shellsort, using Shell's (poor) increments.
 */
// added Comparator less_than to shellSort 
template <typename Comparable, typename Comparator>
void shellSort(vector<Comparable> & a, Comparator less_than) {
  for (int gap = a.size() / 2; gap > 0; gap /= 2)
    for (int i = gap; i < a.size(); ++i) {
      Comparable tmp = std::move(a[i]);
      int j = i;
      for (; j >= gap && less_than(tmp, a[j - gap]); j -= gap) // add less_than
        a[j] = std::move(a[j - gap]);
      a[j] = std::move(tmp);
    }
}

// Driver for ShellSort
// @a: input/output vector to be sorted.
// @less_than: Comparator to be used.
// added Comparator less_than to shellSort
template <typename Comparable, typename Comparator>
void ShellSort(vector<Comparable> &a, Comparator less_than) {
  
   shellSort(a, less_than); // call shellSort with less_than
}

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild( int i )
{
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
// added Comparator less_than to percDown
template <typename Comparable, typename Comparator>
void percDown( vector<Comparable> & a, int i, int n, Comparator less_than)
{
    int child;
    Comparable tmp;

    for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
    {
        child = leftChild( i );
        if( child != n - 1 && less_than( a[ child ], a[ child + 1 ] ) ) // add less_than
            ++child;
        if( less_than( tmp, a[ child ] ) ) // add less_than
            a[ i ] = std::move( a[ child ] );
        else
            break;
    }
    a[ i ] = std::move( tmp );
}

/**
 * Standard heapsort.
 */
// Driver for HeapSort.
// @a: input/output vector to be sorted.
// @less_than: Comparator to be used.
// added Comparator less_than to HeapSort
template <typename Comparable, typename Comparator>
void HeapSort(vector<Comparable> &a, Comparator less_than) {
  // Add code. You can use any of functions above (after you modified them), or any other helper
  // function you write.

  for (int i = a.size() / 2 - 1; i >= 0; i--) {  /* buildHeap */
    percDown(a, i, a.size(), less_than);  // call percolateDown with less_than
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    std::swap(a[0], a[i]);                      /* deleteMax */
    percDown(a, 0, i, less_than); // call percolateDown with less_than
  }

}

/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */

// added Comparator less_than to merge 
template <typename Comparable, typename Comparator>
void merge( vector<Comparable> & a, vector<Comparable> & tmpArray,
            int leftPos, int rightPos, int rightEnd, Comparator less_than )
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while( leftPos <= leftEnd && rightPos <= rightEnd )
        if( less_than( a[ leftPos ], a[ rightPos ] ))  // added less_than
            tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        else
            tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    while( leftPos <= leftEnd )    // Copy rest of first half
        tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );

    while( rightPos <= rightEnd )  // Copy rest of right half
        tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    // Copy tmpArray back
    for( int i = 0; i < numElements; ++i, --rightEnd )
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
}
/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
// added Comparator less_than to mergeSort
template <typename Comparable, typename Comparator>
void mergeSort( vector<Comparable> & a,
                vector<Comparable> & tmpArray, int left, int right, Comparator less_than )
{
    if( left < right )
    {
        int center = ( left + right ) / 2;
        mergeSort( a, tmpArray, left, center, less_than ); // added less_than
        mergeSort( a, tmpArray, center + 1, right, less_than );
        merge( a, tmpArray, left, center + 1, right, less_than );
    }
}
/**
 * Mergesort algorithm (driver).
 */
// Driver for MergeSort.
// @a: input/output vector to be sorted.
// @less_than: Comparator to be used.
template <typename Comparable, typename Comparator>
void MergeSort(vector<Comparable> &a, Comparator less_than) {
  
   vector<Comparable> tmpArray(a.size()); // make a vector of size a.size()
   mergeSort(a, tmpArray, 0, a.size() - 1, less_than); // Call mergeSort function with Comparator

}
/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
 // added Comparator less_than to median3
 // median3 looks at the first, middle, and last elements of the vector
template <typename Comparable, typename Comparator>
const Comparable & median3( vector<Comparable> & a, int left, int right, Comparator less_than)
{
    int center = ( left + right ) / 2;

    if( less_than( a[ center ], a[ left ] ) ) // added less_than
        std::swap( a[ left ], a[ center ] );
    if( less_than( a[ right ], a[ left ] ) )
        std::swap( a[ left ], a[ right ] );
    if( less_than( a[ right ], a[ center ] ) )
        std::swap( a[ center ], a[ right ] );

    // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

// Notes: QuickSort = pivot 
// Correct position of pivot in final, sorted array
// Items to the left are smaller
// Items to the right are larger

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
// added Comparator less_than to quicksort
template <typename Comparable, typename Comparator>
void quicksort( vector<Comparable> & a, int left, int right, Comparator less_than)
{
    if( left + 10 <= right )
    {
        // pivot 
        const Comparable & pivot = median3( a, left, right, less_than );

        // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( less_than( a[ ++i ], pivot ) ) { }
            while( less_than( pivot, a[ --j ] ) ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot

        quicksort( a, left, i - 1, less_than );     // Sort small elements
        quicksort( a, i + 1, right, less_than );    // Sort large elements
    }
    else  // Do an insertion sort on the subarray
        insertionSort( a, left, right, less_than );
}
/**
 * Quicksort algorithm (driver).
 */
// Driver for QuickSort (median of 3 partitioning).
// @a: input/output vector to be sorted.
// @less_than: Comparator to be used.
// added Comparator less_than to QuickSort
template <typename Comparable, typename Comparator>
void QuickSort(vector<Comparable> &a, Comparator less_than) {

    // Call quicksort function and pass in the vector, left, and right
    quicksort(a, 0, a.size() - 1, less_than);  

}
// a helper that swaps two elements in middle
template <typename Comparable, typename Comparator>
void swapMiddle( vector<Comparable> & a, int left, int right, Comparator less_than)
{
    std::swap( a[ (left + right) / 2 ], a[ right ] );
}
/**
 * Internal quicksort2 method that makes recursive calls.
 * Uses middle pivot (always select the middle item in the array)
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
// added Comparator less_than to quicksort2
// in this quicksort2, the pivot is always the middle element
// also, using quicksort function previously used but modifiying it 
template <typename Comparable, typename Comparator>
void quicksort2( vector<Comparable> & a, int left, int right, Comparator less_than)
{
    if( left + 10 <= right )
    {
        // call swapMiddle which swaps the middle element with the right element
        swapMiddle( a, left, right, less_than );
        const Comparable & pivot = a[right ]; 

        // Begin partitioning
        // instead of subtracting the right, we are subtracting the left
        // starts at left - 1
        int i = left -1 , j = right;
        for( ; ; )
        {
            while( less_than( a[ ++i ], pivot ) ) { }
            while( less_than( pivot, a[ --j ] ) ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        // remove the -1 from the right
        std::swap( a[ i ], a[ right] );  // Restore pivot


        quicksort2( a, left, i - 1, less_than );     // Sort small elements
        quicksort2( a, i + 1, right, less_than );    // Sort large elements
    }
    else  // Do an insertion sort on the subarray
        insertionSort( a, left, right, less_than );
}
// Driver for QuickSort2 (middle pivot).
// @a: input/output vector to be sorted.
// @less_than: Comparator to be used.
// added Comparator less_than to QuickSort2
template <typename Comparable, typename Comparator>
void QuickSort2(vector<Comparable> &a, Comparator less_than) {

    // Call the recursive quicksort2 function and pass in the vector, left, and right
    quicksort2(a, 0, a.size() - 1, less_than); 
}

// make a helper that swaps left and right
template <typename Comparable, typename Comparator>
void swapLeftRight( vector<Comparable> & a, int left, int right, Comparator less_than)
{
    std::swap( a[ left ], a[ right ] );
}
/**
 * Internal quicksort3 method that makes recursive calls.
 * First pivot (always select the first item in the array)
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
// added Comparator less_than to quicksort3
// in this quicksort3, the pivot is always the first element
// also, using quicksort function previously used but modifiying it
template <typename Comparable, typename Comparator>
void quicksort3( vector<Comparable> & a, int left, int right, Comparator less_than)
{
    if( left + 10 <= right )
    {
        // call swapLeftRight which swaps the first element with the right element
        swapLeftRight( a, left, right, less_than );
        // make the pivot equal to right
        const Comparable & pivot = a[right ];

        // Begin partitioning
        // instead of subtracting the right, we are subtracting the left by 1
        // starts at left - 1
        // same as quicksort2
        int i = left-1, j = right;
        for( ; ; )
        {
            while( less_than( a[ ++i ], pivot ) ) { }
            while( less_than( pivot, a[ --j ] ) ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        // removed the -1 for right like in quicksort2
        std::swap( a[ i ], a[ right] );  // Restore pivot
                                              
        quicksort3( a, left, i - 1, less_than );     // Sort small elements
        quicksort3( a, i + 1, right, less_than );    // Sort large elements
    }
    else  // Do an insertion sort on the subarray
        insertionSort( a, left, right, less_than );
}
// Driver for QuickSort3 using first as pivot
// @a: input/output vector to be sorted.
// @less_than: Comparator to be used.
// added Comparator less_than to QuickSort3
template <typename Comparable, typename Comparator>
void QuickSort3(vector<Comparable> &a, Comparator less_than) {

    // Call quicksort3 function and pass in the vector, left, and right
    quicksort3(a, 0, a.size() - 1, less_than);
  
}
template <typename Comparable>
void SORT( vector<Comparable> & items )
{
    if( items.size( ) > 1 )
    {
        vector<Comparable> smaller;
        vector<Comparable> same;
        vector<Comparable> larger;
        
        auto chosenItem = items[ items.size( ) / 2 ];
        
        for( auto & i : items )
        {
            if( i < chosenItem )
                smaller.push_back( std::move( i ) );
            else if( chosenItem < i )
                larger.push_back( std::move( i ) );
            else
                same.push_back( std::move( i ) );
        }
        
        SORT( smaller );     // Recursive call!
        SORT( larger );      // Recursive call!
        
        std::move( begin( smaller ), end( smaller ), begin( items ) );
        std::move( begin( same ), end( same ), begin( items ) + smaller.size( ) );
        std::move( begin( larger ), end( larger ), end( items ) - larger.size( ) );

/*
        items.clear( );
        items.insert( end( items ), begin( smaller ), end( smaller ) );
        items.insert( end( items ), begin( same ), end( same ) );
        items.insert( end( items ), begin( larger ), end( larger ) );
*/
    }
}

/*
 * This is the more public version of insertion sort.
 * It requires a pair of iterators and a comparison
 * function object.
 */
template <typename RandomIterator, typename Comparator>
void insertionSort( const RandomIterator & begin,
                    const RandomIterator & end,
                    Comparator lessThan )
{
    if( begin == end )
        return;
        
    RandomIterator j;

    for( RandomIterator p = begin+1; p != end; ++p )
    {
        auto tmp = std::move( *p );
        for( j = p; j != begin && lessThan( tmp, *( j-1 ) ); --j )
            *j = std::move( *(j-1) );
        *j = std::move( tmp );
    }
}

/*
 * The two-parameter version calls the three parameter version, using C++11 decltype
 */
template <typename RandomIterator>
void insertionSort( const RandomIterator & begin,
                    const RandomIterator & end )
{
    insertionSort( begin, end, less<decltype(*begin )>{ } );
}

#endif  // SORT_H
