#include <iostream>
#include <vector>
using namespace std;
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
class PriorityQueue {
private:
    Heap heap;

public:
    // Insert with priority
    void insertWithPriority(int value) {
        heap.insert(value);
    }

    // Extract the element with the highest priority (max in this case)
    int extractHighestPriority() {
        return heap.extractMax();
    }

   
};



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
    PriorityQueue pq;
    pq.insertWithPriority(20);
    pq.insertWithPriority(30);
    pq.insertWithPriority(40);
    pq.insertWithPriority(50);

    cout<<pq.extractHighestPriority()<<endl;

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

  cout << "Minimum element in the heap: " << heap.extractMin() << endl;

    return 0;
}
