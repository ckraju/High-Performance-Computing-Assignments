#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char* argv[])
{
	int i;

   int n=atoi(argv[1]);
 	int threads=atoi(argv[2]);
	float start=omp_get_wtime(); 
	int  tmp_sum = 0;
	int sum[threads];
	omp_set_num_threads(threads);
	#pragma omp parallel firstprivate(tmp_sum)
	{
		#pragma omp for 
		for(i=0;i<n;i++)
		{
			tmp_sum += i+1;
		}
		sum[omp_get_thread_num()] = tmp_sum;
	}
	int steps=threads;
	while(steps>1)
	{
		int j=steps/2;
		steps = steps/2 + steps%2;
		#pragma omp parallel for 
		for(i=0;i<j;i++)
		{
			sum[i] += sum[i+j];
		}
	}
	float stop=omp_get_wtime();
	printf("%0.10f %d\n", (stop-start),sum[0]);
	return 0;
}
