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

double jet(double x1, double x2)
{
  double __const_4 = 3.0;
  double __const_7 = 1.0;
  double __const_9 = 3.0;
  double __const_8 = 3.0;
  double __const_6 = 6.0;
  double __const_5 = 4.0;
  double __const_3 = 2.0;
  double __const_2 = 1.0;
  double __const_1 = 2.0;
  double __const_0 = 3.0;
  double _expr_0   = __const_3 * x1;        // ['*', ['Variable', '__const_3'], ['Input', 'x1']]
  double _expr_1   = x1        * x1;        // ['*', ['Input', 'x1'], ['Input', 'x1']]
  double _expr_2   = __const_0 * _expr_1;   // ['*', ['Variable', '__const_0'], ['Variable', '_expr_1']]
  double _expr_3   = __const_1 * x2;        // ['*', ['Variable', '__const_1'], ['Input', 'x2']]
  double _expr_4   = _expr_2   + _expr_3;   // ['+', ['Variable', '_expr_2'], ['Variable', '_expr_3']]
  double _expr_5   = _expr_4   - x1;        // ['-', ['Variable', '_expr_4'], ['Input', 'x1']]
  double _expr_6   = _expr_1   + __const_2; // ['+', ['Variable', '_expr_1'], ['Variable', '__const_2']]
  double _expr_7   = _expr_5   / _expr_6;   // ['/', ['Variable', '_expr_5'], ['Variable', '_expr_6']]
  double _expr_8   = _expr_0   * _expr_7;   // ['*', ['Variable', '_expr_0'], ['Variable', '_expr_7']]
  double _expr_9   = _expr_7   - __const_4; // ['-', ['Variable', '_expr_7'], ['Variable', '__const_4']]
  double _expr_10  = _expr_8   * _expr_9;   // ['*', ['Variable', '_expr_8'], ['Variable', '_expr_9']]
  double _expr_11  = __const_5 * _expr_7;   // ['*', ['Variable', '__const_5'], ['Variable', '_expr_7']]
  double _expr_12  = _expr_11  - __const_6; // ['-', ['Variable', '_expr_11'], ['Variable', '__const_6']]
  double _expr_13  = _expr_1   * _expr_12;  // ['*', ['Variable', '_expr_1'], ['Variable', '_expr_12']]
  double _expr_14  = _expr_10  + _expr_13;  // ['+', ['Variable', '_expr_10'], ['Variable', '_expr_13']]
  double _expr_15  = _expr_1   + __const_7; // ['+', ['Variable', '_expr_1'], ['Variable', '__const_7']]
  double _expr_16  = _expr_14  * _expr_15;  // ['*', ['Variable', '_expr_14'], ['Variable', '_expr_15']]
  double _expr_17  = __const_8 * _expr_1;   // ['*', ['Variable', '__const_8'], ['Variable', '_expr_1']]
  double _expr_18  = _expr_17  * _expr_7;   // ['*', ['Variable', '_expr_17'], ['Variable', '_expr_7']]
  double _expr_19  = _expr_16  + _expr_18;  // ['+', ['Variable', '_expr_16'], ['Variable', '_expr_18']]
  double _expr_20  = _expr_1   * x1;        // ['*', ['Variable', '_expr_1'], ['Input', 'x1']]
  double _expr_21  = _expr_19  + _expr_20;  // ['+', ['Variable', '_expr_19'], ['Variable', '_expr_20']]
  double _expr_22  = _expr_21  + x1;        // ['+', ['Variable', '_expr_21'], ['Input', 'x1']]
  double _expr_23  = __const_9 * _expr_7;   // ['*', ['Variable', '__const_9'], ['Variable', '_expr_7']]
  double _expr_24  = _expr_22  + _expr_23;  // ['+', ['Variable', '_expr_22'], ['Variable', '_expr_23']]
  double _expr_25  = x1        + _expr_24;  // ['+', ['Input', 'x1'], ['Variable', '_expr_24']]
  return _expr_25;
}

int main() {
  // variables for logging/checking
  long double log[INPUTS];
  long double threshold = 5e-3; 

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
    double x1 = finputs1[l];
    double x2 = finputs2[l];
    log[l] = jet(x1, x2);
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
