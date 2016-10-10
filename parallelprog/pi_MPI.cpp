#include<stdio.h>
#include<time.h>
#include<math.h>
#include<mpi.h>

long num_steps = 100000;
double step;
double PI25DT = M_PI;
// MPI
int main(int argc, char* argv[]){
  int i, my_rank, numprocs;
  double x, pi, sum = 0.0, my_pi;
  clock_t start, end;

  start = clock();

  step = 1.0 / (double)num_steps;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  if(my_rank == 0){
	printf("Enter the numer of intervals\n");
	scanf("%d",&num_steps);
	printf("n=%d\n",num_steps);
  }
  
  MPI_Bcast(&num_steps,1,MPI_INT,0,MPI_COMM_WORLD);

  for(i = my_rank + 1; i<= num_steps; i += numprocs){
    x = (i - 0.5) * step;
	sum += 4.0 / (1.0 + x * x);
  }

  my_pi = step * sum;
  MPI_Reduce(&my_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  /* if(my_rank == 0) -> print out*/
  if(my_rank == 0){
	 end = clock();
	 printf(" pi is approximately: %1f Error is: %1f \n",fabs(pi-PI25DT),my_pi);
	 printf("time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
  }

  MPI_Finalize();
}
