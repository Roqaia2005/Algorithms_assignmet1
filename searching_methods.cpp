#include <iostream>
#include <vector>
using namespace std;

// implement sequential search
int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // key found at index i
        }
    }
    return -1; // key not found
}


// implement recursive sequential search
int recursiveSequentialSearch(int arr[], int size, int index, int target) {
    if (index >= size) {
        return -1; // key not found
    }
    if (arr[index] == target) {
        return index; // key found at index
    }
    return recursiveSequentialSearch(arr, size, index + 1, target); 
}


// implement binary search
int arr[5];

int binarySearch(int arr[], int low, int high, int target)
{

    while (low <= high)
    {
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

// implement recursive binary search --------->Done
int RBsearch(int arr[], int low, int high, int key)
{
    if (low > high)
    {
        return -1; // Not found
    }
    else
    {
        int mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        if (key < arr[mid])
            return RBsearch(arr, low, mid - 1, key);
        else
            return RBsearch(arr, mid + 1, high, key);
    }
}
int RecursiveBinarySearch(int arr[], int low, int high, int value)
{
    if (low == high)
    {
        if (arr[low] == value)
        {
            return low;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] > value)
        {
            return RecursiveBinarySearch(arr, low, mid - 1, value);
        }
        else if (arr[mid] < value)
        {
            return RecursiveBinarySearch(arr, mid + 1, high, value);
        }
    }
}

// test your function in main
<<<<<<< HEAD

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int key;
    cout << "enter element you search for " << endl;
    cin >> key;
    cout << binarySearch(arr, 0, 4, key) << endl;
    cout << RBsearch(arr, 0, 4, key) << endl;
=======
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int key;

    cout << "Enter element you search for: ";
    cin >> key;

    // Test Sequential Search
    cout << "Sequential Search Result: " << sequentialSearch(arr, 5, key) << endl;

    // Test Recursive Sequential Search
    cout << "Recursive Sequential Search Result: " << recursiveSequentialSearch(arr, 5, 0, key) << endl;

    // Test Binary Search
    cout << "Binary Search Result: " << binarySearch(arr, 0, 4, key) << endl;

    // Test Recursive Binary Search
    cout << "Recursive Binary Search Result: " << RBsearch(arr, 0, 4, key) << endl;

>>>>>>> 17bfb569e2d3956a0ac01a4c45b6524509267dd2
    return 0;
}
