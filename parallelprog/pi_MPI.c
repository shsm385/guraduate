#include<stdio.h>
#include<time.h>
#include<mpi.h>

long num_steps = 100000;
double step;

// MPI
int main(){
  int i, my_rank, numprocs;
  double x, pi, sum = 0.0, my_pi;
  clock_t start, end;

  start = clock();

  step = 1.0 / (double)num_steps;
  MPI_Init();
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  for(i = my_rank + 1; i<= num_steps; i += numprocs){
    x = (i - 0.5) * step;
	sum += 4.0 / (1.0 + x * x);
  }

  my_pi = step * sum;
  MPI_Reduce(&my_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  /* if(my_rank == 0) -> print out*/

  MPI_Finalize();
  end = clock();
  
  pirnt("pi = %lf\n", my_py);
  printf("time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}
