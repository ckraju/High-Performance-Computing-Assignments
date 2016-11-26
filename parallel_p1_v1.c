#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdint.h>


int main( int argc, char *argv[] )
{    
    int n=atoi(argv[1]);  
    double pi=0;
    int i=0;
    double s = omp_get_wtime();
    
    #pragma omp parallel for reduction(+:pi)
    for(i=0;i<n;i+=2)
    {
        pi+=1/(2*i+1.0);
    }
    #pragma omp parallel for reduction(-:pi)  
    for(i=1;i<n;i+=2)
    {
        pi-=1/(2*i+1.0);
    }
    pi *=4;
    
printf("%d      ",n);
    printf("time = %f\n", omp_get_wtime() - s);    
   // printf("pi  %lf \n",pi  );
}


