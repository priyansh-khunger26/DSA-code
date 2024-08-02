#include <bits/stdc++.h>

void merge(int *arr, int l, int mid, int r) {
    int *helper = new int [r-l+1];
    int index = 0;

    int i = l,j = mid+1;
    while(i <= mid && j <= r) {
        if(arr[i] < arr[j]) {
            helper[index++]= arr[i++];
        }else{
            helper[index++] = arr[j++];
        }
    }

    while(i <= mid) {
        helper[index++]= arr[i++];
    }

    while(j <= r) {
        helper[index++] = arr[j++];
    }

    for(int i = 0;i < index;i++) {
        arr[l++] = helper[i];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l >= r) {
        return;
    }

    int mid = (l + r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l,mid,r);
}
