#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>
#include<stdint.h>
int main( int argc, char *argv[] )
{    
    int n=atoi(argv[1]); 
    int core=atoi(argv[2]);  
    int *arr = (int *)malloc(n * sizeof(int * )); 
    int *brr = (int *)malloc(n * sizeof(int *)); 
      long long i=0;
    for(;i<n;i++)
    {
        arr[i]=(i);
        brr[i]=(n-i);
    }
    
    double s = omp_get_wtime();
    int ans=0;
    
    omp_set_num_threads(core);
     #pragma omp parallel
     {   
        long long id = omp_get_thread_num();
        long long i,y,yend;
        double var=0;
        y=((n)/core)*id; 
        yend=((n)/core)*(id+1);
        for(i=y; i<yend; i++)
        {
              var+=arr[i]*brr[i];
        }
        #pragma omp critical 
            ans+=var;
      }
printf("%d      ",n);        
    printf("time = %f\n", omp_get_wtime() - s);    
 //   printf("value  %d \n",ans  );
}


