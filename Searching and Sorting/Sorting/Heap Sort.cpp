#include <bits/stdc++.h>

void heapify(int *heap, int size) {
    int child = size-1;
    int parent = (child-1)/2;
    while(parent >= 0 && heap[parent] > heap[child]) {
        swap(heap[parent], heap[child]);
        child = parent;
        parent = (child-1)/2;
    }
}

void downHeapify(int *heap, int size) {
    int childIndex = 0;
    int leftChild = 1, rightChild = 2;
    while(leftChild < size) {
        int ans = min(heap[childIndex], heap[leftChild]);
        if(rightChild < size) {
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
}

void heapSort(int arr[], int n) {
    for(int i = 1;i < n;i++) {
        heapify(arr,i+1);
    }
    
    for(int i = 0;i < n-1;i++) {
        swap(arr[0], arr[n-1-i]);
        downHeapify(arr, n-i-1);
    }
}
