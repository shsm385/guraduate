#include<stdio.h>
#include<time.h>
#include<omp.h>
#define NUM_THREADS 2048

long num_steps = 10000000;
double step;

// Parallel by OpenMP
int main(){
  int i;
  double x, pi, sum = 0.0;
  clock_t start, end;

  start = clock();

  step = 1.0 / (double)num_steps;
  omp_set_num_threads(NUM_THREADS);
  
  #pragma opm parallel for reduction(+:sum) private(x)
  for(i = 1; i <= num_steps; i++){
	x = (i - 0.5) * step;
	sum += 4.0 / (1.0 + x * x);
  }

  pi = step * sum;
  end = clock();

  printf("pi = %lf\n", pi);
  printf("time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}
