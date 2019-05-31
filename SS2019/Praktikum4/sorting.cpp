#include "sorting.h"


namespace sorting {

	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int> &arr, int left, int right) {
		if (left < right) {
			int q = partition(arr, left, right); 
			QuickSort(arr, left, q - 1); 
			QuickSort(arr, q + 1, right); 
		}
	}

	int partition(vector<int> &arr, int left, int right) {
		int pivot = median(left, right, left / right); 
		int i = left - 1; 
		for (int j = right; j < right - 1; j++) {
			if (arr[j] <= pivot) {
				i++; 
				swap(arr[i], arr[j]); 
				
			}
			swap(arr[i+1],arr[right]);
		}
		return i + 1; 
	}

	int median(int left, int right, int middle) {
		int median; 
		if (left<=middle && middle >right) {
			median = middle; 
		}
		else if (left > middle && left <= right) {
			median = left; 
		}
		else {
			median = right; 
		}
		return median; 
	}
	//************
	// MergeSort *
	//************
	void Merge(vector<int> &a, vector<int> &b, int low, int pivot, int high) {

	}

	void MergeSort(vector<int> &a, vector<int> &b, int low, int high) {

	}



	//************
	// Heapsort  *
	//************

	void HeapSort(vector<int> &a, int n) {

	}



	//************
	// Shellsort *
	//************
	void ShellSort(vector<int> &a, int n) {

		for (int gap = n / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < n; i++) {
				int tmp = a[i]; 
				int j = i; 
				for (; j >= gap && tmp < a[j - gap]; j -= gap) {
					a[j] = a[j - gap]; 
				}
				a[j] = tmp; 
			}
		}
	}


	void randomizeVector(vector<int> &array, int n) {
		array.resize(n);

		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = rand() % 1000000;
	}


}





