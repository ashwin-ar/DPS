#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp

#define N 1000000 // ONE MILLION

int main()
{
    int counter = 0; 
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("\n how many threads are execcuting this? = %d\n",omp_get_num_threads());
        }
        #pragma omp for reduction( +: counter)
        for (int i = 0; i < N-1; i++)
        {
            counter = counter+1;
        }
    }
    printf("%d",counter);
    // code
    double end = omp_get_wtime();
    printf("\n2. Time: %f seconds", (double)(end - start));
    return 0;
}