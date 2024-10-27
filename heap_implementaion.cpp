#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Heap {
protected:
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

    
    
    void heapify(vector<int> &v, int n, int i){
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
        //vector<int>v = heap;
        int n = heap.size();
        BuildMaxHeap(heap);
        for (int i = n-1; i > 0; --i)
        {
            swap(heap[0], heap[i]);
            heapify(heap, i, 0);
        }
        cout << "Sorted Data is: ";
        for(int item : heap) {
            cout << item << " ";
        }
        cout << endl;
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


class PriorityQueue {
private:
    Heap heap;

public:
    void insertWithPriority(int value, int priority) {
        heap.insert(value);
    }

    int extractHighestPriority() {
        return heap.extractMax();
    }

    void display() {
        heap.display();
    }
};


int main(){
    Heap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(40);

    cout << "Heap elements: ";
    heap.heapsort();
    heap.display();

   cout << "Extracted Max: " << heap.extractMax() << endl;
   cout << "Heap after extracting max: ";
    heap.display();

    cout << "Minimum element in the heap: " << heap.extractMin() << endl;


    PriorityQueue pq;
    pq.insertWithPriority(5, 1);
    pq.insertWithPriority(4, 2);
    pq.insertWithPriority(3, 4);
    pq.insertWithPriority(7, 6);


   

    cout << "Priority Queue elements: ";
    pq.display();

    int highestPriorityElement = pq.extractHighestPriority();
    cout << "Highest priority element: " << highestPriorityElement << endl;
    cout << "Priority Queue after extraction: ";
    pq.display();

    return 0;


   

}




// another implementation of heap class and priority queue with using pair 

// #include <iostream>
// #include <vector>
// #include <utility>
// using namespace std;

// class Heap {
// protected:
//     vector<pair<int, int>> heap;

// public:
    
//     void maxHeapify(int index) {
//         int largest = index;
//         int left = 2 * index + 1;
//         int right = 2 * index + 2;

        
//         if (left < heap.size() && heap[left].second > heap[largest].second)
//             largest = left;

//         if (right < heap.size() && heap[right].second > heap[largest].second)
//             largest = right;

//         if (largest != index) {
//             swap(heap[index], heap[largest]);
//             maxHeapify(largest);
//         }
//     }

  
//     void heapifyUp(int index) {
//         if (index && heap[(index - 1) / 2].second < heap[index].second) {
//             swap(heap[index], heap[(index - 1) / 2]);
//             heapifyUp((index - 1) / 2);
//         }
//     }

    
//     void insert(pair<int, int> element) {
//         heap.push_back(element);
//         heapifyUp(heap.size() - 1);
//     }

  
//     pair<int, int> extractMax() {
//         if (heap.empty()) {
//             cout << "Heap is empty" << endl;
//             return {-1, -1}; 
//         }
//         pair<int, int> maxElement = heap[0];
//         heap[0] = heap.back();
//         heap.pop_back();
//         maxHeapify(0);
//         return maxElement;
//     }

//     void display() {
//         for (const auto &val : heap) {
//             cout << "(" << val.first << ", " << val.second << ") ";
//         }
//         cout << endl;
//     }
//      void buildMaxHeap() {
//         for (int i = heap.size() / 2 - 1; i >= 0; --i) {
//             maxHeapify(i);
//         }
//     }

//     vector<pair<int, int>> heapSort() {
//         buildMaxHeap();
//         vector<pair<int, int>> sorted;

//         for (int i = heap.size() - 1; i >= 0; --i) {
//             sorted.push_back(heap[0]);
//             swap(heap[0], heap[i]); 
//             maxHeapify(0); 
//         }
        
        
//         reverse(sorted.begin(), sorted.end());
//         return sorted;
//     }
    
// };

// class PriorityQueue {
// private:
//     Heap heap;

// public:
   
//     void insertWithPriority(int value, int priority) {
//         heap.insert({value, priority});
//     }

   
//     pair<int, int> extractHighestPriority() {
//         return heap.extractMax();
//     }

   
//     void display() {
//         heap.display();
//     }
// };

// int main() {
//     Heap heap;

    
//     heap.insert({5, 1});
//     heap.insert({4, 2});
//     heap.insert({3, 4});
//     heap.insert({7, 6});

//     cout << "Heap elements (value, priority): ";
//     heap.display();

//     auto highestPriorityElementh = heap.extractMax();
//     cout << "Highest priority element extracted: (" << highestPriorityElementh.first << ", " << highestPriorityElementh.second << ")" << endl;

//     cout << "Heap after extraction: ";
//     heap.display();

//     // Perform heap sort
//     vector<pair<int, int>> sortedElements = heap.heapSort();
//     cout << "Sorted elements (value, priority): ";
//     for (const auto &element : sortedElements) {
//         cout << "(" << element.first << ", " << element.second << ") ";
//     }
//     cout << endl;

//     return 0;
 
    
//     PriorityQueue pq;

    
//     pq.insertWithPriority(5, 1);
//     pq.insertWithPriority(4, 2);
//     pq.insertWithPriority(3, 4);
//     pq.insertWithPriority(7, 6);

//     cout << "Priority Queue elements (value, priority): ";
//     pq.display();

//     auto highestPriorityElement = pq.extractHighestPriority();
//     cout << "Highest priority element: (" << highestPriorityElement.first << ", " << highestPriorityElement.second << ")" << endl;

//     cout << "Priority Queue after extraction: ";
//     pq.display();

//     return 0;
// }


