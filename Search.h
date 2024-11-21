#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // ???

void printArray(flexibleType arr[], int n) 
{
    if(n <= 0)
    {
        return;
    }
    cout << arr[n-1] << " ";
    printArray(arr, n-1);
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    if(start > end || start < 0)
    {
        return false;
    }
    if(arr[start] == target)
    {
        return true;
    }
    return seqSearch(target, arr, start + 1, end);
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int mid = n/2;
    while(n >= 1 && arr[mid] != target)
    {
        if(target > arr[mid])
        {
            n /= 2;
            mid = mid + mid/2;
        }
        else if(target < arr[mid])
        {
            n /= 2;
            mid = mid - mid/2;
        }
    }
    return arr[mid] == target;
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    int mid = n/2;
    // BASE CASE
    // 1. Index is target
    if(charray[mid] == target)
    {
        return true;
    }
    // 2. There is nothing in the list
    if(n == 0)
    {
        return false;
    }
    // RECURSIVE CASE
    if(target > charray[mid])
    {
        char *start = &charray[mid+1];
        return binSearchR(target, start, n/2);
    }
    return binSearchR(target, charray, n/2);
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int index1, int index2) {
    double temp = darray[index1];
    darray[index1] = darray[index2];
    darray[index2] = temp;
}

int minFind(double darray[], int n) {
    double smallest = darray[0];
    int smallestindx = 0;
    for(int i = 0; i < n; i++)
    {
        if(darray[i] < smallest)
        {
            smallest = darray[i];
            smallestindx = i;
        }
    }
    return smallestindx;
}

void newSort(double darray[], int n) 
{
    for(int i = 0; i < n; i++)
    {
        double *start = &darray[i];
        swap(darray, minFind(start, n-i) + i, i);
    }
}
