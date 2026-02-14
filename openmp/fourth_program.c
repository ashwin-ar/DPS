#include <stdio.h>
#include <omp.h>
#include<unistd.h>
#define MAX 5
int main()
{
    int i, j;
    /*
        (i) j is dependant on previous value of j // race condition because it is still sequential.
        (ii) removing that dependency of a parallel variable -> j+=2 -> j=j+2 -> new_var=init_val+2*i
            making sequential to parallel.  
    
        
        note: but this is okay if there is math dependancy. What if the memory has been shared 
        then this happensss?

    */
    j = 5;
#pragma omp parallel for num_threads(3)
    for (i = 0; i < MAX; i++) // (i)
    {
        j += 2;
        sleep(1);
        printf("\n i %d , j %d", i, j);
    }

    j = 5;
    printf("\n___________________");

#pragma omp parallel for num_threads(3)
    for (i = 0; i < MAX; i++) // (ii)
    {
        int k = j + 2*i;
        sleep(1);
        printf("\n i %d , k %d", i, k);
    }

    printf("\n___________________");

    int sum=1; 
    i=0;j =0;

    #pragma omp parallel for num_threads(3)
    for (i = 1; i < 10; i++) // (ii)
    {
        sum = sum * i;
        sleep(1);
        printf("\n i %d , sum %d", i, sum);
    }
      printf("\nfinalsum = %d",sum);
  
    printf("\n___________________");
    
    sum=1; 
    i=0;j =0;

    #pragma omp parallel for num_threads(3) reduction( * : sum)
    // openmp does -> global_sum = initial_sum * (product of all private sums)
    for (i = 1; i < 10; i++) // (ii)
    {
        sum *=  i;
        sleep(1);
        printf("\n i %d , sum %d", i, sum);
    }
    printf("\nfinalsum = %d",sum);

    return 0;
}