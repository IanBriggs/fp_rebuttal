#include "logging/cov_log.h"
#include "logging/cov_checker.h"
#include "logging/cov_serializer.h"

#include <time.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern uint64_t current_time_ns(void);
const size_t INPUTS = 1000;
#define PI 3.14159265

double cone_sa(double r, double h)
{
  double h2   = h * h; 
  double r2   = r * r; 
  double hr2  = h2 + r2; 
  double pir  = PI * r; 

  double tm1  = sqrt(hr2); 
  double tm2  = r + tm1; 
  double rel  = pir * tm2; 

  return rel;
}

int main() {
  // variables for logging/checking
  long double log[INPUTS];
  long double threshold = 5e-5; 

  // 0. read input from the file final_inputs
  int finputs1[INPUTS];

  FILE* infile1 = fopen("final_inputs1", "r");
  if (!infile1) 
  {
    printf("Could not open final_inputs1\n");
  }

  char *s = malloc(sizeof(long double));
  for (size_t i = 0; i < INPUTS; i++)
  {
    if (!feof(infile1))
    {
      fscanf(infile1, "%s", s);
      finputs1[i] = (double) cov_deserialize(s, sizeof(long double));
    }
  }

  int finputs2[INPUTS];

  FILE* infile2 = fopen("final_inputs2", "r");
  if (!infile2) 
  {
    printf("Could not open final_inputs2\n");
  }

  //char *s = malloc(10);
  for (size_t i = 0; i < INPUTS; i++)
  {
    if (!feof(infile2))
    {
      fscanf(infile2, "%s", s);
      finputs2[i] = (int)cov_deserialize(s, sizeof(long double));
    }
  }



  uint64_t start = current_time_ns();
  for (size_t l = 0; l < INPUTS; l++)
  {
    double r = finputs1[l];
    double h = finputs2[l];
    log[l] = cone_sa(r, h);
  }
  uint64_t end = current_time_ns();

  long int diff = (end-start);


  // 2. create spec, or checking results
  if (access("spec.cov", F_OK) == -1) {
    cov_arr_spec_log("spec.cov", threshold, INPUTS, log);
  }
  cov_arr_log(log, INPUTS, "result", "log.cov");
  cov_check("log.cov", "spec.cov", INPUTS);

  // 3. print score (diff) to a file
  FILE* file;
  file = fopen("score.cov", "w");
  fprintf(file, "%ld\n", diff);
  fclose(file);

  return 0;
}
