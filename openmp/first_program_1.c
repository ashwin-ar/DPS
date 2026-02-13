#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp
#include <unistd.h>

int main()
{
    int i = 0, sum1 = 0; // iv

    /* Comments:
      i. how to start & end my parallel block
      ii. which thread is executing this
      iii. Creating 'x' no of threads.
        a. method 1 - using a function above pragma - omp_set_num_threads
        b. method 2 - using a clause num_threads in pragma statement
        anything can be used. if both used then construct is used.

        note: Only 0-to x cores will execute this; x can be any number
        note: without using this by default it was 16 threads, when we just used pragma omp parallel
      iv. private & shared variable. 
    */
    omp_set_num_threads(30);         /// iii
    printf("\n Begin fork - before the fork block ");
    #pragma omp parallel num_threads(5) // iii
    {                                // i
        int sum2 = 0;                // iv
        i = omp_get_thread_num();    // ii
        sum1 += i;
        sum2 += i;
        printf("\n hello world %d, sum1=%d, sum2=%d", i, sum1, sum2);
    }
    printf("\n all done - executes only when everything is joined");
    return 0;
}