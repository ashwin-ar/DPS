#include <pthread.h>
#include <stdio.h>

// P2: Parallel thread
void *threadFunction(void *arg){
    static int j=1;
    printf("what is this %d", j);
    pthread_exit(NULL); // return any value, that can be used by another thread
}
// P1: Main Thread
int main(){
    pthread_t threadList[2];
    // 1: Thread creation
    for(int i=0; i< 2; i++){
        // e1 : pthread_create(i ... -> Arg 1 should be an address, where thread ID will be stored.
        // e2 : arg3 should be a pointer to function, that thread will execute.
        if (pthread_create(&threadList[i],NULL, threadFunction, NULL) != 0){
            printf("Error in thread %d creation",i);
            return 1;
        } 
    }

    return 0;
}