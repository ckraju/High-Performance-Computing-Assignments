#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <unistd.h>
int **curr_serial;
int **next_serial;
int **prefix_sum;

void prefix(int r,int c)
{
	int i,j;
	for(i=1;i<r-1;i++)
	{
		for(j=1;j<c-1;j++)
		{
			prefix_sum[i][j]=curr_serial[i][j]-prefix_sum[i-1][j-1]+prefix_sum[i-1][j]+prefix_sum[i][j-1];
			// dp for prefix sum
			//we have explained it in report
		}
	}
}
void print_state(int **state,int r,int c)  //print the state of the grid
{
	int i,j;
	for ( i = 0; i < r; ++i)
	{
		for (j = 0; j < c; ++j)
		{
			printf("%d ",state[i][j] );
		}
		printf("\n");
	}
	printf("\n");

}void update(int r, int c, int **curr_serial, int **next_serial)
{
	prefix(r,c);
	int i, j;
	for(i = 3; i < r-3; i++)
	{
		for(j = 3; j < c-3; j++)
		{
			//printf("%d ", curr_serial[i][j]);
			int alive_neighbours = 0;
			alive_neighbours = prefix_sum[i][j]-prefix_sum[i-3][j]-prefix_sum[i][j-3]+prefix_sum[i-3][j-3];
			int is_alive = curr_serial[i][j];
			next_serial[i][j] = is_alive; // next_state[i][j] is temporary grid to store next state of each cell
			if(is_alive && (alive_neighbours < 2 || alive_neighbours > 3))// update status as per over-population
													// and under-population rule
			{
				next_serial[i][j] = 0;
			}
			if(!is_alive && alive_neighbours == 3) // update status as per reproduction rule
			{
				next_serial[i][j] = 1;
			}
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			curr_serial[i][j]=next_serial[i][j]; // make current_state = next_state.
		}

	}
}


int main(int argc , char** argv)
{
	int i, j, r, c, total_steps, steps;   // r = rows, c = columns, total_steps = number of generations
	r=atoi(argv[1]);
	c=atoi(argv[2]);
	total_steps=atoi(argv[3]);
	curr_serial = (int **)(malloc(r * sizeof(int *)));
	next_serial = (int **)(malloc(r * sizeof(int *)));
	prefix_sum = (int **)(malloc(r * sizeof(int *)));
	
	for(i = 0; i < r; i++)
	{
		curr_serial[i] = (int *)(malloc(c * sizeof(int)));
		next_serial[i] = (int *)(malloc(c * sizeof(int)));
		prefix_sum[i] = (int *)(malloc(c * sizeof(int)));
		for(j = 0; j < c; j++)
		{
			curr_serial[i][j]=rand()%2;   // current_state[i][j] = 1  ==>  (i, j) is alive 
											// current_state[i][j] = 0  ==>  (i, j) is dead
			prefix_sum[i][j]=0;
		}
	}
	
	double start=omp_get_wtime();
	for(steps = 0; steps < total_steps; steps++)
	{
		update(r, c,curr_serial,next_serial); // finds next_state of each cell from current_state as per rules of Game of Life
	}
	double stop=omp_get_wtime();
	printf("%0.10lf\n", (stop-start));
}