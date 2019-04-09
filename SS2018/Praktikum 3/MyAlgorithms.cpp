#include "MyAlgorithms.h"
#include <omp.h>

namespace MyAlgorithms {

	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int> &arr, int left, int right)
	{
		if (left < right)
		{
			int q = partition(arr, left, right);
			QuickSort(arr, left, q - 1);
			QuickSort(arr, q + 1, right);
		}
	}

	int partition(vector<int> &arr, int left, int right)
	{
		//int x = median(arr[0],int(arr[(arr.size() - 1) / 2]), arr[arr.size()-1]); 
		int x = arr[right];
		int i = left - 1;
		for (int j = left; j <= right - 1; j++)
		{
			if (arr[j] <= x)
			{
				i = i + 1;
				swap(arr[i], arr[j]);
			}

		}
		swap(arr[i + 1], arr[right]);
		return i + 1;
	}

	int median(int left, int middle, int right)
	{
		if ((left > middle && left < right) || (left < middle && left > right)) return left;
		else if ((middle > left && middle < right) || (middle < left && middle > right))return middle;
		else return right;
	}

	//************
	// MergeSort *
	//************
	void MergeSort(vector<int> &a, int low, int high)
	{
		int q; 
		if (low < high)
		{
			q = int((low + high) / 2);
			MergeSort(a, low, q);
			MergeSort(a, q + 1, high);
			Merge(a, low, q, high);
		}
	}

	void Merge(vector<int>&a, int low, int pivot, int high)
	{
		int n1 = pivot - low + 1;
		int n2 = high - pivot;
		vector <int>L(n1+1);
		vector <int>R(n2+1);
		for (int i = 0; i < n1; i++)
		{
			L[i] = a[low + i];
		}
		for (int j = 0; j < n2; j++)
		{
			R[j] = a[pivot + j+1];
		}
		int i = 0; // Initial index of first subarray
		int j = 0; // Initial index of second subarray
		int k = low; // Initial index of merged subarray
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				a[k] = L[i];
				i++;
			}
			else
			{
				a[k] = R[j];
				j++;
			}
			k++;
		}

		/* Copy the remaining elements of L[], if there
		are any */
		while (i < n1)
		{
			a[k] = L[i];
			i++;
			k++;
		}

		/* Copy the remaining elements of R[], if there
		are any */
		while (j < n2)
		{
			a[k] = R[j];
			j++;
			k++;
		}

	}

	//************
	// Heapsort  *
	//************

	void HeapSort(vector<int> &a)
	{
		int n = a.size();
		int i = n / 2;
		while (i >= 0)
		{
			percDown(a, i, n);
			i = i - 1;
		}
		int j = n - 1;
		while (j > 0)
		{
			swap(a[0], a[j]);
			percDown(a, 0, j);
			j = j - 1;
		}
	}

	void percDown(vector<int>&a, int p, int n)
	{
		int child = p;
		int tmp = a[p];
		int j = p;
		while (leftChild(j) < n)
		{
			child = leftChild(j);
			if ((child != (n - 1)) && (a[child] > a[child + 1]))
				child = child + 1;
			if (tmp > a[child])
			{
				swap(a[j], a[child]);
				j = child;
			}
			else break;
		}
	}

	int leftChild(int i)
	{
		return 2 * i + 1; 
	}

	//************
	// Shellsort *
	//************
	void ShellSort(vector<int> &a, int n)
	{
		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i++)
			{
				int tmp = a[i];
				int j = i;
				for (; j >= gap&&tmp < a[j - gap]; j -= gap)
				{
					a[j] = a[j - gap];
				}
				a[j] = tmp;
			}
		}
	}

	//************************************
	//Matrix Multiplication Column Major *
	//************************************

	void MatrixMul_ColMajor(vector<double> &A, vector<double> &B, vector<double> &C, int n, int numThreads)
	{
		int num_procs = omp_get_num_procs();
		omp_set_num_threads(num_procs);

		//lda, ldb, ldc are leading dimensions of matrices A,B and C
		int lda = n;
		int ldb = n;
		int ldc = n;
		double s = 0.0;

#pragma omp parallel for
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				s = 0.0;
				for (int k = 0; k<n; k++) {
					s = s + A[i + k*lda] * B[k + j*ldb];
				}
				C[i + j*ldc] = s;
			}
		}
	}

	//*********************************
	//Matrix Multiplication Row Major *
	//*********************************

	void MatrixMul_RowMajor(vector<double> &A, vector<double> &B, vector<double> &C, int n, int numThreads)
	{
		int num_procs = omp_get_num_procs(); 
		omp_set_num_threads(num_procs);

		int lda = n;
		int ldb = n;
		int ldc = n;
		double s = 0.0;

#pragma omp parallel for
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				s = 0.0;
				for (int k = 0; k < n; k++)
				{
					s = s + A[i*lda + k] * B[k*ldb + j];
				}
				C[i*ldc + j] = s;
			}
		}

	}

	//********************
	// helper functions  *
	//********************
	double fRand(double fMin, double fMax)
	{
		double f = (double)rand() / RAND_MAX;
		return fMin + f * (fMax - fMin);
	}

	void randomizeMatrix(vector<double> &matrix, int n)
	{
		matrix.resize(n*n);
		int i;
		for (i = 0; i<matrix.size(); i++)
			matrix[i] = fRand(-1000, 1000);
	}

	void randomizeArray(vector<int> &array, int n)
	{
		array.resize(n);

		for (int i = 0; i<array.size(); i++)
			array[i] = rand() % 1000000;
	}
}
