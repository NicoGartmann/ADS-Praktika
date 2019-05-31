#include "sorting.h"


namespace sorting {

	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int> &arr, int left, int right) {

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





