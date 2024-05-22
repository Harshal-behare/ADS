#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        if (l < heap.size() && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }

        int r = rightChild(i);
        if (r < heap.size() && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void display() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(30);
    maxHeap.insert(25);
    maxHeap.insert(35);
    maxHeap.insert(40);
    maxHeap.insert(15);

    cout << "Max-Heap: ";
    maxHeap.display();

    return 0;
}
