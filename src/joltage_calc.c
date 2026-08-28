#include "joltage_calc.h"
#include <ctype.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static const int DIGITS = 12;

unsigned char get_largest(const char *gate, size_t *offset, size_t len) {
  unsigned char largest = 0;
  size_t largest_index = 0;
  size_t start = (*offset == SIZE_MAX) ? 0 : *offset + 1;
  for (size_t i = start; i < len; ++i) {
    unsigned char char_num = gate[i];
    if (!isdigit(char_num)) {
      fprintf(stderr, "Non-number character found: %c\n", gate[i]);
      continue;
    }
    int num = char_num - '0';
    if (num > (largest - '0')) {
      largest = char_num;
      largest_index = i;
    }
  }
  *offset = largest_index;
  return largest;
}

uintmax_t get_joltage_from_gate(const char *gate) {

  size_t len = strlen(gate);
  if (len < DIGITS) {
    fprintf(stderr, "Gate must contain at least two numbers\n");
    return 0;
  }

  size_t offset = SIZE_MAX;
  char s[13];

  for (size_t i = 0; i < DIGITS; ++i) {
    s[i] = get_largest(gate, &offset, len - (DIGITS - i) + 1);
  }
  s[12] = '\0';

  return strtoumax(s, NULL, 10);
}
