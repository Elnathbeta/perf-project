/*
 * Compute exp(x) using a power series.
 * exp(x) = sum from n=0 to infinity of x^n / n!
 * The computation is distributed among different machines
 */
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

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
	MPI_Init(&argc, &argv);

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s x iterations\n", argv[0]);
		exit(1);
	}
	const double X = atof(argv[1]);
	const int ITERATIONS = atol(argv[2]);
	int totProc, curProc;
	
	MPI_Comm_size(MPI_COMM_WORLD, &totProc);
	MPI_Comm_rank(MPI_COMM_WORLD, &curProc);
	
	// Computing which process will do which part of the series.
	// Last process will do more computations if it isn't divisible.
	int start = ITERATIONS/totProc * curProc;
	int end = (ITERATIONS/totProc * (curProc + 1)) -1;
	if (curProc == totProc -1)
	{
		end += (ITERATIONS % totProc);
	}
	
	printf("Process %d: computing terms %d to %d\n", curProc, start, end);
	
	long double result = 0;
	for(int i = start; i <= end; ++i)
	{
		result += termOfSeries(X, i);
	}
	
	if(curProc == 0)
	{
		long double partialResult[totProc];
		MPI_Gather(NULL, 0, MPI_BYTE, partialResult, 1, MPI_LONG_DOUBLE, 0, MPI_COMM_WORLD);
		for(int i = 1; i < totProc; ++i)
		{
			result += partialResult[i];
		}
		printf("I think that exp(%lf) = %.30Lf\n", X, result);
		printf("Diff with math.h exponential: %.30Lf\n", result - exp(X));
	}
	else
	{
		MPI_Gather(&result, 1, MPI_LONG_DOUBLE, NULL, 0, MPI_BYTE, 0, MPI_COMM_WORLD);
	}
	
	MPI_Finalize();
	return EXIT_SUCCESS;
}
