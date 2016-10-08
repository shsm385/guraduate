#include<stdio.h>
#include<time.h>

long num_steps = 100000;
double step;

// Successively
int main(){
  int i;
  double x, pi, sum = 0.0;
  clock_t start, end;

  start = clock();

  step = 1.0 / (double)num_steps;
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
