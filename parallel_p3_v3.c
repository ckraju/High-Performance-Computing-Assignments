#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdint.h> 
#include <stdlib.h>
void check(int n,int **first,int **second,int **ans )
{

    int ans2[n][n];
    int c,d,k,sum=0;
    double time1=omp_get_wtime();
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
    double time2=omp_get_wtime();
    

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
    printf("    %d\n",error);

//    printf("serial time = %lf   \n",time2 - time1); 
}

int main( int argc, char *argv[] )
{    
    int n=atoi(argv[1]);
    //int core=atoi(argv[2]);
    int i=0;
    int core=4;
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
            ans[i][j]=0;
        }
    }
    



    //  timer is starting before i am transposing the matrix

    double s = omp_get_wtime();
    int **trans = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
        trans[i] = (int *)malloc(n * sizeof(int));
    for(i=0;i<n;i++)
    {
        int j=0;
        for(j=0;j<n;j++)
        {
            trans[i][j]=second[j][i];
        }
    }


    omp_set_num_threads(core);
    #pragma omp parallel 
    {

        int c,d,k;   
        long long id = omp_get_thread_num();
        long long y,yend;
        int sum=0;
        int i=0;
        int **ans2 = (int **)malloc(n * sizeof(int *));
        for (i=0; i<n; i++)
            ans2[i] = (int *)malloc(n * sizeof(int));
        for(i=0;i<n;i++)
        {
            int j=0;
            for(j=0;j<n;j++)
            {
                ans2[i][j]=0;
            }
        }
        y=((n)/core)*id; 
        yend=((n)/core)*(id+1);
        for(c=y; c<yend; c++)
        {
            for (d = 0; d < n; d++) 
            {
                for (k = 0; k < n; k++) 
                {
                    sum = sum + first[c][k]*trans[d][k];
                }
                
                    ans2[c][d] = sum;
                    sum = 0;
            }
        }
        #pragma omp critical
        for(i=0;i<n;i++)
        {
            int j=0;
            for(j=0;j<n;j++)
            {
                ans[i][j]+=ans2[i][j];
            }
        }

    }
    printf("%d %lf",n, omp_get_wtime() - s); 
   // check(n,first,second,ans);
    return 0;
}