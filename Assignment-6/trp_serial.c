#include <stdio.h>
#include <unistd.h>
#include <omp.h>	
double Trap(double h, double a,long str,long b){ 
	double s=0;
	long i=0;	
	for(i=str;i<=b;i++)
	{
		s = s + 4.0 / (1.0 + (a+i*h)*(a+i*h));
		//printf("%.10f\n",s);
	}
	return s;
}
long tol(char *s)
{
	long ret = 0;
	int i;
	for(i = 0; s[i]; i++)
	{
		ret = ret * 10 + (int)(s[i] - '0');
	}
	return ret;
}
int main(int argc, char** argv) 
{
	long  n = tol(argv[1]);
	double a=0;
	double b=1;  
	//printf("%ld\n", n);
	double start=0;	
	double total;
	start=omp_get_wtime();
	double h=(b-a)/n;
	total=Trap(h,a,1,n-1);  // calling the calculating pi function 
	//printf("%lf\n",total);	
	total=(a*a+b*b +2*total)*h/2;	
	//printf("With n = %ld \n", n);
	//printf("%lf\n", total); 
	double end=omp_get_wtime(); 
	printf("%lf",end-start); 
	return 0;
}
