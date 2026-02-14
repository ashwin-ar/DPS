#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <pthread.h>
#include <unistd.h> // for time

void* threadFunc(void* arg){
    int* temp_arg = (int*) arg;
    while (1) {
        int cpu = sched_getcpu();   // which core am I on right now?
        printf("Thread %d running on CPU %d\n",*temp_arg, cpu);
        usleep(500000);             // slow down so you can see changes
    }
    return NULL;
}

int main(){
    pthread_t thread_list[2];
    int thread_id[2] = {0,1};

    pthread_create(&thread_list[0], NULL, threadFunc, &thread_id[0]);
    pthread_create(&thread_list[1], NULL, threadFunc, &thread_id[1]);
    //pthread_join(thread_list[0],NULL);

    pthread_exit(NULL);
    return 0;
}