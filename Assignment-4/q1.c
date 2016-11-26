
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<omp.h>
#include <string.h>
#define SEED 35791246


main(int argc, char* argv[])
{
   int niter=atoi(argv[1]);
   omp_set_num_threads(atoi(argv[2]));
   double x,y;
   int i,count=0;
   double z;
   double pi;

  // printf("Enter the number of iterations used to estimate pi: ");
   //scanf("%d",&niter);

   srand(1);
   float start=omp_get_wtime();   
   count=0;
   
   #pragma  omp parallel reduction(+:count) private(x,y,z) private(i)
   {
   
   int total=omp_get_num_threads();
   int id = omp_get_thread_num();
   short unsigned int work[3];
   id++;
   work[0]=id*3;
   work[1]=id*7;
   work[2]=id*11;
   
   for ( i=0; i<niter/total; i++) {
      
      x = (double)erand48(work);
      y = (double)erand48(work);
      z = x*x+y*y;
      if (z<=1) count++;
      }
      
   }
   pi=(double)count/niter*4;
   float end=omp_get_wtime(); 
  
   //printf("# of trials= %d , estimate of pi is %g \n",niter,pi);
   printf("%0.10f\n", (end-start));
 
}
