#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int cntr = 0;// global variables are 0 by default,but for safety init. it into 0

void* counter(void* arg){
    cntr = 0;
    int* time = (int*) arg; // Casting void* to int*
    printf("\n Loop %d", *time);
    for(int i=0;i< *time; i++){
        cntr++;
        printf(" %d", cntr);

    }
}

void main(){

    pthread_t thread[3]; // I need 3 threads, each counting certain time

    int totalTime[] = {10,20,30};   // in seconds

    void* (*fp_cntr)(void*);
    fp_cntr = counter;
    pthread_create(thread+0, NULL, fp_cntr,(void*) (totalTime+0));
    pthread_create(thread+1, NULL, fp_cntr,(void*) (totalTime+1));
    pthread_create(thread+2, NULL, fp_cntr,(void*) (totalTime+2));

    for(int i=0;i < 3;i++){
        pthread_join(thread[i], NULL);
    }

}