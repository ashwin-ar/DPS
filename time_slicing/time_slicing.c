#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int coutner =0;

void *thread(void* arg){
    int* temp_arg = (int*) arg;

    return NULL;
}

int main(){
    pthread_t thread_list[2];
    int thread_id[2] = {0,1};
    
    pthread_create(&thread_list[0],NULL,thread,&thread_id[0]);
    pthread_join(thread_list[0], NULL);
    return NULL;
}