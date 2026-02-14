#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t garden_mutex;
enum entrance{west=0,east=1};

void *inc_thread(void* arg){
    int* temp_arg = (int*) arg;
    /* METHOD - 1
    while (counter < 100){
        pthread_mutex_lock(&garden_mutex);
        counter++;
        printf("\n New Visitor entered through %d; Count=%d", *temp_arg, counter);
        pthread_mutex_unlock(&garden_mutex);
    }*/ // this gives race as,we unlock inside & never lock again.

    /* METHOD - 2 
    pthread_mutex_lock(&garden_mutex);
    while (counter < 100){
        counter++;
    } // only one thread executes
    pthread_mutex_unlock(&garden_mutex);
    */
    
    /*METHOD - 3 */
        for(int i=0;i<100;i++){
        pthread_mutex_lock(&garden_mutex);
        if (counter >= 100){
            pthread_mutex_unlock(&garden_mutex);
            break;
        }
        counter++;
        printf("\n New Visitor entered through %d; Count=%d", *temp_arg, counter);
        pthread_mutex_unlock(&garden_mutex);
        //usleep(1000);
    } // this gives race as,we unlock inside & never lock again.

    /*METHOD - 4*/
     /*   while(1){
            pthread_mutex_lock(&garden_mutex);
            if(counter >= 100){
                pthread_mutex_unlock(&garden_mutex);
                printf("\n thread went %d; Count=%d", *temp_arg, counter);
                break;
            }
            counter++;
            
            printf("\n New Visitor entered through %d; Count=%d", *temp_arg, counter);
            pthread_mutex_unlock(&garden_mutex);
            usleep(1000); // this is used because, so that only one thread should not unblock & block immediately
        }    */
    // whereever counter is referred - there we should ensure proper lock is there
    return NULL;
}

int main(){

    int thread_id[2] ={west,east};
    pthread_t entrance[2];
    pthread_mutex_init(&garden_mutex,NULL);

    pthread_create(&entrance[west],NULL,inc_thread, (void*) (&thread_id[west]));
    pthread_create(&entrance[east],NULL,inc_thread, (void*) (&thread_id[east]));

    pthread_join(entrance[0],NULL);
    pthread_join(entrance[1],NULL);

    return 0;
}