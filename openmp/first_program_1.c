#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp

int main(){
    /*  iii. Creating 'x' no of threads
        a. method 1 - using a function above pragma - omp_set_num_threads
        b. method 2 - using a construct num_threads in pragma statement
        
        note: without using this by default it was 16 threads, when we just used pragma omp parallel 
    */
    omp_set_num_threads(30); // iii. Only 0-to xcores will execute this; x canbe any number
    #pragma omp parallel num_threads(20) // iii. either this or omp_set_num_threads can be used
    { // i. how to start & end my parallel block
    int i=0;
    
    i = omp_get_thread_num(); //ii. which thread is executing this
    printf("\n hello %d",i);
    printf(" world %d",i);
    }
    return 0;
}