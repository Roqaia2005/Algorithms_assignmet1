#include <iostream>
using namespace std;

class Heap
{

    // member 1 ->
    //  Implement methods for inserting an element and maintaining the heap property
    // (heapify).
    // Implement methods to extract the maximum and minimum from the heap.
};

// member 2 ->
// Use the heap implementation (from step 1) to build a priority queue.
// Define methods for inserting an element with a priority and extracting the highest priority element.
// Ensure the insertion maintains the heap property.

// member 3 -> //Implement Heap Sort:
//  Utilize your heap implementation to sort an array.
// Build a max heap from the array and repeatedly extract the max element from the
// heap and rebuild it until the array is sorted.

void heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && v[left] > v[largest])
    {
        largest = left;
    }
    if (right < n && v[right] > v[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void BuildMaxHeap(vector<int> &v)
{
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(v, n, i);
    }
}

void heapsort(vector<int> &v)
{
    int n = v.size();
    BuildMaxHeap(v);
    for (int i = n - 1; i >= 1; --i)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main()
{

    return 0;
}
