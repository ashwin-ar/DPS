#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <pthread.h>
#include <unistd.h> // for time

void* threadFunc(void* arg){
    int* temp_arg = (int*) arg;
    // existing soft affinity
    int cpu = sched_getcpu();
    sleep(10);
    printf("\n thread %d current cpu %d",*temp_arg,cpu);
    sleep(2);

    // assign a new affinity (or) pin thread to a cpu
    cpu_set_t new_affinity;
    CPU_ZERO(&new_affinity);
    CPU_SET(0,&new_affinity);

    pthread_setaffinity_np(pthread_self(),sizeof(new_affinity),&new_affinity);


    //check new affinity
    while(1){
        cpu = sched_getcpu();
        sleep(1);
        printf("\n thread %d current cpu %d",*temp_arg,cpu);
    }

    return NULL;
}

int main(){
    pthread_t thread_list[2];
    int thread_id[2] = {0,1};

    pthread_create(&thread_list[0], NULL, threadFunc, &thread_id[0]);
    pthread_create(&thread_list[1], NULL, threadFunc, &thread_id[1]);

    pthread_join(thread_list[0],NULL);
    pthread_join(thread_list[1],NULL);

    pthread_exit(NULL);
    return 0;
}