#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp

int main(){
    /* Comments:
      i. how to start & end my parallel block  
      ii. which thread is executing this
      iii. Creating 'x' no of threads.
        a. method 1 - using a function above pragma - omp_set_num_threads
        b. method 2 - using a construct num_threads in pragma statement
        anything can be used. if both used then construct is used.
        
        note: Only 0-to xcores will execute this; x canbe any number
        note: without using this by default it was 16 threads, when we just used pragma omp parallel 
    */
    omp_set_num_threads(30); /// iii
    #pragma omp parallel num_threads(20) // iii
    {// i
    int i=0;
    
    i = omp_get_thread_num(); //ii
    printf("\n hello %d",i);
    printf(" world %d",i);
    }
    return 0;
}