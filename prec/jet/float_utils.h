#ifndef FLOAT_SUM_H
#define FLOAT_SUM_H

#include <stdint.h>
#include <stddef.h>


#include "static_assert.h"


typedef double flt;
typedef uint64_t hex;

static const size_t RAND_HEX_MAX = UINT64_MAX;

typedef struct _mul_unit {
  hex hi : sizeof(hex)*8;
  hex lo : sizeof(hex)*8;
} mul_unit;

STATIC_ASSERT(sizeof(flt) == sizeof(hex),
	      "flt and hex must be the same size");


flt flt_sum(const size_t length, const flt *const float_array);
hex flt_to_hex(const flt in);
flt hex_to_flt(const hex in);
flt rand_real_range(const flt low, const flt high);
hex rand_hex_range(const hex low, const hex high);
hex ulps_between(const flt low, const flt high);
flt rand_ulp_range(const flt low, const flt high);
flt corrupt_flt(const flt in, const size_t high_index, const size_t low_index);

#endif
