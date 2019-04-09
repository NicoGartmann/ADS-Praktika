#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <vector>
#include <omp.h>
#include "MyAlgorithms.h"
using namespace std;

int main(int argc, char** argv) {
	//***************
	// file streams *
	//***************
	ofstream matrixmul_colmajor_singlethread;

	matrixmul_colmajor_singlethread.open("matrixmul_colmajor_singlethread.txt", ios::out | ios::app);


	//********************
	//benchmark settings *
	//********************

	double dtime;
	int n_start = 1000;
	int n_start_matrix = 2; 
	int n_step_matrix = 1; 
	int n_end_matrix = 1800; 
	int n_step = 1000;
	int n_end = 1000000;
	int numThreads = 1; //only for matrix multiplication
	int num_procs = omp_get_num_procs();
	omp_set_num_threads(num_procs);

	//********************************************************************
	//data structures for sorting algorithms (int) and matrices (double) *
	//********************************************************************

	vector<int> array, temp_array;
	vector<double> A, B, C;


	//********************************************************
	//benchmark main loop (run only ONE algorithm at a time) *
	//********************************************************
#pragma omp parallel for 
	for (int n = n_start_matrix; n<n_end_matrix; n += n_step_matrix) {
	//cout << "n: " << n << endl;

	//***************************************
	//init data structure with random values*
	//***************************************

	//sorting algorithms
	//MyAlgorithms::randomizeArray(array, n);

	//matrix multiplication
	if (n>800) { n_step_matrix=11; }
	MyAlgorithms::randomizeMatrix(A,n);
	MyAlgorithms::randomizeMatrix(B,n);
	C.resize(n*n);

	//****************
	//  start clock  *
	//****************
	dtime = omp_get_wtime();

	//**********************
	//  execute algorithm  *
	//**********************
	MyAlgorithms::MatrixMul_ColMajor(A,B,C,n,numThreads);


	//***************
	//  stop clock  *
	//***************
	dtime = omp_get_wtime() - dtime;

	//*************************
	//  write results to file *
	//*************************
	matrixmul_colmajor_singlethread << n << "\t" << setprecision(10) << scientific << dtime << endl;

	}

	//**********************
	//  close file handles *
	//**********************

	matrixmul_colmajor_singlethread.close();
}
