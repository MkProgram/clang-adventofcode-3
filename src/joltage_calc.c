#include "joltage_calc.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_joltage_from_gate(char *gate) {

  size_t len = strlen(gate);
  if (len < 2) {
    fprintf(stderr, "Gate must contain at least two numbers\n");
    return 0;
  }

  int first = 0;
  int second = 0;
  size_t first_index = 0;

  for (size_t i = 0; i < len - 1; ++i) {
    unsigned char char_num = gate[i];
    if (!isdigit(char_num)) {
      fprintf(stderr, "Non-number character found: %c\n", gate[i]);
      continue;
    }
    int num = char_num - '0';
    if (num > first) {
      first = num;
      first_index = i;
    }
  }
  for (size_t j = first_index + 1; j < len; ++j) {
    unsigned char char_num = gate[j];
    if (!isdigit(char_num)) {
      fprintf(stderr, "Non-number character found: %c\n", gate[j]);
      continue;
    }
    int num = char_num - '0';
    if (num > second) {
      second = num;
    }
  }

  return (first * 10) + second;
}
