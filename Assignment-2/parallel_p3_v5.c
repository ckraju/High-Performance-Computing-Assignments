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
    printf("      %d\n",error);
}

int main( int argc, char *argv[] )
{    
    int n=atoi(argv[1]);
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


    
    #pragma omp parallel 
    {

        long long id = omp_get_thread_num();
        long long y,yend;
        int sum=0;
        y=((n)/4)*id; 
        yend=((n)/4)*(id+1);
        int jj,kk,j,k;
        int bls=32;
        int temp;
        //printf("%lld   %lld %lld \n",y,yend,id);
        for(jj=y; jj<yend; jj+=bls)
        {
            for( kk=0;kk<n;kk+= bls)
            {       
                    int i=0;
                    for(i=0;i<n;i++)
                    {
                            for( j = jj; j<((jj+bls)>n?n:(jj+bls)); j++)
                            {
                                    temp = 0;
                                    for( k = kk; k<((kk+bls)>n?n:(kk+bls)); k++)
                                    {
                                            temp += first[i][k]*trans[j][k];
                                    }
                                    #pragma omp critical
                                    ans[i][j] += temp;
                            }
                    }
            }
        }
    }
    printf("%d %lf",n, omp_get_wtime() - s); 
   // check(n,first,second,ans);
    return 0;
}