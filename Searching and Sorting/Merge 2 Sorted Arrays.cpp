void merge(int arr1[], int size1, int arr2[], int size2, int ans[])
{

    int i = 0, j = 0;

    int index = 0;
    while(i < size1 && j < size2) {
        if(arr1[i] < arr2[j]) {
            ans[index++] = arr1[i++];
        }else{
            ans[index++] = arr2[j++];
        }
    }

    while(i < size1) {
        ans[index++] = arr1[i++];
    }

    while(j < size2) {
        ans[index++] = arr2[j++];
    }

}

