#include <iostream>
using namespace std;

class MaxHeap {
private:
    int arr[100];
    int size;

public:
    MaxHeap() {
        arr[0] = -1; // Dummy value for 1-based indexing
        size = 0;
    }

    void insert(int element) {
        size++;
        int index = size;
        arr[index] = element;

        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        // Move the last element to the root and reduce the size
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            int largest = i;

            if (leftIndex <= size && arr[largest] < arr[leftIndex]) {
                largest = leftIndex;
            }

            if (rightIndex <= size && arr[largest] < arr[rightIndex]) {
                largest = rightIndex;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    void display() {
        for (int i = 1; i <= size; i++) { // Iterate up to size inclusively
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[],int n,int i){

    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left < n && arr[largest] < arr[left]){
        largest=left;
    }
    if(right < n &&  arr[largest]<arr[right]){
        largest=right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main() {
    MaxHeap maxHeap;

    // Inserting elements into the max heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(50);

    cout << "Max Heap: ";
    maxHeap.display();

    // Deleting the root of the max heap
    maxHeap.deleteFromHeap();

    cout << "Max Heap after deleting the root: ";
    maxHeap.display();

    
 // int arr[6]= {-1,54,53,55,52,50};
    // int n=5;
    // for(int i=n/2;i>0;i--){
    //     heapify(arr,n,i);
    // }
    // cout<<"printing the array now: "<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}

