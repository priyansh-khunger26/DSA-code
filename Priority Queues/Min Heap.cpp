#include <bits/stdc++.h>

class MinHeap{
    vector<int> heap;

    public:
    int size() {
        return heap.size();
    }

    bool empty() {
        return heap.size() == 0;
    }

    void insert(int num) {
        heap.push_back(num);
        int child = heap.size()-1;
        int parent = (child-1)/2;
        while(parent >= 0 && heap[parent] > heap[child]) {
            swap(heap[parent], heap[child]);
            child = parent;
            parent = (child-1)/2;
        }
    }

    int getMin() {
        if(heap.size() == 0) {
            return -1;
        }

        return heap[0];
    }

    int removeMin() {
        int size = heap.size();
        if(size == 0) {
            return -1;
        }

        int temp = heap[0];
        swap(heap[0], heap[size-1]);
        heap.pop_back();

        int childIndex = 0;
        int leftChild = 1, rightChild = 2;
        while(leftChild < heap.size()) {
            int ans = min(heap[childIndex], heap[leftChild]);
            if(rightChild < heap.size()) {
                ans= min(ans, heap[rightChild]);
            }

            if(ans == heap[childIndex]) {
                break;
            }

            if(ans == heap[leftChild]) {
                swap(heap[childIndex], heap[leftChild]);
                childIndex = leftChild;
                leftChild = 2*childIndex+1;
                rightChild = leftChild+1;
            }else{
                swap(heap[childIndex], heap[rightChild]);
                childIndex = rightChild;
                leftChild = 2*childIndex+1;
                rightChild = leftChild+1;
            }
        }

        return temp;
    }

    void print() {
        for(int i = 0;i < heap.size();i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
