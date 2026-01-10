#include <pthread.h>
#include <stdio.h>
int sum = 0;    //sum is a shared resource

// P2: Parallel thread
void *threadFunction(void *arg){
    // * arg is the thread no here??
    float *num = (float *)arg;
    sum++;
    printf("\n Executing thread %f & sum = %d", *num, sum);
    //pthread_exit(NULL); // return any value, that can be used by another thread
}
// P1: Main Thread
int main(){
    pthread_t threadList[2];

    // any type of arg that we wish to pass, later will be typecasted into void
    float argument[] = {1.0,2.5}; 

    // 1: Thread creation
    for(int i=0; i< 2; i++){
        // e1 : pthread_create(i ... -> Arg 1 should be an address, where thread ID will be stored.
        // e2 : arg3 should be a pointer to function, that thread will execute.
        if (pthread_create(&threadList[i],NULL, threadFunction, (void *)(argument+i)) != 0){
            printf("Error in thread %d creation",i);
            return 1;
        } 
    }
    /*
     * Without calling pthread_join -> 
     * Random behaviour, sometimes just 1 thread is executed, Sometimes none
    */ 
    for(int i=0;i < 2; i++){
        pthread_join(threadList[i],NULL);
    }
    return 0;
}