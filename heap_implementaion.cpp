#include <iostream>
#include <vector>
using namespace std;



    // member 1 ->
    //  Implement methods for inserting an element and maintaining the heap property
    // (heapify).
    // Implement methods to extract the maximum and minimum from the heap.

class Heap {
private:
    vector<int> heap;

    void maxHeapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            maxHeapify(largest);
        }
    }

    void heapifyUp(int index) {
        if (index && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }

public:
    void insert(int element) {
        heap.push_back(element);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
           cout << "Heap is empty" << endl;
           return -1; // 
        }
        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0);
        return maxElement;
    }

    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return -1; // 
        }
        int minElement = heap[0];
        for (int i = 1; i < heap.size(); i++) {
            if (heap[i] < minElement)
                minElement = heap[i];
        }
        return minElement;
    }

    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
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
    for (int i = n-1; i >= 1; --i)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
int main() {
    Heap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(40);

  cout << "Heap elements: ";
    heap.display();

   cout << "Extracted Max: " << heap.extractMax() << endl;
   cout << "Heap after extracting max: ";
    heap.display();

  cout << "Minimum element in the heap: " << heap.extractMin() << sendl;

    return 0;
}
