#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdint.h>
double integrate(double a, double b, long n)
{
	double h = (b-a)/n;
	double approx=(2/(1+a*a))   +  (2/(1+b*b));
	double s = omp_get_wtime();
	double var=0;
	long long i=0;
	#pragma omp parallel for reduction(+:approx)
	for(i=0; i<n; i++)
	{
	    	double x=a+h*i;
	    	approx+=4/(1+x*x);
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

