#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
// #include <iomanip>
// #include <iostream>

// using namespace std;
void serialEstimate();
void parallelEstimate();

const unsigned int NUMBEROFDARTS = 500000000;

int main()
{
    double x;
    double y;
    double piEstimate;

	double parallelPiEstimate;

    srand(0);


	serialEstimate();

	parallelEstimate();

    return 0;
}

void serialEstimate()
{
	double x;
	double y;
	
	double piEstimate;

	srand(0);

	int dartsInCircle = 0;

	for (int i = 0; i < NUMBEROFDARTS; i++)
	{
		x = ((double) rand() / (RAND_MAX));
		y = ((double) rand() / (RAND_MAX));

		if ((x * x + y * y) < 1)
		{
			dartsInCircle++;
		}
	}

	printf("Number in circle: %d\n", dartsInCircle);
	piEstimate = 4 * (double) dartsInCircle / NUMBEROFDARTS;

	printf("Estimate: %f with %d points of estimation in serial\n", piEstimate, NUMBEROFDARTS);

	printf("Actual: %f\n", M_PI);
}

void parallelEstimate()
{
	double x;
	double y;
	
	double piEstimate;

	srand(0);

	int dartsInCircle = 0;

	int thread_count = omp_get_num_procs();

	# pragma omp parallel for num_threads(thread_count)
	for (int i = 0; i < NUMBEROFDARTS; i++)
	{
		x = ((double) rand() / (RAND_MAX));
		y = ((double) rand() / (RAND_MAX));

		if ((x * x + y * y) < 1)
		{
			dartsInCircle++;
			//printf("%d\n", omp_get_thread_num());
		}
	}

	printf("Number in circle: %d\n", dartsInCircle);
	piEstimate = 4 * (double) dartsInCircle / NUMBEROFDARTS;

	printf("Estimate: %f with %d points of estimation in parallel\n", piEstimate, NUMBEROFDARTS);

	printf("Actual: %f\n", M_PI);
}
