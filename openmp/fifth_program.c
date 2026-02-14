// to understand constructs

#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp
#include <unistd.h>

int main()
{
#pragma omp parallel num_threads(5)
    {
#pragma omp single
        { // used for - initialization - reading input - printing once - allocating shared data
            printf("\n one thread runs it, others will run other parts \n");

            printf("\n this } is a barrier, all threads wait for single thread to complete");
        }
        printf("\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d ", i);
        }
    }

    printf("\n___________________\n");

#pragma omp parallel num_threads(5)
    {
#pragma omp for
        for (int i = 0; i < 3; i++)
        {
            printf("%d ", i);
        }
    }

    printf("\n___________________\n");

#pragma omp parallel num_threads(5)
    {
        #pragma omp sections
        {
        #pragma omp section
            for (int i = 0; i < 3; i++)
            {
                printf("a");
            }
        #pragma omp section
            for (int i = 0; i < 3; i++)
            {
                printf("b");
            }
        }
    }
    return 0;
}