#include "GS.hpp"

std::vector<double> GSM(const CSR &A, const std::vector<double> &x_0, const std::vector<double> &b, const double tolerance) {
	const int N = size(x_0);
	std::vector<double> x = x_0, x_last(N, 100), diag(N);
	double counter, row_begin, row_end;

	diag = A.getDiag();

	while (first_norm(x - x_last) > tolerance) {
		x_last = x;
		x = TopDownIteration(A, diag, b, x);
	}
	
    return x;
}