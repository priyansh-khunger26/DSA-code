#include <bits/stdc++.h>

int partitionArray(int input[], int start, int end) {
	int pivot = start + rand() % (end - start);
	swap(input[pivot], input[end]);

	pivot = end;

	int helper = start;
	for(int i = start;i < end;i++) {
		if(input[i] < input[pivot]) {
			swap(input[i], input[helper++]);
		}
	}

	swap(input[helper], input[pivot]);

	return helper;
}

void quickSort(int input[], int start, int end) {
	if(start >= end) {
		return;
	}

	int pivot = partitionArray(input, start, end);
	quickSort(input, start, pivot-1);
	quickSort(input, pivot+1, end);
}
