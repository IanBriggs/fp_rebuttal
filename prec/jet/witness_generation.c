#include "logging/cov_log.h"
#include "logging/cov_checker.h"
#include "logging/cov_serializer.h"

#include <time.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>


#include "float_utils.h"

double jet64(double x1, double x2)
{
  double __const_0 = 3.0;
  double __const_1 = 2.0;
  double __const_2 = 1.0;
  double __const_3 = 2.0;
  double __const_4 = 3.0;
  double __const_5 = 4.0;
  double __const_6 = 6.0;
  double __const_7 = 1.0;
  double __const_8 = 3.0;
  double __const_9 = 3.0;
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




double jetprec(float x1, float x2) {
  float __const_0 = 3.0;
  float __const_1 = 2.0;
  float __const_2 = 1.0;
  float __const_3 = 2.0;
  float __const_4 = 3.0;
  float __const_5 = 4.0;
  float __const_6 = 6.0;
  float __const_7 = 1.0;
  float __const_8 = 3.0;
  float __const_9 = 3.0;
  float _expr_0   = __const_3 * x1;        // ['*', ['Variable', '__const_3'], ['Input', 'x1']]
  float _expr_1   = x1        * x1;        // ['*', ['Input', 'x1'], ['Input', 'x1']]
  float _expr_2   = __const_0 * _expr_1;   // ['*', ['Variable', '__const_0'], ['Variable', '_expr_1']]
  float _expr_3   = __const_1 * x2;        // ['*', ['Variable', '__const_1'], ['Input', 'x2']]
  float _expr_4   = _expr_2   + _expr_3;   // ['+', ['Variable', '_expr_2'], ['Variable', '_expr_3']]
  float _expr_5   = _expr_4   - x1;        // ['-', ['Variable', '_expr_4'], ['Input', 'x1']]
  float _expr_6   = _expr_1   + __const_2; // ['+', ['Variable', '_expr_1'], ['Variable', '__const_2']]
  float _expr_7   = _expr_5   / _expr_6;   // ['/', ['Variable', '_expr_5'], ['Variable', '_expr_6']]
  float _expr_8   = _expr_0   * _expr_7;   // ['*', ['Variable', '_expr_0'], ['Variable', '_expr_7']]
  float _expr_9   = _expr_7   - __const_4; // ['-', ['Variable', '_expr_7'], ['Variable', '__const_4']]
  float _expr_10  = _expr_8   * _expr_9;   // ['*', ['Variable', '_expr_8'], ['Variable', '_expr_9']]
  float _expr_11  = __const_5 * _expr_7;   // ['*', ['Variable', '__const_5'], ['Variable', '_expr_7']]
  float _expr_12  = _expr_11  - __const_6; // ['-', ['Variable', '_expr_11'], ['Variable', '__const_6']]
  float _expr_13  = _expr_1   * _expr_12;  // ['*', ['Variable', '_expr_1'], ['Variable', '_expr_12']]
  float _expr_14  = _expr_10  + _expr_13;  // ['+', ['Variable', '_expr_10'], ['Variable', '_expr_13']]
  float _expr_15  = _expr_1   + __const_7; // ['+', ['Variable', '_expr_1'], ['Variable', '__const_7']]
  float _expr_16  = _expr_14  * _expr_15;  // ['*', ['Variable', '_expr_14'], ['Variable', '_expr_15']]
  float _expr_17  = __const_8 * _expr_1;   // ['*', ['Variable', '__const_8'], ['Variable', '_expr_1']]
  float _expr_18  = _expr_17  * _expr_7;   // ['*', ['Variable', '_expr_17'], ['Variable', '_expr_7']]
  float _expr_19  = _expr_16  + _expr_18;  // ['+', ['Variable', '_expr_16'], ['Variable', '_expr_18']]
  float _expr_20  = _expr_1   * x1;        // ['*', ['Variable', '_expr_1'], ['Input', 'x1']]
  float _expr_21  = _expr_19  + _expr_20;  // ['+', ['Variable', '_expr_19'], ['Variable', '_expr_20']]
  float _expr_22  = _expr_21  + x1;        // ['+', ['Variable', '_expr_21'], ['Input', 'x1']]
  float _expr_23  = __const_9 * _expr_7;   // ['*', ['Variable', '__const_9'], ['Variable', '_expr_7']]
  float _expr_24  = _expr_22  + _expr_23;  // ['+', ['Variable', '_expr_22'], ['Variable', '_expr_23']]
  float _expr_25  = x1        + _expr_24;  // ['+', ['Input', 'x1'], ['Variable', '_expr_24']]
  return _expr_25;
}



int main() {
  srandom(42);
  long double threshold = 1.02e-3; 
  
  double max_x1 = 0.0;
  double max_x2 = 0.0;
  double max_diff = -100000000000000000000.0;
  for (size_t k=0; k<10; k++) {
    for (size_t i=0; i<80; i++) {
      for (size_t j=0; j<1000000; j++) {
	double x1 = rand_real_range(-5.0,  5.0);
	double x2 = rand_real_range(-20.0,  5.0);
	double j64 = jet64(x1, x2);
	double jprec = jetprec(x1, x2);
	
	double diff = fabs(j64-jprec);
	if (diff > max_diff) {
	  max_diff = diff;
	  max_x1 = x1;
	  max_x2 = x2;
	}

	if (k > 0 && max_diff > threshold) {
	  printf("\n\nx1 = %lf\n", max_x1);
	  printf("x2 = %lf\n", max_x2);
	  printf("all-double answer: %lf\n", jet64(max_x1, max_x2));
	  printf("prec answer:       %lf\n", jetprec(max_x1, max_x2));
	  printf("difference:        %lf\n", max_diff);
	  return 0;
	}
      }

      printf(".");
      fflush(stdout);
    }

    printf("\nmax_diff: %a\n", max_diff);
  }

  return 1;
}
