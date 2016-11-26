#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdint.h>
#include<stdlib.h>
int main( int argc, char *argv[] )
{    
    int n=atoi(argv[1]);  
    int *arr = (int *)malloc(n * sizeof(int * )); 
    int *brr = (int *)malloc(n * sizeof(int *)); 
      long long i=0;
    for(;i<n;i++)
    {
        arr[i]=(i+1);
        brr[i]=(n-i);
    }
    
    double s = omp_get_wtime();
    int ans=0;
    for(i=0;i<n;i++)
    {
        ans+=arr[i]*brr[i];
    }
   
printf("%d      ",n);
    printf("time = %f\n", omp_get_wtime() - s);    
 //   printf("value  %d \n",ans  );
}


