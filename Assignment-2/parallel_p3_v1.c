#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdint.h> 
#include <stdlib.h>
void check(int n,int **first,int **second,int **ans )
{

    int ans2[n][n];
    int c,d,k,sum=0;
    for (c = 0; c < n; c++) 
    {
        for (d = 0; d < n; d++) 
        {
            for (k = 0; k < n; k++) 
            {
                sum = sum + first[c][k]*second[k][d];
            }
            ans2[c][d] = sum;
            sum = 0;
        }
    }
    int error=0;
    for(c=0;c<n;c++)
    {
        for(d=0;d<n;d++)
        {
            if(ans2[c][d]!=ans[c][d])
            {  
                //printf("c=%c d=%d\n",c,d); 
                error++;
            }
        }
    }
    printf("%d\n",error);
}

int main( int argc, char *argv[] )
{    
    int n=atoi(argv[1]);
    int core=atoi(argv[2]);
    int i=0;
    
    int **first = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
         first[i] = (int *)malloc(n * sizeof(int));
    
    int **second = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
        second[i] = (int *)malloc(n * sizeof(int));
    
    int **ans = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
        ans[i] = (int *)malloc(n * sizeof(int));

    for(i=0;i<n;i++)
    {
        int j=0;
        for(j=0;j<n;j++)
        {
            first[i][j]=i+j;
            second[i][j]=j-i;
        }
    }
    double s = omp_get_wtime();
    int c,d,k,sum=0;
    for (c = 0; c < n; c++) 
    {
        for (d = 0; d < n; d++) 
        {
            #pragma omp parallel for reduction(+:sum) num_threads(core)
            for (k = 0; k < n; k++) 
            {
                sum = sum + first[c][k]*second[k][d];
            }
            ans[c][d] = sum;
            sum = 0;
        }
    }
    printf("%d %lf",n, omp_get_wtime() - s); 
    //check(n,first,second,ans);
    return 0;
}