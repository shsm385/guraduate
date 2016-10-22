#include<stdio.h>
#include<time.h>
#include<omp.h>
#include<math.h>
#define NUM_THREADS 2048

long num_steps = 10000000;
double step;

// Parallel by OpenMP
int main(){
  int i;
  double x, pi, sum[NUM_THREADS];
  clock_t start, end;

  start = clock();

  step = 1.0 / (double)num_steps;
  omp_set_num_threads(NUM_THREADS);
  
  #pragma opm parallel private(x)
  { int my_id = omp_get_thread_num();
   for(i = my_id, sum[my_id]=0.0; i <= num_steps; i+=NUM_THREADS){
 	 x = (i + 0.5) * step;
	 sum[my_id] += 4.0 / (1.0 + x * x);
   }
  }

  for(i=0, pi=0.0; i<NUM_THREADS; i++){ 
    pi += step * sum[i];
  }

  end = clock();

  printf("pi = %lf\n", fabs(pi - M_PI));
  printf("time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}
