#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdint.h>
double integrate(double a, double b, long n)
{
    
    
	double h = (b-a)/n;
	double approx=(2/(1+a*a))   +  (2/(1+b*b));
	double s = omp_get_wtime();

 
	#pragma omp parallel
	{   
	    	long long id = omp_get_thread_num();
	    	long long i,y,yend; double x,sum=0.0;
	    	double var=0;
	     	y=((n)/4)*id;
	     	yend=((n)/4)*(id+1);
	  	 
	    	x=a +(b/4)*id;   
	    	for(i=y; i<yend; i++)
	    	{
			x+=h;
			var+=4/(1+x*x);
	    	}
	   	 
	    	#pragma omp critical
			approx+=var;
	}
	approx*=h;
	printf("\n%f", omp_get_wtime() - s);    
    
   return approx;

}

int main()
{
	double a ,b;
	long n;
	//scanf("%lf %lf %ld",&a,&b,&n);
	a = 0;
	b = 1;
	n = 1000000000;
	double u =integrate(a,b,n);
	printf("\n%lf\n",u);

}

