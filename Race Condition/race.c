/* Output without using mutex
 Loop 0
 Loop 1 0 1
 Loop 2 10 20 11 12 13 21 2 3 4 14 15 22 23 5 6 16 17 18 7 8 24 25 19 26 9 27 28 29
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct data{
    int id;
    int totalTime;
};

// typedef of structure is simple. Think whatever in between as one line
// So whatever in between typedef & ; is called with the last variable name

// typedef struct data{int id;int totalTime;} frame;

void* counter(void* arg){
    struct data* currentData = (struct data*) arg; // Casting void* to int*
    printf("\n Loop %d", currentData->id);
    for(int i= (currentData->id)*10 ;i< (currentData -> totalTime); i++){
        printf(" %d", i);
    }
}

void main(){

    pthread_t thread[3]; // I need 3 threads, each counting certain time

    struct data dataFrame[3] = {{0,10}, {1,20}, {2,30}};

    void* (*fp_cntr)(void*);
    fp_cntr = counter;

    pthread_create(thread+0, NULL, fp_cntr,(void*) (dataFrame+0));
    pthread_create(thread+1, NULL, fp_cntr,(void*) (dataFrame+1));
    pthread_create(thread+2, NULL, fp_cntr,(void*) (dataFrame+2));

    for(int i=0;i < 3;i++){
        pthread_join(thread[i], NULL);
    }

}