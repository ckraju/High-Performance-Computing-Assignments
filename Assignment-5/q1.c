#include<stdio.h>
#include<omp.h>
int main(int argc , char** argv)
{
    int n = atoi(argv[1]);

    
    int i = 0; 
    int *a = (int*)malloc(sizeof(int) * (n + 1));
    int *prefix = (int*)malloc(sizeof(int) * (n + 1));
    for(i = 0; i < n; i++)
    {
        a[i] = i;
    }
    double start = omp_get_wtime();  
    prefix[0] = a[0];
    for(i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    double end = omp_get_wtime();
    printf("%d %lf\n",prefix[n-1] ,(end-start));
}