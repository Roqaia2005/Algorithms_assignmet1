#include <iostream>
#include <vector>
using namespace std;
class Heap {
private:
    vector<int> heap;
    public:

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

void heapsort()
{
    vector<int>v;
    int n = v.size();
    BuildMaxHeap(v);
    for (int i = n-1; i >= 1; --i)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


    void insert(int element) {
        heap.push_back(element);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
           cout << "Heap is empty" << endl;
           return -1; 
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
            return -1; 
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
class PriorityQueue:Heap {
private:
    vector<pair<int,int>>pq;

public:
   
    void insert(int value,int priority) {
        pq.push_back(make_pair(priority, value));
        heapifyUp(pq.size() - 1);
        
    }

    
    int extractHighestPriority() {
        return Heap:: extractMax();
    }
  

   
};

int main(){
    Heap h;
    h.insert(1);
    h.insert(4);
    h.insert(2);
    h.insert(5);

    h.display();

    h.heapsort();
    h.display();

    PriorityQueue pq;

    pq.insert(5, 1);
    pq.insert(4, 2);
    pq.insert(2, 0);
    pq.insert(6, 4);
    pq.insert(1, 3);

   cout<< pq.extractHighestPriority();
}




