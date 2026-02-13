#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp

int main(){
    #pragma omp parallel 
    { // i. how to start & end my parallel block
    int i=0;
    
    i = omp_get_thread_num(); //ii. which thread is executing this
    printf("\n hello %d",i);
    printf(" world %d",i);
    }
    return 0;
}