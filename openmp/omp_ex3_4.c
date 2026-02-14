#include <stdio.h>
#include <omp.h>

int main()
{
    long counter = 0;
    long N = 1000000;
    double start = omp_get_wtime();
#pragma omp parallel for
    for (long i = 0; i < N; i++)
    {
        #pragma omp critical
        {
            counter += 1; // no reduction, direct update
        }
    }
    double end = omp_get_wtime();
    printf("Final counter without reduction= %ld\n", counter);
    printf("Execution time %f \n", (end-start));
    return 0;
}