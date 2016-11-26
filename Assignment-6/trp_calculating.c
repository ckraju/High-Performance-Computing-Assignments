#include <stdio.h>
#include "mpi.h"
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
	int me;  // rank of the thread
	int nproc; //total processors
	long  n = tol(argv[1]);
	double a=0.0;
	double b=1.0;  
	   
	int  src;	
	int  dst = 0;	
	double local_ans; // local answer for saving the total summation in that thread
	double total;
	int  tag = 50;  // message tag for identifying the message
	double start=0;	//starting point of each thread
	MPI_Status sts;	// for saving status of the sent message
	
	start=omp_get_wtime();
	
	//initialize
	MPI_Init(&argc, &argv);  
	MPI_Comm_rank(MPI_COMM_WORLD, &me);
	//Adding all the available processor in the computation	
	MPI_Comm_size(MPI_COMM_WORLD, &nproc);	 
	double h=(b-a)/n;
	local_ans=Trap(h,a,1+(me*n)/nproc , ((me+1)*n)/nproc);  // calling the calculating pi function 
		
	double temp;			
	if(me == 0)  //getting all the answer from each processes and saving the sum 
	{
		total = local_ans;
		for (src = 1; src < nproc; src++)
		{	
			MPI_Recv(&temp,1,MPI_DOUBLE,src,tag,MPI_COMM_WORLD,&sts);
			total += temp;
			//printf("With n = %ld \n", n);
		
		}
		total=(a*a+b*b +2*total)*h/2;	
			
	} 
	else 
	{   
		MPI_Send(&local_ans,1,MPI_DOUBLE,dst,tag,MPI_COMM_WORLD);
	}
	
	if(me == 0) 
	{
		//printf("With n = %ld \n", n);
		printf("%lf\n",total); 
	}
	MPI_Finalize();
	if(me == 0) 
	{
		double end=omp_get_wtime(); 
		printf("%lf",end-start); 
	}
	return 0;
}
