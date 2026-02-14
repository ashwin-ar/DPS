#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;

void *inc_thread(void* arg){
    int* temp_counter = (int*) arg;
    counter++;
    printf("counter value in %d %d",*temp_counter, counter);
    return NULL;
}

int main(){

    int thread_id[2] ={0,1};
    pthread_t thread[2];
    
    pthread_create(&thread[0],NULL,inc_thread, (void*) (&thread_id[0]));
    //pthread_join(thread[0],NULL);

    pthread_create(&thread[1],NULL,inc_thread, (void*) (&thread_id[1]));
    //pthread_detach(thread[1]);
    //pthread_join(thread[1],NULL);

    //Subtask-1
    //pthread_join(thread[0],NULL); // it's important to have pthread_join, if not the threads would be creataed & the main would exit
    printf("main done\n");
    /* 
        exit in main - non blocking join - other thread will continue running, even if the main program exits
        join - blocking - waits untill everyone is merged
        nothing - program can return directly

        detach - just says that it will clear it's own memory even if main return, but without exit it kills itself
    */
    pthread_exit(NULL); 
    return 0;
    printf("this won't execute\n");

}