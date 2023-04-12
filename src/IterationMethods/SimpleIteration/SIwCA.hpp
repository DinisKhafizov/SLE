#ifndef SIMPLE_ITERATION_METH_WITH_CHEB_ACCEL
#define SIMPLE_ITERATION_METH_WITH_CHEB_ACCEL

#include <iostream>
#include <vector>
#include"Matrixes/CSR/MatrixOnCSR.hpp"
#include "Vect/VectorOperations.hpp"
#include "Acceleration/Cheb_Accel.hpp"

std::vector<double> SIMwCA(const CSR &A, const std::vector<double> &x_0, const std::vector<double> &b, const double tolerance, const double lambda_min, 
const double lambda_max, const int n) {

	std::vector<int> nums = Numbers(n);
	std::vector<double> taus = TauFromCheb(n, lambda_min, lambda_max);
	int N = size(x_0); 
	double norm = 0; 
	std::vector<double> x = x_0;
    std::vector<double> r = A*x - b;

	for (int i = 0; i < pow(2, n); ++i) {
		x = x - taus[nums[i]] * r;
        r = A * x - b;
		norm = first_norm(r);
	}

	if (norm > tolerance) {
		return SIMwCA(A, x, b, tolerance, lambda_min, lambda_max, n);
	}
	else {
		return x;
	}

}

#endif