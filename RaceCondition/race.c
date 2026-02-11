/* Output without using mutex
 Loop 0
 Loop 1 0 1
 Loop 2 10 20 11 12 13 21 2 3 4 14 15 22 23 5 6 16 17 18 7 8 24 25 19 26 9 27 28 29
*/

/* Output with mutex
 Loop 0 0 1 2 3 4 5 6 7 8 9
 Loop 1 10 11 12 13 14 15 16 17 18 19
 Loop 2 20 21 22 23 24 25 26 27 28 29*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock; //creating a mutex lock

struct data{
    int id;
    int totalTime;
};

// typedef of structure is simple. Think whatever in between as one line
// So whatever in between typedef & ; is called with the last variable name

// typedef struct data{int id;int totalTime;} frame;

void* counter(void* arg){
    pthread_mutex_lock(&lock);

    struct data* currentData = (struct data*) arg; // Casting void* to int*
    printf("\n Loop %d", currentData->id);
    for(int i= (currentData->id)*10 ;i< (currentData -> totalTime); i++){
        printf(" %d", i);
    }
    
    //pthread_exit(NULL);
    pthread_mutex_unlock(&lock);
}

void main(){

    pthread_t thread[3]; // I need 3 threads, each counting certain time

    struct data dataFrame[3] = {{0,10}, {1,20}, {2,30}};

    void* (*fp_cntr)(void*);
    fp_cntr = counter;

    pthread_mutex_init(&lock, NULL);

    pthread_create(thread+0, NULL, fp_cntr,(void*) (dataFrame+0));
    pthread_create(thread+1, NULL, fp_cntr,(void*) (dataFrame+1));
    pthread_create(thread+2, NULL, fp_cntr,(void*) (dataFrame+2));

    /*for(int i=0;i < 3;i++){
        pthread_join(thread[i], NULLa);
    }*/

    pthread_mutex_destroy(&lock);
}