#include "bank_processor.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  puts("Lets process the gates!");
  FILE *file = NULL;
  const char *floc = "voltage_gates.txt";

  file = fopen(floc, "r");
  if (file == NULL) {
    fprintf(stderr, "Can't open file: %s\n", floc);
    return EXIT_FAILURE;
  }
  uintmax_t joltage = process_banks_from_file(file);

  fclose(file);

  printf("Joltage is: %" PRIuMAX "\n", joltage);

  return EXIT_SUCCESS;
}
