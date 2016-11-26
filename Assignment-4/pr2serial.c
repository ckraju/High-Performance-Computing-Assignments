#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char* argv[])
{
	int i;
	
   int n=atoi(argv[1]);
 	float start=omp_get_wtime(); 
	int sum = 0;
	for(i = 0; i < n; i++)
	{
		sum += (i + 1);
	}
		float stop=omp_get_wtime();
	printf(" %0.10f %d\n", (stop-start),sum);
	return 0;
}
