#include <iostream>
using namespace std;

// implement sequential search 

// implement recursive sequential search

// implement binary search 
int arr[5];

int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        
        if (arr[mid] == target)
            return mid;

       
        if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// implement recursive binary search 

// test your function in main 

int main(){

    return 0;
}
