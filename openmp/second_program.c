#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp
#include <unistd.h>

int main()
{
#pragma omp parallel num_threads(3) // each thread executes all the loops completely. 3*10 = 30
    for (int i = 0; i < 10; i++)
    {
        int t = omp_get_thread_num();
        printf("\n thread %d executes %d", t, i);
    }
    printf("\n___________________");
#pragma omp parallel for num_threads(3) // loop is split only 10 loops. loops are divided among all the threads.
    for (int i = 0; i < 10; i++)
    {
        int t = omp_get_thread_num();
        printf("\n thread %d executes %d", t, i);
    }
    printf("\n___________________");
    printf("\n___________________");

// exploring private clause
#pragma omp parallel num_threads(5)
    {
        int i = 0;
        i++;
        printf("\t %d", i);
    }

    return 0;
}