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
		
		int pivot = arr[right]; 
		//int pivot = median(left, right, (right+left)/2); 
		int i = left - 1; 
		for (int j = left; j <= right - 1; j++) {
			if (arr[j] <= pivot) {
				i++; 
				swap(arr[i], arr[j]); 
				
			}
		}
		swap(arr[i + 1], arr[right]);
		return i + 1; 
	}

	int median(int left, int right, int middle) {
		int median; 
		if (middle>=left && middle < right) {
			median = middle; 
		}
		else if (left >= middle && left < right) {
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
	void Merge(vector<int> &a,vector<int> &b, int low, int pivot, int high) {
		int n1 = pivot - low + 1; 
		int n2 = high - pivot; 
		vector<int> L(n1 + 1);
		for (int i = 0; i < n1; i++) {
			L[i] = a[low + i]; 
		}
		vector<int> R(n2+1); 
		for (int j = 0; j < n2; j++) {
			R[j] = a[pivot + j+1]; 
		}
		int i = 1, j = 1, k = low; 
		while(i<n1&&j<n2){
			if (L[i] <= R[j]) {
				a[k] = L[i]; 
				i++; 
			}
			else {
				a[k] = R[j]; 
				j++; 
			}
			k++; 
		}

		while (i < n1) {
			a[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			a[k] = R[j];
			j++;
			k++;
		}
	}

	void MergeSort(vector<int> &a,vector<int> &b, int low, int high) {
		if (low < high) {
			int q = (low + high) / 2; 
			MergeSort(a,b, low, q); 
			MergeSort(a,b, q + 1, high);
			Merge(a,b, low, q, high); 
		}
	}



	//************
	// Heapsort  *
	//************

	void HeapSort(vector<int> &a, int n) {
		int i = n / 2; 
		while (i >= 0) {
			percDown(a, i, n);
			i--; 
		}
		int j = n - 1; 
		while (j > 0) {
			swap(a[0], a[j]); 
			percDown(a, 0, j); 
			j--; 
		}
	}

	int leftChild(int i) {
		return 2 * i + 1; 
	}

	void percDown(vector<int> &a, int p, int r) {
		int child = p; 
		int tmp = a[p]; 
		int j = p; 
		while (leftChild(j) < r) {
			child = leftChild(j);
			if ((child != r - 1) && (a[child] > a[child + 1])) {
				child++; 
			}
			if (tmp > a[child]) {
				swap(a[j], a[child]); 
				j = child; 
			}
			else break; 
		}
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





