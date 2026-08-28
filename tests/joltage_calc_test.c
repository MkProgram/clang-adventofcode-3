#include "joltage_calc.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  const char *name;
  const char *gate;
  uintmax_t expected;
} JOLTAGE_GATE_CASE;

static const JOLTAGE_GATE_CASE cases[] = {
    {"First", "987654321111111", 987654321111},
    {"Second", "811111111111119", 811111111119},
    {"Third", "234234234234278", 434234234278},
    {"Forth", "818181911112111", 888911112111}};

int test_joltage_gate_calculation(void) {
  int failures = 0;

  for (size_t i = 0; i < sizeof cases / sizeof cases[0]; ++i) {
    uintmax_t actual = get_joltage_from_gate(cases[i].gate);

    if (actual != cases[i].expected) {
      fprintf(stderr,
              "FAILURE: %s: Expected %" PRIuMAX ", actual %" PRIuMAX "\n",
              cases[i].name, cases[i].expected, actual);
      ++failures;
    }
  }

  return failures;
}

int main(void) {
  int failures = 0;

  failures += test_joltage_gate_calculation();

  if (failures == 0) {
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
