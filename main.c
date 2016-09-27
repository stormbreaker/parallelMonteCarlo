#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// #include <iomanip>
// #include <iostream>

// using namespace std;

int main()
{
    double x;
    double y;
    int NUMBEROFDARTS = 500;
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

    piEstimate = 4 * (double) dartsInCircle/NUMBEROFDARTS;

    printf("Estimate: %f with %d points of estimation\n", piEstimate, NUMBEROFDARTS);
    printf("Actual: %f\n", M_PI);

    return 0;
}
