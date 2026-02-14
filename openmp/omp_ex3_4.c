#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    long counter = 0;
    long N = 1000000;
    double start = clock();
    for (long i = 0; i < N; i++)
    {
        {
            counter += 1; // no reduction, direct update
        }
    }
    double end = clock();
    printf("Final counter without reduction= %ld\n", counter);
    printf("Execution time %f \n", (end-start)/ CLOCKS_PER_SEC);
    return 0;
}