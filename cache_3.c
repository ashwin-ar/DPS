#include <stdio.h>
#include <time.h>

#define N 10000000
int a[N];

int main() {
    clock_t start, end;

    // Good temporal locality
    start = clock();
    long long sum1 = 0;
    for (int i = 0; i < N; i++)
        sum1 += a[i];
    end = clock();
    printf("First pass: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Second pass reuses cached data
    start = clock();
    long long sum2 = 0;
    for (int i = 0; i < N; i++)
        sum2 += a[i];
    end = clock();
    printf("Second pass: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
}