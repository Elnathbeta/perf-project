/*
 * Compute exp(x) using a power series.
 * exp(x) = sum from n=0 to infinity of x^n / n!
 * The computation is distributed using omp.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

long double termOfSeries(double x, int n)
{
	long double result = 1;
	for(int i = 1; i <= n; ++i)
	{
		result *= x / (long double)i;
	}
	return result;
}

int main(int argc, char** argv)
{
	if (argc < 4)
	{
		fprintf(stderr, "Usage: %s nthreads x iterations\n", argv[0]);
		exit(1);
	}
	omp_set_num_threads(atol(argv[1]));
	const double X = atof(argv[2]);
	const int ITERATIONS = atol(argv[3]);
	
	//printf("Computing exp(%lf) with %d iterations...\n", X, ITERATIONS);
	
	long double result = 0;
	#pragma omp parallel for reduction (+:result)
	for(int i = 0; i < ITERATIONS; ++i)
	{
		result += termOfSeries(X, i);
	}
	
	printf("I think that exp(%lf) = %.30Lf\n", X, result);
	printf("Diff with math.h exponential: %.30Lf\n", result - exp(X));
}
