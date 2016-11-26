#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdint.h>

int main( int argc, char *argv[] )
{    
    int n=atoi(argv[1]);  
    //    int core=atoi(argv[2]); 
  int core=4;
  double pi=0;
    int i=0;
    omp_set_num_threads(core);
    double s = omp_get_wtime();
     #pragma omp parallel
    {   
        long long id = omp_get_thread_num();
        long long i,y,yend;
        double var=0;
        y=((n)/core)*id; 
         yend=((n)/core)*(id+1);
        if(y%2!=0)
             y-=1;
        for(i=y; i<yend; i+=2)
        {
              var+=1/(2*i+1.0);
        }
        y+=1;
        for(i=y; i<yend; i+=2)
        {
            var-=1/(2*i+1.0);
        }
        
        
    #pragma omp critical 
            pi+=var;
    }
    pi *=4;

printf("%d      ",n);
    printf("time = %f\n", omp_get_wtime() - s);    
// /    printf("pi  %lf \n",pi  );
}


