#include "logging/cov_log.h"
#include "logging/cov_serializer.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <time.h>

const size_t INPUTS = 1000;

uint64_t
rand_32_bit()
{
  static size_t bit_index = 31;
  static uint64_t rand_bitfield;

  if (bit_index == 31) {
    // random() returns a signed, positive 32 bit value
    // this means the highest bit will always be 0
    // to get a 32 bit random value we take random bits
    // from another call to random and put them in the highest
    // bit position. Every 31 calls we run out of random bits
    // and must do an extra call to random()
    rand_bitfield = (uint64_t) random();
    bit_index = 0;
  }

  uint64_t r = (uint64_t) random();
  r |= ((rand_bitfield >> bit_index) & 0x1) << 31;
  bit_index++;

  return r;
}


uint64_t
rand_uint64_t(void)
{
  return rand_32_bit() | (rand_32_bit() << 32);
}


double
rand_real_range(const double low, const double high)
{
  assert(!isnan(low));
  assert(!isnan(high));
  assert(low <= high);

  const double r = ((double) rand_uint64_t()) / (double) UINT64_MAX;
  const double diff = high - low;
  const double rr = r * diff;
  const double retval = low + rr;

  assert(retval >= low);
  assert(retval <= high);
  return retval;
}


int 
main()
{
  srandom(42);
  double inputs1[INPUTS];
  double inputs2[INPUTS];

  for (size_t i=0; i<INPUTS; i++) {
    inputs1[i] = rand_real_range(1.0, 10.0);
    inputs2[i] = rand_real_range(1.0, 10.0);
    cov_log("", "final_inputs1", 1, (long double) inputs1[i]);
    cov_log("", "final_inputs2", 1, (long double) inputs2[i]);
  }





  double finputs1[INPUTS];

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
      finputs1[i] = cov_deserialize(s, sizeof(long double));
    }
    printf("%f ==? %f \n", inputs1[i], finputs1[i]);
  }

  double finputs2[INPUTS];

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
      finputs2[i] = cov_deserialize(s, sizeof(long double));
    }
    printf("%f ==? %f \n", inputs2[i], finputs2[i]);
  }

}
