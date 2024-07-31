#include <bits/stdc++.h>

void insertionSort(int arr[], int n)
{
    //write your code here
    for(int i = 1;i < n;i++) {
        for(int j = i; j > 0;j--) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }else{
                break;
            }
        }
    }
}
