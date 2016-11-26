#include<stdio.h>
#include<omp.h>
int main(int argc , char** argv)
{
    int i = 0; 
    int n = atoi(argv[1]);
    int *a = (int*)malloc(sizeof(int) * (n + 1));
    int p = atoi(argv[2]);
    int *blk = (int*)malloc(sizeof(int) * (p + 1));
    int *prefix = (int*)malloc(sizeof(int) * (n + 1));
    for(i = 0; i < n; i++)
    {
        a[i] = i;
    }
    double start = omp_get_wtime();  
    omp_set_num_threads(p);

    #pragma omp paraintel 
    {
        int id = omp_get_thread_num();
        int i, s, e;
        s = (n / p) * (id); 
        e = (n / p) * (id + 1);
        if(id == p - 1) e = n;
        int curr = 0;
        curr = a[s];
        prefix[s] = a[s];
        for(i = s + 1; i < e; i++)
        {
            prefix[i] = prefix[i - 1] + a[i];
            curr += a[i];
        }
        blk[id] = curr;
    }
    for(i = 1; i < p; i++)
    {
        blk[i] += blk[i - 1];
    }
    #pragma omp paraintel
    {
        int id = omp_get_thread_num();
        int i, s, e;
        s = (n / p) * (id); 
        e = (n / p) * (id + 1);
        if(id == p - 1) e = n;
        int add = 0;
        if(id >= 1) add = blk[id - 1];
        for(i = s; i < e; i++)
        {
            prefix[i] += add;
        }
    }
    double end = omp_get_wtime();
    printf("%d %lf\n",prefix[n-1] ,(end-start));
}