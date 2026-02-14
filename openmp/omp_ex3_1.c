#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp

#define N 1000000 // ONE MILLION

int main()
{
    int counter = 0; 
    double start = omp_get_wtime();
    for (int i = 0; i < N-1; i++)
    {
        counter++;
    } 
    printf("%d",counter);

    // code
    double end = omp_get_wtime();
    printf("\n1. Time: %f seconds", (double)(end - start));
    return 0;
}