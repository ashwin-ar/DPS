#include <stdio.h>
#include <stdlib.h>
#include <omp.h> //openmp
#include <unistd.h>

int main()
{
// exploring private clause
#pragma omp parallel num_threads(5)
{
    int i=0;
    i++;
    printf("\t %d",i);
}
printf("___________________");

/*
    - Easier way to private a variable is by declaring it inside the block. 
    But if we want the varibale to be initialized, compute outside and 
    remain as private inside a block then we need private clause 
    
    (i) Private is same as normal private
    (ii) If we need it to be get a value from outside & be private to each loop
    we need firstprivate (case where some other function computes it outside my thread)
    (iii) If it should bring back the last value of the loop ,then we need lastprivate.
*/
int i=0; // (i)
#pragma omp parallel private(i) num_threads(5)
{
    i++; // this can result in garbage value, as it just declares, not copies/initialises the variable i
    printf("\t %d",i);
}
printf("\n i = %d",i);
printf("\n___________________");

int j=20; // (ii)
#pragma omp parallel for firstprivate(j) num_threads(5)
for(int loop_var=0;loop_var<4;loop_var++){
    j++; // now all thread would have got own copy of i, as firstprivate is used.
    printf("\t %d",j);
}
printf("\n j = %d",j);
printf("\n___________________");

int k=0;
#pragma omp parallel for lastprivate(k) num_threads(5)
for(int loop_var=0;loop_var<4;loop_var++){
    k = loop_var;     // just k can result in garbage value, as it just declares, not copies/initialises the variable i
    printf("\t %d",k);
}
printf("\n k= %d",k);
    return 0;
}