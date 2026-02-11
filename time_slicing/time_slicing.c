#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // for sleep function

int counter =0;

void *thread(void* arg){
    int* temp_arg = (int*) arg;

    for(int i=0;i<10000;i++){
        // Simulating Race condition - this was actually given in pdf as onyl two counter increments, but I was not able to simualte it over here
        // so using a for loop & rest is same

        // Time slicing - thread 1 @ instant 0 and thread 2 @ instant 1
        int temp = counter;
        usleep(1);
        counter = temp+1;
    }
    return NULL;
}

int main(){
    pthread_t thread_list[2];
    int thread_id[2] = {0,1};
    
    pthread_create(&thread_list[0],NULL,thread,&thread_id[0]);
    pthread_create(&thread_list[1],NULL,thread,&thread_id[1]);
    
    pthread_join(thread_list[0], NULL);
    pthread_join(thread_list[1], NULL);

    printf("Final counter = %d\n", counter);
    
    return 0;
}