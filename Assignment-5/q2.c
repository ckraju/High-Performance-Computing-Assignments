#include<stdio.h>
#include<omp.h>
int main(int argc , char** argv)
{
    int i = 0; 
    int n = atoi(argv[1]);
    
    int F = 500;
    int *b = (int*)malloc(sizeof(int) * (n + 1));
    int *prefix = (int*)malloc(sizeof(int) * (n + 1));
    int *tmp = (int*)malloc(sizeof(int) * 103);
    for(i = 0;i < n; i++)
    {
        b[i] = rand() % 1000;
    }
    double start=omp_get_wtime();  
    int sz = 0;
    for(i = 0; i < n; i++)
    {
        if(b[i] > F) sz++;
    }
    int k = 0;
    int *ans = (int*)malloc(sizeof(int) * sz);
    for(i = 0; i < n; i++)
    {
        if(b[i] > F) ans[k++] = b[i]; 
    }
    double end=omp_get_wtime();
    printf("%d %lf\n", prefix[n-1],(end-start));
}